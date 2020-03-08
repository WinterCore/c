#include <stdio.h>
#include "queue.h"

int main(void) {
    struct queue *q = create_queue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    printf("%d", dequeue(q));

    return 0;
}
