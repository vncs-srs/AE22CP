/*Implemente uma função que verifica se a matriz esparsa é uma matriz triangular, 
onde todos os elementos acima ou abaixo da diagonal principal são obrigatoriamente nulos.

Input Format

Na primeira linha deve ser lido um número inteiro, que representará os números de linhas 
e de colunas (matriz quadrada). Em seguida, uma matriz deve ser lida. Por último, a matriz 
bidimensional deve ser convertida para uma matriz esparsa.

Constraints

Deve ser utilizada uma estrutura de matriz esparsa, como a que foi apresentada em sala de aula.

Será atribuída a nota zero no caso em que a verificação for feita em matriz de inteiros em vez 
de matriz esparsa.

Output Format

Deve ser impresso "triangular" se a matriz for triangular ou "nao triangular", caso contrário.

Sample Input 0
4
1 0 0 0
1 1 0 0
1 1 1 0
1 1 1 1

Sample Output 0
triangular

Sample Input 1
4
1 1 1 1
0 1 1 1
0 0 1 1
0 0 0 1

Sample Output 1
triangular

Sample Input 2
5
0 2 0 1 0
1 0 0 3 1
2 3 0 0 0
1 3 2 0 1
0 0 4 0 1

Sample Output 2
nao triangular*/

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

    }
    printf("\n");
}
int verifica_triangular_sup(Spa_Mat* mat)
{
    for (int i = 0; i < mat->n_lin; i++) 
    {
        Cell *cell = mat->lin[i]->head->next;
        while (cell != NULL) 
        {
            if (i < cell->col && cell->item != 0) 
            {
                return 0;
            }                                    
            cell = cell->next;
        }
    }
    return 1;
}
int verifica_triangular(Spa_Mat* mat)
{

    for (int i = 0; i < mat->n_lin; i++) 
    {
        Cell *cell = mat->lin[i]->head->next;
        while (cell != NULL) 
        {
            if (i > cell->col && cell->item != 0)
            {
                return verifica_triangular_sup(mat);
            }                  
            cell = cell->next;

        }
    }
    return 1;
}

int main(void)
{
    int tam,n;

    scanf("%d",&tam);

        Spa_Mat *matriz = criar(tam,tam);

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            scanf("%d",&n);
            trocar(n,i,j,matriz);
        }
        
    }
    if (verifica_triangular(matriz))
        printf("triangular\n");
    else
        printf("nao triangular\n");


    liberar_matriz(matriz);




    return 0;
}