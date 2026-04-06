#include "arqTDA.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cheia(struct stack *stk, int n){
    if(stk->topo1 + 1 == stk->topo2) return 1;
    return 0;
}

int vazia(struct stack *stk, int n){
    if(n == 1) if(stk->topo1 < 0) return 1;
    if(n == 2) if(stk->topo2 == stk->tamInfo2) return 1;
    return 0;
}

struct stack *cria(int tam1, int tam2){
    struct stack *stk = NULL;
    stk = malloc(sizeof(struct stack));

    if(stk){
        stk->vet = malloc(sizeof(tipo) * (tam1 + tam2));
        if(stk->vet){
            stk->topo1 = -1;
            stk->topo2 = tam1 + tam2;
            stk->tamInfo1 = tam1;
            stk->tamInfo2 = tam2 + tam1;
            stk->tamVet = tam1 + tam2;
        }
        else{
            free(stk);
            stk = NULL;
        }
    }
    return stk;
}

int empilha(tipo *reg, struct stack *stk, int n){
    
    if(n == 1 && !cheia(stk, 1)){
        (stk->topo1)++;
        memcpy(&(stk->vet[stk->topo1]), reg, sizeof(tipo));
        return 1;    
    }
    else if(n == 2 && !cheia(stk, 2)){
        (stk->topo2)--;
        memcpy(&(stk->vet[stk->topo2]), reg, sizeof(tipo));
        return 1;
    }
    return 0;
}

int desempilha(struct stack *stk, int n){
    if(n == 1 && !vazia(stk, 1)){
        (stk->topo1)--;
        return 1;
    }
    else if(n == 2 && !vazia(stk, 2)){
        (stk->topo2)++;
        return 1;
    }
    return 0;
}

int reinicia(struct stack *stk, int n){
    if(stk == NULL) return 0;

    if(n == 1) stk->topo1 = -1;
    else if(n == 2) stk->topo2 = stk->tamVet;
    else{
        stk->topo1 = -1;
        stk->topo2 = stk->tamVet;
    }

    return 1;
}

int busca(tipo *reg,struct stack *stk, int n){
    if(n == 1){
        if(!vazia(stk, 1)){
            *reg = stk->vet[stk->topo1];
            return 1;
        }
    }
    else if(n == 2){
        if(!vazia(stk, 2)){
            *reg = stk->vet[stk->topo2];
            return 1;
        }
    }
    return 0;
}

int numeroDeEmpilhados(struct stack *stk, int n){
    if(stk == NULL || vazia(stk, n)) return 0;
    
    if(n == 1) return stk->topo1 + 1;
    if(n == 2) return (stk->tamVet - stk->topo2);  
    
    return 0;
}

struct stack *destroi(struct stack *stk){
    
    if(stk){
        free(stk->vet);
        free(stk);
    }
    return NULL;
}

