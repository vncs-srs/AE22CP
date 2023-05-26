
#include <stdio.h>

int bigO(n)
{
    int k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            k++;
    return k;
}

int main() 
{
    int n,entrada;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        scanf("%d",&entrada);
        printf("%d\n",bigO(entrada));
    }

    
    return 0;
}