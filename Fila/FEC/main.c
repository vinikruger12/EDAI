#include <stdio.h>
#include <stdlib.h>
#include "arqFE.h"

int main() {
    int tamanho = 3;
    printf("--- Iniciando Testes da Fila Circular (Com ints) ---\n");
    
    Fila *fila = cria(tamanho);
    if (!fila) {
        printf("Erro ao alocar a fila!\n");
        return 1;
    }
    printf("Fila criada com tamanho maximo de %d.\n", tamanho);

    // Variáveis agora são ints simples
    int item;

    for (int i = 1; i <= 3; i++) {
        item = i * 10; 
        if (enfileira(fila, &item)) {
            printf("Enfileirou: %d\n", item);
        }
    }

    if (testaCheia(fila)) {
        printf("Teste ok: A fila esta CHEIA!\n");
    }

    item = 40;
    if (!enfileira(fila, &item)) {
        printf("Teste ok: Fila rejeitou o %d por estar cheia.\n", item);
    }

    int frente, cauda;
    buscaNaFrente(fila);
    buscaNaCauda(fila);
    printf("Valor na frente: %d | Valor na cauda: %d\n", frente, cauda);

    int removido;
    desenfileira(fila, &removido);
    printf("Desenfileirou: %d\n", removido);
    desenfileira(fila, &removido);
    printf("Desenfileirou: %d\n", removido);

    printf("Tamanho atual da fila: %d\n", fila->tamanhoDaFila);

    item = 88;
    enfileira(fila, &item);
    printf("Enfileirou (teste circular): %d\n", item);
    
    item = 99;
    enfileira(fila, &item);
    printf("Enfileirou (teste circular): %d\n", item);

    printf("\nEsvaziando a fila por completo:\n");
    while (!testaVazia(fila)) {
        desenfileira(fila, &removido);
        printf("- Saiu: %d\n", removido);
    }

    fila = destroi(fila);
    printf("\nFila destruida com sucesso. Fim dos testes!\n");

    return 0;
}