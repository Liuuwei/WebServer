#pragma once

#include "Statistics.h"
#include "Callback.h"
#include "Buffer.h"
#include "Mutex.h"
#include "Cond.h"

#include <unistd.h>

#include <functional>
#include <memory>
#include <thread>
#include <vector>
#include <mutex>
#include <unistd.h>
#include <sys/types.h>
#include <sys/epoll.h>

class Thread {
    public:
        Thread(int *epollfd);
        ~Thread() {}
        void start();
        void begin();
        int* epollFd() const { return epollfd_; };
        int tid() const { return tid_; }
        Mutex mutex_;
        Cond cond_;
    private:
        void send(int fd, const char *buf, int size);
        void close(int fd);
        int* epollfd_;
        int tid_;
        std::shared_ptr<std::thread> thread_;
        std::vector<epoll_event> events_;
        void handleRead(int fd);
        std::string format_;
        std::string end_;
};