#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int valor; // simplificado
    struct Nodo *link;
} Nodo;

typedef struct Descritor{
    int tamanho;
    Nodo *inicio;
} descritor;

int insere(descritor *p, Nodo *novo, int pos){
    if(p->tamanho == 0) return 0;
    if(pos < 1 || pos > p->tamanho) return 0;
    
    Nodo *aux = p->inicio;
    if(pos == 1){
        novo->link = p -> inicio;
        p -> inicio = novo;
    }
    else{
        for(int i = 1;i < pos-1;i++){
            aux = aux -> link;
        }

        novo -> link = aux -> link;
        aux -> link = novo;
    }

    p->tamanho++;
    return 1;
}

int main(){

}