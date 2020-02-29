#include "quicksort.h"


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int *start, int *end) {
    if (start < end) {
        int *pi = partition(arr, start, end);

        quickSort(arr, start, pi - 1);
        quickSort(arr, pi + 1, end);
    }
}

int *partition(int arr[], int *start, int *end) {
    int pivot = *end;
    int *pos = start;

    while (start < end) {
        if (*start < pivot) {
            swap(pos, start);
            pos++;
        }
        start++;
    }
    swap(end, pos);
    return pos;
}
