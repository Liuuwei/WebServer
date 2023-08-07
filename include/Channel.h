#ifndef CHANNEL_H
#define CHANNEL_H

#include <functional>
#include <sys/epoll.h>

class EventLoop;

class Channel {
public:
    Channel(EventLoop* loop_, int fd);
    ~Channel();
    int fd() const {
        return fd_;
    }
    int events() const {
        return events_;
    }
    int revents() const {
        return revents_;
    }
    void enableRead();
    void enableWrite();
    void unableRead();
    void unableWrite();
    void setReadCallback(std::function<void()> cb);
    void setWriteCallback(std::function<void()> cb);
    void setRevents(int events);
    void unableRevents(int events);
    void handleEvent();
    void shutdown();
private:
    int fd_;
    int events_;
    int revents_;
    EventLoop* loop_;
    std::function<void()> readCallback = nullptr;
    std::function<void()> writeCallback = nullptr;
    void update();
};

#endif