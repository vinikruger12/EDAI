#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
} info;


struct Node{
    int dados;
    struct Node *under;
};

struct stack{
    struct Node *top;
    int stackSize;
};

int vazia(struct stack *stk);
struct stack *cria();
int insert(info *reg, struct stack *stk);
int pop(struct stack *stk);
int first(struct stack *stk);
void reset(struct stack *stk);
struct stack *destroy(struct stack *stk);
