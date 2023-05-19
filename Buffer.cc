#include "Buffer.h"

#include <sys/uio.h>
#include <arpa/inet.h>

Buffer::Buffer(size_t size) : buffer_(size + InitialSize) , readAble_(0){

}

int Buffer::send(int fd) {
    int n = 0;
    while(n < buffer_.size()) {
        n += ::write(fd, &*buffer_.begin() + n, buffer_.size());
    }
    buffer_.clear();
    return n;
}

int Buffer::recv(int fd) {
    // char extraBuf[65536] = {0};
    // ::iovec iov[2];
    // iov[0].iov_base = &*buffer_.begin();
    // iov[0].iov_len = buffer_.size();
    // iov[1].iov_base = extraBuf;
    // iov[1].iov_len = sizeof(extraBuf);

    //int n = readv(fd, iov, 2);
    // if (n > buffer_.size()) {
    //     int len = n - buffer_.size();
    //     append(extraBuf, len);
    // }
    int n = 0;
    n = ::recv(fd, &*buffer_.begin() + readAble_, buffer_.size(), 0);
    readAble_ += n;
    return n;
}

void Buffer::append(const char *buf, int len) {
    int n = buffer_.size();
    buffer_.resize(buffer_.size() * 2);
    std::copy(buf, buf + len, &*buffer_.begin() + n);
}

std::string Buffer::retrieve() {
    std::string result(&*buffer_.begin(), readAble_);
    buffer_.clear();
    readAble_ = 0;
    return result;
}