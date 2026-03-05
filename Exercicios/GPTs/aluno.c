#include <stdio.h>

struct Aluno{
    char nome[20];
    float nota;
};

int main(){
    struct Aluno aluno = {"Vinicius", 10};
    struct Aluno *p = &aluno;
    p->nota = 1000;
    printf("%s tirou %f\n", aluno.nome, aluno.nota);
}