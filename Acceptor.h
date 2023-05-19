#pragma once

#include <arpa/inet.h>
#include <unistd.h>
#include <string>

class Acceptor {
    public:
        Acceptor(const std::string ip = "10.211.55.3", int port = 9999);
        ~Acceptor() { ::close(listenfd_); }
    private:
        int getEpoll();
        int ret;
        int listenfd_;
        sockaddr_in addr_;
};