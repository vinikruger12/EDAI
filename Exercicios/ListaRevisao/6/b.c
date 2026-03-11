#include <stdio.h>

struct nodo{ 
    int x;
    struct nodo *link;
};

int contaNodo(struct nodo *p){
    int x = 0;
    struct nodo *inicio = p;
    while(p != NULL){
        x++;
        if(p->link == inicio) break;
        p = p->link;
    }
    return x;
}


int main(){
    struct nodo n1, n2, n3, n4;

    n1.x = 1;
    n1.link = &n2;

    n2.x = 2;
    n2.link = &n3;

    n3.x = 3;
    n3.link = &n4;

    n4.x = 4;
    n4.link = &n1;

    struct nodo *p = &n1;

    printf("O número de nós é %d\n", contaNodo(p));

}