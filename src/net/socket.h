#ifndef PUUBIE_SOCKET_H
#define PUUBIE_SOCKET_H
#include "netdb.h"

typedef struct {
    char address[INET6_ADDRSTRLEN];
    in_port_t port;
} sockInfo;

int tcpSocket(const char *host, const char *service);
int udpSocket(const char *host, const char *service);
void getSockInfo(const struct sockaddr *address, sockInfo *si);

#endif //PUUBIE_SOCKET_H
