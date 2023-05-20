#pragma once

#include <pthread.h>

class Cond {
    public:
        Cond(pthread_mutex_t mutex) : mutex_(mutex) {
            pthread_cond_init(&cond_, nullptr);
        }
        ~Cond() {
            pthread_cond_destroy(&cond_);
        }
        void wait() {
            pthread_cond_wait(&cond_, &mutex_);
        }
        void notify() {
            pthread_cond_signal(&cond_);
        }
        void notifyAll() {
            pthread_cond_broadcast(&cond_);
        }
    private:
        pthread_mutex_t mutex_;
        pthread_cond_t cond_;
};