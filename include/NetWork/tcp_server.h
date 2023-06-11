#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

class TCP_Server
{
private:
    int tcpServerSocket; // tcpServer套接字

public:
    explicit TCP_Server(int port);
};

#endif // !TCP_SERVER_H