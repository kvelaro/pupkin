#include "message.h"
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

int getNextMessage(FILE *streamIn, Message *msg)
{
    char ch;
    unsigned int size, processed = 0;
    // header detection
    ch = getc(streamIn);
    if(ch != SOH) {
        return -1;
    }

    // size detection
    msg->size[0] = getc(streamIn);
    msg->size[1] = getc(streamIn);
    msg->size[2] = getc(streamIn);

    size = (unsigned int)msg->size;

    // header detection
    ch = getc(streamIn);
    if(ch != SOT)
    {
        return -1;
    }
    msg->body = (char *)malloc(size);

    while(processed < size) {
        msg->body = fgetc(streamIn);
        msg->body++;
        processed++;
    }
    return 0;
}

int putMessage(FILE *streamIn, Message *msg)
{
    char ch;
    char *buf;
    unsigned int size, processed = 0;

    size = (unsigned int)msg->size;
    buf = (char *)malloc(50);

    buf[0] = SOH;
    buf[1] = 2;
//    buf += 4;
//    *(buf++) = (unsigned int)msg->size[1];
//    *(buf++) = (unsigned int)msg->size[2];
//    *(buf++) = SOT;
    //@todo strcpy
    strcpy(buf, msg->body);
    return 0;
}