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
    umpratodos *p_u;
    
    p_u = &u;
    u.val_int = 15;

    printf("%d\n", p_u->val_int);
    
    u.val_double = 1.38;
    
    printf("%g\n", p_u->val_double);
    printf("%d\n", p_u->val_int);
    
    return 0;
}