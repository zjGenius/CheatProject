#include "MessageQueue.h"

MessageQueue::MessageQueue()
{
    initMsg();
}

/**
 * @brief 初始化
 */
void MessageQueue::initMsg()
{
    if ((msgKey = ftok(MSG_KEY, 1)) < 0)
    {
        perror("ftok error");
        exit(-1);
    }

    if ((msgId = msgget(msgKey, IPC_CREAT | 0777)) == -1)
    {
        perror("msgget error");
        exit(-1);
    }
    printf("messageQueueId=%d\n", msgId);
}

/**
 * @brief 发送
 */
void MessageQueue::sendQueue()
{
    MsgData msgData;
    static int num = 0;

    memset(&msgData, 0, sizeof(MsgData));
    msgData.type = 1;
    sprintf(msgData.data, "send num %d", ++num);

    msgsnd(msgId, &msgData, sizeof(MsgData), IPC_NOWAIT);
}

/**
 * @brief 接收
 */
void MessageQueue::recvQueue()
{
    MsgData msgData;
    memset(&msgData, 0, sizeof(MsgData));
    msgrcv(msgId, &msgData, sizeof(MsgData), 0, IPC_NOWAIT);

    if(msgData.type == 1)
        printf("recv: '%s'", msgData.data);
}

MessageQueue::~MessageQueue()
{}