#ifndef PUUBIE_DELIMITER_H
#define PUUBIE_DELIMITER_H
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15
 +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
 |SOH (8 bit) -> 00000001|  size (24 bits)       |
 +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
 |                  up to 16 MB                  |
 +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
 |                     payload                   |
 +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
*/


#define SOH 0x0001  // start of header
#define SOT 0x0002  // start of text

typedef struct _message {
    unsigned char size[3];
    void *body;
} Message;

int getNextMessage(FILE *streamIn, Message *msg);
int putMessage(FILE *streamIn, Message *msg);

#endif //PUUBIE_DELIMITER_H
