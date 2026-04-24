#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
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

int vazia(struct stack *stk);
struct stack *cria();
int insert(info *reg, struct stack *stk);
int pop(struct stack *stk);
info first(struct stack *stk);
void reset(struct stack *stk);
struct stack *destroy(struct stack *stk);
