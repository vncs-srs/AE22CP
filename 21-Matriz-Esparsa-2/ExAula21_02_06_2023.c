#include<stdio.h>
#include<stdlib.h>

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


// Se existir elemento na posi��o [l][c], retorne o valor. Caso contr�rio, retorne 0 (nulo)
int buscar_pos(int l, int c, Spa_Mat* mat){
    int i;
    Cell *aux;
    int valor = 0;

    if ((mat != NULL) && validar_pos_matriz(l, c, mat)){
        aux = mat->lin[l]->head;

        while ((aux != NULL) && (c < aux->col))
            aux = aux->next;

        if ((aux != NULL) && (c == aux->col))
            valor = aux->item;
    }

    return valor;
}


// Esta fun��o s� � chamada quando item > 0
// Caso a c�lula com coluna col exista, basta mudar o seu respectivo valor. Caso contr�rio,
// deve ser criada uma nova c�lula
static void trocar_inserir_na_lista(int item, int col, ListaE *l){
    Cell *auxA, *auxP, *novo;

    // Verificar se a lista da matriz tem a cabe�a vazia ou a coluna em que a coluna em que
    // haver� inser��o � menor em compara��o com a da primeira c�lula da lista.
    // Caso esse teste retornar verdadeiro, a c�lula ser� inserida na primeira posi��o da lista.
    if ((l->head == NULL) || (col < l->head->col)){
        novo = criar_celula(item, col);
        novo->next = l->head;
        l->head = novo;
    // Se a lista n�o estiver vazia, � verificado se o seu primeiro elemento tem a coluna igual
    // a col. Caso positivo, apenas o valor da c�lula � trocado
    }else if (col == l->head->col){
        l->head->item = item;
    }else{
        auxA = l->head; // a nova c�lula dever� ser colocada entre auxP e auxA
        auxP = auxA;

        // Encontrar uma posi��o adequada para inser��o/troca
        while ((auxP != NULL) && (auxP->col < col)){
            auxA = auxP;
            auxP = auxP->next;
        }

        // Se a coluna col existir, basta trocar o valor de item
        if ((auxP != NULL) && (col == auxP->col))
            auxP->item = item;
        // Caso contr�rio, uma nova c�lula deve ser criada
        else{
            novo = criar_celula(item, col);
            novo->next = auxA->next; // auxP
            auxA->next = novo;
        }
    }
}


// Esta fun��o s� � chamada quando item <= 0
// Caso a c�lula com coluna col exista, basta remover a c�luna. Caso contr�rio, nada � feito.
static void remover_na_lista(int col, ListaE *l){
    Cell *auxA, *auxP = NULL;

    if (l->head != NULL){
    	// Verificar se a c�lula que dever� ser removida � o primeiro elemento da lista.
        if (col == l->head->col){
            auxP = l->head;
            l->head = l->head->next;
            free(auxP);
        }else{
            auxA = l->head;
            auxP = auxA; // Se for feita a remo��o, auxP ser� removida e auxA->next = auxP->next

            // Encontrar uma posi��o adequada para remo��o
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


// Se item for <= 0, uma c�lula poder� ser removida. Caso contr�rio, poder� ocorrer um dos seguintes
// cen�rios:
// 1 - Se a coluna existir na l-�sima lista, a sua respectiva c�lula ter� o seu valor alterado.
// 2 - Caso contr�rio, uma nova c�lula dever� ser criada e inserida de forma ordenada (por coluna)
//     na l-�sima lista
void trocar(int item, int l, int c, Spa_Mat* mat){
    if (validar_pos_matriz(l, c, mat)){
        if (item > 0)
            trocar_inserir_na_lista(item, c, mat->lin[l]);
        else
            remover_na_lista(c, mat->lin[l]);
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

static void inserir_primeiro(ListaE*l , int col, int item)
{
    Cell* nova=criar_celula(item,col);
    nova->next = l->head;
    l->head = nova;
}

Spa_Mat* converter(int **mat, int l, int c){
    int i, j;
    Spa_Mat* me = criar(l, c);
    for (i = 0; i < l; i++)
        for (j = c - 1; j >= 0; j--)
            if (mat[i][j] > 0)
                inserir_primeiro(me->lin[i], j, mat[i][j]);
    return me;
}

int main(void)
{
    int i;
    int **mat = (int**) malloc(3 * sizeof(int*));
    for (i = 0; i < 3; i++)
        mat[i] = (int*) malloc(3 * sizeof(int));

    mat[0][0]=1;
    mat[0][1]=0;
    mat[0][2]=0;
    mat[1][0]=0;
    mat[1][1]=1;
    mat[1][2]=0;
    mat[2][0]=0;
    mat[2][1]=0;
    mat[2][2]=3;

    Spa_Mat *matrix = converter(mat,3,3);

    imprimir(matrix);

    printf("\nExiste o elemento 1? %d\n",buscar(1,matrix));
    printf("\nExiste o elemento 3? %d\n",buscar(3,matrix));

    return 0;
}
