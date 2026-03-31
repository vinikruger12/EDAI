#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SIM 1
#define NAO 0
#define SUCESSO 1
#define FRACASSO 0


typedef struct aluno{  char nome[20];
			int rg;
		}info;
			
struct pilha{ int topo;
              info *vet; 
              int tamVet;
            };





//======================PILHA=====================
struct pilha * cria(int tamVet);
int cheia(struct pilha *pil);
int vazia(struct pilha *pil);

int empilha(info *reg, struct pilha *pil);
int desempilha(info *reg, struct pilha *pil);
int busca(info *reg, struct pilha *pil);

struct pilha *destroi(struct pilha *pil);
