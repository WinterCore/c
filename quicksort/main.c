#include <stdio.h>
#include "quicksort.h"


int main(void) {
    int a[] = {6, 5, 4, 3, 2, 1, 0};

    quickSort(a, &a[0], &a[6]);

    int *p = a;
    while (p < &a[7]) {
        printf("%d - ", *p++);
    }
}
