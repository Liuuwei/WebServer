#pragma once

#include <string>

#include <arpa/inet.h>
#include <unistd.h>

class TcpServer {
    public:
        TcpServer(int *listenfd, const std::string ip = "10.211.55.3", int port = 9999);
        ~TcpServer() { ::close(*listenfd_); }
    private:
        std::string ip_;
        int port_;
        int *listenfd_;
        sockaddr_in addr_;
};