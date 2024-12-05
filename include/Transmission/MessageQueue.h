/**
 * @file MessageQueue.h
 * @author zhangjun (zhangjun.sole@qq.com)
 * @brief 消息队列操作 (类似邮件)
 * @version 0.1
 * @date 2023-12-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __MESSAGE_QUEUE__
#define __MESSAGE_QUEUE__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_KEY "/mnt/emmc1/root/setup.sh"  ///< 为创建消息队列的文件,确保该文件不会被删除

// 消息结构体
struct MsgData
{
    uint8_t type;
    char data[1024];
};

class MessageQueue
{
private:
    key_t msgKey;
    int msgId;

public:
    MessageQueue(/* args */);
    ~MessageQueue();

    void sendQueue();
    void recvQueue();

private:
    void initMsg();
};

#endif // !__MESSAGE_QUEUE__