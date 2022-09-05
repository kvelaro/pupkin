#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"


bool addQueue(QueueList **list, const char *name, const Node* data) {
    if(list == NULL) {
        return false;
    }
    *list = (QueueList*) malloc(sizeof (QueueList));
    if(*list == NULL) {
        return false;
    }
    (*list)->name = (char *) malloc(sizeof(name));
    (*list)->name = name;
    (*list)->queue = (Queue *) malloc(sizeof (Queue));
    (*list)->next = NULL;
    if((*list)->name == NULL || (*list)->queue == NULL) {
        return false;
    }
    return addNode((*list)->queue, data);
}

bool addNode(Queue *queue, const Node* data) {
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL) {
        return false;
    }
    node = (Node*) data;
    node->next = NULL;

    if(queue->head == NULL) {
        queue->head = node;
    }
    //need to update next of the previous one
    else {
        queue->tail->next = node;
    }
    queue->tail = node;
    return true;
}

//Queue inside operations

bool enqueue(QueueList **list, const char *name, const Node* data) {
    if(list == NULL) {
        return false;
    }
    if(*list) {
        do {
            //@todo check when last element taken

            if(strcmp((*list)->name, name) == 0) {
                addNode((*list)->queue, data);
            }
        } while ((*list)->next != NULL);
    }
    else {
        addQueue(list, name, data);
    }
    return true;
}

void *dequeue(char *queueName) {

}

void purge(char *queueName) {

}