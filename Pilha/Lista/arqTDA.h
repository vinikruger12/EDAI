#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
} info1;

typedef struct {
    char c;
} info2;

typedef union {
    info1 x;
    info2 c;
} tipo;

struct stack{
    int tamInfo1;
    int tamInfo2;
    int tamVet;
    tipo *vet;
    int topo1;
    int topo2;
};


int cheia(struct stack *stk, int n);
int vazia(struct stack *stk, int n);
struct stack *cria(int tam1, int tam2);
int empilha(tipo *reg, struct stack *stk, int n);
int desempilha(struct stack *stk, int n);
int reinicia(struct stack *stk, int n);
int busca(tipo *reg,struct stack *stk, int n);
int numeroDeEmpilhados(struct stack *stk, int n);
struct stack *destroi(struct stack *stk);


