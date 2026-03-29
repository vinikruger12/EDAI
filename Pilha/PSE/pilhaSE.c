#include <stdio.h>
#include <stdlib.h>

struct Node{
    int dados;
    struct Node *under;
};

struct stack{
    struct Node *top;
    int stackSize;
};

int vazia(struct stack *stk){
    return stk->stackSize == 0;
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

int insert(int n, struct stack *stk){
    if(stk == NULL) return 0;

    struct Node *aux = NULL;
    aux = malloc(sizeof(struct Node));

    if(aux != NULL){
        aux->dados = n;
        aux->under = stk->top;
        stk->top = aux;
        (stk->stackSize)++;
        return 1;
    }
    return 0;
    
}


int main(){

}