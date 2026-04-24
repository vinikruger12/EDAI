#include "arqPDE.h"
#include <stdlib.h>
#include <stdio.h>
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

    struct Node *novo = NULL, *old = stk->top;
    novo = malloc(sizeof(struct Node));

    if(novo != NULL){
        memcpy(&(novo->dados), reg, sizeof(info));
        novo->under = stk->top;
        if(old != NULL) old->upper = novo;
        stk->top = novo;
        novo->upper = NULL;
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
        if(aux != NULL) aux->upper = NULL;
        (stk->stackSize)--;
        return 1;
    }
    return 0;
}

info first(struct stack *stk){
    info reg = {-1,-1};
    if(stk == NULL || vazia(stk)) return reg;
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
