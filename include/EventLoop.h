#ifndef EVENTLOOP_H
#define EVENTLOOP_H

#include "TcpServer.h"
#include "Poll.h"
#include "Channel.h"

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
private:
    Poll poll_;
    pid_t threadId_;
    std::mutex mutex_;
    int wakeUpFd_;
    Channel wakeUpChannel_;
    std::vector<Functor> functors_;
    bool isInLoopThread() const;
    void handleRead() const;
    void wakeUp() const;
    void doFunctors();
};

#endif