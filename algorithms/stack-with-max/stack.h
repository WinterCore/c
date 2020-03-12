#ifndef STACK_H

#define STACK_H
#include <stdbool.h>

struct node {
    int value;
    struct node *next;
};

bool is_empty(struct node **);
void push(struct node **, int);
int pop(struct node **);


#endif
