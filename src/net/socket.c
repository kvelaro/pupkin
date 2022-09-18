#include "socket.h"
#include <string.h>
#include "arpa/inet.h"
#include <arpa/inet.h>
#include <malloc.h>
#include <syslog.h>
#include "../log/syslog.h"




#define MAXPENDING 1

void getSockInfo(const struct sockaddr *addr, sockInfo *si)
{
    if(addr == NULL || si == NULL) {
        return;
    }
    char buf[INET6_ADDRSTRLEN];
    void *numericAddress;
    in_port_t port;

    switch (addr->sa_family) {
        case AF_INET:
            numericAddress = &((struct sockaddr_in *)addr)->sin_addr;
            port = ntohs(((struct sockaddr_in *)addr)->sin_port);
            break;
        case AF_INET6:
            numericAddress = &((struct sockaddr_in6 *)addr)->sin6_addr;
            port = ntohs(((struct sockaddr_in *)addr)->sin_port);
            break;
        default:
            return;
    }
    if(inet_ntop(addr->sa_family, numericAddress, buf, sizeof(buf)) != NULL) {
        strcpy(si->address, buf);
        si->port = port;
    }
}


int tcpSocket(const char *host, const char *service)
{
    struct addrinfo addrCriteria, *addrInfo;
    memset(&addrCriteria, 0, sizeof addrCriteria);
    addrCriteria.ai_family = AF_UNSPEC;
    addrCriteria.ai_socktype = SOCK_STREAM;
    addrCriteria.ai_protocol = IPPROTO_TCP;

    int rtVal = getaddrinfo(host, service, &addrCriteria, &addrInfo);
    if(rtVal != 0) {
        logit(LOG_ERR, "getaddrinfo() failed", 1);
    }

    int sock = -1;
    for(struct addrinfo *addr = addrInfo; addr != NULL; addr = addrInfo->ai_next) {
        sock = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        if(sock < 0) {
            logit(LOG_INFO, "not a valid structure", 0);
            continue;
        }
        rtVal = bind(sock, addr->ai_addr, addr->ai_addrlen);
        if(rtVal < 0) {
            logit(LOG_ERR, "bind() error", 1);
        }
        rtVal = listen(sock, MAXPENDING);
        if(rtVal < 0) {
            logit(LOG_ERR, "listen() error", 1);
        }
        sockInfo *sInfo;
        sInfo = (sockInfo *)malloc(sizeof(sockInfo));
        getSockInfo(addr->ai_addr, sInfo);

        printf("Server is up and running on %s:%u\r\n", sInfo->address, sInfo->port);
        free(sInfo);
        break;
    }
    freeaddrinfo(addrInfo);

    struct sockaddr cAddr;
    unsigned int cAddrLen = sizeof(cAddr);

    //@todo
    while(1) {
        rtVal = accept(sock, &cAddr, &cAddrLen);

        sockInfo *sInfo;
        sInfo = (sockInfo *)malloc(sizeof(sockInfo));
        getSockInfo(&cAddr, sInfo);
        printf("New client %s:%u has been connected\r\n", sInfo->address, sInfo->port);
        free(sInfo);

        if(rtVal < 0) {
            logit(LOG_ERR, "accept() error", 1);
        }
    }

}

int udpSocket(const char *host, const char *service)
{
    struct addrinfo addrCriteria, *addrInfo;
    memset(&addrCriteria, 0, sizeof addrCriteria);
    addrCriteria.ai_family = AF_UNSPEC;
    addrCriteria.ai_socktype = SOCK_DGRAM;
    addrCriteria.ai_protocol = IPPROTO_UDP;
    //addrCriteria.ai_flags = AI_PASSIVE;

    int rtVal = getaddrinfo(host, service, &addrCriteria, &addrInfo);
    if(rtVal != 0) {
        logit(LOG_ERR, "getaddrinfo() failed", 1);
    }

    int sock = -1;
    for(struct addrinfo *addr = addrInfo; addr != NULL; addr = addrInfo->ai_next) {
        sock = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        if(sock < 0) {
            logit(LOG_INFO, "not a valid structure", 0);
            continue;
        }
        rtVal = bind(sock, addr->ai_addr, addr->ai_addrlen);
        if(rtVal < 0) {
            logit(LOG_ERR, "bind() error", 1);
        }
        sockInfo *sInfo;
        sInfo = (sockInfo *)malloc(sizeof(sockInfo));
        getSockInfo(addr->ai_addr, sInfo);

        printf("Server is up and running on %s:%u\r\n", sInfo->address, sInfo->port);
        free(sInfo);
        break;
    }
    freeaddrinfo(addrInfo);

    while(1) {}
}