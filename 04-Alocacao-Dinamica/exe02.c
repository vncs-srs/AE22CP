#include <stdio.h>
#include <stdlib.h>

int* func(int *v)
{
    int *p = (int*) malloc(2 * sizeof(int));
    p[0] = v[0] * v[0];
    p[1] = v[1] * v[1];
    
    printf("\n%d %d\n",p[0],p[1]);

    return p;
}

int main(void)
{
    int *v, *p;
    int x[2]={3,7};

    v=x;

    p= func(v);
    printf("\n%d\n",*p);
    p++; //Pula uma porção de memoria
    printf("\n%d\n",*p);

    return 0;
}
