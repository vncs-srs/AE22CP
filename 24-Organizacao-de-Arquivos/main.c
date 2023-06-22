#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct{
    long RA;
    char nome[70];
    int codigo_curso;
    float coef;
}Aluno;

void write_bin_file(char * path, Aluno content[], int n){
    FILE * arq = fopen(path, "wb");
    int i = 0;
    if (arq){
        fwrite(content, sizeof(Aluno), n, arq);
        fclose(arq);
}else
    printf("Erro ao gerar o arquivo");
}

void read_bin_file(char * path, Aluno content[], int n){
    FILE * arq = fopen(path, "rb");
    if (arq){
        fread(content, sizeof(Aluno), n, arq);
        fclose(arq);
    }else
        printf("Erro ao abrir o arquivo");
}

int getPosicaoAluno(Aluno Aluno[], int n, char * nome){
    int i;
    for (i = 0; i < n; i++)
        if (strcmp(Aluno[i].nome, nome) == 0)
            return i;
    return -1;
}

void setAluno(char * path, int position, Aluno *aluno){
    FILE * arq = fopen(path, "r+b");
    if (arq){
        fseek(arq, sizeof(Aluno) * (position), SEEK_SET);
        fwrite(aluno, sizeof(Aluno), 1, arq);
        fclose(arq);
    }
}

void write_file(char * path, char * content){
    FILE * arq = fopen(path, "w");
    fputs(content, arq);
    fclose(arq);
}
void append_file(char * path, char * content, unsigned int times){
    FILE * arq = fopen(path, "a");
    int i;
    if (arq){
        for (i = 0; i < times; i++){
            fputs("\n", arq);
            fputs(content, arq);
        }
        fclose(arq);
    }
}
void print_file_content(char * path){
    FILE * arq = fopen(path, "r");
    if (arq==NULL)
    {
        printf("Falha na abertura do arquivo.\n");
    }
    
    char str[100];

    if (arq){
        while (!feof(arq)){
            fgets(str, 100, arq);
            printf("%s", str);
        }

        printf("\n");
        int close = fclose(arq);
        if (close == 0)
            printf("Operacao bem sucedida!\n");
        else
            printf("Falha ao fechar o arquivo.\n");
    }
}

int main()
{
    Aluno Alg1[3]={{111,"AAA",111,0.67},{222,"BBB",222,0.56},{333,"CCC",333,0.89}},Backup[3];
    write_bin_file("test.dat",Alg1,3);
    read_bin_file("test.dat",Backup,3);
    for (int i = 0; i < 3; i++)
    {
        printf("RA: %ld - Nome: %s - Cod. Curso: %d - Coef.: %f\n",Backup[i].RA,Backup[i].nome,Backup[i].codigo_curso,Backup[i].coef);
    }
    int pos = getPosicaoAluno(Alg1,3,"BBB");
    Aluno x = {321,"Bob",123,0.36};
    printf("------\n"); 
    setAluno("test.dat",pos,&x);
    read_bin_file("test.dat",Backup,3);
    for (int i = 0; i < 3; i++)
    {
        printf("RA: %ld - Nome: %s - Cod. Curso: %d - Coef.: %f\n",Backup[i].RA,Backup[i].nome,Backup[i].codigo_curso,Backup[i].coef);
    }
    /*write_file("arquivo.txt","Hoje e dia de chuva");
    append_file("arquivo.txt","A aula de hoje e sobre arquivos",10);
    //print_file_content("/home/user/Downloads/teste.txt");
    print_file_content("teste.txt");
    print_file_content("arquivo.txt");*/

    return 0;
}
