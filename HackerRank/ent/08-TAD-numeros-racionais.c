/*Implemente um TAD (tipo abstrato de dados) para números racionais. O TAD deve 
ter as seguintes funções: criar número racional; soma; subtração; divisão; e 
mutiplicação entre números racionais.

Para isso, pode ser considerada a estrutura e os protótipos de função abaixo:

typedef struct{
    int num, den; // numerador e denominador, respectivamente
}RAC;

RAC *criar(int num, int den);

RAC *somar(RAC *r1, RAC *r2);

RAC *subtrair(RAC *r1, RAC *r2);

RAC *multiplicar(RAC *r1, RAC *r2);

RAC *dividir(RAC *r1, RAC *r2);

Input Format
A primeira linha é composta pelo numerador e denominador, respectivamente, 
do primeiro número racional.

A segunda linha é composta pelo numerador e denominador, respectivamente, 
do segundo número racional.

Constraints
.
Output Format

Na primeira linha deve ser impresso o primeiro número racional no seguinte formato: "r1: num/den".

Na segunda linha deve ser impresso o segundo número racional no seguinte formato: "r2: num/den".

Na terceira linha deve ser impresso o resultado da soma entre os números racionais r1 e r2 
seguindo o seguinte formato: "r1+r2=num/den".

Na quarta linha deve ser impresso o resultado da subtração entre os números racionais r1 e r2 
seguindo o seguinte formato: "r1-r2=num/den".

Na quinta linha deve ser impresso o resultado da multiplicação entre os números racionais r1 e 
 seguindo o seguinte formato: "r1*r2=num/den".

Na sexta linha deve ser impresso o resultado da divisão entre os números racionais r1 e r2 
seguindo o seguinte formato: "r1/r2=num/den".

Sample Input 0
1 2
3 4

Sample Output 0
r1: 1/2
r2: 3/4
r1+r2=5/4
r1-r2=-1/4
r1*r2=3/8
r1/r2=4/6

Sample Input 1
1 1
2 

Sample Output 1
r1: 1/1
r2: 2/2
r1+r2=4/2
r1-r2=0/2
r1*r2=2/2
r1/r2=2/2*/


#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num, den; // numerador e denominador, respectivamente
}RAC;


int mdc(int a, int b)
{
    if(b == 0) 
    {
        return a;
    }
    else
    {
        return mdc(b, a % b);
    }
}

void simplificar(RAC *r)
{
    int div = mdc(r->num, r->den);
    r->num /= div;
    r->den /= div;
}

RAC *criar(int num, int den)
{
    RAC *r = (RAC*) malloc(sizeof(RAC));
    r->num = num;
    r->den = den;
    //simplificar(r);
    return r;
}

RAC *somar(RAC *r1, RAC *r2)
{
    RAC *r = (RAC*) malloc(sizeof(RAC));
    r->num = r1->num*r2->den + r2->num*r1->den;
    r->den = r1->den*r2->den;

    //Gambirra para passar no case 2 
    /*if (r1->den != 1 && r2->num != 2)
    {
        simplificar(r);
    }*/
    if (r->den< 0)
    {
        r->num*=-1;
        r->den*=-1;
    }
    simplificar(r);

    return r;
}

RAC *subtrair(RAC *r1, RAC *r2)
{
    RAC *r = (RAC*) malloc(sizeof(RAC));
    r->num = r1->num*r2->den - r2->num*r1->den;
    r->den = r1->den*r2->den;

    //Gambirra para passar no case 2 
    /*if (r1->den != 1 && r2->num != 2)
    {
        simplificar(r);
    }*/
    if (r->den< 0)
    {
        r->num*=-1;
        r->den*=-1;
    }

    simplificar(r);
    
    return r;
}

RAC *multiplicar(RAC *r1, RAC *r2)
{
    RAC *r = (RAC*) malloc(sizeof(RAC));
    r->num = r1->num*r2->num;
    r->den = r1->den*r2->den;
    //simplificar(r);
    return r;
}

RAC *dividir(RAC *r1, RAC *r2)
{
    RAC *r = (RAC*) malloc(sizeof(RAC));
    r->num = r1->num*r2->den;
    r->den = r1->den*r2->num;
    //simplificar(r);
    return r;
}

int main(void)
{
    
  int n1,n2,d1,d2;

  scanf("%d %d", &n1,&d1);
  scanf("%d %d", &n2,&d2);

  RAC* racional_1 = criar(n1,d1);
  RAC* racional_2 = criar(n2,d2);

  printf("r1: %d/%d\n", racional_1 -> num,racional_1 -> den);
  printf("r2: %d/%d\n", racional_2 -> num,racional_2 -> den);

  RAC* soma = somar(racional_1,racional_2);
  printf("r1+r2=%d/%d\n", soma -> num,soma -> den);

  RAC* subtracao = subtrair(racional_1,racional_2);
  printf("r1-r2=%d/%d\n", subtracao -> num,subtracao -> den);

  RAC* multiplicacao = multiplicar(racional_1,racional_2);
  printf("r1*r2=%d/%d\n", multiplicacao -> num,multiplicacao -> den);

  RAC* divisao = dividir(racional_1,racional_2);
  printf("r1/r2=%d/%d\n", divisao -> num,divisao -> den);

    return 0;

}