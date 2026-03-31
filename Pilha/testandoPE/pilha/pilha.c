#include "arq.h"
#include <stdlib.h>

/*
Pilha vazia: topo < 0
Pilha não vazia: topo >= 0
Pilha cheia: topo >= tamVet
*/


int cheia(struct pilha *pil)
{ 	int a,b;

	a=pil->topo;
	b=pil->tamVet-1;
 
	if (a >= b)
		return SIM;
	else
		return NAO;
}

int vazia(struct pilha *pil)
{
  if (pil->topo < 0)
    return SIM;
  else
    return NAO;
}

struct pilha * cria(int tamVet)
{   struct pilha *p=NULL;
	p=(struct pilha *)malloc(sizeof(struct pilha));
    if (p)
    {
	p->vet=(info *)malloc(sizeof(info)*tamVet);//<<<<<<
        if (p->vet) 
            {   p->topo=-1;
                p->tamVet=tamVet;

            }
	else
	  { free(p); // atomicidade
            p=NULL; 
	  }
    }
    return p;
}

int empilha(info *reg, struct pilha *pil)
{  
    if (cheia(pil)==NAO)
    {
        (pil->topo)++;
	memcpy(&(pil->vet[pil->topo]), reg, sizeof(info)); 
	//pil->vet[pil->topo]=*reg;
        return SUCESSO;
    }
    else
        return FRACASSO;
}

int desempilha(info *reg, struct pilha *pil)
{  
    if (vazia(pil)==NAO)
    {	memcpy(reg, &(pil->vet[pil->topo]),sizeof(info)); 
	//*reg = pil->vet[pil->topo];
        (pil->topo)--;
        return SUCESSO;
    }
    else
        return FRACASSO;
}

int busca(info *reg, struct pilha *pil)
{  
    if (vazia(pil)==NAO)
    {   memcpy(reg, &(pil->vet[pil->topo]),sizeof(info)); //<<<<<<<<<<<
        return SUCESSO;
    }
    else
        return FRACASSO;
}

struct pilha *destroi(struct pilha *pil)
{
  free(pil->vet);
  free(pil);
  return NULL;	
}	

int tamanho(struct pilha *stk){
    if(!vazia(stk)){
        return stk->topo-1;
    }
    return 0;
}

int reset(struct pilha *stk){
    if(stk != NULL){
        stk->topo = -1;
        return 1;
    }
    return 0;
}
