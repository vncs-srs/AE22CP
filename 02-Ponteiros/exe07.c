#include <stdio.h>

int main(void)
{
    int x[4];
    int *a, *b;
    *x = 118;
    *(x + 2) = 4;
    *(x + x[2] - 1) = 51;
    x[1] = 25;
    a = x;
    b = &x[2];
    printf(" %d\n", x[0]);
    printf(" %d\n", x[1]);
    printf(" %d\n", x[2]);
    printf(" %d\n", x[3]);
    printf(" %d\n", *a);
    printf(" %d\n", *b);
    return 0;
}