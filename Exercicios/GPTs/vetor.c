#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno{
    char nome[20];
    float nota;
};

int main(){
    printf("Digite quantos alunos você quer cadastrar: \n");
    int nAlunos;
    scanf("%d", &nAlunos);

    struct Aluno *alunos;
    alunos = malloc(sizeof(struct Aluno) * nAlunos);

    for(int i = 0;i < nAlunos;i++){
        printf("Digite o nome do aluno número %d\n", i);
        char nomeAluno[20];
        scanf("%s", nomeAluno);

        printf("Digite a nota do aluno número %d\n", i);
        float notaAluno;
        scanf("%f", &notaAluno);

        strcpy((alunos+i)->nome, nomeAluno);
        (alunos+i)->nota = notaAluno;
    }

    float media = 0;
    float x = 0;
    char alunoTop[20];
    for(int i = 0;i < nAlunos;i++){
        printf("Aluno %s tirou %f\n", (alunos+i)->nome, (alunos+i)->nota);
        media += (alunos+i)->nota;

        if((alunos+i)->nota > x){
            x = (alunos+i)->nota;
            strcpy(alunoTop, (alunos+i)->nome);
        }

    }

    printf("A média dos alunos foi %f\n", media/nAlunos);
    printf("O aluno com a maior nota foi o %s\n", alunoTop);
}   