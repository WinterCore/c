#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int foo(char i) {
    return i * 2;
}

int (*return_foo(void)) (char c) {
    return foo;
}

int main(void) {
    printf("%d", return_foo()(1));

    return 0;
}
