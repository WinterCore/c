#include <stdio.h>
#include "randomized-queue.h"

int main(void) {
    struct randomized_queue *q = create_randomized_queue();

    enqueue(q, 5);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    printf("%d", dequeue(q));
    printf("%d", dequeue(q));
    printf("%d", dequeue(q));
    printf("%d", dequeue(q));
    printf("%d", dequeue(q));

    return 0;
}
