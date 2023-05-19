#pragma once

#include "Buffer.h"

#include <unistd.h>

#include <functional>
#include <memory>
#include <thread>
#include <vector>
#include <mutex>
#include <sys/epoll.h>

class Thread {
    public:
        Thread(int *epollfd);
        ~Thread() {}
        void start();
        void begin();
        std::mutex mutex_;
    private:
        void send(int fd, const char *buf, int size);
        void close(int fd);
        int *epollfd_;
        std::shared_ptr<std::thread> thread_;
        std::vector<epoll_event> events_;
        void handleRead(int fd);
        std::string format_;
        std::string end_;
};