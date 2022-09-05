#ifndef PUPKIN_QUEUE_H
#define PUPKIN_QUEUE_H

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

void enqueue(QueueList *list, char *name, void *node);

#endif //PUPKIN_QUEUE_H
