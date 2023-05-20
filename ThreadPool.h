#pragma once

#include "TcpServer.h"
#include "Thread.h"

#include <sys/epoll.h>

#include <vector>
#include <string>
#include <memory>
#include <thread>

extern int connections;
extern long long files;

class ThreadPool {
    public:
        ThreadPool(const std::string ip = "10.211.55.3", int port = 9999);
        ~ThreadPool() {}
        void setThreadNums(int threadNum) { threadNums_ = threadNum; }
        void begin();
        void start();
    private:
        int next_;
        int port_;
        int listenfd_;
        int threadNums_;
        std::string ip_;
        TcpServer server_;
        std::vector<int> fds_;
        std::shared_ptr<Thread> getThread();
        std::vector<std::shared_ptr<Thread>> threads_;
};