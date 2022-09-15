#include <netdb.h>
#include <sys/socket.h>
#include <memory.h>
#include "../about/info.h"

#define MAXPENDING 1

int tcpSocket(const char *host, const char *service)
{
    struct addrinfo addrCriteria, *addrInfo;
    memset(&addrCriteria, 0, sizeof addrCriteria);
    addrCriteria.ai_family = AF_UNSPEC;
    addrCriteria.ai_socktype = SOCK_STREAM;
    addrCriteria.ai_protocol = IPPROTO_TCP;

    int rtVal = getaddrinfo(host, service, &addrCriteria, &addrInfo);
    if(rtVal != 0) {
        logger(LOG_ERR, "getaddrinfo() failed", 1);
    }

    int sock = -1;
    for(struct addrinfo *addr = addrInfo; addr != NULL; addr = addrInfo->ai_next) {
        sock = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        if(sock < 0) {
            logger(LOG_INFO, "not a valid structure", 0);
            continue;
        }
        rtVal = bind(sock, addr->ai_addr, addr->ai_addrlen);
        if(rtVal < 0) {
            logger(LOG_ERR, "bind() error", 1);
        }
        rtVal = listen(sock, MAXPENDING);
        if(rtVal < 0) {
            logger(LOG_ERR, "listen() error", 1);
        }
        break;
    }
    freeaddrinfo(addrInfo);

    struct sockaddr cAddr;
    unsigned int cAddrLen = sizeof(cAddr);

    while(1) {
        rtVal = accept(sock, &cAddr, &cAddrLen);
        if(rtVal < 0) {
            logger(LOG_ERR, "accept() error", 1);
        }
    }

}