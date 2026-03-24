#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int valor;
    struct Nodo *link;
} Nodo;

typedef struct Descritor{
    int tamanho;
    Nodo *inicio;
} descritor;

int reinicia(descritor *p){
    if(p == NULL) return 0;
    
    Nodo *aux = p->inicio;
    Nodo *temp;

    while(aux != NULL){ 
        temp = aux;
        aux = aux->link;
        free(temp);
    }

    p->inicio = NULL;
    p->tamanho = 0;
    return 1;
}

int main(){
    descritor lista;
    lista.inicio = NULL;
    lista.tamanho = 0;

    // Criando manualmente 3 nós
    Nodo *n1 = malloc(sizeof(Nodo));
    Nodo *n2 = malloc(sizeof(Nodo));
    Nodo *n3 = malloc(sizeof(Nodo));

    n1->valor = 10;
    n2->valor = 20;
    n3->valor = 30;

    // Encadeando
    n1->link = n2;
    n2->link = n3;
    n3->link = NULL;

    // Atualizando descritor
    lista.inicio = n1;
    lista.tamanho = 3;

    printf("Antes: tamanho = %d\n", lista.tamanho);

    // Chamando reinicia
    int resultado = reinicia(&lista);

    printf("Resultado = %d\n", resultado);
    printf("Depois: tamanho = %d\n", lista.tamanho);
    printf("Inicio = %p\n", lista.inicio);

    return 0;
}