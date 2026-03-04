#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h> //https://stackoverflow.com/questions/9053658/correct-format-specifier-to-print-pointer-or-address

// gcc -o saida -Wall codigosRevisaoC.c -lm


struct teste{ 	int inteiro;
				float real;
                char nome[30];
                char rua[30];
                int *apont;
        };

struct teste2{ 	int inteiro;
				float real;
                char nome[30];
                struct teste2 *self;
        };
        
typedef struct informacao{	int idade;
				char nome[30];
		}info;
		
typedef struct nodo{	int idade;
						char nome[30];
						struct nodo *link;
		}Nodo;

//==========================================================		
// 5 "printf" para hexadecimais		
// 10 "printf" para endereços de memoria 		
// 15, 20, ponteiros, ponteiro-para-ponteiro, structs
// 30, 40, 50: miscelânea com ponteiros e structs
// 35: ponteiro void
// 60, 70:   aritmética de ponteiros
// 80, 90: structs, malloc e uso de memcpy
// 100 : lista em um vetor de ponteiros
// 110, 120 : lista encadeada
// 130 : lista encadeada com o último tendo link de encadeamento anulado
// 140 : lista encadeada circular
// 150 : lista encadeada finalizada em laço
//
// 10, 15 e 20 sao os itens C, D e E na lista de execicios
//==========================================================
#define TEST 30//10// 15//20//30//150//140// 140//130
 
