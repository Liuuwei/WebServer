#include "EventLoop.h"
#include "Log.h"

#include <sys/eventfd.h>
#include <sys/types.h>
#include <sys/timerfd.h>

EventLoop::EventLoop() : threadId_(gettid()), wakeUpFd_(eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC)), wakeUpChannel_(this, wakeUpFd_),
                         timeFd_(timerfd_create(CLOCK_REALTIME, TFD_NONBLOCK)), timeChannel_(this, timeFd_) {
    wakeUpChannel_.setReadCallback(std::bind(&EventLoop::handleRead, this));
    wakeUpChannel_.enableRead();
    timeChannel_.setReadCallback(std::bind(&EventLoop::handleTimer, this));
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

void EventLoop::handleTimer() {
    uint64_t one = 1;
    ssize_t n = read(timeFd_, &one, sizeof(one));
    if (timerCallback_) {
        timerCallback_();
    }
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
    timeval time;
    gettimeofday(&time, nullptr);
    long int curTime = time.tv_sec;
    for (auto it = tcps_.begin(); it != tcps_.end(); ++it) {
        if (it->second->time_.tv_sec < curTime - 8) {
            it->second->handleClose();
        }
    }
}

void EventLoop::addTcp(std::shared_ptr<TcpConnection> tcp) {
    std::unique_lock lock(tcpMutex_);
    if (tcps_.find(tcp->fd()) == tcps_.end())
        tcps_.insert({tcp->fd(), tcp});
}

void EventLoop::removeTcp(int fd) {
    std::unique_lock lock(tcpMutex_);
    if (tcps_.find(fd) != tcps_.end()) {
        poll_.removeChannel(tcps_[fd]->channel());
        tcps_.erase(fd);
    }
}

void EventLoop::runAt(const itimerspec& time, std::function<void()> cb) {
    if (cb) {
        timerCallback_ = std::move(cb);
    }
    if (timerfd_settime(timeFd_, 0, &time, nullptr) == -1) {
        Log::Instance()->DEBUG("timerfd_settime failed %d", timeFd_);
    }
    timeChannel_.enableRead();
}

void EventLoop::closeTimer() {
    itimerspec time{};
    time.it_value.tv_sec = 0;
    time.it_value.tv_nsec = 0;
    time.it_interval.tv_sec = 0;
    time.it_interval.tv_nsec = 0;
    if (timerfd_settime(timeFd_, 0, &time, nullptr) == -1) {
        Log::Instance()->DEBUG("timerfd_settime failed %d", timeFd_);
    }
    timeChannel_.unableRead();
}