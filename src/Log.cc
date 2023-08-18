//
// Created by Liuwei on 2023/8/18.
//
#include "Log.h"

Log::Log() : fd_(0) {
    fileName_ = name + getTime();
    fd_ = open(fileName_.c_str(), O_CREAT | O_RDWR | O_APPEND);
    fstat(fd_, &fileStat_);
}

Log::~Log() {

}

Log* Log::Instance() {
    static Log log;
    return &log;
}

void Log::start() {
    while (true) {
        if (fileStat_.st_size > 1000000) {
            fileName_ = name + getTime();
            fd_ = open(fileName_.c_str(), O_CREAT | O_RDWR | O_APPEND);
            fstat(fd_, &fileStat_);
        }
        std::unique_lock lock(mutex_);
        while (logs_.empty()) {
            cond_.wait(lock);
        }
        std::vector<std::string> logs;
        logs.swap(logs_);
        lock.unlock();
        for (int i = 0; i < logs.size(); ++i) {
            int n = write(fd_, logs[i].c_str(), logs[i].size());
        }
    }
}

std::string Log::getTime() {
    struct timeval time{};
    gettimeofday(&time, nullptr);
    time_t rawTime = time.tv_sec;
    struct tm* timeInfo = localtime(&rawTime);
    std::string ret = std::to_string(timeInfo->tm_year + 1900) + '-' + std::to_string(timeInfo->tm_mon + 1) + '-'
            + std::to_string(timeInfo->tm_mday);
    return ret;
}