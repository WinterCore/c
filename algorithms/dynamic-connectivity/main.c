#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct object {
    int id;
    int size;
};

void read_line(char *);
void union_objects(struct object *[], int, int, int);
bool are_objects_connected(struct object *[], int, int);

void read_line(char *str) {
    char c;
    while ((c = getchar()) == ' ');
    while (c != '\n' && c != EOF) {
        *str++ = c;
        c = getchar();
    }
    *str = '\0';
}

struct object *get_root(struct object *arr[], int o) {
    int t = arr[o]->id;
    while (t != arr[t]->id)
        t = arr[t]->id;
    return arr[t];
}

void union_objects(struct object *arr[], int size, int a, int b) {
    struct object *t = get_root(arr, a);
    struct object *u = get_root(arr, b);
    if (t->size > u->size) {
        u->id = t->id;
        t->size += u->size;
    } else  {
        t->id = u->id;
        u->size += u->size;
    }
}

bool are_objects_connected(struct object *arr[], int a, int b) {
    return get_root(arr, a)->id == get_root(arr, b)->id;
}

void initialize_objects_array(struct object *arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i]       = malloc(sizeof(struct object));
        arr[i]->id   = i;
        arr[i]->size = 1;
    }
}

int main(int argc, char **argv) {
    int n;
    char c[100];
    sscanf(*(argv + 1), "%d", &n);
    struct object *arr[n];
    initialize_objects_array(arr, n);

    // while (1) {
    //     int a, b;
    //     printf("Please enter 2 objects (integers) to union: ");
    //     read_line(c);
    //     if (strlen(c) == 0)
    //         break;
    //     int read = sscanf(c, "%d %d", &a, &b);
    //     if (read != 2) {
    //         printf("Error: please enter 2 valid integers\n");
    //         continue;
    //     }
    //     union_objects(arr, n, a, b);
    // }
    union_objects(arr, n, 3, 4);
    union_objects(arr, n, 8, 4);
    union_objects(arr, n, 9, 4);
    union_objects(arr, n, 4, 6);
    union_objects(arr, n, 0, 6);
    union_objects(arr, n, 2, 6);
    union_objects(arr, n, 5, 6);
    union_objects(arr, n, 1, 2);
    union_objects(arr, n, 7, 2);

    // while (1) {
    //     int a, b;
    //     printf("Please enter 2 objects (integers) to check if they're connected: ");
    //     read_line(c);
    //     if (strlen(c) == 0)
    //         break;
    //     int read = sscanf(c, "%d %d", &a, &b);
    //     if (read != 2) {
    //         printf("Error: please enter 2 valid integers\n");
    //         continue;
    //     }
    //     if (are_objects_connected(arr, a, b))
    //         printf("%d and %d are connected\n", a, b);
    //     else
    //         printf("%d and %d are not connected\n", a, b);
    // }

    for (int i = 0; i < n; i++) {
        printf("%d - ", arr[i]->id);
    }
    return 0;
}
