#include "arq.h"
 

// https://www.geeksforgeeks.org/iterative-tower-of-hanoi/
//=======================================================

// Driver Program
int main()
{   	
	info reg, data[]={{"Wilson",6},{"Ponte",5},{"Marialucia",10},{"Uva",3},{"Veneza",6},{"Tania",5}};
	int num_of_students=sizeof(data)/sizeof(info);
	struct pilha *pil=NULL;

	pil = cria(num_of_students);

	printf("\n\n");
	puts("Empilhando");
	for (int i=0;i<num_of_students;i++)
	{	empilha(&data[i],pil);
		printf("palavra: %s \n",data[i].palavra);
	}
	busca(&reg,pil);
	printf("\nTopo da pilha: %s \n",reg.palavra );
	printf("\nDesempilhando \n");
	for (int i=1;i<=num_of_students;i++)
	{		
		desempilha(&reg,pil);
		printf("palavra: %s, ",reg.palavra);
		printf("tamanho da palavra: %i \n",reg.tamanhoPalavra);		
	}
	printf("\n\n");
	return 0;
}

