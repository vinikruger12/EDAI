#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SIM 1
#define NAO 0
#define SUCESSO 1
#define FRACASSO 0

// POR MEIO DESSE DEFINE É POSSÍVEL ESCOLHER UMA DENTRE DUAS APLICAÇÕES:
// Ou a solução do problema das torres de Hanoi ("#define HANOI 1") ou a
// simples execução de testes de funções da PSE (nesse caso basta comentar a
// linha que aplica "#define HANOI 1"
//
// 
#define HANOI 1



//======== Modelos de dados (structs) representando a informacao usada na  
//======== APLICACAO ESCOLHIDA via diretiva define
//
#ifdef HANOI
typedef struct ponto{  	
	float x;
	float y;
	}info;
#else
typedef struct blabla{ 
    char palavra[15];
    int idade;
    }info;

#endif

//======== Modelo de dados utilizados na implementação da PILHA	
//	
// Nó contendo campo de encadeamento (apontador "abaixo") e área 
// para os dados da aplicação (campo "info")
struct noPSE{	
	info dados;
	struct noPSE *abaixo;
	};	
//
// Descritor da pilha, contendo:
// O apontador "topo", o qual indica o endereço do descritor da pilha e
// o "tamanho" atual da pilha
struct pilha{ 
	struct noPSE *topo;
	int tamPilha;
	};


//=== Operações da APLICACAO da PILHA na solucao do 
//=== problema das Torres de Hanoi
//
void moveDisksBetweenTwoPoles(struct pilha *src,
            struct pilha *dest, char s, char d);
//---- Function to show the movement of disks
void moveDisk(char fromPeg, char toPeg, int disk);
//---- Function to implement TOH puzzle
void tohIterative(int num_of_disks, struct pilha
             *src, struct pilha *aux,
             struct pilha *dest);
long int pow_(long int b, long int e);
//================================================
//
//
//====== Operações providas na interface da PILHA
//
struct pilha * cria(void);
int vazia(struct pilha *pil);
int empilha(info *reg, struct pilha *pil);
int desempilha(info *reg, struct pilha *pil);
int busca(info *reg, struct pilha *pil);
void reinicia(struct pilha *pil);
struct pilha *destroi(struct pilha *pil);
