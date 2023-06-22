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

int buscar(int key, HashT *t,float c){
    int h1 = hashingF(key, t->tam,c); 
    int h2 = rehash(key,t->tam);
    int i, rh;

    if (t->buckets[h1] == key) 
        return h1;
    else if (t->buckets[h1] >= 0){
        i = 1; 
            h2 = 1 + key % (t->tam -1);
            rh = (h1 +i*h2) % t->tam;
    
        while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] >= 0)){
            rh = (h1 +i*h2) % t->tam;
            i++;
        }


        if ((i < t->tam) && (t->buckets[rh] == key))
            return rh;
    }else
        return -1;
    return rh;
}

int inserir(int key, HashT *t,float c){
    int x;
    int i, rh;
    int h1 = hashingF(key, t->tam,c); 
    int h2 = rehash(key,t->tam);



    if ((t != NULL) && (key > 0)){
        x = hashingF(key, t->tam,c); 

        if (t->buckets[x] <= 0){
            t->buckets[x] = key;

            return 1;
        }else{ 
            i = 1; 
 
            h2 = 1 + key % (t->tam -1);
            rh = (h1 +i*h2) % t->tam;
            
            while ((i < t->tam) && (t->buckets[rh] != key) && (t->buckets[rh] > 0)){
                rh = (h1 +i*h2) % t->tam;
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
    int n,key,tam;

    scanf("%f %d",&c,&n);
    scanf("%d",&tam);

    HashT *myHT = criar(n);
    int pos[tam];

    for (int i = 0; i < tam; i++)
    {
        scanf("%d",&key);
        inserir(key,myHT,c);
        pos[i] = buscar(key,myHT,c);
    }
    for ( int i = 0; i < tam; i++)
    {
        printf("%d\n",pos[i]);
    }
    
    liberar(myHT);

    return 0;
}