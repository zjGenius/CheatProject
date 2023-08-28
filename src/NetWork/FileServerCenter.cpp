#include "FileServerCenter.h"
using namespace FileTransmitServer;

FileServerCenter::FileServerCenter()
{
    // 初始化地址
    memset(&server, 0, sizeof(server));
    memset(&client, 0, sizeof(client));
    // 获取监听套接字
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0)
    {
        printf("socket error!\n");
        return;
    }
    // 填入地址
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    // 绑定
    if (bind(listen_fd, (struct sockaddr *)&server, saddrlen) < 0)
    {
        printf("bind error!\n");
        return;
    }
    // 监听
    if (listen(listen_fd, 5) < 0)
    {
        printf("listen error!\n");
        return;
    }
}
FileServerCenter::~FileServerCenter()
{
}