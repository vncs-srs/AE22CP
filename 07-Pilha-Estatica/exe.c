
# include <stdio.h>

int multiplica_dois(int a, int b)
{
    return a * b;
}

int multiplica_tres(int x, int y, int z)
{
    return multiplica_dois(x, y) * z;
}


int main()
{
    printf("%d * %d * %d = %d", 4, 5, 3, multiplica_tres(5, 4, 3));
    return 0;
}