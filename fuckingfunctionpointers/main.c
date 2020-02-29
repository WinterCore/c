#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

float *bar(int i) {
    static float f;
    f = i;
    return &f;
}

float *(*x(void))(int) {
    return bar;
}


void foo(int i) {
    printf("fuckingfunctionpointers: %d", i);
}
void (*z(int h, void (*y)(int)))(int) {
    return y;
}


int main(void) {
    float *(*(*y)(void))(int) = x;
    void (*(*h)(int, void (*)(int)))(int) = z;
    h(20, foo)(20);
    printf("\n\n%f", *y()(100));
    return 0;
}

// array of functions that return char and take an int param
// pointer to a function that takes 0 args
// function that takes an (int, function that takes an int and returns void) returns a function that takes an int
