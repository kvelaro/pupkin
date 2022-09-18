#include  <stdio.h>
#include "net/socket.h"

int main() {
//    QueueList *list = NULL;
    setvbuf(stdout, NULL, _IONBF, 0);
    udpSocket( "0.0.0.0", "5000");

    return 0;
}