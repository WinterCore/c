#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "randomized-queue.h"


struct randomized_queue *create_randomized_queue() {
    struct randomized_queue *d = malloc(sizeof(struct randomized_queue));
    srand(time(0));
    d->i = 0;
    d->n = 1;
    d->d = malloc(sizeof(char *));
    return d;
}

bool is_empty(struct randomized_queue *d) {
    return d->i == 0;
}

void resize(struct randomized_queue *d) {
    if (d->i >= d->n) {
        d->n = d->n * 2;
        d->d = realloc(d->d, sizeof(char *) * d->n);
    } else if (d->i < d->n / 4) {
        d->n = d->n / 2;
        d->d = realloc(d->d, sizeof(char *) * d->n);
    }
}

void enqueue(struct randomized_queue *d, char *value) {
    resize(d);
    char *s = malloc(strlen(value));
    strcpy(s, value);
    d->d[d->i++] = s;
}

int int_in_range(int min, int max) {
    return rand() % (max - min) + min;
}

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

char *dequeue(struct randomized_queue *d) {
    int r = int_in_range(0, d->i);
    swap(&d->d[r], &d->d[d->i - 1]);

    d->i--;
    return d->d[d->i];
}

