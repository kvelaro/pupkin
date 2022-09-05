#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue/queue.h"

int main() {
    char *str1 = "fist";
    char *str2 = "sec";
    char *str3 = "third";

    QueueList *list = NULL;

    Node *n1 = (Node *) malloc(sizeof(Node));
    n1->data = (char*) malloc(sizeof(strlen(str1)));
    n1->data = str1;

    Node *n2 = (Node *) malloc(sizeof(Node));
    n2->data = (char*) malloc(sizeof(strlen(str1)));
    n2->data = str2;

    Node *n3 = (Node *) malloc(sizeof(Node));
    n3->data = (char*) malloc(sizeof(strlen(str3)));
    n3->data = str3;

    enqueue(&list, "test", n1);
    enqueue(&list, "test", n2);
    enqueue(&list, "test", n3);
    int a = 1;
}
