#ifndef DEQUE_H
#define DEQUE_H
#include <stdbool.h>

struct randomized_queue {
    int *d, i, n;
};

struct randomized_queue *create_randomized_queue();

bool is_empty(struct randomized_queue *d);
void enqueue(struct randomized_queue *d, int value);
int dequeue(struct randomized_queue *d);
int sample(struct randomized_queue *d);

#endif
