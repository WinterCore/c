#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct t {
    int i;
};

void nothing(void) {

    printf("NOthing");
}

void (*foo(struct t *s, long i))(void) {
    return nothing;
}

int main(void) {
    // a : char *(*p)(char *);
    // b : void (*(*f)(struct t *, long))(void)

    void (*(*f)(struct t *, long))(void) = foo;
    f(&(struct t) {1}, 10)();

    return 0;
}

// array of functions that return char and take an int param
// pointer to a function that takes 0 args
// function that takes an (int, function that takes an int and returns void) returns a function that takes an int
