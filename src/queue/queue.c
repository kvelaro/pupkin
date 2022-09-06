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
    (*list)->queue = (Queue *) malloc(sizeof (Queue));
    if((*list)->name == NULL || (*list)->queue == NULL) {
        return false;
    }
    (*list)->name = (char *) name;
    (*list)->next = NULL;
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
        bool queueExists = false;
        QueueList *lptr = *list;
        while(true) {
            //@todo check when last element taken
            if(strcmp(lptr->name, name) == 0) {
                queueExists = true;
                addNode(lptr->queue, data);
                break;
            }
            if(lptr->next != NULL) {
                lptr = lptr->next;
            }
            else {
                break;
            }
        }
        if(queueExists == false) {
            addQueue(&lptr->next, name, data);
        }
    }
    else {
        addQueue(list, name, data);
    }
    return true;
}

void* dequeue(QueueList **list, char *name) {
    if(list == NULL) {
        return false;
    }
    if(*list) {
        QueueList *lptr = *list;
        while(true) {
            //@todo check when last element taken
            if(strcmp(lptr->name, name) == 0) {
                return nodeShift(&lptr->queue);
            }
            if(lptr->next != NULL) {
                lptr = lptr->next;
            }
            else {
                return false;
            }
        }
    }
}

Node* nodeShift(Queue **queue) {
    Queue *qptr = *queue;
    Node * nptr;
    if(qptr == NULL || qptr->head == NULL) {
        return NULL;
    }
    nptr = qptr->head;
    qptr->head = nptr->next;
    nptr->next = NULL;
    return nptr;
}

void purge(char *queueName) {

}