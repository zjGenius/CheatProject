#ifndef IQ_TRANSMIT_CENTER_H
#define IQ_TRANSMIT_CENTER_H

#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>

#define PACK_HEAD 0xEEEEEEEE
#define PACK_END 0xEEEEEEFF
#define BUFF_SIZE 1024

enum READMode
{
    FILE_R,
    IIO_R
};

#pragma pack(1)
typedef struct IQ_PACK
{
    uint32_t head;
    uint16_t pack_num;
    uint16_t num;
    char data[1024];
    uint32_t end;
};
typedef struct signalInfo
{
    float freq;
    float fs;
    int dataLen;
    short data[18000];
};
#pragma pack()

class IQTransmit
{
private:
    int udp_fd; // 套接字
    struct sockaddr_in udp_Addr;

    int sendIQMode; // 读iq数据模式

public:
    explicit IQTransmit(std::string ip, int port);
    void sendMode(int mode, std::string filePath = " ");
    void readIQFile(std::string filePath);

private:
    void sendIQFile(std::string filePath);
};

#endif // !IQ_TRANSMIT_CENTER_H