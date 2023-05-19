#pragma once

#include <arpa/inet.h>
#include <unistd.h>
#include <string>

class Acceptor {
    public:
        Acceptor(const std::string ip, int port);
        ~Acceptor() { ::close(listenfd_); }
        int listenfd() const { return listenfd_; }
    private:
        //int getEpoll();
        std::string ip_;
        int port_;
        int ret;
        int listenfd_;
        sockaddr_in addr_;
};