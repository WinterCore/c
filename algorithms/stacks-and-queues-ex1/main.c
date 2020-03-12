#include <stdio.h>
#include "deque.h"

int main(void) {
    struct deque *d = create_deque();
    add_first(d, 1);
    add_first(d, 2);
    add_first(d, 3);
    add_first(d, 1);
    add_last(d, 0);
    printf("%d\n", remove_last(d));
    printf("%d\n", remove_last(d));
    printf("%d\n", remove_last(d));
    printf("%d\n", remove_last(d));
    printf("%d\n", remove_last(d));
    printf("%d\n", remove_last(d));
    print(d);

    return 0;
}
