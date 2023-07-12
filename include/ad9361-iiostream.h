#ifndef __AD9361_IIOSTREAM_H__
#define __AD9361_IIOSTREAM_H__


#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


int sendIQData(const char *udp_send_ip, sockaddr_in &udp_Addr);

#endif