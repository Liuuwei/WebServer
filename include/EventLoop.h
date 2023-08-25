#ifndef EVENTLOOP_H
#define EVENTLOOP_H

#include "TcpServer.h"
#include "Poll.h"
#include "Channel.h"
#include "TcpConnection.h"

#include <memory>
#include <functional>
#include <mutex>

class EventLoop {
public:
    typedef std::function<void()> Functor;
public:
    EventLoop();
    ~EventLoop();
    void loop();
    void runInLoop(Functor cb);
    void updateInLoop(Channel* channel);
    pid_t LoopThreadId() const {
        return threadId_;
    }
    void addTcp(std::shared_ptr<TcpConnection> tcp);
    void removeTcp(int fd);
    void runAt(const itimerspec& time, std::function<void()> cb);
    void closeTimer();
private:
    Poll poll_;
    pid_t threadId_;
    std::mutex funMutex_;
    std::mutex tcpMutex_;
    int wakeUpFd_;
    Channel wakeUpChannel_;
    int timeFd_;
    Channel timeChannel_;
    std::vector<Functor> functors_;
    std::unordered_map<int, std::shared_ptr<TcpConnection>> tcps_;
    std::function<void()> timerCallback_;
    bool isInLoopThread() const;
    void handleRead() const;
    void handleTimer();
    void wakeUp() const;
    void doFunctors();
};

#endif