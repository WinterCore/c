#ifndef DEQUE_H
#define DEQUE_H
#include <stdbool.h>

struct randomized_queue {
    char **d;
    int i, n;
};

struct randomized_queue *create_randomized_queue();

bool is_empty(struct randomized_queue *d);
void enqueue(struct randomized_queue *d, char *value);
char *dequeue(struct randomized_queue *d);
char *sample(struct randomized_queue *d);

#endif
