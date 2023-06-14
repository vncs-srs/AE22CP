/*Implemente uma função que receba uma matriz esparsa. A função deverá retornar um 
vetor onde o i-ésimo elemento é igual a soma de todos os elementos da i-ésima coluna da matriz.

Input Format

A primeira linha contém os números de linhas e de colunas. Em seguida, uma matriz deve ser lida. 
Lembre-se: 0 é valor nulo, ou seja, deve ser ignorado.

Constraints

Deve ser utilizada uma estrutura de matriz esparsa, como a que foi apresentada em sala de aula.

Será atribuída a nota zero no caso em que a verificação for feita em matriz de inteiros em vez 
de matriz esparsa.

Output Format

Imprimir o vetor.

Sample Input 0
5 5
0 2 0 1 0
1 0 0 3 1
2 3 0 0 0
1 3 2 0 1
0 0 4 0 1

Sample Output 0

4 8 6 4 3*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Cell Cell;

typedef struct ListaE ListaE;

typedef struct Spa_Mat Spa_Mat;

struct Cell{
        int item;
        int lin;
        int col;
        int valor;
        Cell *next;
};


struct ListaE{
        Cell *head;
};


struct Spa_Mat{
        Cell elementos[MAX];

       int n_lin;
       int n_col;
       int qtdElementos;
       ListaE **lin;
};

Spa_Mat* criar(int l, int c);

Cell* criar_celula(int item, int col);

void imprimir(Spa_Mat* mat);

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

void inserirElemento(Spa_Mat *matriz, int linha, int coluna, int valor) {

    Cell novoElemento = {linha, coluna, valor};
    matriz->elementos[matriz->qtdElementos] = novoElemento;
    matriz->qtdElementos++;
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
void somarColunas(Spa_Mat *matriz, int *vetorSoma) {
    for (int i = 0; i < matriz->n_col; i++) {
        vetorSoma[i] = 0;

        for (int j = 0; j < matriz->qtdElementos; j++) {
            Cell elementoAtual = matriz->elementos[j];

            if (elementoAtual.col == i) {
                vetorSoma[i] += elementoAtual.valor;
            }
        }
    }
}


int main(void)
{
        int lin, col,n;
        Spa_Mat matriz;

        scanf("%d %d ",&lin,&col);

        for (int i = 0; i < lin; i++)
        {
                for (int j = 0; j < col; j++)
                {
                        scanf("%d",&n);
                        inserirElemento(&matriz,i,j,n);
                }
                
        }
        

}