#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {
    struct node *n = NULL;
    push(&n, 5);
    push(&n, 3);
    push(&n, 2);
    print(n);
    printf("Popped: %d", pop(&n));
    print(n);
    return 0;
}
