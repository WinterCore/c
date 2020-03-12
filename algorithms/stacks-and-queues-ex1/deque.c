#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void print(struct deque *d) {
    struct node *t = d->head;
    printf("Deque data : ");
    while (t) {
        printf("%d ", t->value);
        t = t->next;
    }
}

struct deque *create_deque() {
    return (struct deque *) malloc(sizeof(struct deque));
}

bool is_empty(struct deque *d) {
    return d->head == NULL || d->tail == NULL;
}

void add_first(struct deque *d, int value) {
    struct node *n = malloc(sizeof(struct node));
    n->value = value;
    n->next = NULL;
    n->prev = NULL;
    if (is_empty(d))
        d->tail = d->head = n;
    else {
        n->next = d->head;
        d->head->prev = n;
        d->head = n;
    }
}

void add_last(struct deque *d, int value) {
    struct node *n = malloc(sizeof(struct node));
    n->value = value;
    n->next = NULL;
    n->prev = NULL;
    if (is_empty(d))
        d->tail = d->head = n;
    else {
        d->tail->next = n;
        n->prev = d->tail;
        d->tail = n;
    }
}

int remove_first(struct deque *d) {
    if (is_empty(d)) {
        printf("The queue is empty");
        exit(EXIT_FAILURE);
    }
    int value = d->head->value;
    struct node *old = d->head;
    d->head       = old->next;
    if (d->head != NULL)
        d->head->prev = NULL;
    free(old);
    return value;
}

int remove_last(struct deque *d) {
    if (is_empty(d)) {
        printf("The queue is empty");
        exit(EXIT_FAILURE);
    }
    int value = d->tail->value;
    struct node *old = d->tail;
    d->tail       = old->prev;
    if (d->tail != NULL)
        d->tail->next = NULL;
    free(old);
    return value;
}
