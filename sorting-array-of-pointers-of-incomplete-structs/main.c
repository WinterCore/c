#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct vstring {
    int size;
    char str[];
};


void read_word(char *p) {
    char c;
    while ((c = getchar()) == ' ');
    while (c != '\n' && c != EOF) {
        *p++ = c;
        c = getchar();
    }
    *p = '\0';
}

void print(struct vstring *p) {
    int i = 0;
    while (i < p->size)
        putchar(p->str[i++]);
    putchar('\n');
}

int compare(const void *a, const void *b) {
    const char *a1 = *(char **)a, *a2 = *(char **)b;
    return strcmp(a1 + sizeof(int), a2 + sizeof(int));
}

int main(void) {
    char a[20];
    struct vstring **p = malloc(0);
    int num_words = 0;

    while (1) {
        printf("Enter a word: ");
        read_word(a);
        int len = strlen(a);
        if (len == 0)
            break;
        p = realloc(p, sizeof(p) * num_words + 1);
        p[num_words] =  malloc(sizeof(struct vstring) + len + 1);
        p[num_words]->size = len;
        strcpy(p[num_words]->str, a);
        num_words += 1;
    }
    qsort(p, num_words, sizeof(p[0]), compare);
    int i = 0;
    while (i < num_words) {
        print(p[i++]);
    }

    return 0;
}
