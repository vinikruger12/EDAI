#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
} info;

struct stack{
    int tam;
    info *vet;
    int topo1;
    int topo2;
};

int cheia(struct stack *stk, int n);
int vazia(struct stack *stk, int n);
struct stack *cria(int tam);
int empilha(info *reg, struct stack *stk, int n);
int desempilha(struct stack *stk, int n);
int reinicia(struct stack *stk, int n);
int busca(info *reg,struct stack *stk, int n);
int numeroDeEmpilhados(struct stack *stk, int n);
struct stack *destroi(struct stack *stk);
