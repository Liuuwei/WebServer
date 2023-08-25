#ifndef TCP_CONNECTION_H
#define TCP_CONNECTION_H

#include "Channel.h"
#include "Buffer.h"
#include "Util.h"

#include <memory>

class TcpConnection : public std::enable_shared_from_this<TcpConnection> {
public:
    typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;
    typedef std::function<void(TcpConnectionPtr, Buffer*)> MessageCallback;
public:
    TcpConnection(EventLoop* loop, int fd, const std::string& ip);
    ~TcpConnection();
    void start();
    void setMessageCallback(MessageCallback cb);
    void setIp(const std::string& ip);
    void send(const std::string& msg);
    int fd() const { return channel_.fd(); }
    Channel* channel() { return &channel_; }
    void handleClose();
    timeval time_;
private:
    EventLoop* loop_;
    Channel channel_;
    Buffer inputBuffer_;
    Buffer outputBuffer_;
    std::string ip_;
    void handleRead();
    void handleWrite();
    MessageCallback messageCallback_;
};

#endif