//
// Created by Liuwei on 2023/8/28.
//
#include "TcpClient.h"
#include <assert.h>

TcpClient::TcpClient(EventLoop* loop, std::string ip, int port) : loop_(loop), connector_(ip, port),
                                                              threadPoll_(1, loop_) {

}

TcpClient::~TcpClient() {

}

void TcpClient::connect() {
    int ret = connector_.connect();
    if (ret == -1) {
        std::cout << "connect failed" << std::endl;
    }
    fd_ = connector_.fd();
    readConn_ = std::make_shared<TcpConnection>(threadPoll_.getOneLoop(), fd_, ip_);
    readConn_->setReadCallback(readCallback_);
    writeConn_ = std::make_shared<TcpConnection>(loop_, fd_, ip_);
    writeConn_->setWriteCallback(writeCallback_);
}

void TcpClient::send(std::string msg) {
    writeConn_->send(msg);
}