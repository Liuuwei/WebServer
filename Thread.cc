#include "Thread.h"

#include <sys/socket.h>
#include <sys/epoll.h>
#include <unistd.h>

#include <mutex>
#include <string>
#include <regex>


Thread::Thread(int *epollfd) : epollfd_(epollfd), events_(1024){
    printf("New Thread Create\n");
}

void Thread::begin() {
    thread_ = std::shared_ptr<std::thread>(new std::thread([&]() {
        start();
    }));
}

void Thread::start() {
    while(true) {
        int numEvents = 0;
        numEvents = ::epoll_wait(*epollfd_, &*events_.begin(), events_.size(), 1000);
        if (numEvents > events_.size()) {
            events_.resize(events_.size() * 2);
        }
        if (numEvents > 0) {
            for (int i = 0; i < numEvents; i ++ ) {
                epoll_event event = events_[i];
                if (event.events & EPOLLIN) {
                    handleRead(event.data.fd);
                } 
            }
        }
    }   
}

//! GET /index.html HTTP/1.1
//! Host: 10.211.55.3:9999
//! Connection: keep-alive
//! Cache-Control: max-age=0
//! Upgrade-Insecure-Requests: 1
//! User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/113.0.0.0 Safari/537.36
//! Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7
//! Accept-Encoding: gzip, deflate
//! Accept-Language: zh-CN,zh;q=0.9

void Thread::handleRead(int fd) {
    std::vector<char> buf(65536);
    int n = ::recv(fd, &*buf.begin(), buf.size(), 0);
    if (n <= 0) {
        close(fd);
        return ;
    }
    std::string src(buf.begin(), buf.begin() + n);
    //for (auto c : buf)printf("%c", c);
        
    std::string rmsg = "HTTP/1.1 200 OK\r\n";
    rmsg += "Server: WebServer\r\n";
    rmsg += "Connection: keep-alive\r\n";
    rmsg += "Content-Type: text/html\r\n";
    rmsg += "Content-Length: ";

    std::string pattern = "^([A-Z]+) (.+) HTTP/1";
    std::regex r(pattern);
    std::smatch result;
    std::regex_search(src, result, r);
    if (result.size() == 0) {
        printf("regex failed\n");
        close(fd);
        return ;
    }
    std::string type = result[1];
    std::string path = result[2];
    if (type != "GET") {
        printf("type error\n");
        close(fd);
        return ;
    }
    std::string fileName = "www";
    if (path == "/")
        fileName += "/index.html";
    else
        fileName += result[2];
    
    printf("fileName: %s\n", fileName.c_str());
    
    FILE *fp = fopen(fileName.c_str(), "rb");
    if (fp == nullptr) {
        printf("file doesn't exist\n");
        close(fd);
        return ;
    }
    int fileSize = 0;
    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    fseek(fp, 0, 0);
    printf("filesize is %d\n", fileSize);
    rmsg += std::to_string(fileSize);
    rmsg += "\r\n\r\n";
    send(fd, rmsg.c_str(), rmsg.size());
    
    for ( ; ; ) {
        int len = ::fread(&*buf.begin(), 1, buf.size(), fp);
        if (len <= 0)break;
        send(fd, &*buf.begin(), len);
    }
    printf("tid : %d\n", gettid());
}


void Thread::send(int fd, const char *buf, int size) {
    int n = 0;
    while (n < size) {
        int len = ::send(fd, buf + n, size - n, 0);
        printf("%d: %d\n", __LINE__, n);
        if (len <= 0)break;
        n += len;
    }
}

void Thread::close(int fd) {
    epoll_ctl(*epollfd_, EPOLL_CTL_DEL, fd, nullptr);
    printf("close %d\n", fd);
}