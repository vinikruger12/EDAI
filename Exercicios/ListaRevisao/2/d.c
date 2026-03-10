#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct teste{ 
    int inteiro;
    float real;
    char nome[30];
} informacao;

int main(){
    informacao *p = NULL, x = {321, 2.39, "Silva"};    
    p = &x;
    printf("Campos da variável x: %i, %f, %s\n", (*p).inteiro, p->real, (*p).nome);
}

/*
main(void)
{ informacao *p, x = {321, 2.39, "Silva"};
p = &x;
printf(“Campos da variável x: %i, %f, %s”, p.inteiro, p.real, p.nome);
}
*/