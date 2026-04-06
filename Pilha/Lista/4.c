#include "arqPDE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inverte(struct stack *stk){
    if(stk == NULL || vazia(stk)) return 0;

    struct Node *aux = stk->top;
    while(aux->under != NULL){
        aux = aux->under;
    }
    stk->top = aux;
    struct Node *aux2 = stk->top;
    
    while(aux2 != NULL){
        struct Node *temp = aux2->under;
        aux2->under = aux2->upper;
        aux2->upper = temp;
        aux2 = aux2->under;
    }
    return 1;
}

int main(){
    struct stack *pilha = cria();
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
    insert(&a, pilha);
    insert(&b, pilha);
    insert(&c, pilha);
    insert(&d, pilha);
    insert(&e, pilha);

    struct Node *aux = pilha->top;
    while(aux != NULL){
        printf("%d \n", aux->dados.x);
        aux = aux->under;
    }

    inverte(pilha);
    aux = pilha->top;
    while(aux != NULL){
        printf("%d \n", aux->dados.x);
        aux = aux->under;
    }
}