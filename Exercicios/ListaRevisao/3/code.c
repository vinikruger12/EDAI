#include <stdio.h>

typedef struct nodados{
    int tamInfo;
    struct nodados *pt;
} NoDados;

int main(){
    NoDados *p = NULL, a = {123, NULL};
    NoDados *q = NULL, b = {321, NULL};
    p = &a;
    q = &b;
    p->pt = q;
    q->pt = q;
}