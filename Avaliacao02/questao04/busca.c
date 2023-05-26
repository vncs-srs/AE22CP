#include <stdio.h>
#include "listaE.c"
#include "listaE.h"

int busca_sequencial(int x, int v[], int n,ListaE *l){
	int i;

	for (i = 0; i < n; i++)
		if (x == v[i])
			inserir_ordenado(i,l); // inserir ordenado corrigido 

	l = NULL;
}


static int busca_bin(int x, int v[], int ini, int fim,ListaE *l){
	int meio;


	if ((ini == fim) && (x == v[ini]))
		return ini;

	else if (ini < fim){
		
		meio = (ini + fim) / 2;

	
		if (x == v[meio])
			inserir_ordenado(meio,l);

		else if (x < v[meio])
			return busca_bin(x, v, ini, meio - 1,l);

		else
			return busca_bin(x, v, meio + 1, fim,l);
	}else
		l = NULL;
}


int busca_binaria(int x, int v[] , int n,ListaE *l){
	return busca_bin(x, v, 0, n - 1,l);
}

int main(void)
{
    ListaE *l1= criar_listaE();
    ListaE *l2= criar_listaE();

    int tam,key,i;

    scanf("%d",&tam); //Tamanho da arry

    int v[tam];

    for ( i = 0; i < tam; i++)
    {
        scanf("%d",&v[i]);//Entrada de dados
    }

    scanf("%d",&key);// chave a ser procurada 

    busca_binaria(key,v,tam,l1);
    busca_sequencial(key,v,tam,l2);


    imprimir(l1);
    imprimir(l2);

    liberar_LE(l1);
    liberar_LE(l2);
   
    

    return 0;
}