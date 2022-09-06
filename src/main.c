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


    Node *n4 = (Node *) malloc(sizeof(Node));
    n4->data = (char*) malloc(sizeof(strlen(str1)));
    n4->data = str1;

    Node *n5 = (Node *) malloc(sizeof(Node));
    n5->data = (char*) malloc(sizeof(strlen(str2)));
    n5->data = str2;

    Node *n6 = (Node *) malloc(sizeof(Node));
    n6->data = (char*) malloc(sizeof(strlen(str3)));
    n6->data = str3;


    Node *n7 = (Node *) malloc(sizeof(Node));
    n7->data = (char*) malloc(sizeof(strlen(str1)));
    n7->data = str3;

    Node *n8 = (Node *) malloc(sizeof(Node));
    n8->data = (char*) malloc(sizeof(strlen(str2)));
    n8->data = str3;

    Node *n9 = (Node *) malloc(sizeof(Node));
    n9->data = (char*) malloc(sizeof(strlen(str3)));
    n9->data = str3;

    enqueue(&list, "test", n1);
    enqueue(&list, "test", n2);
    enqueue(&list, "test", n3);

    enqueue(&list, "test1", n4);
    enqueue(&list, "test1", n5);
    enqueue(&list, "test1", n6);

    enqueue(&list, "test2", n7);
    enqueue(&list, "test2", n8);
    enqueue(&list, "test2", n9);
    int a = 1;
}
