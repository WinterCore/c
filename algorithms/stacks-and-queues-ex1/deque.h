#ifndef DEQUE_H
#define DEQUE_H
#include <stdbool.h>

struct node {
    int value;
    struct node *next;
    struct node *prev;
};

struct deque {
    struct node *head;
    struct node *tail;
};

struct deque *create_deque();

bool is_empty(struct deque *d);
void add_first(struct deque *d, int value);
void add_last(struct deque *d, int value);
int remove_first(struct deque *d);
int remove_last(struct deque *d);
void print(struct deque *d);

#endif
