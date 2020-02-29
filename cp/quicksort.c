#include <stdio.h>
#include <stdbool.h>

#define LENGTH 10

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[], int min, int max) {
    bool dir = true;
    while (min < max) {
        if (dir) {
            if (arr[max] <= arr[min]) {
                swap(arr, max, min);
                dir = false;
                min += 1;
            } else {
                max -= 1;
            }
        } else {
            if (arr[min] >= arr[max]) {
                swap(arr, min, max);
                dir = true;
                max -= 1;
            } else {
                min += 1;
            }
        }
    }
    return min;
}

void quicksort(int arr[], int min, int max) {
    if (min < max) {
        int mid = partition(arr, min, max);

        quicksort(arr, mid + 1, max);
        quicksort(arr, min, mid - 1);
    }
}

int main() {
    int arr[] = {9, 16, 47, 82, 4, 66, 12, 3, 25, 51};

    quicksort(arr, 0, LENGTH - 1);

    for (int i = 0; i < LENGTH; i += 1) {
        printf("%d ", arr[i]);
    }

    return 0;
}