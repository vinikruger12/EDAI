#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arqPSE.h"

int contaNos(struct stack *stk){
    int n = 0;
    if(stk == NULL || vazia(stk)) return 0;

    struct Node *aux = stk->top;
    while(aux != NULL){
        n++;
        aux = aux->under;
    }
    return n;

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
    printf("A pilha tem %d nós\n", contaNos(pilha));
}