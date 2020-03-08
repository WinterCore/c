#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node *next;
};


void enqueue(struct node **tail, int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next  = NULL;
    if (*tail == NULL)
        *tail = newNode;
    else
        (*tail)->next = newNode;
}

int dequeue(struct node **head) {
    if (*head == NULL) {
        printf("Queue is empty");
        exit(EXIT_FAILURE);
    }
    struct node *old = *head;
    int value = old->value;
    *head = old->next;
    free(old);
    return value;
}

int main(void) {
    struct node *h = NULL;
    struct node *t = NULL;
    push(&h, 1);

    printf("%d\n", pop(&p));
    printf("%d", pop(&p));

    return 0;
}

// array of functions that return char and take an int param
// pointer to a function that takes 0 args
// function that takes an (int, function that takes an int and returns void) returns a function that takes an int
