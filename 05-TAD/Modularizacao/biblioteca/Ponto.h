/* arquivo Ponto.h */
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<math.h>
typedef struct ponto Ponto;
Ponto* criar(float x, float y);
int acessar(Ponto *p, float *x, float *y);
int alterar(Ponto *p, float x, float y);
float ponto_x(Ponto *p);
float ponto_y(Ponto *p);
void imprimir_ponto(Ponto *p);
float distancia(Ponto *p1, Ponto *p2);
