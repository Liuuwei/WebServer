#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <mutex>

#include "TcpServer.h"
#include "Thread.h"

std::mutex mutex_;

int main() {
    int listenfd;
    TcpServer server(&listenfd);
    int connfd = ::accept(listenfd, nullptr, nullptr);
    int epollfd = epoll_create(1);
    epoll_event event;
    event.data.fd = connfd;
    event.events = EPOLLIN;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, connfd, &event);
    Thread thread(&epollfd);
    thread.begin();
    while (true) {
        connfd = ::accept(listenfd, nullptr, nullptr);      
        printf("new connection\n"); 
        epoll_event event;
        event.data.fd = connfd;
        event.events = EPOLLIN;
        std::unique_lock lock(thread.mutex_);
        epoll_ctl(epollfd, EPOLL_CTL_ADD, connfd, &event);       
    }
    return 0;
}