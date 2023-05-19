#pragma once

#include "Acceptor.h"
#include "Thread.h"

#include <sys/epoll.h>

#include <functional>
#include <vector>
#include <string>
#include <memory>
#include <thread>

class ThreadPool {
    public:
    ThreadPool(const std::string ip, int port);
    ~ThreadPool();
    void setThtreadNumx(int threadNum) { threadNums_ = threadNum; }
    void start();
    private:
    void threadFunc();
    int threadNums_;
    std::vector<int> fds_;
    std::vector<std::shared_ptr<Thread>> threads_;
    Acceptor acceptor_;  
};