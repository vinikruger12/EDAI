#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int i;
    int j;
} info;

typedef struct {
    info *vetFila;
    int tamVetor;
    int frente; /* indexa o início da Fila */
    int cauda; /*indexa o final da Fila */
    int tamanhoDaFila; /*num de elementos*/
} Fila;

Fila * cria(int tamVet, int tam);
Fila * destroi(Fila *p);
int buscaNaFrente(Fila *p, info *reg);
int buscaNaCauda(Fila *p, info *reg);
int testaVazia(Fila *p);
int testaCheia(Fila *p);
int reinicializa(Fila *p);
int enfileira(Fila *p, info *novo);
int desenfileira(Fila *p, info *reg); 