#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "percolation.h"
#include "union.h"

#define ANSI_COLOR_RED   "\x1b[33m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

void open(struct object *s[], int size, int row, int col) {
    int curr = row + col * size;
    s[curr]->isOpen = true;
    if (col > 0 && s[curr - size]->isOpen) // top cell
        union_objects(s, curr, curr - size);
    if (col < size - 1 && s[curr + size]->isOpen) // bottom cell
        union_objects(s, curr, curr + size);
    if (row > 0 && s[curr - 1]->isOpen) // left cell
        union_objects(s, curr, curr - 1);
    if (row < size - 1 && s[curr + 1]->isOpen) // right cell
        union_objects(s, curr, curr + 1);

    // Connect corners that are in the top & bottom rows to 2 virtual objects
    //          (n * n) for top row
    //          (n * n + 1) for bottom row
    // This is done to increase the performance of the percolates function
    if (col == size - 1)
        union_objects(s, curr, size * size + 1);
    if (col == 0)
        union_objects(s, curr, size * size);
}


void visualize(struct object *s[], int size, int row, int col) {
    for (int i = 0; i < size; i += 1) {
        for (int j = 0; j < size; j += 1) {
            if (row == j && col == i)
                printf("▉▉▉");
            else
                if (s[i * size + j]->isOpen)
                    printf(ANSI_COLOR_GREEN "▉▉▉" ANSI_COLOR_RESET);
                else
                    printf(ANSI_COLOR_RED "▉▉▉" ANSI_COLOR_RESET);
        }
        printf("\n");
    }
}

void initialize(struct object *s[], int size) {
    for (int i = size * size + 1; i >= 0; i -= 1) {
        s[i] = malloc(sizeof(struct object));
        if (s[i] == NULL) {
            printf("There's not enough ram to continue. Allocated for %d out of %d objects", i, size * size);
            exit(EXIT_FAILURE);
        }
        s[i]->size   = 1;
        s[i]->id     = i;
        s[i]->isOpen = 0;
    }
}

bool percolates(struct object *s[], int size) {
    return are_objects_connected(s, size * size, size * size + 1);
}

bool is_full(struct object *s[], int size, int row, int col) {
    int curr = col * size + row;
    return are_objects_connected(s, curr, size * size);
}

double run(int size, bool vis) {
    int open_count = 0;
    srand(time(0));
    struct object **data = malloc(sizeof(int *) * size * size + 2);
    if (data == NULL) {
        printf("There's not enough ram to allocate for %d objects", size * size);
        exit(EXIT_FAILURE);
    }
    initialize(data, size);
    while (!percolates(data, size)) {
        int row = rand() % size;
        int col = rand() % size;
        if (!data[col * size + row]->isOpen) {
            open(data, size, row, col);
            open_count += 1;
            if (vis) {
                printf("\n\n");
                visualize(data, size, row, col);
                printf("\n");
            }
        }
    }
    return (double) open_count / (size * size);
}
