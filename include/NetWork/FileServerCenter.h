/**
 * @file FileServerCenter.h
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief 依赖网络文件传输,支持对单一文件和批量文件进行上传与下载
 * @version 0.1
 * @date 2023-08-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>

#define SERVER_PORT 6868
#define BUFFSIZE 1024

enum TransmitType
{
    INFO,     // 信息,用于双方进行信息交互
    ONE_FILE, // 单文件传输模式
    MORE_FILE // 多文件传输模式
};

#pragma pack(1)
struct FileTransmit
{
    int head;            // 帧头
    uint8_t type;        // 数据类型
    short packNum;       // 包数
    char data[BUFFSIZE]; // 数据
    int tail;            // 帧尾
};
#pragma pack()

namespace FileTransmitServer
{
    class FileServerCenter
    {
    private:
        int listen_fd = -1;        // 监听套接字
        int client_fd = -1;        // 客户端套接字
        struct sockaddr_in server; // 服务端地址
        struct sockaddr_in client; // 客户端地址
        socklen_t saddrlen = sizeof(server);
        socklen_t caddrlen = sizeof(client);

    public:
        FileServerCenter();
        ~FileServerCenter();
    };
}