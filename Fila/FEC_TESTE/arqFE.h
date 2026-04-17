#include <stdlib.h>
#include <stdio.h>



typedef struct {
    int *vetFila;
    int tamVetor;
    int frente;
    int cauda; 
    int tamanhoDaFila; 
} Fila;


Fila *cria(int tamVet);
Fila *destroi(Fila *p);
int buscaNaFrente(Fila *p);
int buscaNaCauda(Fila *p);
int testaVazia(Fila *p);
int testaCheia(Fila *p);
int reinicializa(Fila *p);
int enfileira(Fila *p, int *novo);
int desenfileira(Fila *p, int *reg);