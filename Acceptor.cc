#include "Acceptor.h"

#include <assert.h>
#include <string.h>

Acceptor::Acceptor(const std::string ip, int port) {
    listenfd_ = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&addr_, sizeof(addr_));
    addr_.sin_family = AF_INET;
    addr_.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &addr_.sin_addr);
    ret = bind(listenfd_, (sockaddr *)&addr_, sizeof(addr_));
    assert(ret != -1);
    ret = listen(listenfd_, 1024);
    assert(ret != -1);
}