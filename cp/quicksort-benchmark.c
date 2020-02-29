#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *partition(int arr[], int *low, int *high) {
    int pivot = *high;
    int *p = low - 1, *j;

    for (j = low; j < high; j++) {
        if (*j < pivot) {
            p++;
            swap(p, j);
        }
    }
    swap(p + 1, high);
    return p + 1;
}

void quickSort(int arr[], int *low, int *high) {
    if (low < high) {
        int *middle = partition(arr, low, high);

        quickSort(arr, low, middle - 1);
        quickSort(arr, middle + 1, high);
    }
}

#define N 10000000
int arr[N];

int main() {
    srand(time(NULL));
    clock_t begin, end;
    begin = clock();
    for (int *p = arr; p < arr + N; p++) {
        *p = rand();
    }
    end = clock();

    printf("Filled array in %lf\n", (double)(end - begin) / CLOCKS_PER_SEC);

    begin = clock();
    quickSort(arr, &arr[0], arr + N - 1);
    end = clock();
    printf("Sorted array in %lf\n", (double)(end - begin) / CLOCKS_PER_SEC);

    bool isSorted = true;
    begin = clock();
    for (int *p = arr + 1; p < arr + N; p++) {
        if (*p < *(p - 1)) {
            isSorted = false;
            break;
        }
    }

    end = clock();
    printf("Validated array in %lf\n", (double)(end - begin) / CLOCKS_PER_SEC);
    if (isSorted) {
        printf("Sorted");
    } else {
        printf("Not Sorted");
    }

    return 0;
}
