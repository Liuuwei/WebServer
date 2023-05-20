#include <arpa/inet.h>

#include "../Mutex.h"

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

Mutex mutex_;

int connections = 0;
long long files = 0;

void *fun(void *arg) {
    pthread_detach(pthread_self());

    sockaddr_in addr;
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999);
    inet_pton(AF_INET, "10.211.55.3", &addr.sin_addr);

    int connfd = socket(AF_INET, SOCK_STREAM, 0);
    int ret = connect(connfd, (sockaddr *)&addr, sizeof(addr));
    if (ret == -1)return nullptr;
    const char *buf = "GET /movie.mp4 HTTP/1.1";
    int n = ::send(connfd, buf, strlen(buf), 0);
    char buff[1024] = {0};
    if ( n > 0) connections ++ ;
    while ( (n = ::recv(connfd, buff, sizeof(buff), 0)) > 0) {
        printf("recv\n");
        files += n;
    }
    printf("send %d\n", n);
    return nullptr;
}

void fun(int sig) {
    printf("connections is %d\n", connections);
    printf("fils is %lldMB\n", files/1024/1024);
    exit(0);
}

void addsig(int sig) {
    struct sigaction sg;
    sg.sa_handler = fun;
    sigaction(sig, &sg, nullptr);
}


int main(int argc, char *argv[]) {
    addsig(SIGINT);
    int nums = atoi(argv[1]);
    pthread_t tid;

    for (int i = 0; i < nums; ++ i) {
        pthread_create(&tid, nullptr, fun, nullptr);
    }
    while(true);
}