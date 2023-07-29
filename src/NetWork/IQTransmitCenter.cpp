// #include "IQTransmitCenter.h"

// int udp_fd = -1; // 套接字
// struct sockaddr_in udp_Addr;

// IQTransmit::IQTransmit(std::string ip, int port)
// {
//     udp_fd = socket(PF_INET, SOCK_DGRAM, 0);
//     udp_ip = ip;
//     if (udp_fd == -1)
//     {
//         perror("date time socket error");
//         exit(-1);
//     }
//     udp_Addr.sin_family = AF_INET;
//     udp_Addr.sin_port = htons(port);
//     inet_pton(AF_INET, ip.c_str(), &udp_Addr.sin_addr.s_addr);
// }

// void IQTransmit::sendMode(int mode, std::string filePath)
// {
//     if (mode == READMode::FILE_R)
//     {
//         printf("READMode::FILE_R\n");
//         readIQFile(filePath);
//         printf("\n\n\n");
//         sendIQFile(filePath);
//     }
//     else
//     {
//         printf("READMode::IIO_R\n");
//         printf("\n\n\n");
//         sendIQData("ip:192.168.10.226", udp_Addr);
//         printf("READMode::IIO_R\n");
//     }
// }

// /**
//  * @brief 将IQ数据从文件按BUFF_SIZE长度读取出来
//  *
//  * @param data
//  */
// void IQTransmit::sendIQFile(std::string filePath)
// {
//     FILE *fp;
//     uint16_t pack_num; // 总数据包数
//     uint16_t num = 1;  // 数据包数
//     IQ_PACK IQ_data;
//     if (!(fp = fopen(filePath.c_str(), "rb")))
//     {
//         printf("Fail to open %s file\n", filePath.c_str());
//         return;
//     }
//     fseek(fp, 0, SEEK_END);
//     size_t size = ftell(fp);
//     pack_num = size / BUFF_SIZE;
//     if ((size % BUFF_SIZE) != 0)
//         pack_num += 1;
//     printf("pack_num:%d\n", pack_num);
//     fseek(fp, 0, SEEK_SET);

//     int length;
//     int ret;
//     char buffer[1024];
//     while ((length = fread(buffer, 1, BUFF_SIZE, fp)) > 0)
//     {
//         printf("send %d pack\n", num);
//         memset(&IQ_data, 0, sizeof(IQ_PACK));
//         IQ_data.head = PACK_HEAD;
//         IQ_data.pack_num = pack_num;
//         IQ_data.num = num;
//         memcpy(IQ_data.data, buffer, BUFF_SIZE);
//         IQ_data.end = PACK_END;

//         ret = sendto(udp_fd, (char *)&IQ_data, sizeof(IQ_PACK), 0, (sockaddr *)&udp_Addr, sizeof(udp_Addr));
//         if (!ret)
//         {
//             std::cout << "An error occurred while sending." << std::endl;
//             return;
//         }
//         num++;
//     }
//     fclose(fp);
// }

// void IQTransmit::readIQFile(std::string filePath)
// {
//     FILE *fp = fopen(filePath.c_str(), "rb");
//     signalInfo info;
//     fread(&info.freq, sizeof(float), 1, fp);
//     fread(&info.fs, sizeof(float), 1, fp);
//     fread(&info.dataLen, sizeof(int), 1, fp);
//     fread(&info.data, sizeof(short), 18000, fp);
//     fclose(fp);

//     printf("freq=%f, fs=%0.2f, len=%d\n", info.freq, info.fs, info.dataLen);
//     for (int i = 0; i < 100; i++)
//     {
//         printf("%d, ", info.data[i]);
//     }
//     printf("\n");
// }
