#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

bool is_palindrome(const char *message) {
    const char *left = message, *right;
    while (*message++);
    right = message - 2;

    while (left < right) {
        char l = tolower(*left), r = tolower(*right);
        if (l < 'a' || l > 'z')
            left++;
        else if (r < 'a' || r > 'z')
            right--;
        else if (l != r)
            return false;
        else {
            left++;
            right--;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    char temp[2000];
    printf("Enter a sentence: ");
    fgets(temp, 2000, stdin);
    if (is_palindrome(temp))
        printf("Palindrome");
    else
        printf("Not a palindrome");
    return 0;
}

