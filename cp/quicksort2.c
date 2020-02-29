#include <stdio.h>
#include <stdbool.h>

int partition(int arr[], int min, int high);
void quicksort(int arr[], int min, int high);
void swap(int arr[], int x, int y);

int main() {
    int n;
    printf("How many numbers do you want to sort: ");
    scanf("%u", &n);

    int nums[n];

    for (int i = 0; i < n; i += 1) {
        printf("Enter a number : ");
        scanf("%d", &nums[i]);
    }

    quicksort(nums, 0, n - 1);

    printf("The sorted array : ");
    
    for (int i = 0; i < n; i += 1) {
        printf("%d ", nums[i]);
    }

    return 0;
}


int partition(int arr[], int min, int high) {
    int pivot = arr[high];
    int i = min, j = min;

    while (j < high) {
        if (arr[j] < pivot) {
            swap(arr, j, i);
            i += 1;
        }
        j += 1;
    }
    swap(arr, i, high);
    return i;
}

void quicksort(int arr[], int min, int high) {
    if (min < high) {
        int pivot = partition(arr, min, high);

        quicksort(arr, min, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

void swap(int arr[], int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}