#ifndef ACCPETOR_H
#define ACCPETOR_H

#include <arpa/inet.h>

class Acceptor {
public:
    Acceptor();
    ~Acceptor();
    int acceptNew() const;
    void setListenFd(int fd) {
        listenFd_ = fd;
    }
private:
    int listenFd_;
};

#endif