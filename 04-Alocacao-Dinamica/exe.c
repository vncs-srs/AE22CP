#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s;
    //armazenar 12 caracteres e \0
    s = (char*) malloc(13 * sizeof(char));

    //colocando uma frase na string
    strcpy(s, "kame hame ha");
    
    //realocar espaço para mais um caractere
    s = (char*) realloc(s, 14 * sizeof(char));

    //adicionando o ponto de exclamação à string
    strcat(s, "!");



    return 0;
}