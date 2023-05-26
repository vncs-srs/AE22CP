#include <stdio.h>
#include <strings.h>
#include <stdio_ext.h>

int cont_char(char *s, char c) {
    if (*s == '\0') {
        return 0;
    }
    int cont = cont_char(s + 1, c);
    if (*s == c) {
        cont++;
    }
    return cont;
}


int binario(int decimal)
{
    int resto=decimal%2;
    if(decimal >= 2) {
        binario(decimal/2);
    }
    printf("%d",resto);
}


int main(void)
{
    char s[10];
    char c;
    printf("Insira uma palavra:\n");
    scanf("%s",s);// palavra a ser inserida
    __fpurge(stdin);
    printf("Insira o caractere a ser procurado:\n");
    scanf("%c",&c);//letra a ser procurada
    __fpurge(stdin);
    int cont = cont_char(s, c);
    printf("O caractere '%c' aparece %d vezes na string '%s'.\n", c, cont, s);

    int n;
    printf("Insira um decimal pra transformar em Binario: ");
    scanf("%d",&n);

    binario(n);


    return 0;
}