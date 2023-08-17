#include "EventLoop.h"

#include <sys/eventfd.h>
#include <sys/types.h>

EventLoop::EventLoop() : threadId_(gettid()), wakeUpFd_(eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC)), wakeUpChannel_(this, wakeUpFd_){
    wakeUpChannel_.setReadCallback(std::bind(&EventLoop::handleRead, this));
    wakeUpChannel_.enableRead();
    poll_.updateChannel(&wakeUpChannel_);
}

EventLoop::~EventLoop() {

}

void EventLoop::loop() {
    while (true) {
        poll_.poll();
        doFunctors();
    }
}

void EventLoop::runInLoop(Functor cb) {
    std::unique_lock lock(funMutex_);
    functors_.push_back(std::move(cb));
    if (!isInLoopThread()) {
        wakeUp();
    }
}

void EventLoop::updateInLoop(Channel* channel) {
    if (isInLoopThread()) {
        poll_.updateChannel(channel);
    } else {
        runInLoop(std::bind(&Poll::updateChannel, &poll_, channel));
    }
}

bool EventLoop::isInLoopThread() const {
    return threadId_ == gettid();
}

void EventLoop::handleRead() const {
    uint64_t one = 1;
    ssize_t n = read(wakeUpFd_, &one, sizeof(one));
}

void EventLoop::wakeUp() const {
    uint64_t one = 1;
    ssize_t n = write(wakeUpFd_, &one, sizeof(one));
}

void EventLoop::doFunctors() {
    std::unique_lock lock(funMutex_);
    std::vector<std::function<void()>> newFunctors;
    functors_.swap(newFunctors);
    lock.unlock();
    for (const auto & newFunctor : newFunctors) {
        newFunctor();
    }
}

void EventLoop::addTcp(std::shared_ptr<TcpConnection> tcp) {
    std::unique_lock lock(tcpMutex_);
    tcps_.insert({tcp->fd(), tcp});
}

void EventLoop::removeTcp(int fd) {
    std::unique_lock lock(tcpMutex_);
    if (tcps_.find(fd) != tcps_.end()) {
        tcps_.erase(fd);
    }
}
