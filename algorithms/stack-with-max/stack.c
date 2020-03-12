#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

bool is_empty(struct node **n) {
    return *n == NULL;
}

void push(struct node **n, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Failed to allocate memory for a new stack item. exiting...");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next  = *n;
    *n = new_node;
}


int pop(struct node **n) {
    struct node *old = *n;
    int value = old->value;
    *n = old->next;
    free(old);
    return value;
}
