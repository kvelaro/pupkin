#include <string.h>
#include <stdlib.h>

#include "queue.h"

Queue operations
void addQueue(QueueList *list, char *name, void *node) {
    list = (QueueList*) malloc(sizeof (QueueList));
    list->name = name;
    list->queue = (Queue *) malloc(sizeof (Queue));

    list->next = NULL;
    int a =1;
}

//Queue inside operations

void enqueue(QueueList *list, char *name, void *node) {
    while(list && list->next != NULL) {
        if(strcmp(list->name, name) == 0) {

        }
    }
    addQueue(list, name, node);
}

void *dequeue(char *queueName) {

}

void purge(char *queueName) {

}