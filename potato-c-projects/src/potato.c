#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define GRID_WIDTH 10
#define GRID_HEIGHT 10


bool isDeadend(char grid[][GRID_HEIGHT], int pos[]) {
    return (
        grid[pos[0]][pos[1] - 1] != '.'
        || pos[1] - 1 < 0
    ) && (
        grid[pos[0]][pos[1] + 1] != '.'
        || pos[1] + 1 > GRID_HEIGHT
    ) && (
        grid[pos[0] + 1][pos[1]] != '.'
        || pos[0] + 1 > GRID_WIDTH
    ) && (
        grid[pos[0] - 1][pos[1]] != '.'
        || pos[0] - 1 < 0
    );
}

int main() {
    char grid[GRID_WIDTH][GRID_HEIGHT];
    for (int i = 0; i < GRID_WIDTH; i += 1) {
        for (int j = 0; j < GRID_HEIGHT; j += 1) {
            grid[i][j] = '.';
        }
    }
    char letter = 'A';
    grid[0][0] = letter;
    int pos[] = {0, 0};
    srand(time(NULL));
    while (letter < 'Z') {
        if (isDeadend(grid, pos)) {
            break;
        }
        int r = rand() % 4;
        int newpos[2] = {0};
        memcpy(newpos, pos, sizeof(pos));
        switch (r) {
            case 0:
                newpos[1] -= 1;
                break;
            case 1:
                newpos[0] += 1;
                break;
            case 2:
                newpos[1] += 1;
                break;
            case 3:
                newpos[0] -= 1;
                break;
        }
        if (
            newpos[0] < 0 || newpos[0] > GRID_WIDTH - 1
            || newpos[1] < 0 || newpos[1] > GRID_HEIGHT - 1
            || grid[newpos[0]][newpos[1]] != '.'
        ) {
            continue;
        }
        grid[newpos[0]][newpos[1]] = ++letter;
        memcpy(pos, newpos, sizeof(pos));
    }

    for (int i = 0; i < GRID_WIDTH; i += 1) {
        for (int j = 0; j < GRID_WIDTH; j += 1) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}
