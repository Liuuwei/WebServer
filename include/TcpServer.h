#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include "EventLoop.h"
#include "InetAddr.h"
#include "Acceptor.h"
#include "Buffer.h"
#include "Channel.h"
#include "ThreadPoll.h"
#include "TcpConnection.h"

#include <memory>

class EventLoop;

class TcpServer {
public:
    typedef std::function<void(const std::shared_ptr<TcpConnection>&, Buffer*)> MessageCallback;
public:
    TcpServer(EventLoop* loop, InetAddr addr);
    ~TcpServer();
    void start();
    void setThreadNums(int nums);
    void setOnMessageCallback(const MessageCallback& cb);
private:
    EventLoop* loop_;
    Acceptor acceptor_;
    int listenFd_;
    int threadNums_;
    Channel* listenChannel_;
    MessageCallback onMessageCallback_;
    std::vector<std::shared_ptr<TcpConnection>> tcpConnections_;
    ThreadPoll* threadPoll_;
    std::mutex mutex_;
    void newTcpConnection();
};

#endif