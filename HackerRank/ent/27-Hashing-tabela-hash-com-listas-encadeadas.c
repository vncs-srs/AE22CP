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

typedef struct{
    unsigned int tam;
    int *buckets;
}HashT;


HashT *criar(unsigned int tam);

int buscar(int key, HashT *t);

int inserir(int key, HashT *t);

int remover(int key, HashT *t);

void imprimir(HashT *t);

int liberar(HashT *t);

HashT *criar(unsigned int tam){
    HashT *t = malloc(sizeof(HashT));
    int i;

    t->tam = tam;
    t->buckets = malloc(tam * sizeof(int));

    for (i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}

static int hashingF(int k, int B){
    return k % B;
}

static int overflow_prog(int hashC, int B, int tentativa){
    return (hashC + tentativa) % B;
}

int buscar(int key, HashT *t){
    int x = hashingF(key, t->tam); 
    int i, rh;

    if (t->buckets[x] == key) 
        return x;
    else if (t->buckets[x] >= 0){ 
        i = 1; 
        rh = x; 

        while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] >= 0)){
            rh = overflow_prog(x, t->tam, i); 

            i++; 
        }

        if ((i < t->tam) && (t->buckets[rh] == key))
            return rh;
    }else
        return -1;
}

int inserir(int key, HashT *t){
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
}

int remover(int key, HashT *t){
    int x;

    if (t != NULL){
        x = buscar(key, t); 

        if (x >= 0){
            t->buckets[x] = 0;

            return 1;
        }
    }

    return 0;
}

void imprimir(HashT *t){
    int i;
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
}

int liberar(HashT *t){
    if (t != NULL){
        free(t->buckets);

        free(t);

        return 1;
    }

    return 0;
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