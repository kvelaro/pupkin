#ifndef PUPKIN_QUEUE_H
#define PUPKIN_QUEUE_H

typedef struct _node {
    struct _node *next;
    void *data;
} Node;

typedef struct _queue {
    char *name;
    Node *head;
    Node *tail;
} Queue;

#endif //PUPKIN_QUEUE_H
