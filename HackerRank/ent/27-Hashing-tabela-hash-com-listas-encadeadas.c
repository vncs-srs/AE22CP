/*Implemente um TAD para hashing estático aberto, onde as colisões devem ser resolvidas por meio de listas
encadeadas ordenadas. A função hash deve ser resto de divisão, ou seja, h(k) = k % B, onde k é uma chave 
e B é o tamanho da tabela hash.

Input Format

Na primeira linha deve ser lido o tamanho da tabela hash. Na segunda linha deve ser lida a quantidade de 
chaves que serão alocadas. Por fim, devem ser lidas as chaves que serão alocadas na tabela hash.

Constraints
.
Output Format

Imprimir as posições onde as chaves foram colocadas na tabela. Em seguida, imprimir a tabela hash inteira. 
Para isso, deve ser considerado o seguinte formato: "linha_i: -> item_0 -> item_1 -> ... -> item_n"

Caso a i-ésima linha da matriz esparsa seja nula, basta imprimir "linha_i -> ".

Sample Input 0
10
10
1
2
5
10
13
20
11
18
12
22

Sample Output 0
1
2
5
0
3
0
1
8
2
2

0: -> 10 -> 20
1: -> 1 -> 11
2: -> 2 -> 12 -> 22
3: -> 13
4: -> 
5: -> 5
6: -> 
7: -> 
8: -> 18
9: -> */

#include <stdio.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct Cell{
    unsigned int tam;
    int item;
    Cell *next;
}Cell;

typedef struct{
    int tam;
    Cell **buckets;
}HashT;


HashT *criar(unsigned int tam);

Cell* criar_celula(int key);

int buscar(int key, HashT *t);

int inserir(int key, HashT *t);

int remover(int key, HashT *t);

void imprimir(HashT *t);

int liberar(HashT *t);

HashT *criar(unsigned int tam){
    HashT *t = malloc(sizeof(HashT));

    t->tam = tam;
    t->buckets = calloc(tam, sizeof(Cell*));

    return t;
}
/*HashT *criar(unsigned int tam){
    HashT *t = malloc(sizeof(HashT));
    int i;

    t->tam = tam;
    t->buckets = malloc(tam * sizeof(int));

    for (i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}*/

int hashingF(int k, int B){
    return k % B;
}

static int overflow_prog(int hashC, int B, int tentativa){
    return (hashC + tentativa) % B;
}


int inserir(int key, HashT *t){
    int x = hashingF(key, t->tam);
    Cell *n_cell = criar_celula(key);

    if (t->buckets[x] == NULL) {
        t->buckets[x] = n_cell;
        return x;
    } else {
        Cell *cell = t->buckets[x];
        Cell *prev = NULL;
        while (cell != NULL && cell->item < key) {
            prev = cell;
            cell = cell->next;
        }
        if (prev == NULL) {
            n_cell->next = cell;
            t->buckets[x] = n_cell;
        } else {
            n_cell->next = cell;
            prev->next = n_cell;
        }
        
    }
    return x;
}
/*int inserir(int key, HashT *t){
    int x;
    int i, rh;

    if ((t != NULL) && (key > 0)){
        x = hashingF(key, t->tam); 
        if (t->buckets[x] <= 0){
            t->buckets[x] = key;

            return x;
        }else{ 
            //i = 1; 
            rh = x; 

            while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] > 0)){
                rh = overflow_prog(x, t->tam, i); 

                i++; 
            }

            if ((i < t->tam) && (t->buckets[rh] <= 0)){
                t->buckets[rh] = key;

                return rh;
            }
        }
    }

    return x;
}*/

Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


void imprimir(HashT *t) {
    for (int i = 0; i < t->tam; i++) {
        printf("%d: ", i);
        //if (t->buckets[i] != NULL) {
            Cell *cell = t->buckets[i];
            while (cell != NULL) {
                printf("-> ");
                printf("%d ", cell->item);
                cell = cell->next;
            }
        //}
        printf("\n");
    }
}
/*void imprimir(HashT *t){
    int i;¨
    if (t != NULL)
    {
        for (i = 0; i < t->tam; i++)
        {
            printf("%d: -> ",i);
            if (t->buckets[i] > 0)
            {
                printf("%d ", t->buckets[i]);
            }
            printf("\n");
        }
    }
}*/

int liberar(HashT *t){
        for (int i = 0; i < t->tam; i++) 
        {
        Cell *c = t->buckets[i];
        while (c != NULL) 
        {
            Cell *aux = c;
            c = c->next;
            free(aux);
        }
    }
    free(t->buckets);
    free(t);

    /*if (t != NULL){
        free(t->buckets);

        free(t);

        return 1;
    }

    return 0;*/
}



int main(void)
{
    int tam, nkey,key;

    scanf("%d",&tam);
    scanf("%d",&nkey);

    int pos[nkey];
    HashT *myHT =criar(tam);

    for (int i = 0; i < nkey; i++)
    {
        scanf("%d",&key);
        pos[i]=inserir(key,myHT);
    }
    for (int i = 0; i < nkey; i++)
    {
        printf("%d\n",pos[i]);
    }
    printf("\n");

    imprimir(myHT);

    liberar(myHT);
    

    return 0;
}