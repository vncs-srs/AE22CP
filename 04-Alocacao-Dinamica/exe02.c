#include <stdio.h>
#include <stdlib.h>

int* func(int *v)
{
    int *p = (int*) malloc(2 * sizeof(int));
    p[0] = v[0] * v[0];
    p[1] = v[1] * v[1];

    return p;
}

int main(void)
{
    int *v, *p;

    p= func(v);
    printf("\n%d\n",*p);
    p++;
    printf("\n%d\n",*p);

    return 0;
}

//codigo com segmentatio fault