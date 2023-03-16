#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    float x, y;
}retangulo;

retangulo* soma(retangulo *r1, retangulo *r2)
{
    retangulo aux;
    retangulo *p_aux = &aux;
    p_aux->x = r1->x + r2->x;
    p_aux->y = r1->y + r2->y;
    return p_aux; // Poderá não funcionar corretamente. Porquê?
}

int main()
{
    retangulo a = {1.5,2.5}, b = {3.5,4.5};
    retangulo *r1, *r2;

    r1 = &a;
    r2 = &b;

    retangulo *p = soma(r1,r2);

    printf("\n%.1f %.1f\n",p->x,p->y);


    return 0;
}