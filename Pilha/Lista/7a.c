#include "arqPME.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    struct stack *p = cria(10);

    info a = {1}, b = {2}, c = {3}, d = {4}, e = {5};

    empilha(&a, p, 1);
    empilha(&b, p, 1);
    empilha(&c, p, 1);

    empilha(&d, p, 2);
    empilha(&e, p, 2);

    printf("Topo pilha 1: ");
    info x;
    if(busca(&x, p, 1)) printf("%d\n", x.x);

    printf("Topo pilha 2: ");
    if(busca(&x, p, 2)) printf("%d\n", x.x);

    printf("Qtd pilha 1: %d\n", numeroDeEmpilhados(p, 1));
    printf("Qtd pilha 2: %d\n", numeroDeEmpilhados(p, 2));

    printf("\nDesempilhando pilha 1:\n");
    while(!vazia(p,1)){
        busca(&x, p, 1);
        printf("%d\n", x.x);
        desempilha(p,1);
    }

    printf("\nDesempilhando pilha 2:\n");
    while(!vazia(p,2)){
        busca(&x, p, 2);
        printf("%d\n", x.x);
        desempilha(p,2);
    }

    destroi(p);
    return 0;
}
