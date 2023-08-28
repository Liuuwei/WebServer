//
// Created by Liuwei on 2023/8/28.
//

#ifndef WEBSERVER_TCPCLIENT_H
#define WEBSERVER_TCPCLIENT_H

#include "InetAddr.h"
#include "Connector.h"
#include "EventLoop.h"
#include "TcpConnection.h"

class EventLoop;
class TcpClient {
    typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;
    typedef std::function<void(const TcpConnectionPtr& conn, Buffer* buffer)> MessageCallBack;
public:
    TcpClient(EventLoop* loop, std::string ip, int port);
    ~TcpClient();
    void connect();
    void start();
    void send(std::string msg);
    void setWriteCallback(const MessageCallBack & cb) { writeCallback_ = cb; }
    void setReadCallback(const MessageCallBack & cb) { readCallback_ = cb; }
private:
    EventLoop *loop_;
    int fd_;
    std::string ip_;
    int port_;
    Connector connector_;
    ThreadPoll threadPoll_;
    std::shared_ptr<TcpConnection> readConn_;
    std::shared_ptr<TcpConnection> writeConn_;
    MessageCallBack writeCallback_;
    MessageCallBack readCallback_;
};

#endif //WEBSERVER_TCPCLIENT_H
