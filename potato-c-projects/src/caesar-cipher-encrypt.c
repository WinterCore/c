#include <stdio.h>

#define MAX_LENGTH 100

int main() {
    char message[MAX_LENGTH];
    unsigned int length;
    unsigned int shift;
    printf("Enter message to be encrypted: ");
    while ((message[length++] = getchar()) != '\n');
    printf("Enter shift amount: ");
    scanf("%ud", &shift);
    printf("Encrypted message: ");

    for (int i = 0; i < length; i += 1) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            putchar(((message[i] - 'A' + shift) % 26) + 'A');
        } else if (message[i] >= 'a' && message[i] <= 'z'){
            putchar(((message[i] - 'a' + shift) % 26) + 'a');
        } else {
            putchar(message[i]);
        }
    }

    return 0;
}