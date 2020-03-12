#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "randomized-queue.h"


struct randomized_queue *create_randomized_queue() {
    struct randomized_queue *d = malloc(sizeof(struct randomized_queue));
    srand(time(0));
    d->i = 0;
    d->n = 1;
    d->d = malloc(sizeof(int));
    return d;
}

bool is_empty(struct randomized_queue *d) {
    return d->i == 0;
}

void resize(struct randomized_queue *d) {
    if (d->i >= d->n) {
        d->n = d->n * 2;
        d->d = realloc(d->d, sizeof(int) * d->n);
    } else if (d->i < d->n / 4) {
        d->n = d->n / 2;
        d->d = realloc(d->d, sizeof(int) * d->n);
    }
}

void enqueue(struct randomized_queue *d, int value) {
    resize(d);
    d->d[d->i++] = value;
}

int int_in_range(int min, int max) {
    return rand() % (max - min) + min;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int dequeue(struct randomized_queue *d) {
    int r = int_in_range(0, d->i);
    swap(&d->d[r], &d->d[d->i - 1]);

    d->i--;
    return d->d[d->i];
}

