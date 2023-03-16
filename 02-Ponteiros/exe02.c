#include <stdio.h>

int main(void){
int i = 19;
char c = 'z';
printf("Valor de i: %d\n", i);
printf("Endereco de i: %i\n", &i);
printf("Endereco de i (em hexadecimal): %x\n", &i);
printf("Valor de c: %c\n", c);
printf("Endereco de c: %i\n", &c);
printf("End. de c em hexadecimal: %x\n", &c);
return 0;
}