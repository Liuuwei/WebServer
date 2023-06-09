#include "ThreadPool.h"

ThreadPool::ThreadPool(const std::string ip, int port) : ip_(ip), port_(port), server_(&listenfd_, ip_, port_), next_(0) {

}

void ThreadPool::begin() {
    for (int i = 0; i < threadNums_; i ++ ) {
        int epollfd = epoll_create(5);
        fds_.push_back(epollfd);
        std::shared_ptr<Thread> newThread(new Thread(&epollfd));
        newThread->cond_.wait();
        threads_.push_back(newThread);
    }
    start();
}

void ThreadPool::start() {
    printf("ThreadPoll start\n");
    int epollfd = epoll_create(1024);
    epoll_event event;
    event.data.fd = listenfd_;
    event.events = EPOLLIN;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd_, &event);
    while (true) {
        int numEvents = ::epoll_wait(epollfd, &event, 1, -1);
        if (numEvents > 0) {
            printf("new Conenction tid is %d\n", gettid());
            int connfd = ::accept(listenfd_, nullptr, nullptr);
            printf("connfd is %d\n", connfd);
            std::shared_ptr<Thread> thread = getThread();
            epoll_event event;
            event.data.fd = connfd;
            event.events = EPOLLIN;
            {
                MutexLockGuard lock(thread->mutex_);
                epoll_ctl(*thread->epollFd(), EPOLL_CTL_ADD, connfd, &event);
            }
        } else {
            printf("%s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
            exit(1);
        }
    }    
}

std::shared_ptr<Thread> ThreadPool::getThread() {
    std::shared_ptr<Thread> thread = threads_[next_ ++ ];
    if (next_ >= threadNums_)
        next_ = 0;
    return thread;
}