#include <stdio.h>

// Fatorial iterativo: n!
int fatorial_iter(int n){
    int i, f = 1;
    
    for (i = n; i > 1; i--)
        f *= i;
        
    return f;
}


// farorial recursivo
int fatorial_rec(int n){
    if (n <= 1) // caso base: 0! ou 1!
        return 1;
    else // caso iterativo: n! = n * fatorial(n - 1);
        printf("%d * fatorial_rec(%d)\n",n,n-1);
    	return n * fatorial_rec(n - 1);
}


// Imprimir todos os movimentos da torre de Hanoi de n discos
void hanoi(char de, char para, char via, int n){
    if (n >= 1){ // Caso base: quando n for igual a zero (nada é feito)
        hanoi(de, via, para, n - 1);
        printf("disco %d de %c para %c\n", n, de, para);
        hanoi(via, para, de, n - 1);
    }
}


// Sequência de Fibonacci recursivo
int fib_rec(int n){
    int i, f1, f2, fN;
    
    if (n <= 0) // Caso base 1
        return 0;
    else if (n == 1) // Caso base 2
    	return 1;
    else // Caso iterativo
    	return fib_rec(n - 1) + fib_rec(n - 2);
}


// Sequência de Fibonacci iterativo
int fib_iter(int n){
    int i, f1, f2, fN;
    
    if (n <= 0)
        return 0;
    else{
        f1 = 0; // fib(N - 2)
        f2 = 1; // fib(N - 1)
        fN = 1; // fib(N)
        
        for (i = 2; i <= n; i++){
            fN = f1 + f2;
            f1 = f2;
            f2 = fN;
        }
        
        return fN;
    }
}


// máximo divisor comum iterativo
int mdc_it(int a, int b){
    int c;

    while (b != 0){
        c = b;
        b = a % b;
        a = c;
    }

    return a;
}
    int somatorio_rec(int v[], int i, int m){
    if (i < m)
    return v[i] + somatorio_rec(v, i + 1, m);
    else
    return 0;
    }
    int somatorio(int v[], int m){
    return somatorio_rec(v, 0, m);
    }


int main(){
    /*printf("fatorial_rec(%d)\n",8);
    int resul = fatorial_rec(8);
    printf("resultado fatorial: %d\n",resul);

    int soma,vetor[]={1,1,1,1,1,1,1,1,1,1};
    soma = somatorio(vetor,10);
    printf("resultado somatorio: %d\n",soma);*/

    hanoi('A','C','B',10000);
    return 0;
}
