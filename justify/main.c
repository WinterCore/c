#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_MAX 60

void read_word(char *c) {
    char a;
    while ((a = getchar()) == ' ');
    while (a != ' ' && a != EOF && a != '\t' && a != '\n') {
        *c++ = a;
        a = getchar();
    }
    *c = '\0';
}


void write_line(char *line, int *line_len, int *num_words) {
    int extra_space = LINE_MAX - *line_len;
    while (*line) {
        if (*line == ' ') {
            int space_to_insert = extra_space / (*num_words - 1);
            for (int i = 0; i < space_to_insert + 1; i += 1)
               putchar(' ');
            extra_space -= space_to_insert;
            *num_words -= 1;
        } else {
            putchar(*line);
        }
        line++;
    }
    printf("\n");
}

void clear_line(char *line, int *line_len, int *word_len) {
    line[0] = '\0';
    *line_len = 0;
    *word_len = 0;
}

void add_word(char *word, char *line, int *line_len, int *num_words) {
    if (*num_words > 0) {
        line[*line_len] = ' ';
        line[*line_len + 1] = '\0';
        (*line_len)++;
    }
    strcat(line, word);
    *line_len += strlen(word);
}

void run() {
    char line[200];
    char word[50];
    int word_len = 0, line_len = 0, num_words = 0;
    clear_line(line, &line_len, &num_words);
    while (1) {
        read_word(word);
        word_len = strlen(word);
        if (!word_len) {
            puts(line);
            exit(0);
        }
        if (line_len + word_len > LINE_MAX) {
            write_line(line, &line_len, &num_words);
            clear_line(line, &line_len, &num_words);
        }
        add_word(word, line, &line_len, &num_words);
        num_words += 1;
    }
}

int main(void) {
    run();
    return 0;
}
