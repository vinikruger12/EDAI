#include "arqPSE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inverte(struct stack *stk){
    if(stk == NULL || stk->top == NULL) return 0;

    struct Node *atual = stk->top;
    struct Node *prox = NULL;
    struct Node *ant = NULL;

    while(atual != NULL){
        prox = atual->under;
        atual->under = ant;
        ant = atual;
        atual = prox;
    }

    stk->top = ant;

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
    inverte(pilha);
    while(!vazia(pilha)){
        printf("%d\n", first(pilha));
        pop(pilha);
    }
}