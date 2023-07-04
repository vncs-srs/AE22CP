#include <stdio.h>
#include <stdlib.h>

//Implementação ingênua do bubblesort
void bubblesort(int v[], int n){
	int i, j, x;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (v[j] > v[j + 1]){
				x = v[j];
				v[j] = v[j + 1];
				v[j + 1] = x;
			}
}

//ordenar pares em ordem crescente
void bubblesort_pc(int v[], int n){
	int i, j, x;

    /*for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
            if(v[j]%2==0 || v[j+1]%2==0)
			{
				x = v[j];
				v[j] = v[j + 1];
				v[j + 1] = x;
			}*/
    
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
            
            if(v[j]%2==0 || v[j+1]%2==0)
			if (v[j] > v[j + 1]){
				x = v[j];
				v[j] = v[j + 1];
				v[j + 1] = x;
			}
}

// Melhoria do bubblesort
void bubblesort_V2(int v[], int n){
	int i, j, x, troca = 1;

	for (i = 0; (i < n - 1) && (troca); i++){
		troca = 0;

		for (j = 0; j < n - i - 1; j++)
			if (v[j] > v[j + 1]){
				x = v[j];
				v[j] = v[j + 1];
				v[j + 1] = x;
				troca = 1;
			}
	}
}


// Implementação do selection sort
void selectsort(int v[], int n){
	int i, j, p, aux;
	
	for (i = n - 1; i >= 1;  i--){
		p = i;
	
		for (j = 0; j < i; j++)
			if (v[j] > v[p])
				p = j;
		
		aux = v[i];
		v[i] = v[p];
		v[p] = aux;
	}
}


// Segunda implementação do selection sort
// Provavelmente a forma ordenação simples mais implementada
void selectsort2(int v[], int n){
	int i, j, p, aux;
	
	for (i = 0; i < n - 1;  i++){
		p = i;
	
		for (j = i + 1; j < n; j++)
			if (v[j] < v[p])
				p = j;
		
		if (p != i){
			aux = v[i];
			v[i] = v[p];
			v[p] = aux;
		}
	}
}


// Implementação do método insertion sort
void insertsort_crescente(int v[], int n){
	int i, x,j;

	for (i = 1; i < n; i++){
		x = v[i];
		
		 for (j = i - 1; (j >= 0) && (x  < v[j]); j--)
			v[j + 1] = v[j];

		 v[j + 1] = x;
	}
}

void insertsort_decrescente(int v[], int n){
	int i, x,j;

	for (i = 1; i < n; i++){
		x = v[i];
		
		 for (j = i - 1; (j >= 0) && (x  > v[j]); j--)
			v[j + 1] = v[j];

		 v[j + 1] = x;
	}
}

void ordenaParImpar(int v[], int n);
int contaPares(int v[], int n);
int main(){
    int v[]={4,32,34,543,3456,654,567,87,6789,98};
    
    printf("           Original:   ");
    for(int i=0;i<10;i++)
        printf("%d ",v[i]);
    printf("\n");
    
    ordenaParImpar(v, 10);
    
    /*printf("Resul. ordenaParImpar: ");
    for(int i=0;i<10;i++)
        printf("%d ",v[i]);
    printf("\n");*/
    
    return 0;
}

void ordenaParImpar(int v[], int n){ // O(4n + 2n^2) = O(n^2)
  int nP = contaPares(v,n);  // O(1) + O(n) = O(n + 1) = O(n)
  int nI = n - nP;           // O(1)
  
  int vP[nP], vI[nI], i, iP=0,iI=0;   // O(2)
  for(int i=0;i<n;i++)               // O(1 + 5n + 1 ) = O(5n +2) = O(n)
      if(v[i]%2==1){     //O(1)
          vI[iI] = v[i];  //O(1)
          iI++;          //O(1)
      }
      else{
          vP[iP] = v[i]; //O(1)
          iP++;          //O(1)
      }
  insertsort_crescente(vP, nP); //O((n/2)^2)  = O(n^2)
  insertsort_decrescente(vI, nI); //O((n/2)^2) = O(n^2)
  
  for(int i=0;i<nP;i++)    //O(1+ (n/2)*3 + 1) = O(n)
      printf("%d\n",vP[i]);  //O(1)
  for(int i=0;i<nI;i++)      //O(1+ (n/2)*3 + 1) = O(n)
      printf("%d\n",vI[i]);  //O(1)

  return;
}
int contaPares(int v[], int n){  //O(4n + 5) = O(n)
    int cont=0;          // O(1)
    for(int i=0;i<n;i++) // O(1+ 4n + 1)
        if(v[i]%2==0)    //O(1)
            cont++;     // O(1)
    return cont;
}
