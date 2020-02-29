#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

int main(void) {
    struct node *n = NULL;
    add_node(&n, 2);
    add_node(&n, 5);
    add_node(&n, 10);
    add_node(&n, 12);
    add_node(&n, 15);
    struct node new = {1100, NULL};
    insert_into_ordered_list(&n, &new);
    print(n);
    return 0;
}
