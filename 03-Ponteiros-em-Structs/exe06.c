#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union 
{
    int val_int;
    long val_long;
    double val_double;
}umpratodos;

int main() 
{
    umpratodos u;

    u.val_int = 15;

    printf("%d\n", u.val_int);
    
    u.val_double = 1.38;

    printf("%g\n", u.val_double);
    printf("%d\n", u.val_int);

    return 0;
}