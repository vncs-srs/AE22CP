#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum bits {um = 1, dois = 2, quatro = 4, oito = 8};
enum grandepasso { primeiro, segundo = 100, terceiro};

//PRIMEIRA FORMA DE USA O ENUM
/*enum espectro {vermelho, laranja, amarelo, verde, azul,
violeta, anil, ultravioleta};*/

//SEGUNDA FORMA DE USAR O ENUM
typedef enum {vermelho, laranja, amarelo, verde, azul,
violeta, anil, ultravioleta}espectro;

int main()
{
    int i = terceiro;
     
    printf("i= %d\n",i);

    espectro banda;
    banda = azul; // válido, azul é um enumerador
    banda = 2000; // inválido!, 2000 não é um enumerador
    banda = laranja; // válido
    banda++; // válido
    banda = laranja + vermelho; // válido

    printf("banda = %d\n",banda);
    
    int cor = azul; // válido, tipo espectro promovido a int
    banda = 3; // válido, o tipo espectro atribui um valor para

    cor = 3 + vermelho; // válido, vermelho é convertido para
    
    //banda = espectro(3); // inválido



    return 0;

}