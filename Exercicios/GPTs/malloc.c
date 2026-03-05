#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto{
    char nome[20];
    float preco;
};

int main(){
    struct Produto *camisa;
    camisa = malloc(sizeof(struct Produto));

    if(camisa == NULL) return 1;

    char name[20] = "Nike";
    strcpy(camisa->nome, name);
    camisa->preco = 100;
    printf("%s por R$%f", camisa->nome, camisa->preco);
    free(camisa);
}