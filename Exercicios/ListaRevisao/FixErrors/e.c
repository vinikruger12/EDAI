#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct teste{ 
    int inteiro;
    float real;
    char nome[30];
} informacao;

int main(){
    informacao *p, x = {321, 2.39, "Silva"};
    p = malloc(sizeof(informacao));
    p->inteiro = x.inteiro;
    p->real = x.real;
    strcpy(p->nome, x.nome);
    printf("Campos da variável x: %i, %f, %s\n", p->inteiro, p->real, p->nome);
}

/*
main(void)
{ informacao *p, x = {321, 2.39, "Silva"};
p= (struct teste *) malloc(sizeof(struct teste));
p=&x;
printf(“Campos da variável x: %i, %f, %s”, p->inteiro, p->real, p->nome);
}
*/