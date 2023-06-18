/*Implemente uma função que receba duas matrizes esparsas (m1 e m2). A função deverá retornar uma matriz esparsa 
resultante da soma de m1 e m2. Caso as matrizes tenham dimensões diferentes, a soma se dará a partir da primeira 
linha e da primeira coluna (como se uma matriz menor fosse colocada em cima da matriz maior mais ao topo e lado 
esquerdo possível).

Input Format

A primeira linha contém os números de linhas (l) e de colunas (c). Em seguida, a primeira matriz deve ser lida.

Após leia os números de linhas (l) e de colunas (c) novamente. Posteriormente, a segunda matriz deve ser lida.

Lembre-se: 0 é valor nulo, ou seja, deve ser ignorado.

Constraints

Deve ser utilizada uma estrutura de matriz esparsa, como a que foi apresentada em sala de aula.

Será atribuída a nota zero no caso em que a verificação for feita em matriz de inteiros em vez de matriz esparsa.

Output Format
Imprimir o conteúdo da matriz esparsa de saída como arranjo bidimensional.

Sample Input 0
6 5
0 2 0 1 0
1 0 0 3 1
2 3 0 0 0
1 3 2 0 1
0 0 4 0 1
2 3 0 0 0
6 5
1 0 0 1 0
5 0 0 0 0
0 3 0 1 0
0 0 0 0 1
2 3 0 0 1
1 1 1 0 0

Sample Output 0
1 2 0 2 0
6 0 0 3 1
2 6 0 1 0
1 3 2 0 2
2 3 4 0 2
3 4 1 0 0

Sample Input 1
6 5
0 2 0 1 0
1 0 0 3 1
2 3 0 0 0
1 3 2 0 1
0 0 4 0 1
2 3 0 0 0
3 3
1 1 1
1 0 1
1 1 1

Sample Output 1
1 3 1 1 0
2 0 1 3 1
3 4 1 0 0
1 3 2 0 1
0 0 4 0 1
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

Spa_Mat* criar(int l, int c);

Cell* criar_celula(int item, int col);

int buscar(int item, Spa_Mat* mat);

int buscar_pos(int l, int c, Spa_Mat* mat);

void trocar(int item, int l, int c, Spa_Mat* mat);

Spa_Mat* somar_matrizes(Spa_Mat* m1, Spa_Mat* m2);

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
static int procurar_lista(int item, ListaE *l){
        Cell *aux;

        if (l != NULL){
                aux = l->head;

                while ((aux != NULL) && (aux->item != item))
                	aux = aux->next;
        }

        if ((aux != NULL) && (aux->item == item))
                return 1;
        else
                return 0;
}


int buscar(int item, Spa_Mat* mat){
        int i;
        int aux = 0;

        for (i = 0; (i < mat->n_lin) && (aux == 0); i++)
                aux = procurar_lista(item, mat->lin[i]);

        return aux;
}

static int validar_pos_matriz(int lin, int col, Spa_Mat* mat){
    return (mat != NULL) && (lin >= 0) && (lin < mat->n_lin) && (col >= 0) && (col < mat->n_col);
}

int buscar_pos(int l, int c, Spa_Mat* mat){
    Cell *aux;
    int valor = 0;

    if ((mat != NULL) && validar_pos_matriz(l, c, mat)){
        aux = mat->lin[l]->head;

        while ((aux != NULL) && (c > aux->col))
            aux = aux->next;

        if ((aux != NULL) && (c == aux->col))
            valor = aux->item;
    }

    return valor;
}

static void trocar_inserir_na_lista(int item, int col, ListaE *l){
    Cell *auxA, *auxP, *novo;

    if ((l->head == NULL) || (col < l->head->col)){
        novo = criar_celula(item, col);
        novo->next = l->head;
        l->head = novo;

    }else if (col == l->head->col){
        l->head->item = item;
    }else{
        auxA = l->head; 
        auxP = auxA;

        while ((auxP != NULL) && (auxP->col < col)){
            auxA = auxP;
            auxP = auxP->next;
        }

        if ((auxP != NULL) && (col == auxP->col))
            auxP->item = item;

        else{
            novo = criar_celula(item, col);
            novo->next = auxA->next; 
            auxA->next = novo;
        }
    }
}

static void remover_na_lista(int col, ListaE *l){
    Cell *auxA, *auxP = NULL;
    
    if (l->head != NULL){
        if (col == l->head->col){
            auxP = l->head;
            l->head = l->head->next;
            free(auxP);
        }else{
            auxA = l->head;
            auxP = auxA; 
            while ((auxP != NULL) && (auxP->col < col)){
                auxA = auxP;
                auxP = auxP->next;
            }
            
            if ((auxP != NULL) && (col == auxP->col)){
                auxA->next = auxP->next;

                free(auxP);
            }
        }
    }
}

void trocar(int item, int l, int c, Spa_Mat* mat){
    if (validar_pos_matriz(l, c, mat)){
        if (item > 0)
            trocar_inserir_na_lista(item, c, mat->lin[l]);
        else
            remover_na_lista(c, mat->lin[l]);
    }
}

void liberar_matriz(Spa_Mat* mat){
    int i;
    Cell *auxA, *auxP;

    if (mat != NULL){
        for (i = 0; i < mat->n_lin; i++){
            auxA = mat->lin[i]->head;
            while (auxA != NULL){
                auxP = auxA->next;
                free(auxA);
                auxA = auxP;
            }
            free(mat->lin[i]);
        }
        free(mat->lin);
        free(mat);
    }
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

Spa_Mat* somar_matrizes(Spa_Mat* m1, Spa_Mat* m2) {
    int lin = m1->n_lin > m2->n_lin ? m1->n_lin : m2->n_lin;
    int col = m1->n_col > m2->n_col ? m1->n_col : m2->n_col;

    Spa_Mat* resultado = criar(lin, col);

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            int valor_m1 = buscar_pos(i, j, m1);
            int valor_m2 = buscar_pos(i, j, m2);
            int soma = valor_m1 + valor_m2;
            if (soma != 0) {
                trocar(soma, i, j, resultado);
            }
        }
    }

    return resultado;
}

int main(void)
{
    int l1, c1,l2,c2,n;
    
    scanf("%d %d",&l1,&c1);

    Spa_Mat *m1 = criar(l1,c1);

    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            scanf("%d",&n);
            trocar(n,i,j,m1);
        }
        
    }
    scanf("%d %d",&l2,&c2);

    Spa_Mat *m2 = criar(l2,c2);

    for (int i = 0; i < l2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            scanf("%d",&n);
            trocar(n,i,j,m2);
        }
        
    }
    imprimir(somar_matrizes(m1,m2));

    liberar_matriz(m1);
    liberar_matriz(m2);


    return 0;
}