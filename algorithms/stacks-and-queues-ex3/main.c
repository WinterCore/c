#include <stdio.h>
#include "randomized-queue.h"

void read_word(char *a) {
    char c;
    while ((c = getchar()) == ' ');
    while (c != EOF && c != ' ' && c != '\n') {
        *a++ = c;
        c = getchar();
    }
    *a = '\0';
}


int main(int argc, char **argv) {
    int n;
    char word[100];
    // fasdf
    sscanf(*(argv + 1), "%d", &n);
    struct randomized_queue *q = create_randomized_queue();
    while (1) {
        read_word(word);
        if (word[0] == '\0')
            break;
        enqueue(q, word);
    }
    while (n-- > 0) {
        printf("%s\n", dequeue(q));
    }

    return 0;
}
