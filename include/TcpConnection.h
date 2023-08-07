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
    TcpConnection(EventLoop* loop, int fd);
    ~TcpConnection();
    void start();
    void setMessageCallback(MessageCallback cb);
    void send(const std::string& msg);
private:
    Channel channel_;
    Buffer inputBuffer_;
    Buffer outputBuffer_;
    void handleRead();
    void handleWrite();
    void handleClose();
    MessageCallback messageCallback_;
};

#endif