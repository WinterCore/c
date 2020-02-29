#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define NUM_MAX 100

int generateNumber() {
    srand(time(NULL));
    return rand() % NUM_MAX;
}

void readGuesses(int number) {
    unsigned short numGuesses = 0;
    int guess; 
    while (true) {
        printf("Please enter your guess : ");
        scanf("%d", &guess);

        if (guess == number) {
            printf("Correct, You won in %d guesses.\n\n", numGuesses);
            break;
        } else if (guess < number) {
            printf("Too low.\n\n");
        } else {
            printf("Too high.\n\n");
        }
        numGuesses += 1;
    } 
}

int main() {
    int number = generateNumber();
    printf("A new number has been generated between 0 and %d\n", NUM_MAX);
    readGuesses(number);
    return 0;
}
