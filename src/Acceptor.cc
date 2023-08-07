#include "Acceptor.h"

#include <sys/types.h>
#include <sys/socket.h>

Acceptor::Acceptor() : listenFd_(0) {
    
}

Acceptor::~Acceptor() {

}

int Acceptor::acceptNew() const {
    int fd = accept4(listenFd_, nullptr, nullptr, SOCK_NONBLOCK);
    return fd;
}