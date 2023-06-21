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

int inserir(int key, HashT *t,float c);

int liberar(HashT *t);

static int hashingF(int k, int B,float c);

static int rehash(int k, int B);

static int hashingRH(int hashC, int B, int tentativa, float c);

HashT *criar(unsigned int tam){
    HashT *t = malloc(sizeof(HashT));
    int i;

    t->tam = tam;
    t->buckets = malloc(tam * sizeof(int));

    for (i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}

static int hashingF(int k, int B,float c){
    float val = k * c;
    int intPart = (int)val;
    float decimalPart = val - intPart;

    return (int)(B * decimalPart);
}

static int rehash(int k, int B) {
    return 1 + k % (B - 1);
}

static int hashingRH(int hashC, int B, int tentativa,float c){
    int h1 = hashingF(hashC, B, c);
    int h2 = rehash(hashC, B);

    return (h1 + tentativa * h2) % B;
}

int inserir(int key, HashT *t,float c){
    int x;
    int i=1, rh;

    if ((t != NULL) && (key > 0)){
        x = hashingF(key, t->tam,c); 

        if (t->buckets[x] <= 0){
            t->buckets[x] = key;

            return x;
        }else{  
            rh = x; 

            while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] > 0)){
                rh = hashingRH(x, t->tam, i,c); 
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
    float c;
    int n,key;

    scanf("%f %d",&c,&n);

    HashT *myHT = criar(n);
    int pos[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&key);
        pos[i] = inserir(key,myHT,c);
    }
    for ( int i = 1; i < n; i++)
    {
        printf("%d\n",pos[i]);
    }
    
    liberar(myHT);

    return 0;
}