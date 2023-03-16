#include <stdio.h>

int main(void)
{
    int i;
    int *p_i;

    i = 30;
    p_i = &i; 
    *p_i = 15;

    printf("%d\n", i);
    printf("%d\n",*p_i);
    printf("%d\n", &i);
    printf("%d\n", p_i);

    return 0;
}