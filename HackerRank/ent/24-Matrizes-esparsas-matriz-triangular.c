/*Implemente uma função que verifica se a matriz esparsa é uma matriz triangular, 
onde todos os elementos acima ou abaixo da diagonal principal são obrigatoriamente nulos.

Input Format

Na primeira linha deve ser lido um número inteiro, que representará os números de linhas 
e de colunas (matriz quadrada). Em seguida, uma matriz deve ser lida. Por último, a matriz 
bidimensional deve ser convertida para uma matriz esparsa.

Constraints

Deve ser utilizada uma estrutura de matriz esparsa, como a que foi apresentada em sala de aula.

Será atribuída a nota zero no caso em que a verificação for feita em matriz de inteiros em vez 
de matriz esparsa.

Output Format

Deve ser impresso "triangular" se a matriz for triangular ou "nao triangular", caso contrário.

Sample Input 0
4
1 0 0 0
1 1 0 0
1 1 1 0
1 1 1 1

Sample Output 0
triangular

Sample Input 1
4
1 1 1 1
0 1 1 1
0 0 1 1
0 0 0 1

Sample Output 1
triangular

Sample Input 2
5
0 2 0 1 0
1 0 0 3 1
2 3 0 0 0
1 3 2 0 1
0 0 4 0 1

Sample Output 2
nao triangular*/