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


int main(){
    struct stack *stk = cria();
    if(stk == NULL){
        printf("Erro ao criar pilha!\n");
        return 1;
    }

    insert(10, stk);
    insert(20, stk); 
    insert(30, stk);


    while(!vazia(stk)){
        printf("Tamanho da pilha %d\n", stk->stackSize);
        printf("%d\n", first(stk));
        pop(stk);
    }

    destroy(stk);

}
