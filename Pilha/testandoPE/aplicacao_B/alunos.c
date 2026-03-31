#include "arq.h"
 

// https://www.geeksforgeeks.org/iterative-tower-of-hanoi/
//=======================================================

// Driver Program
int main()
{   	int num_of_students=3;
    	char nome[20];
	struct pilha *pil=NULL;
    	info reg;
	pil = cria(num_of_students);
	
	
	for (int i=1;i<=num_of_students;i++)
	{	printf("Entre com o nome:");
		scanf("%s",reg.nome);
		printf("Entre com o RG:");
		scanf("%i",&(reg.rg));	
		empilha(&reg,pil);
	}

	for (int i=1;i<=num_of_students;i++)
	{		
		desempilha(&reg,pil);
		printf("nome: %s, ",reg.nome);
		printf("RG: %i \n",reg.rg);		
	}
	return 0;
}

