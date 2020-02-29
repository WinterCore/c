#include <stdio.h>

#define MAX_LENGTH 100

int main() {
    char letters[MAX_LENGTH];
    char c;
    printf("Please enter a sentence : ");
    int i = 0;
    while (i < MAX_LENGTH) {
        c = getchar();
        if (c == '?' || c == '.' || c == '!' || c == '\n') {
            break;
        }
        letters[i++] = c;
    }
    int lastPointer = i;
    while (i >= 0) {
        if (letters[i] == ' ' || i == 0) {
            int j = i == 0 ? i : i + 1;
            while (j < lastPointer) {
                putchar(letters[j]);
                j += 1;
            }
            lastPointer = i;
            putchar(' ');
        }
        i -= 1;
    }
    printf("\b%c\n", c);

    return 0;
}