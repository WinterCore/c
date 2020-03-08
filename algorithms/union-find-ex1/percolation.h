#ifndef PERCOLATION_H
#define PERCOLATION_H
#include <stdbool.h>

#include "union.h"

void initialize(struct object *[], int);
bool percolates(struct object *[], int);
bool is_full(struct object *[], int, int, int);
double run(int, bool);
void visualize(struct object *[], int, int, int);
void open(struct object *[], int, int, int);

#endif
