#include <stdio.h>

void imprime_vetor(float m[][2],int lin , int col)
{
    int i,j;
    for ( i = 0; i < lin; i++)
    {
        for ( j = 0; j < col; j++)
        {
            printf ("%.1f ",m[i][j]);
        }
        printf("\n");
    }
    
}

int main(void)
{
    float  m[3][2] = {{1.5 , 2.7}, {3.4, 4.8},{5.2, 6.6}};

    imprime_vetor(m,3,2);

    return 0;
}