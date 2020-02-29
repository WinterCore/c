#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include "linked-list.h"

bool push(struct node **top, int n);
int pop(struct node **top);

#endif
