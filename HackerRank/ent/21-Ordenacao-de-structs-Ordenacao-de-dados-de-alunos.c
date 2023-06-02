/*Adapte um dos algorimos de ordenação para o vetor de elementos da seguinte estrutura:

typedef struct{
    int matricula;
    char* nome;
    char* curso;
    float coef;
}Aluno;
A ordenação deve ser por nome. Caso haja registros com o mesmo nome, o critério de ordenação nesse caso é a matrícula.

Input Format

Na primeira linha deve ser lido o tamanho do vetor. A partir da segunda linha, ler os dados de cada elemento do vetor.

Constraints
.
Output Format

Imprimir os registro ordenados. Diferentemente da forma leitura, cada registro deve ser impresso em uma linha.

Sample Input 0
4
101
chinforoso
engenharia-de-computacao
0.73
205
joana
engenharia-eletrica
0.78
98
roberto
matematica
0.62
105
joana
historia
0.87

Sample Output 0
chinforoso 101 engenharia-de-computacao 0.73
joana 105 historia 0.87
joana 205 engenharia-eletrica 0.78
roberto 98 matematica 0.62*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define dim 100

typedef struct{
    int matricula;
    char* nome;
    char* curso;
    float coef;
}Aluno;

void troca(Aluno* a, Aluno* b){
    Aluno aux = *a;
    *a = *b;
    *b = aux;
}

int comparar(Aluno v[], int menor, int maior){
    char* aux = v[maior].nome;
    int i = (menor - 1);

    for (int j = menor; j <= maior - 1; j++){
        if (strcmp(v[j].nome, aux) < 0 || (strcmp(v[j].nome, aux) == 0 && v[j].matricula < v[maior].matricula)){
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[maior]);
    return (i + 1);
}



void quickSort(Aluno v[], int menor, int maior){
    if (menor < maior){
        int cp = comparar(v, menor, maior);
        quickSort(v, menor, cp - 1);
        quickSort(v, cp + 1, maior);
    }
}

void imprimir_vet_str(Aluno alunos[], int n){
    int i;

    for (i = 0; i < n; i++)
        printf("%s %d %s %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].curso, alunos[i].coef);
}

int main(void)
{
    int n;
    scanf("%d",&n);
    Aluno *alunos =  malloc(n * sizeof(Aluno));


    for (int i = 0; i < n; i++)
    {
        scanf("%d",&alunos[i].matricula);

        alunos[i].nome = (char*) malloc((dim+1) * sizeof(char));
        alunos[i].curso = (char*) malloc((dim +1) * sizeof(char));

        scanf("%s %s %f", alunos[i].nome, alunos[i].curso, &alunos[i].coef);
    }
    quickSort(alunos, 0, n-1);

    imprimir_vet_str(alunos, n);





    return 0;
}