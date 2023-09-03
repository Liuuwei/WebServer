#include "TcpConnection.h"
#include "EventLoop.h"
#include "Log.h"

#include <unistd.h>

TcpConnection::TcpConnection(EventLoop* loop, int fd, const std::string& ip) : loop_(loop), channel_(loop, fd), ip_(ip) {
    channel_.setIp(ip);
    channel_.setReadCallback(std::bind(&TcpConnection::handleRead, this));
    channel_.setWriteCallback(std::bind(&TcpConnection::handleWrite, this));
}

TcpConnection::~TcpConnection() {
    Log::Instance()->LOG("%s close connection", ip_.c_str());
    handleClose();
}

void TcpConnection::start() {
    channel_.enableRead();
}

void TcpConnection::setReadCallback(MessageCallback cb) {
    readCallback_ = cb;
    channel_.enableRead();
}

void TcpConnection::setWriteCallback(MessageCallback cb) {
    writeCallback_ = cb;
    channel_.enableWrite();
}

void TcpConnection::handleRead() {
    loop_->connectionQueue().back().insert(shared_from_this());
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
        readCallback_(shared_from_this(), &inputBuffer_);
    } else {
        handleClose();
    }
}

void TcpConnection::handleWrite() {
    loop_->connectionQueue().back().insert(shared_from_this());
    ssize_t sendAble = outputBuffer_.readAbleBytes();
    if (sendAble == 0) {
        return;
    }
    ssize_t n = outputBuffer_.writeFd(channel_.fd());
    if (n == -1) {
        Log::Instance()->DEBUG("%s: writeFd is -1", ip_.c_str());
    }
    writeCallback_(shared_from_this(), &outputBuffer_);
    if (n == sendAble) {
        channel_.unableWrite();
    }
}

void TcpConnection::handleClose() {
    channel_.shutdown();
}

void TcpConnection::send(const std::string& msg) {
    loop_->connectionQueue().back().insert(shared_from_this());
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
