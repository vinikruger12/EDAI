#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
} info;

struct stack{
    int tam;
    info *vet;
    int topo;
};
int cheia(struct stack *stk);
int vazia(struct stack *stk);
struct stack *cria(int tam);
int empilha(info *reg, struct stack *stk);
int desempilha(struct stack *stk);
int busca(info *reg,struct stack *stk);
struct stack *destroi(struct stack *stk);