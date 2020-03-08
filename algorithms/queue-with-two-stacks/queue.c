#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"


bool is_queue_empty(struct queue *q) {
    return q->r == NULL && q->w == NULL;
}

static void move_to_read(struct queue *q) {
    while (!is_empty(&q->w))
        push(&q->r, pop(&q->w));
}

void enqueue(struct queue *q, int value) {
    push(&q->w, value);
}

int dequeue(struct queue *q) {
    if (is_queue_empty(q)) {
        printf("The queue is empty! Exiting...");
        exit(EXIT_FAILURE);
    }
    if (is_empty(&q->r))
        move_to_read(q);
    return pop(&q->r);
}

struct queue *create_queue() {
    struct queue *q = malloc(sizeof(struct queue));
    return q;
}
