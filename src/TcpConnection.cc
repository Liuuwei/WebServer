#include "TcpConnection.h"
#include "EventLoop.h"
#include "Log.h"

#include <unistd.h>

TcpConnection::TcpConnection(EventLoop* loop, int fd) : loop_(loop), channel_(loop, fd) {
    channel_.setReadCallback(std::bind(&TcpConnection::handleRead, this));
    channel_.setWriteCallback(std::bind(&TcpConnection::handleWrite, this));
}

TcpConnection::~TcpConnection() {
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
    ssize_t n = inputBuffer_.readFd(channel_.fd());
    if (n == -1) {
        Log::Instance()->DEBUG("readFd is -1");
    }
    if (n > 0) {
        messageCallback_(shared_from_this(), &inputBuffer_);
    }
    else {
        handleClose();
    }
}

void TcpConnection::handleWrite() {
    ssize_t sendAble = outputBuffer_.readAbleBytes();
    ssize_t n = outputBuffer_.writeFd(channel_.fd());
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
    if (!msg.empty())
        outputBuffer_.append(msg);
    ssize_t sendAble = outputBuffer_.readAbleBytes();
    ssize_t n = outputBuffer_.writeFd(channel_.fd());
    Log::Instance()->LOG("send %d bytes", n);
    if (n == sendAble) {
        channel_.unableRevents(EPOLLOUT);
    } else {
        channel_.enableWrite();
    }
}