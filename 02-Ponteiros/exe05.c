#include <stdio.h>

/*int main(void)
{
    int i;
    int v[5];
    
    *v = 0;
    *(v + 1) = 10;
    *(v + 2) = 20;
    *(v + 3) = 30;
    *(v + 4) = 40;
    
    for (i = 0; i < 5; i++)
        printf("v[%d] = %d\n", i, *(v + i));

    return 0;
}*/

int main(void)
{
    int i;
    int v[5];
    v[0] = 0;
    v[1] = 10;
    v[2] = 20;
    v[3] = 30;
    v[4] = 40;

    for (i = 0; i < 5; i++)
        printf("v[%d] = %d\n", i, v[i]);

    return 0;
}