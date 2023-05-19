#include "TcpServer.h"

#include <string.h>
#include <assert.h>

TcpServer::TcpServer(int *listenfd, const std::string ip, int port) : listenfd_(listenfd), ip_(ip), port_(port) {
    int ret;
    *listenfd_ = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    ::setsockopt(*listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    bzero(&addr_, sizeof(addr_));
    addr_.sin_port = htons(port_);
    addr_.sin_family = AF_INET;
    inet_pton(AF_INET, ip.c_str(), &addr_.sin_addr);
    ret = bind(*listenfd_, (sockaddr *)&addr_, sizeof(addr_));
    assert(ret != -1);
    ret = listen(*listenfd_, 1024);
    assert(ret != -1);
}