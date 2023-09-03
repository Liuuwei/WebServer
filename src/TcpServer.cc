#include "TcpServer.h"

#include <signal.h>
#include <sys/timerfd.h>
#include "Log.h"

TcpServer::TcpServer(EventLoop* loop, InetAddr addr) : loop_(loop), listenFd_(addr.listenFd()),
                                                        listenChannel_(new Channel(loop, listenFd_)),
                                                        threadNums_(0), threadPoll_(nullptr) {
    signal(SIGPIPE, SIG_IGN);
    acceptor_.setListenFd(listenFd_);
}

TcpServer::~TcpServer() {
    if (listenChannel_) {
        delete listenChannel_;
        listenChannel_ = nullptr;
    }
    if (threadPoll_) {
        delete threadPoll_;
        threadPoll_ = nullptr;
    }
}

void TcpServer::start() {
    listenChannel_->setReadCallback(std::bind(&TcpServer::newTcpConnection, this));
    listenChannel_->enableRead();
    loop_->updateInLoop(listenChannel_);
    std::thread t([&]() {
        Log::Instance()->start();
    });
    t.detach();
}

void TcpServer::setOnMessageCallback(const MessageCallback & cb) {
    onMessageCallback_ = cb;
}

void TcpServer::setThreadNums(int nums) {
    threadNums_ = nums;
    threadPoll_ = new ThreadPoll(threadNums_, loop_);
    loops_.reserve(nums);
    for (int i = 0; i < nums; i++) {
        loops_.push_back(threadPoll_->getOneLoop());
    }
    loops_.push_back(loop_);
}

void TcpServer::newTcpConnection() {
    auto tcp = acceptor_.acceptNew();
    int fd = tcp.first;
    if (fd == -1) { return; }
    std::cout << "new client" << std::endl;
    Log::Instance()->LOG("connect one new client %s", tcp.second.c_str());
    auto loop = threadPoll_->getOneLoop();
    std::shared_ptr<TcpConnection> conn = std::make_shared<TcpConnection>(loop, fd, tcp.second);
    loop->connectionQueue().back().insert(conn);
    conn->setReadCallback(onMessageCallback_);
}