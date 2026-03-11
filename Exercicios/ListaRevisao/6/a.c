#include <stdio.h>

struct nodo{ 
    int x;
    struct nodo *link;
};

int contaNodo(struct nodo *p){
    if(p != NULL) return 1 + contaNodo(p->link);
    else return 0;
}

int main(){
    struct nodo n1, n2, n3;
    n1.x = 1;
    n1.link = &n2;

    n2.x = 2;
    n2.link = &n3;

    n3.x = 3;
    n3.link = NULL;

    struct nodo *p = &n1;

    printf("O número de nós é %d\n", contaNodo(p));
}