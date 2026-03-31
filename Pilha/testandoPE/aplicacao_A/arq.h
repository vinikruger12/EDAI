#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SIM 1
#define NAO 0
#define SUCESSO 1
#define FRACASSO 0


typedef struct ponto{  	float x;
			float y;
			}info;
			
struct pilha{ int topo;
              info *vet; 
              int tamVet;
                };



			



//======================APLICACAO=====================
void moveDisksBetweenTwoPoles(struct pilha *src,
            struct pilha *dest, char s, char d);

//Function to show the movement of disks
void moveDisk(char fromPeg, char toPeg, int disk);

//Function to implement TOH puzzle
void tohIterative(int num_of_disks, struct pilha
             *src, struct pilha *aux,
             struct pilha *dest);
long int pow_(long int b, long int e);

//======================PILHA=====================
struct pilha * cria(int tamVet);
int cheia(struct pilha *pil);
int vazia(struct pilha *pil);

int empilha(info *reg, struct pilha *pil);
int desempilha(info *reg, struct pilha *pil);
int busca(info *reg, struct pilha *pil);

struct pilha *destroi(struct pilha *pil);
