#include <stdio.h>

char *digits[][3] = {
    {
        " _ ",
        "| |",
        "|_|"
    }, {
        "   ",
        "  |",
        "  |"
    }, {
        " _ ",
        " _|",
        "|_ "
    }, {
        " _ ",
        " _|",
        " _|",
    }, {
        "   ",
        "|_|",
        "  |",
    }, {
        " _ ",
        "|_ ",
        " _|"
    }, {
        " _ ",
        "|_ ",
        "|_|"
    }, {
        " _ ",
        "  |",
        "  |"
    }, {
        " _ ",
        "|_|",
        "|_|"
    }, {
        " _ ",
        "|_|",
        " _|"
    }
};

int main(int argc, char *argv[]) {
    printf("Please enter a number: ");
    char c;
    int numbers[10];
    int *p = numbers;
    while ((c = getchar()) != '\n' && p < &numbers[10]) {
        if (c >= '0' && c <= '9') {
            *p++ = c - '0';
        }
    }
    int i = 0;
    int *it = numbers;
    while (i < 3) {
        it = numbers;
        while (it < p) {
            printf("%s ", digits[*it][i]);
            it++;
        }
        printf("\n");
        i++;
    }
}

