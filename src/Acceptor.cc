#include "Acceptor.h"
#include "Log.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <string>

Acceptor::Acceptor() : listenFd_(0) {
    
}

Acceptor::~Acceptor() {

}

int Acceptor::acceptNew() const {
    sockaddr_in peerAddr{};
    socklen_t len = sizeof(peerAddr);
    int fd = accept4(listenFd_, (sockaddr*)&peerAddr, &len, SOCK_NONBLOCK);
    std::string ip(64, '\0');
    inet_ntop(AF_INET, &peerAddr.sin_addr, &*ip.begin(), ip.size());
    Log::Instance()->LOG("ip: %s", ip.c_str());
    return fd;
}