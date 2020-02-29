#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

int gcd(int m, int n) {
    if (n <= 0) {
        return m;
    }

    int r = m % n;
    m = n;
    n = r;

    return gcd(m, n);
}

int main() {
    int a, b;


    printf("Please enter the first number: ");
    scanf("%d", &a);
    printf("Please enter the second number: ");
    scanf("%d", &b);

    printf("The greatest common divisor for %d and %d is %d", a, b, gcd(a, b));
    return 0;
}
