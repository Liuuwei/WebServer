#include "ThreadPool.h"
#include "Statistics.h"

#include <signal.h>


int main(int argc, char *argv[]) {
    ThreadPool threadPool;
    threadPool.setThreadNums(atoi(argv[1]));
    threadPool.begin();
    while (true);
    return 0;
}