int main(void)
{
	system("clear");
	
#if TEST == 5//=====================================================
    int data = 29;
	printf("\n %s TESTE %i \n","\U0001F3AC",TEST);      
    printf("%i\n", data);    // just print data
    printf("%x\n", data);    // just print data in lower case hexadecimal
    printf("%0x\n", data);   // just print data ('0' on its own has no effect)
    printf("%8x\n", data);   // print in 8 width and pad with blank spaces
    printf("%08x\n", data);  // print in 8 width and pad with 0's
	printf("\n ================= FIM TESTE %i \n\n",TEST);
	


#elif TEST == 10
	int *p=NULL, **pp=NULL, x = 321, y=101;
	printf("\n %s TESTE %i \n\n","\U0001F3AC",TEST);   
	p = &x;
	pp=&p;
	*p= -3;
	y=**pp;
	printf("\n \'&p\' = %p \n", (uintptr_t)&p);	//máscara alternativa: %016lX	
	printf("\n\'*p\' =  %i \n", *p);	
	printf("\n\'x\' =  %i \n", x);	
	printf("\n \'&x\' = %p \n", (uintptr_t)&x);	
	printf("\n \'&pp\' = %p \n", (uintptr_t)&pp);
	printf("\n \'pp\' = %p \n", (uintptr_t)pp);
	printf("\n \'*pp\' = %p \n", (uintptr_t)*pp);
	printf("\n \'**pp\' = %i \n", **pp);
	printf("\n \'&(*pp)==&(p)\' = %p \n", (uintptr_t)&(*pp));
	printf("\n \'&(**pp)==&(*(*pp))==&(*p)==&x\' = %p \n", (uintptr_t)&(**pp));	
	printf("\n\'y\' =  %i \n", y);	
	printf("\n ================= FIM TESTE %i \n\n",TEST);

#elif TEST == 15  //=====================================================
	printf("\n TESTE %i \n",TEST);
	struct teste2 x = {115, 2.5, "Smith", NULL},*p=NULL;
	p = &x;
	p->self = &x;
	printf("\n \'&x\': %p \n", (uintptr_t)&x);	
	printf("\n \'&p\': %p \n", (uintptr_t)&p);
	printf("\n \'p\': %p \n", (uintptr_t)p);	
	printf("\n \'p->inteiro\': %i \n", (p->inteiro));	
	printf("\n \'p->real\': %f \n", (p->real));	
	printf("\n \'p->nome\': %s \n", (p->nome));
	printf("\n \'p->self\': %p \n", (uintptr_t)(p->self));
	printf("\n \'&(p->self)\': %p \n", (uintptr_t)&(p->self));	
	printf("\n ================= FIM TESTE %i \n\n",TEST);	


#elif TEST == 20  //=====================================================
	printf("\n TESTE %i \n",TEST);
	struct teste x = {321, 2.39, "Silva", "Timbo", NULL},*p=NULL;
	int y= 101;
	p = &x;
	p->apont= &y;
	printf("\n \'&p\' (endereço de \'p\'): %p \n", (uintptr_t)&p);	
	printf("\n \'p\' (conteudo de \'p\'): %p \n", (uintptr_t)p);	
	printf("\n \'p\' aponta para o endereço onde a estrutura \'x\' reservou um bloco de %li bytes \n", sizeof(struct teste));
	printf(" distribuidos entre %li (inteiro) %li (real)  %li (nome) %li (rua) %li (apont) bytes \n",sizeof(x.inteiro), sizeof(x.real), sizeof(x.nome), sizeof(x.rua),sizeof(x.apont));
	printf("----------- Ponteiros consomem 8 bytes, em sistemas de 64-bits \n\n");	 //https://stackoverflow.com/questions/399003/is-the-sizeofsome-pointer-always-equal-to-four
	
	printf("\n TECLE \n");
	getchar();
	
	printf("\n \'&(p->inteiro)\' = %p \n", (uintptr_t)&(p->inteiro))//máscara alternativa: %016lX;	
	printf("\n 		\'p->inteiro\' =  %i \n", (p->inteiro));	
	printf("\n \'&(p->real)\' = %p \n", (uintptr_t)&(p->real));	
	printf("\n 		\'p->real\' = %f \n", (p->real));	
	printf("\n \'&(p->nome)\' = %p \n", (uintptr_t)&(p->nome));
	printf("\n 		\'p->nome\' = %s \n", (p->nome));		
	printf("\n \'&(p->rua)\' = %p \n", (uintptr_t)&(p->rua));
	printf("\n 		\'p->rua\' = %s \n", (p->rua));	
	printf("\n \'&(p->apont)\' = %p \n", (uintptr_t)&(p->apont));
	printf("\n 		\'p->apont\' = %p  \n", (uintptr_t)(p->apont));	
	printf("\n 			\'*(p->apont)\' = %i \n", *(p->apont));	
	printf("\n \'&y\' =  %p  \n", (uintptr_t) &y);	
	printf("\n ================= FIM TESTE %i \n\n",TEST);

	

	
#elif TEST == 30//=====================================================
	int x=29, y=-33, *p=NULL, **pp=NULL;
	printf("\n TESTE %i \n",TEST);	
	    pp=&p;
	printf("\n endereço de \'x\':%p \n", (uintptr_t)&x); //máscara alternativa: %016lX
	printf("\n endereço de \'y\':%p \n", (uintptr_t)&y);
	printf("\n endereço de \'p\': %p \n", (uintptr_t)&p);	
	printf("\n endereço de \'pp\': %p \n", (uintptr_t)&pp);
	printf("\n \'p\' aponta para: %p \n", (uintptr_t)p);	
	printf("\n \'pp\' aponta para: %p \n", (uintptr_t)pp);	

	printf("\n TECLE \n");
	getchar();

	p=&x;
	pp=&p;	

	printf("\n------------ Após as atribuições----------------\n");	
	printf("\n endereço de \'x\':%p \n", (uintptr_t)&x); //máscara alternativa: %016lX
	printf("\n endereço de \'y\':%p \n", (uintptr_t)&y);	
	printf("\n endereço de \'p\': %p \n", (uintptr_t)&p);	
	printf("\n endereço de \'*pp\': %p \n", (uintptr_t)&(*pp));	
	printf("\n endereço de \'**pp\': %p \n", (uintptr_t)&(**pp));
	printf("\n endereço de \'pp\': %p \n", (uintptr_t)&pp);
	printf("\n \'p\' aponta para: %p \n", (uintptr_t)p);	
	printf("\n \'pp\' aponta para: %p \n", (uintptr_t)pp);	

	printf("\n TECLE \n");
	getchar();
			
	printf("\n--------- Exemplo 1: Indireção/delegação ------------\n");
	printf("\n Lendo \'p\' por meio de \'*pp\' == %p \n", (uintptr_t)*pp);
	printf("\n Lendo \'x\' por meio de \'*p\' ==  %i \n", *p);
	printf("\n Lendo \'x\' por meio de \'**pp\' == %i \n", **pp);

	*p = 94;
	printf("\n Alterando \'x\' por meio de \'*p\' =  %i \n", *p);
	
	printf("\n TECLE \n");
	getchar();
	
	printf("\n--------- Exemplo 2: Indireção/delegação ------------\n");	
	*pp = &y;
	printf("\n Alterando o endereço apontado por \'p\' por meio de \'*pp\' = &y == %p \n", (uintptr_t)&y);
	printf("\n Lendo \'y\' por meio de \'*p\' ==  %i \n", *p);	
	printf("\n Lendo \'y\' por meio de \'**pp\' == %i \n", **pp);

	printf("\n TECLE \n");
	getchar();

	printf("\n---------- Exemplo 3: Indireção/delegação -----------\n");	
	**pp = 137;
	printf("\n Alterando \'y\' por meio de \'**pp\' = %i \n", y);

	printf("\n ================= FIM TESTE %i \n\n",TEST);

	
#elif TEST == 35//=====================================================

		int a=10, vet[]={1,2,3,4,5}, *p=NULL;
		float b=35.75;
		info y = {31,"Wilson"};
		void *ptr; // Declaracao de um ponteiro para um tipo genérico (void)
	
		printf("\n TESTE %i \n\n",TEST);	

		printf("%s Acessando inteiro, float ou struct por meio do ponteiro void\n","\U0001F91e");	
		ptr=&a; // Atribuindo o endereço de um inteiro.
		printf("a = %d \n", * ( (int*) ptr) );
		ptr=&b; // Atribuindo o endereço de um float.
		printf("b = %f \n",*( (float*) ptr) );
		ptr= &y;
		printf("nome= %s, idade = %i \n\n", ((info*) ptr)->nome,((info*) ptr)->idade);		
		printf("%s FUNCIONA\n","\U0001F44D");
		puts("TECLE!");
		getchar();
		
		printf("%s Acessando um vetor por aritmetica de ponteiro convencional\n","\U0001F91e");
		p=&vet[0];
		for (int i =0;i<6;i++,p++)
			printf("vet[%i] = %i \n", i, *p);
		printf("%s CLARO QUE FUNCIONA\n","\U0001F600");
		puts("TECLE!");
		getchar();
			
		printf("\n\n%s Acessando um vetor por aritmetica de ponteiro void\n","\U0001F91e");			
		ptr=&vet[0];
		for (int i =0;i<6;i++,ptr++)
			printf("vet[%i] = %i \n", i,  *( (int*) ptr) );
			
		printf("%s ponteiros void não se adequam a aritmetica de ponteiros"," \xf0\x9f\x98\x95");	
								
		printf("\n ================= FIM TESTE %i \n\n",TEST);	
		//http://www.circuitstoday.com/void-pointers-in-c
		
#elif TEST == 40//=====================================================

	info *p=NULL, y = {31,"Wilson"};
	p= &y;
	printf("\n TESTE %i \n",TEST);	
	// Diferentes formas de acessar os campos da struct
	printf("\n \'y.nome\': %s, \'y.idade\': %i \n", y.nome, y.idade);
	printf("\n \'p->nome\': %s, \'p->idade\': %i \n", p->nome, p->idade);
	printf("\n \'(*p).nome\': %s, \'*(p).idade\': %i \n", (*p).nome, (*p).idade);
	printf("\n ================= FIM TESTE %i \n\n",TEST);

#elif TEST == 50//=====================================================

	info *p=NULL, y = {31,"Wilson"};
	p= &y;
	printf("\n TESTE %i \n",TEST);	
	// Endereço da struct X endereço dos campos da struct
	printf("\n \'p\' aponta para a struct no endereco: %p \n", (uintptr_t)p);
	printf("\n endereço de \'p->nome\': %p \n", (uintptr_t) &(p->nome));
	printf("\n endereço de \'p->idade\': %p \n", (uintptr_t)&(p->idade));
	printf("\n ================= FIM TESTE %i \n\n",TEST);

#elif TEST == 60//=====================================================

	char str[ ]= "linguagem C", *px, *py, aux;
	printf("\n TESTE %i \n",TEST);
		
	printf("\n %s \n",str);
	px = py = str;
	for(;*py != '\0'; py++);
    py--;
	while(px<py)
	{ 	aux = *px;
		/*  16 says that you want to show 8 digits
			0 that you want to prefix with 0's instead of just blank spaces
			X that you want to print in upper-case hexadecimal.
		*/ 

		printf("\n %p \n", (uintptr_t)px);		
		*px = *py;
		*py = aux;
		px++;
		py--;
	}

	printf("\n %s \n",str);
	printf("\n ================= FIM TESTE %i \n\n",TEST);

#elif TEST == 70//=====================================================

	info *p=NULL, data[]={{31,"Wilson"},{23,"Pedro"},{32,"Maria"},{18,"Ana"},{81,"Vania"},{18,"Tania"}};
	int i, tamVet=sizeof(data)/sizeof(info);
	printf("\n TESTE %i \n",TEST);	
    p= data; // p= &data[0]
	for(i=0;i<tamVet;i++)
		printf("\n %s \n", (p+i)->nome);
	printf("\n ================= FIM TESTE %i \n\n",TEST);
	
#elif TEST == 80//=====================================================
	info x, y = {31,"Wilson"};
	printf("\n TESTE %i \n\n",TEST);	
	printf("Ex1 do uso do \'memcpy\'");
	memcpy(&x, &y,sizeof(info));
	printf("\n y --- nome: %s, idade: %i \n", y.nome, y.idade);
	printf("\n x --- nome: %s, idade: %i \n", x.nome, x.idade);
	printf("\n ================= FIM TESTE %i \n\n",TEST);

#elif TEST == 90//=====================================================

	info *p=NULL, y = {31,"Wilson"};
	printf("\n TESTE %i \n\n",TEST);	
	p= (info *)malloc(sizeof(info));
	if (p==NULL)
	{
      fprintf(stderr, "Erro na alocaçao de memoria! Exiting...\n");
      exit(-1);
	}	
	printf("Ex2 do uso do \'memcpy\' e apontador");
	memcpy(p, &y,sizeof(info));
	printf("\n \'y.nome\': %s, \'y.idade\': %i \n", y.nome, y.idade);
	printf("\n \'p->nome\': %s, \'p->idade\': %i \n", p->nome, p->idade);
	
	printf("\n TECLE \n");
	getchar();
	
	// Muito importante: um free() para cada malloc()!!!!!!!!!
	printf("\n Garbage collection... \n");
	free(p);
	printf("\n ================= FIM TESTE %i \n\n",TEST);

			
#elif TEST == 100//=====================================================
   
   	info **copia=NULL, data[]={{31,"Wilson"},{23,"Pedro"},{32,"Maria"},{18,"Ana"},{81,"Vania"},{18,"Tania"}};
   	
	int i, tamVet=sizeof(data)/sizeof(info);

	printf("\n TESTE %i \n\n",TEST);	
	copia= (info **) malloc(tamVet*sizeof(info));
    if(copia == NULL)	
	{
      fprintf(stderr, "Erro na alocaçao de memoria! Exiting...\n");
      exit(-1);
	}
   
	for(i=0;i<tamVet;i++)
		printf("\n copia[%i] aponta para: %p \n", i,(uintptr_t)copia[i]);
	
	printf("\n TECLE \n");	
	getchar();
	  
   	for(i=0;i<tamVet;i++)
			{	copia[i] = (info *) malloc(sizeof(info));
				memcpy(copia[i], &data[i], sizeof(info));
			}	
	printf("\n------------ Após as atribuições ----------------\n");		
	for(i=0;i<tamVet;i++)
		printf("\n copia[%i] aponta para: %p --- nome: %s, idade: %i \n",  i,(uintptr_t)copia[i], copia[i]->nome, copia[i]->idade);
	
	printf("\n TECLE \n");	
	getchar();
	
	// Muito importante: um free() para cada malloc()!!!!!!!!!
	printf("\n Garbage collection... \n");
	
   	for(i=0;i<tamVet;i++)
			free(copia[i]);
	free(copia);
	printf("\n ================= FIM TESTE %i \n\n",TEST);
		
#elif TEST == 110//=====================================================
   
   	Nodo *aux1 = NULL, *aux2 = NULL, *lista=NULL; 
   	info  data[]={{31,"Wilson"},{23,"Pedro"},{32,"Maria"},{18,"Ana"},{81,"Vania"},{18,"Tania"}};
   	
	int i, tamVet=sizeof(data)/sizeof(info);
	
	printf("\n TESTE %i \n",TEST);	
    printf("\n Inicializaçao \n");	

   	for(i=0;i<tamVet;i++)
			{	//printf("\n %i \n",i);
				
				aux2 = (Nodo *) malloc(sizeof(Nodo));
				if(aux2 == NULL)	
				{
					fprintf(stderr, "Erro na alocaçao de memoria! Exiting...\n");
					exit(-1);
				}
				if(i== 0) 
				{	aux1=lista=aux2;
					strcpy(lista->nome, data[i].nome);
					lista->idade = data[i].idade;
					lista->link=NULL;
				}				
				aux1->link=aux2;
				strcpy(aux2->nome, data[i].nome);
				aux2->idade = data[i].idade;
				aux2->link=NULL;
				aux1=aux2;
			}	
	printf("\n TECLE \n");	
	getchar();		
	
	printf("\n------------ Após as atribuições ----------------\n");	
	aux1=lista;	
	while(aux1 != NULL)
	{	printf("\n \'aux1\' aponta para: %p --- nome: %s, idade: %i \n", (uintptr_t)aux1, aux1->nome, aux1->idade);
		aux1=aux1->link;
	}
	printf("\n TECLE \n");	
	getchar();

	printf("\n Garbage collection... \n");	
	// Muito importante: um free() para cada malloc()!!!!!!!!!
	aux1=lista;
	while(lista->link != NULL)
	{	lista=lista->link;	
		printf("\n Removendo nome: %s, idade: %i \n", aux1->nome, aux1->idade);
		free(aux1);
		aux1=lista;
	}	
	printf("\n Removendo nome: %s, idade: %i \n", aux1->nome, aux1->idade);
	free(aux1);
	printf("\n ================= FIM TESTE %i \n\n",TEST);


#elif TEST == 120
	system("clear");   
   	Nodo *p = NULL, *aux1 = NULL; 
   	info  data[]={{31,"Wilson"},{23,"Pedro"},{32,"Maria"},{18,"Ana"},{81,"Vania"},{18,"Tania"}};
   	
	int i, tamVet=sizeof(data)/sizeof(info);

    	printf("\n Inicializaçao \n");	

	p = (Nodo *) malloc(sizeof(Nodo));
	if(p == NULL)	
	{
	  fprintf(stderr, "Erro na alocaçao de memoria! Exiting...\n");
	  exit(-1);
	}
	 
	
	strcpy(p->nome, data[0].nome);
	p->idade = data[0].idade;
	p->link=NULL;
	
	aux1=p;
   	for(i=1;i<tamVet;i++)
			{	//printf("\n %i \n",i);
				
				aux1->link = (Nodo *) malloc(sizeof(Nodo));
				if(aux1->link == NULL)	
				{
					fprintf(stderr, "Erro na alocaçao de memoria! Exiting...\n");
					exit(-1);
				}
				
				strcpy(aux1->link->nome, data[i].nome);
				aux1->link->idade = data[i].idade;
				aux1->link->link=NULL;
				aux1=aux1->link;
			}	
	printf("\n TECLE \n");	
	getchar();		
	
	printf("\n------------ Após as atribuições ----------------\n");	
	aux1=p;	
	while(aux1 != NULL)
	{	printf("\n \'aux1\' aponta para: %p --- nome: %s, idade: %i \n", (uintptr_t)aux1, aux1->nome, aux1->idade);
		aux1=aux1->link;
	}
	printf("\n TECLE \n");	
	getchar();

	printf("\n Garbage collection... \n");	
	// Muito importante: um free() para cada malloc()!!!!!!!!!
	
	do
	{	aux1= p->link;
		printf("\n Removendo nome: %s, idade: %i \n", p->nome, p->idade);
		free(p);
		p=aux1;
	}while(p!=NULL);		

	printf("\n =================  FIM TESTE %i \n\n",TEST);	

#elif TEST == 130//=====================================================
    // sequencia encadeada com o último tendo link de encadeamento anulado
   	Nodo *aux1 = NULL, *aux2 = NULL, *lista=NULL; 
   	info  data[]={{31,"Wilson"},{23,"Pedro"},{32,"Maria"},{18,"Ana"},{81,"Vania"},{18,"Tania"}};
   	int cont=0;
	int i, tamVet=sizeof(data)/sizeof(info);
	
	printf("\n TESTE %i \n",TEST);	
    printf("\n Inicializaçao \n");	

   	for(i=0;i<tamVet;i++)
			{	//printf("\n %i \n",i);
				
				aux2 = (Nodo *) malloc(sizeof(Nodo));
				if(aux2 == NULL)	
				{
					fprintf(stderr, "Erro na alocaçao de memoria! Exiting...\n");
					exit(-1);
				}
				if(i== 0) 
				{	aux1=lista=aux2;
					strcpy(lista->nome, data[i].nome);
					lista->idade = data[i].idade;
					lista->link=NULL;
				}				
				aux1->link=aux2;
				strcpy(aux2->nome, data[i].nome);
				aux2->idade = data[i].idade;
				aux2->link=NULL; // o último tem link de encadeamento anulado
				aux1=aux2;
			}	
	printf("\n TECLE \n");	
	getchar();		
	
	//printf("\n------------ Após as atribuições ----------------\n");	
	aux1=lista;	
	cont=0;
	while(aux1 != NULL)
	{	printf("\n \'aux1\' aponta para: %p --- nome: %s, idade: %i ", (uintptr_t)aux1, aux1->nome, aux1->idade);
		cont++;
		aux1=aux1->link;
	}
	printf("\n Tamanho da sequencia: %i \n TECLE \n",cont);	
	getchar();

	printf("\n Garbage collection... \n");	
	// Muito importante: um free() para cada malloc()!!!!!!!!!
	aux1=lista;
	while(lista->link != NULL)
	{	lista=lista->link;	
		printf("\n Removendo nome: %s, idade: %i ", aux1->nome, aux1->idade);
		free(aux1);
		aux1=lista;
	}	
	printf("\n Removendo nome: %s, idade: %i ", aux1->nome, aux1->idade);
	free(aux1);
	lista=NULL;
	printf("\n ================= FIM TESTE %i \n\n",TEST);


#elif TEST == 140//=====================================================
    // sequencia encadeada com o último tendo link para o primeiro
   	Nodo *aux1 = NULL, *aux2 = NULL, *lista=NULL; 
   	info  data[]={{31,"Wilson"},{23,"Pedro"},{32,"Maria"},{18,"Ana"},{81,"Vania"},{18,"Tania"}};
   	int cont=0;
	int i, tamVet=sizeof(data)/sizeof(info);
	
	printf("\n TESTE %i \n",TEST);	
    printf("\n Inicializaçao \n");	

   	for(i=0;i<tamVet;i++)
			{	//printf("\n %i \n",i);
				
				aux2 = (Nodo *) malloc(sizeof(Nodo));
				if(aux2 == NULL)	
				{
					fprintf(stderr, "Erro na alocaçao de memoria! Exiting...\n");
					exit(-1);
				}
				if(i== 0) 
				{	aux1=lista=aux2;
					strcpy(lista->nome, data[i].nome);
					lista->idade = data[i].idade;
					lista->link=NULL;
				}				
				aux1->link=aux2;
				strcpy(aux2->nome, data[i].nome);
				aux2->idade = data[i].idade;
				aux2->link=lista; // o último tem link de encadeamento anulado
				aux1=aux2;
			}	
	printf("\n TECLE \n");	
	getchar();		
	
	//printf("\n------------ Após as atribuições ----------------\n");	
	
	cont=0;
	if (!lista)
	    return cont;
	aux1=lista;	    
	do
	{	printf("\n \'aux1\' aponta para: %p --- nome: %s, idade: %i ", (uintptr_t)aux1, aux1->nome, aux1->idade);
		cont++;
		aux1=aux1->link;
	}while(aux1!=lista); //nunca vai ser NULL)
	printf("\n Tamanho da sequencia: %i \n TECLE \n",cont);	
	getchar();
/*
	AQUI TEMOS UM PROBLEMA PARA O COLETOR DE LIXO:
	POIS AA MEDIDA QUE OS NÓS SAO LIBERADOS (FREE), NÃO FICA NENHUM NÓ ATIVO NA ANTIGA PRIMEIRA POSICAO DA LISTA, QUE SE TORNA UM ARRANJO CIRCULAR 
	LOGICAMENTE INCONSISTENTE (NAO HÁ MAIS O PRIMEIRO ELEMENTO QUE RECEBIA O LINK CIRCULR A PARTI DO ULTIMO). UMA SOLUÇÃO É UTILIZAR UM DESCRITOR 
	CONTENDO O TAMANHO DA LISTA OU ENCONTRAR O ÚLTIMO ELEMENTO E DEIXAR UM PONTEIRO NELE, O QUAL CONTROLARIA O LAÇO. ESSA É A OPCAO ADOTRADA AQUI.
	obs: SABE-SE QUE EM TERMOS DE MEMÓRIA, O PRIMEIRO ELEMENTO AINDA EXISTE, APESAR DE TER SIDO LIBERADO, MAS AINDA ASSIM É UMA INCONSISTêNCIA LÓGICA
	PROGRAMAR COM ESSA PREMISSA
*/	
	printf("\n Garbage collection... \n");	
	// Muito importante: um free() para cada malloc()!!!!!!!!!

	if (!lista)
	    return;
	aux2=lista;
	while(aux2->link != lista)
    	aux2=aux2->link;
	aux1=lista;	    
	while(aux1->link != aux2)
	{	
		printf("\n Removendo nome: %s, idade: %i ", aux1->nome, aux1->idade);	    
	    free(aux1);
	    	
	    aux1=aux1->link;	    
	}	
	printf("\n Removendo nome: %s, idade: %i ", aux1->nome, aux1->idade);
	free(aux1);
	printf("\n Removendo nome: %s, idade: %i \n", aux2->nome, aux2->idade);
	free(aux2);	
	lista=NULL;
	
	printf("\n ================= FIM TESTE %i \n\n",TEST);

#elif TEST == 150//=====================================================
    // sequencia encadeada com o último tendo link de encadeamento em laço
   	Nodo *aux1 = NULL, *aux2 = NULL, *lista=NULL; 
   	info  data[]={{31,"Wilson"},{23,"Pedro"},{32,"Maria"},{18,"Ana"},{81,"Vania"},{18,"Tania"}};
   	int cont=0;
	int i, tamVet=sizeof(data)/sizeof(info);
	
	printf("\n TESTE %i \n",TEST);	
    printf("\n Inicializaçao \n");	

   	for(i=0;i<tamVet;i++)
			{	//printf("\n %i \n",i);
				
				aux2 = (Nodo *) malloc(sizeof(Nodo));
				if(aux2 == NULL)	
				{
					fprintf(stderr, "Erro na alocaçao de memoria! Exiting...\n");
					exit(-1);
				}
				if(i== 0) 
				{	aux1=lista=aux2;
					strcpy(lista->nome, data[i].nome);
					lista->idade = data[i].idade;
					lista->link=NULL;
				}				
				aux1->link=aux2;
				strcpy(aux2->nome, data[i].nome);
				aux2->idade = data[i].idade;
				aux2->link=aux2; // o último tem link em laço para ele mesmo
				aux1=aux2;
			}	
	printf("\n TECLE \n");	
	getchar();		
	
	//printf("\n------------ Após as atribuições ----------------\n");	
	
	cont=0;
	if (!lista) 
	    return cont;
	
	aux1=lista;	    
	while(aux1->link != aux1)
	{	printf("\n \'aux1\' aponta para: %p --- nome: %s, idade: %i ", (uintptr_t)aux1, aux1->nome, aux1->idade);
		cont++;
		aux1=aux1->link;
	}
    printf("\n \'aux1\' aponta para: %p --- nome: %s, idade: %i ", (uintptr_t)aux1, aux1->nome, aux1->idade);
	cont++;	
	printf("\n Tamanho da sequencia: %i \n TECLE \n",cont);	
	getchar();


	printf("\n Garbage collection... \n");	
	// Muito importante: um free() para cada malloc()!!!!!!!!!
	aux1=lista;
	while(lista->link != aux1)
	{	lista=lista->link;	
		printf("\n Removendo nome: %s, idade: %i ", aux1->nome, aux1->idade);
		free(aux1);
		aux1=lista;
	}	
	printf("\n Removendo nome: %s, idade: %i ", aux1->nome, aux1->idade);
	free(aux1);
	lista=NULL;
	printf("\n ================= FIM TESTE %i \n\n",TEST);

#elif TEST
		printf("\n ------------------ \n OPCAO DE TESTE INVALIDA \n---------------------\n\n");
		getchar();
#endif

    return 0;
}




