#include <stdio.h>

int main() {
    int letters[26] = {0};
    char c;
    printf("Enter the first word: ");
    while ((c = getchar()) != '\n') {
        if (c >= 'A' && c <= 'Z') c = (c - 'A') + 'a'; // Convert to lowercase
        letters[c - 'a'] += 1;
    }
    printf("Enter the second word: ");
    while ((c = getchar()) != '\n') {
        if (c >= 'A' && c <= 'Z') c = (c - 'A') + 'a'; // Convert to lowercase
        letters[c - 'a'] -= 1;
    }
    for (int i = 0; i < 26; i += 1) {
        if (letters[i] != 0) {
            printf("The words are not anagrams.");
            return 0;
        }
    }
    printf("The words are anagrams.");
    return 0;
}