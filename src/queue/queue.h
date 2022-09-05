#ifndef PUPKIN_QUEUE_H
#define PUPKIN_QUEUE_H

#include <stdbool.h>

typedef struct _node {
    struct _node *next;
    void *data;
} Node;

typedef struct _queue {
    Node *head;
    Node *tail;
} Queue;

typedef struct _list {
    char *name;
    Queue *queue;
    struct _list *next;
} QueueList;

bool addQueue(QueueList **list, const char *name, const Node* data);

bool addNode(Queue *queue, const const Node* data);

bool enqueue(QueueList **list, const char *name, const Node* data);



#endif //PUPKIN_QUEUE_H
