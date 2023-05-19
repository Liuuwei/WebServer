#pragma once

#include <string>
#include <vector>
#include <unistd.h>

class Buffer {
    public:
        static const int InitialSize = 65536;
        Buffer(size_t size = 0);
        ~Buffer(){}
        int send(int fd);
        int recv(int fd);
        std::string retrieve();
        void append(const char *, int);
    private:
        int readAble_;
        std::vector<char> buffer_;
};