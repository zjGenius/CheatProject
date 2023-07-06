#include "IQRecvData.h"

IQRecv::IQRecv(std::string ip, int port)
{
    udp_fd = socket(PF_INET, SOCK_DGRAM, 0);
    if (udp_fd == -1)
    {
        perror("date time socket error");
        exit(-1);
    }
    udp_Addr.sin_family = AF_INET;
    udp_Addr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &udp_Addr.sin_addr.s_addr);
    bind(udp_fd, (sockaddr*)&udp_Addr, sizeof(udp_Addr));
}

void IQRecv::recv_fun(std::string filePath)
{
    FILE *fp = fopen(filePath.c_str(), "w+");
    while (1)
    {
        char buff[2048] = {0};
        memset(buff, 0, 2048);
        int ret = recv(udp_fd, buff, 2048, 0);
        IQ_PACK IQ_data = *(IQ_PACK *)buff;
        printf("IQ num: %d\n", IQ_data.num);
        fwrite(IQ_data.data, 1, 1024, fp);
    }
}