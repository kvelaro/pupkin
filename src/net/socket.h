#ifndef PUUBIE_SOCKET_H
#define PUUBIE_SOCKET_H
#include "netdb.h"

typedef struct {
    char address[INET6_ADDRSTRLEN];
    in_port_t port;
} sockInfo;
int server(const char *host, const char *service, int proto);
int client(const char *host, const char *service, int proto);

int udpSocket(const char *host, const char *service);
void getSockInfo(const struct sockaddr *address, sockInfo *si);

#endif //PUUBIE_SOCKET_H
