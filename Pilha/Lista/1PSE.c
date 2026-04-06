#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arqPSE.h"


int buscaNaBase(struct stack *stk, info *reg){
    if(!vazia(stk) && stk != NULL){
        struct Node *aux = stk->top;
        while(aux->under != NULL){
            aux = aux->under;
        }
        memcpy(reg, &(aux->dados), sizeof(info));
        return 1;
    }
    return 0;
}

int main(){
    struct stack *pilha = cria(100);
    info a,b,c,d,e;
    a.x = 4;
    b.x = 5;
    c.x = 6;
    d.x = 7;
    e.x = 8;
    insert(&a, pilha);
    insert(&b, pilha);
    insert(&c, pilha);
    insert(&d, pilha);
    insert(&e, pilha);
    info x;
    buscaNaBase(pilha, &x);
    printf("%d\n", x.x);
}