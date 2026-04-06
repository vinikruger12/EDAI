#include <stdio.h>
#include <stdlib.h>
#include "arqPSE.h"
#include <string.h>


int vazia(struct stack *stk){
    return (stk->stackSize == 0 || stk == NULL);
}

struct stack *cria(){
    struct stack *stk = NULL;
    stk = malloc(sizeof(struct stack));
    
    if(stk){
        stk->top = NULL;
        stk->stackSize = 0;
    }
    else return NULL;

    return stk;
}

int insert(info *reg, struct stack *stk){
    if(stk == NULL) return 0;

    struct Node *aux = NULL;
    aux = malloc(sizeof(struct Node));

    if(aux != NULL){
        memcpy(&(aux->dados), reg, sizeof(info));
        aux->under = stk->top;
        stk->top = aux;
        (stk->stackSize)++;
        return 1;
    }
    return 0;
    
}

int pop(struct stack *stk){
    struct Node *aux = NULL;
    if(!vazia(stk)){
        aux = stk->top->under;
        free(stk->top);
        stk->top = aux;
        (stk->stackSize)--;
        return 1;
    }
    return 0;
}

int first(struct stack *stk){
    if(stk == NULL || vazia(stk)) return 0;
    return stk->top->dados;
}

void reset(struct stack *stk){
    while(pop(stk));
}

struct stack *destroy(struct stack *stk){
    if(stk == NULL) return NULL;
    reset(stk);
    free(stk);
    return NULL;
}
