/*Implemente uma função que receba uma matriz esparsa e um vetor de números inteiros. 
A função deverá comparar o vetor com cada linha da matriz. Caso o vetor seja encontrado, 
deve ser retornada a linha em que o mesmo foi localizado. Caso contrário, a função 
deverá retornar -1.

Input Format
A primeira linha contém os números de linhas (l) e de colunas (c). Em seguida, uma matriz 
deve ser lida. Lembre-se: 0 é valor nulo, ou seja, deve ser ignorado.

Por fim, deve ser lido um vetor com c elementos.

Constraints
Deve ser utilizada uma estrutura de matriz esparsa, como a que foi apresentada em sala de aula.

Será atribuída a nota zero no caso em que a verificação for feita em matriz de inteiros em vez 
de matriz esparsa.

Output Format
Imprimir a posição da primeira linha em que o vetor foi encontrado. Caso o vetor não seja em 
encontrado, imprimir -1

Sample Input 0
5 5
0 2 0 1 0
1 0 0 3 1
2 3 0 0 0
1 3 2 0 1
0 0 4 0 1
2 3 0 0 0

Sample Output 0
2

Explanation 0
matriz:
0 2 0 1 0 1 0 0 3 1 2 3 0 0 0 1 3 2 0 1 0 0 4 0 1

Vetor:
2 3 0 0 0*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

typedef struct Spa_Mat Spa_Mat;

struct Cell{
        int item;
        int col;
        Cell *next;
};


struct ListaE{
        Cell *head;
};


struct Spa_Mat{
       int n_lin;
       int n_col;
       ListaE **lin;
};

Spa_Mat* criar(int l, int c){
        Spa_Mat* mat = (Spa_Mat*) malloc(sizeof(Spa_Mat));
        int i;

        mat->n_col = c;
        mat->n_lin = l;
        mat->lin = (ListaE**) malloc(sizeof(ListaE*) * l);

        for (i = 0; i < l; i++){
                mat->lin[i] = (ListaE*) malloc(sizeof(ListaE));
                mat->lin[i]->head = NULL;
        }

        return mat;
}


Cell* criar_celula(int item, int col){
	Cell *nova = (Cell*) malloc(sizeof(Cell));
	nova->item = item;
	nova->col = col;
	nova->next = NULL;

	return nova;
}

void imprimir(Spa_Mat* mat){
    int i, j;
    Cell* aux;

    for (i = 0; i < mat->n_lin; i++){
        aux = mat->lin[i]->head;
        j = 0;

        while (aux != NULL){
            while (j < aux->col){
                printf("0 ");
                j++;
            }

            printf("%d ", aux->item);
            j++;
            aux = aux->next;
        }

        for (j; j < mat->n_col; j++)
            printf("0 ");

        printf("\n");
    }
}

int main(void)
{



    return 0;
}