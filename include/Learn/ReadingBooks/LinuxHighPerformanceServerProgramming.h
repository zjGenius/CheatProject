/**
 * @file LinuxHighPerformanceServerProgramming.h
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief Linux高性能服务器编程书籍学习
 * @version 0.1
 * @date 2024-12-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#define once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <pthread.h>


class LinuxHighPerformanceServerProgramming
{
private:
    /* data */
public:
    LinuxHighPerformanceServerProgramming(/* args */);
    ~LinuxHighPerformanceServerProgramming();

    void Run();
private:
    int LT_EF_test(int argc, char* argv[]);
};
