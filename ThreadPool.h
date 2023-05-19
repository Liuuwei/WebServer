#pragma once

#include "TcpServer.h"
#include "Thread.h"

#include <sys/epoll.h>

#include <functional>
#include <vector>
#include <string>
#include <memory>
#include <thread>

class ThreadPool {
    public:
        ThreadPool(const std::string ip = "10.211.55.3", int port = 9999);
        ~ThreadPool() {}
        void setThreadNums(int threadNum) { threadNums_ = threadNum; }
        void begin();
        void start();
    private:
        std::shared_ptr<Thread> getThread();
        std::string ip_;
        int port_;
        int threadNums_;
        int listenfd_;
        std::vector<int> fds_;
        std::vector<std::shared_ptr<Thread>> threads_;
        TcpServer server_;
        int next_;
};