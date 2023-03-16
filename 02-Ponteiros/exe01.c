#include <stdio.h>

typedef struct retangulo
{
    int x, y;
}Retangulo;

int main(void)
{
    printf("%d\n", sizeof(double));
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(Retangulo));
    return 0;
}