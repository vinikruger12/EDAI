#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arqPE.h"


int buscaNaBase(struct stack *stk, info *reg){
    if(stk != NULL && stk->topo != -1){
        memcpy(reg, &(stk->vet[0]), sizeof(info));
        return 1;
    } 
    return 0;
}

int main(){
    struct stack *pilha = cria(100);
    info a,b;
    a.x = 1;
    b.x = 2;
    empilha(&a, pilha);
    empilha(&b, pilha);
    info x;
    buscaNaBase(pilha, &x);
    printf("%d\n", x.x);
}