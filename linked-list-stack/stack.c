#include <stdbool.h>
#include <stdlib.h>
#include "linked-list.c"

bool push(struct node **top, int n) {
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
        return false; // Memory allocation failed
    newNode->value = n;
    newNode->next = *top;
    *top = newNode;
    return true;
}

int pop(struct node **top) {
    if (*top == NULL)
        return 0;
    struct node *node = *top;
    int val = node->value;
    *top = node->next;
    free(node);
    return val;
}
