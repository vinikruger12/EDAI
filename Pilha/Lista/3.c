#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
} info;

struct Node{
    info dados;
    struct Node *under;
    struct Node *upper;
};

struct stack{
    struct Node *top;
    int stackSize;
};

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

    struct Node *new = NULL, *old = stk->top;
    new = malloc(sizeof(struct Node));

    if(new != NULL){
        memcpy(&(new->dados), reg, sizeof(info));
        new->under = stk->top;
        if(old != NULL) old->upper = new;
        stk->top = new;
        new->upper = NULL;
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

int first(struct stack *stk){
    if(stk == NULL || vazia(stk)) return 0;
    return stk->top->dados.x;
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

    aux = pilha->top;
    while(aux->under != NULL){
        aux = aux->under;
    }

    while(aux != NULL){
        printf("%d \n", aux->dados.x);
        aux = aux->upper;
    }

}
