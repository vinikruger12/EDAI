#include <stdio.h>

typedef struct teste{ 
    int inteiro;
    float real;
    char nome[30];
} informacao;

int main(){
    informacao *p, x = {321, 2.39, "Silva"};
    p = &x;
    if(p != NULL){
        printf("Ponteiro inicializado corretamente! \n");
        printf("Valores da struct X: %i, %f, %s\n", p->inteiro, p->real, p->nome);
    }
    else printf("O ponteiro está anulado!\n");
}

/*
main(void)
{
informacao *p, x = {321, 2.39, "Silva"};
if (p)
{ printf(“ponteiro inicializado corretamente \n”);
printf(“valores da struct X: %i, %f, %s”, p->inteiro, p->real, p→nome);
}
else
printf(“o ponteiro está anulado”);
}
*/