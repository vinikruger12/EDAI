#include "arqPE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cheia(struct stack *stk){
    if((stk->topo) >= (stk->tam-1)) return 1;
    return 0;
}

int vazia(struct stack *stk){
    if(stk->topo < 0) return 1;
    return 0;
}

struct stack *cria(int tam){
    struct stack *stk = NULL;
    stk = malloc(sizeof(struct stack));

    if(stk){
        stk->vet = malloc(sizeof(info) * tam);
        if(stk->vet){
            stk->topo = -1;
            stk->tam = tam;
        }
        else{
            free(stk);
            stk = NULL;
        }
    }
    return stk;
}

int empilha(info *reg, struct stack *stk){
    
    if(!cheia(stk)){
        (stk->topo)++;
        memcpy(&(stk->vet[stk->topo]), reg, sizeof(info));
        return 1;    
    }
    return 0;
}

int desempilha(struct stack *stk){
    if(!vazia(stk)){
        (stk->topo)--;
        return 1;
    }
    return 0;
}

int busca(info *reg,struct stack *stk){
    if(!vazia(stk)){
        *reg = stk->vet[stk->topo];
        return 1;
    }
    return 0;
}

struct stack *destroi(struct stack *stk){
    
    if(stk){
        free(stk->vet);
        free(stk);
    }
    return NULL;
}

