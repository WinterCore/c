#ifndef QUEUE_H

#define QUEUE_h
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

struct queue {
    struct node *r;
    struct node *w;
};

bool is_queue_empty(struct queue *q);
void enqueue(struct queue *q, int value);
int dequeue(struct queue *q);
struct queue *create_queue();

#endif
