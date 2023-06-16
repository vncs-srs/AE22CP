/*Implemente um TAD para hashing estático fechado utilizando as seguintes abordagens vistas para a sala 
de aula: -> função hash: método da multiplicação -> rehash: segunda função hash --> h1(k) = método da 
multiplicação --> h2(k) = 1 + k % (B - 1) --> rh(k, i) = (h1(k) + i * h2(k)) % B

Input Format

Na primeira linha devem ser lidos a constante c considerada na alocação de chaves (tipo float), sendo 
que 0 < c < 1 e o tamanho n da tabela hash (tipo int). Na segunda linha deve ser lida a quantidade de 
chaves que serão alocadas. Por fim, devem ser lidas as chaves que serão alocadas na tabela hash.

Constraints
.
Output Format

Imprimir a posição onde cada chave foi alocada.

Sample Input 0
0.1 10
8
1
2
5
10
13
20
11
18

Sample Output 0
1
2
5
0
3
6
4
8*/


#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned int tam;
    int *buckets;
}HashT;

HashT *criar(unsigned int tam);

HashT *criar(unsigned int tam){
    HashT *t = malloc(sizeof(HashT));
    int i;

    t->tam = tam;
    t->buckets = malloc(tam * sizeof(int));

    for (i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}

int buscar(int key, HashT *t);

int inserir(int key, HashT *t);

int remover(int key, HashT *t);

void imprimir(HashT *t);

int liberar(HashT *t);

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

            return 1;
        }else{ 
            i = 1; 
            rh = x; 

            while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] > 0)){
                rh = overflow_prog(x, t->tam, i); 

                i++; 
            }

            if ((i < t->tam) && (t->buckets[rh] <= 0)){
                t->buckets[rh] = key;

                return 1;
            }
        }
    }

    return 0;
}

int remover(int key, HashT *t){
    int x;

    if (t != NULL){
        x = buscar(key, t);

        if (t->buckets[x] == key){
            t->buckets[x] = -1;

            return 1;
        }
    }

    return 0;
}

void imprimir(HashT *t){
    int i;
    if (t != NULL){
        for (i = 0; i < t->tam; i++)
            if (t->buckets[i] >= 0)
                printf("%d\n", t->buckets[i]);
        
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

multiplica_hash(float c,int chave)
{

}

int main(void)
{
    float c;
    int n,key;

    scanf("%f %d",&c,&n);

    HashT *myHT = criar(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&key);
        inserir(key,myHT);
    }
    

    return 0;
}