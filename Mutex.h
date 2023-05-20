#pragma once

#include <pthread.h>

class Mutex {
    public:
        Mutex() {
            pthread_mutex_init(&mutex_, nullptr);
        }
        void lock() {
            pthread_mutex_lock(&mutex_);
        }
        void unlock() {
            pthread_mutex_unlock(&mutex_);
        }
    private:
    pthread_mutex_t mutex_;
};

class MutexLockGuard {
    public:
    MutexLockGuard(Mutex &mutex) {
        mutex_.lock();
    }
    ~MutexLockGuard() {
        mutex_.unlock();
    }
    private:
        Mutex mutex_;
};