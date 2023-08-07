#include "TcpConnection.h"

#include <unistd.h>

TcpConnection::TcpConnection(EventLoop* loop, int fd) : channel_(loop, fd) {
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
    start();
}

void TcpConnection::handleRead() {
    ssize_t n = inputBuffer_.readFd(channel_.fd());
    if (n == -1) {
        DEBUG();
    }
    if (n > 0) {
        messageCallback_(shared_from_this(), &inputBuffer_);
    }
    else {
        handleClose();
    }
}

void TcpConnection::handleWrite() {

}

void TcpConnection::handleClose() {
    LOG("handleClose");
    channel_.shutdown();
}

void TcpConnection::send(const std::string& msg) {
    outputBuffer_.append(msg);
    ssize_t sendAble = outputBuffer_.readAbleBytes();
    ssize_t n = outputBuffer_.writeFd(channel_.fd());
    LOG("send %d bytes", n);
    if (n == sendAble) {
        channel_.unableRevents(EPOLLOUT);
    }
}