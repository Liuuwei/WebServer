#include "ThreadPoll.h"
#include "Util.h"
#include "EventLoop.h"

ThreadPoll::ThreadPoll(int nums) : mark_(0), nums_(nums), threads_(nums), loops_(nums), sem_(0){
    for (int i = 0; i < nums; i++) {
        EventLoop* loop = nullptr;
        auto thread = new Thread(&loop, sem_);
        threads_[i] = thread;
        loops_[i] = loop;
    }
}

ThreadPoll::~ThreadPoll() {
    for (int i = 0; i < nums_; i++) {
        if (threads_[i]) {
            delete threads_[i];
            threads_[i] = nullptr;
        }
    }
}

EventLoop* ThreadPoll::getOneLoop() {
    EventLoop* loop = loops_[mark_];
    mark_ = (mark_ + 1) % nums_;
    return loop;
}