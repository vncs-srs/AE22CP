#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union
{
    char A[2];
    struct 
    {
        char B;
        char C;
    };
    
}dataType;

int main(void)
{
    dataType Dado;
    Dado.A[0] = 'a';
    Dado.A[1] = 'b';
    Dado.B = 'c';
    Dado.C = 'd';
    printf("%c %c %c %c\n",Dado.A[0],Dado.A[1],Dado.B,Dado.C);

    return 0;

}
