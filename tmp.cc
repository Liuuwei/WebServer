#include "ThreadPool.h"

int main() {
    ThreadPool threadPool;
    threadPool.setThreadNums(5);
    threadPool.begin();
    while (true);
    return 0;
}