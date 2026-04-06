#include "arqTDA.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    struct stack *p = cria(5, 5);

    tipo a, b, c, d, e;

    a.x.x = 10;
    b.x.x = 20;
    c.x.x = 30;

    empilha(&a, p, 1);
    empilha(&b, p, 1);
    empilha(&c, p, 1);

    d.c.c = 'A';
    e.c.c = 'B';

    empilha(&d, p, 2);
    empilha(&e, p, 2);

    tipo aux;

    printf("Topo pilha 1: ");
    if(busca(&aux, p, 1)) printf("%d\n", aux.x.x);

    printf("Topo pilha 2: ");
    if(busca(&aux, p, 2)) printf("%c\n", aux.c.c);

    printf("Qtd pilha 1: %d\n", numeroDeEmpilhados(p, 1));
    printf("Qtd pilha 2: %d\n", numeroDeEmpilhados(p, 2));

    printf("\nDesempilhando pilha 1:\n");
    while(!vazia(p,1)){
        busca(&aux, p, 1);
        printf("%d\n", aux.x.x);
        desempilha(p,1);
    }

    printf("\nDesempilhando pilha 2:\n");
    while(!vazia(p,2)){
        busca(&aux, p, 2);
        printf("%c\n", aux.c.c);
        desempilha(p,2);
    }

    destroi(p);
    return 0;
}