#include <stdio.h>
#include <string.h>
#include <math.h>

#define INDENT(x) PRAGMA(ident #x)
#define PRAGMA(x) _Pragma(#x)


int main(int argc, char *argv[]) {
    INDENT(foo);

    return 0;
}
