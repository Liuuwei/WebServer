//
// Created by Liuwei on 2023/8/17.
//
#include <unistd.h>
#include <stdlib.h>

int main() {
    int f = fork();
    if (f > 0) {
        exit(0);
    }
    setsid();
    execl("/clion/bin/test", "./test", nullptr);
}