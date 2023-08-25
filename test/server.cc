#include "Buffer.h"
#include "InetAddr.h"
#include "EventLoop.h"
#include "ThreadPoll.h"
#include "HTTP.h"
#include <thread>
#include "Log.h"


void onMessage(const std::shared_ptr<TcpConnection>& conn, Buffer* buffer) {
    if (buffer->FindEnd()) {
        std::string url = buffer->retriveSome(buffer->FindEnd() - buffer->readIndex() + 1);
        request request_ = HTTP::parse(url);
        std::string ret = HTTP::generate(request_);
        conn->send(ret);
    }
}

int main() {
    std::cout << "IOThread: " << gettid() << std::endl;
    EventLoop loop;
    InetAddr addr;
    TcpServer server(&loop, addr);
    server.setOnMessageCallback(onMessage);
    server.setThreadNums(1);
    server.start();
    loop.loop();
}