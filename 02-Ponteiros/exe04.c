#include <stdio.h>

//Não realiza troca

/*void troca(int a, int b)
{
    int aux;
    aux = a;
    a = b;
    b = aux;
}

int main(void)
{
    int x, y;
    x = 5;
    y = 10;
    troca(x, y);
    printf("%d\n", x);
    printf("%d\n", y);

    return 0;
}*/

//Realiza a a troca atravez de ponteiro exemplo *a

void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
int main(void)
{
    int x, y;
    x = 5;
    y = 10;
    troca(&x, &y);
    printf("%d\n", x);
    printf("%d\n", y);

    return 0;
}