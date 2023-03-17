/*Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve conter a matrícula do aluno, nome,
 nota da primeira prova, nota da segunda prova e nota da terceira prova.

(a) Permita ao usuário entrar com os dados de n alunos. (b) Encontre o aluno com maior nota da primeira prova. (c) Encontre
 o aluno com maior média geral. (d) Encontre o aluno com menor média geral (e) Para cada aluno diga se ele foi aprovado ou 
 reprovado, considerando a média 6 para aprovação.

Input Format

A primeira linha é composta por um número n de alunos. Seguem a matricula (numérico até 65000), 
nome (string max 255 caracteres) e 3 notas (float com 1 casa de precisão)

Constraints
.
Output Format

A saída devera informar, para cada aluno se ele foi aprovado ou reprovado. Seguido das soluções para as questões (b), (c) e (d)

Sample Input 0
3
13515
Dudu
10.0 3.1 8.2
13516
Lilian
8.5 9.5 9.0
13518
Gustavo
6.0 2.0 2.1

Sample Output 0
Aprovado!
Aprovado!
Reprovado!
O aluno com maior media e: 13516 Lilian 9.0
O aluno com menor media e: 13518 Gustavo 3.4
O aluno com maior P1 e: 13515 Dudu 10.0

Sample Input 1
5
13515
Farofa
1.0 3.1 8.2
13516
Lilian
0.5 9.5 9.0
13518
Gusvo
0.0 2.0 2.1
13517
Pira
0.0 2.0 2.1
13519
Lucas
0.0 2.0 2.1

Sample Output 1
Reprovado!
Aprovado!
Reprovado!
Reprovado!
Reprovado!
O aluno com maior media e: 13516 Lilian 6.3
O aluno com menor media e: 13518 Gusvo 1.4
O aluno com maior P1 e: 13515 Farofa 1.0*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    char nome[255];
    int RA;
    float coef;
    float n1,n2,n3;
}Aluno;

Aluno media_vec(Aluno v3)
{
    v3.coef=(v3.n1+v3.n2+v3.n3)/3.0;
    
    return(v3);
}

int main(void)
{
    int dim,i;

    scanf("%d",&dim);

    Aluno vetor[dim];
    
    Aluno maior,menor,maiorp1;

    maior.coef=-99;
    menor.coef=100.01;

    for ( i = 0; i < dim; i++)
    {

        scanf("%d",&vetor[i].RA);
        scanf("%s",vetor[i].nome);
        scanf("%f %f %f",&vetor[i].n1,&vetor[i].n2,&vetor[i].n3);

        vetor[i] = media_vec(vetor[i]);

        if (vetor[i].coef > maior.coef)
        {
            maior=vetor[i];
        }
        if (vetor[i].coef<menor.coef)
        {
            menor=vetor[i];
        }
        if (vetor[i].n1>maiorp1.n1)
        {
            maiorp1=vetor[i];
        }
        
    }
    
    for ( i = 0; i < dim ; i++)
    {
        if (vetor[i].coef>=6)
        {
            printf("Aprovado!\n");
        }
        else 
        {
            printf("Reprovado!\n");
        }
        
    }
    
    printf("O aluno com maior media e: %d %s %.1f\n",maior.RA,maior.nome,maior.coef);
    printf("O aluno com menor media e: %d %s %.1f\n",menor.RA,menor.nome,menor.coef);
    printf("O aluno com maior P1 e: %d %s %.1f\n",maiorp1.RA,maiorp1.nome,maiorp1.n1);
    

    return 0;
    
}