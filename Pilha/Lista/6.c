#include "arqPE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numeroDeEmpilhados(struct stack *stk){
    if(stk == NULL || vazia(stk)) return 0;
    return stk->topo + 1;  
}

int main(){
    struct stack *pilha = cria(100);
    if(pilha == NULL){
        printf("Erro ao criar pilha!\n");
        return 1;
    }

    info a,b,c,d,e;
    a.x = 4;
    b.x = 5;
    c.x = 6;
    d.x = 7;
    e.x = 8;
    empilha(&a, pilha);
    empilha(&b, pilha);
    empilha(&c, pilha);
    empilha(&d, pilha);
    empilha(&e, pilha);
    printf("A pilha tem %d nós\n", numeroDeEmpilhados(pilha));
}