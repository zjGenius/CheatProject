#ifndef IQ_RECV_H
#define IQ_RECV_H

#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>

#include "IQTransmitCenter.h"

#define PACK_HEAD 0xEEEEEEEE
#define PACK_END 0xEEEEEEFF
#define BUFF_SIZE 1024

class IQRecv
{
private:
    int udp_fd; // 套接字
    struct sockaddr_in udp_Addr;

    int sendIQMode; // 读iq数据模式

public:
    explicit IQRecv(std::string ip, int port);
    void recv_fun(std::string filePath);

private:
    void sendIQFile(std::string filePath);
    void readIQFile(std::string filePath);
};

#endif // !IQ_RECV_H