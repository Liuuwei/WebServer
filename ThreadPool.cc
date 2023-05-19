#include "ThreadPool.h"
#include "Thread.h"

ThreadPool::ThreadPool(const std::string ip, int port) : acceptor_(ip, port) {
    
    for (int i = 0; i < threadNums_; i ++ ) {
        int epollfd = epoll_create(5);
        fds_.push_back(epollfd);
        std::shared_ptr<Thread> newThread(new Thread(&epollfd));
        threads_.push_back(newThread);
    }
}