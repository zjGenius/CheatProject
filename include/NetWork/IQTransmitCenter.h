#ifndef IQ_TRANSMIT_CENTER_H
#define IQ_TRANSMIT_CENTER_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

#define PACK_HEAD 0xEEEEEEEE
#define PACK_END 0xEEEEEEFF

#pragma pack(1)
typedef struct IQ_Head
{
    uint32_t head;
    uint16_t pack_num;
};

typedef struct IQ_Data
{
    uint32_t head;
    uint32_t* data;
};

typedef struct IQ_Tail
{
    uint32_t head;
    uint16_t pack_num;
};

#pragma pack()

class IQTransmit
{
private:
    int udp_fd; // 套接字

public:
    explicit IQTransmit(std::string ip, int port);
};

#endif // !IQ_TRANSMIT_CENTER_H