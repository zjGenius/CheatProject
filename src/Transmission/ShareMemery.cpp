#include "ShareMemery.h"

ShareMemery::ShareMemery()
{
    initShm();
}

void ShareMemery::initShm()
{
    // 打开共享内存文件
    if ((fd = shm_open("/my_shm", O_CREAT | O_RDWR, 0666)) == -1)
    {
        perror("shm error");
        exit(-1);
    }

    // 调整共享内存文件大小
    if (ftruncate(fd, sizeof(ShmData)) == -1)
    {
        perror("ftruncate error");
        exit(-1);
    }

    // 将共享内存映射到进程地址空间中
    if ((shmData = (ShmData *)mmap(NULL, sizeof(ShmData), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED)
    {
        perror("mmap error");
        exit(-1);
    }

    // 初始化互斥量属性
    pthread_mutexattr_init(&mutextAttr);
    pthread_mutexattr_setpshared(&mutextAttr, PTHREAD_PROCESS_SHARED); // 允许其他进程访问

    // 创建互斥量
    mutex = &(shmData->mutex);
    pthread_mutex_init(mutex, &mutextAttr);
}

void ShareMemery::sendShmData()
{
    static int num = 0;
    while (1)
    {
        // 发送数据
        pthread_mutex_lock(mutex);
        sprintf(shmData->data, "num:%d", ++num);
        pthread_mutex_unlock(mutex);

        sleep(1);
    }
}

void ShareMemery::recvShmData()
{
    while (1)
    {
        // 发送数据
        // if (!pthread_mutex_trylock(mutex))
        //     continue;
        pthread_mutex_lock(mutex);
        printf("recv: '%s'\n", shmData->data);
        pthread_mutex_unlock(mutex);

        // sleep(1);
    }
}

ShareMemery::~ShareMemery()
{
    // 解除共享内存映射
    if (munmap(shmData, sizeof(ShmData)) == -1)
    {
        perror("munmap");
        exit(-1);
    }

    // 删除共享内存文件
    if (shm_unlink("/my_shm") == -1)
    {
        perror("shm_unlink");
        exit(-1);
    }
}