#pragma once

#include <unistd.h>
#include <arpa/inet.h>

class Send {
    public:
    static void send(int fd, const char *buf, int size) {
        int n = 0;
        while (n < size) {
            int len = ::send(fd, buf + n, size - n, 0);
            if (len <= 0)break;
            n += len;
        }
    }
    private:  
};