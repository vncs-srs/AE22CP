#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Exemplo de algoritmo de ordenação linear
void counting_sort(int *A, int *B, int n, int k){
    int i, j, C[k+1];

    for (i = 0; i <= k; i++)
        C[i] = 0;

    for (j = 0; j < n; j++){
        C[A[j]] = C[A[j]] + 1; //printf("\nC[A[%d]]++ C[%d]=%d",j,A[j],C[A[j]]);
    }   
    printf("\nC[]="); for(int t=0;t<=k;t++)printf("%d ",C[t]);
    // Para cada i = {0, 1, ..., k}, aqui é determinado
    // quantos elementos são menores ou iguais a "i"
    for (i = 1; i <= k; i++)
        C[i] += C[i - 1];
    
    printf("\nC[]="); for(int t=0;t<=k;t++)printf("%d ",C[t]);
    for (j = n - 1; j >= 0; j--){
        B[C[A[j]]-1] = A[j];  printf("\nB[C[A[j]]-1] = B[C[A[%d]]-1] = B[C[%d]]-1] = B[%d] = %d",j,A[j]-1,C[A[j]]-1,A[j]);
        C[A[j]]--;
    }
    printf("\nC[]="); for(int t=0;t<=k;t++)printf("%d ",C[t]);
}


//Ordenação de strings
//************************************************

// Outrar versão do compara_char: #define comparar2(c1, c2) c1 == c2 ? 0 : c1 < c2 ? -1 : 1
int comparar_char(char c1, char c2){
    if (c1 == c2) return 0;
    else if (c1 < c2) return -1;
    else return 1;
}


int comparar(char s1[], char s2[]){
	int i;

	for (i = 0; (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++);

	return comparar_char(s1[i], s2[i]);
}


void troca(char **vstr, int p1, int p2){
    char *str;

    str = vstr[p1];
    vstr[p1] = vstr[p2];
    vstr[p2] = str;
}


void bubblesort(char **vstr, int n){
    int i, j, t = 1;

    for (i = 0; (i < n - 1) && t; i++){
        t = 0;

    for (j = 0; j < n - i - 1; j++)
        if (comparar(vstr[j], vstr[j + 1]) > 0){
            troca(vstr, j, j + 1);
            t = 1;
        }
    }
}


void quicksort(char **vstr, int n_cima, int n_baixo){
    int i = n_cima, j = n_baixo;
    char *pivo = vstr[(i + j) / 2];

    do{
        while ((comparar(vstr[i], pivo) < 0) && (i < j))
            i++;

        while ((comparar(vstr[j], pivo) > 0) && (j > i))
            j--;

        if (i <= j){
            troca(vstr, i, j);
            i++;
            j--;
        }
    }while (i <= j);

	if (j > n_cima)
		quicksort(vstr, n_cima, j);
	if (i < n_baixo)
		quicksort(vstr, i, n_baixo);
}


void imprimir_vet_str(char **vstr, int n){
    int i;

    for (i = 0; i < n; i++)
        printf("%s\n", vstr[i]);
}


int main(){
    /*----------------------[]*/
    int A[]={2,4,3,1,2,3,1,3}, B[8];
    
    counting_sort(A,B,8,5);
    printf("\n");
    printf("A: ");
    for(int i=0;i<8;i++)
        printf("%d ",A[i]);
    printf("\n");
    printf("B: ");
    for(int i=0;i<8;i++)printf("%d ",B[i]);
    /*[]----------------------*/
    
    /*----------------------[]
    int i;
    char **vstr = (char**) malloc(6 * sizeof(char*));

    for (i = 0; i < 6; i++)
        vstr[i] = (char*) malloc(5 * sizeof(char));

    strcpy(vstr[0], "fabio");
    strcpy(vstr[1], "elzae");
    strcpy(vstr[2], "dulci");
    strcpy(vstr[3], "claud");
    strcpy(vstr[4], "beatr");
    strcpy(vstr[5], "analu");

    printf("---------\nAntes:\n");
    imprimir_vet_str(vstr, 6);
    printf("---------\nDepois:\n");

    quicksort(vstr, 0, 5);
    //bubblesort(vstr, 6);

    imprimir_vet_str(vstr, 6);
    
    /*----------------------[]*/
    return 0;
}
