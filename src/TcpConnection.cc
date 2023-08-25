#include "TcpConnection.h"
#include "EventLoop.h"
#include "Log.h"

#include <unistd.h>

TcpConnection::TcpConnection(EventLoop* loop, int fd, const std::string& ip) : loop_(loop), channel_(loop, fd), ip_(ip) {
    gettimeofday(&time_, nullptr);
    channel_.setIp(ip);
    channel_.setReadCallback(std::bind(&TcpConnection::handleRead, this));
    channel_.setWriteCallback(std::bind(&TcpConnection::handleWrite, this));
}

TcpConnection::~TcpConnection() {
    Log::Instance()->LOG("%s close connection", ip_.c_str());
}

void TcpConnection::start() {
    channel_.enableRead();
}

void TcpConnection::setMessageCallback(MessageCallback cb) {
    messageCallback_ = cb;
    loop_->addTcp(shared_from_this());
    start();
}

void TcpConnection::handleRead() {
    gettimeofday(&time_, nullptr);
    ssize_t n = inputBuffer_.readFd(channel_.fd());
    if (n == 0) {
        Log::Instance()->DEBUG(": %s readFd is 0", ip_.c_str());
        handleClose();
        return;
    }
    if (n == -1) {
        Log::Instance()->DEBUG(": %s readFd is -1", ip_.c_str());
        if (errno != EAGAIN || errno != EWOULDBLOCK)
            handleClose();
        return;
    }
    /* 数据量太大认为是异常连接直接关闭 */
    if (inputBuffer_.readAbleBytes() > 65536) {
        handleClose();
        return;
    }
    if (n > 0) {
        messageCallback_(shared_from_this(), &inputBuffer_);
    } else {
        handleClose();
    }
}

void TcpConnection::handleWrite() {
    gettimeofday(&time_, nullptr);
    ssize_t sendAble = outputBuffer_.readAbleBytes();
    ssize_t n = outputBuffer_.writeFd(channel_.fd());
    if (n == -1) {
        Log::Instance()->DEBUG("%s: writeFd is -1", ip_.c_str());
    }
    if (n == sendAble) {
        channel_.unableWrite();
    }
}

void TcpConnection::handleClose() {
    channel_.shutdown();
    loop_->runInLoop([&]() {
        loop_->removeTcp(fd());
    });
}

void TcpConnection::send(const std::string& msg) {
    gettimeofday(&time_, nullptr);
    if (!msg.empty())
        outputBuffer_.append(msg);
    ssize_t sendAble = outputBuffer_.readAbleBytes();
    ssize_t n = outputBuffer_.writeFd(channel_.fd());
    if (n == -1) {
        Log::Instance()->DEBUG("%s: send is -1", ip_.c_str());
        handleClose();
        return;
    }
    Log::Instance()->LOG("%s: send %d bytes", ip_.c_str(), n);
    if (n == sendAble) {
        channel_.unableRevents(EPOLLOUT);
    } else {
        channel_.enableWrite();
    }
}

void TcpConnection::setIp(const std::string &ip) {
    ip_ = ip;
}
