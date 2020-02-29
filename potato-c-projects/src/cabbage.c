#include <stdio.h>
#define ID(n) n

int main(int argc, char *argv[]) {
    int ID(1);
    ID(1) = 5;

    printf("%d", ID(1));
}

