#ifndef PUUBIE_QUEUE_H
#define PUUBIE_QUEUE_H



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

void* dequeue(QueueList **list, char *name);

Node* nodeShift(Queue **queue);

bool purge(QueueList **list, char *name);

bool emptify(Queue *queue);

#endif //PUUBIE_QUEUE_H
