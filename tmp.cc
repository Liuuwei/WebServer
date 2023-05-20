#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <mutex>
#include <regex>

#include "ThreadPool.h"
#include "TcpServer.h"
#include "Thread.h"
#include "Send.h"

int main() {
    ThreadPool threadPool;
    threadPool.setThreadNums(5);
    threadPool.begin();
    while (true);
    return 0;
}