/**
 * @file ShareMemery.h
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief 共享内存
 * @version 0.1
 * @date 2023-12-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __SHARE_MEMERY__
#define __SHARE_MEMERY__

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

struct ShmData
{
    pthread_mutex_t mutex;
    char data[SHM_SIZE];
};


class ShareMemery
{
private:
    int fd;
    ShmData *shmData;
    pthread_mutexattr_t mutextAttr;
    pthread_mutex_t *mutex;

public:
    ShareMemery(/* args */);
    ~ShareMemery();

    void sendShmData();
    void recvShmData();

private:
    void initShm();
};


#endif // !__SHARE_MEMERY__