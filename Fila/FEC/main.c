#include <stdio.h>
#include <stdlib.h>
#include "arqFE.h"

void imprimir_estado(Fila *f) {
    printf(">> Estado: Tamanho=%d | Frente=%d | Cauda=%d\n", 
            f->tamanhoDaFila, f->frente, f->cauda);
}

int main() {
    // Definimos um tamanho pequeno (3) para forçar a circularidade rapidamente
    int tamanho_max = 3;
    Fila *minhaFila = cria(tamanho_max, sizeof(info));

    if (!minhaFila) {
        printf("Erro ao criar a fila!\n");
        return 1;
    }

    printf("--- Teste 1: Insercao ate encher ---\n");
    info aux;
    for (int i = 1; i <= 3; i++) {
        aux.x = i * 10; // Inserindo 10, 20, 30
        if (enfileira(minhaFila, &aux)) {
            printf("Enfileirou: %d\n", aux.x);
        }
    }
    imprimir_estado(minhaFila);

    printf("\n--- Teste 2: Tentar inserir em fila cheia ---\n");
    aux.x = 40;
    if (!enfileira(minhaFila, &aux)) {
        printf("Sucesso: Fila rejeitou o 40 (Fila Cheia) [cite: 398]\n");
    }

    printf("\n--- Teste 3: Remocao para abrir espaco ---\n");
    info reg;
    if (desenfileira(minhaFila, &reg)) {
        printf("Desenfileirou: %d (era a frente)\n", reg.x);
    }
    imprimir_estado(minhaFila);

    printf("\n--- Teste 4: A Mágica da Circularidade (FEC) ---\n");
    /* Neste ponto: frente=1, cauda=2, tamanho=2.
       O vetor tem espaco no indice 0. 
       Ao enfileirar, a cauda deve ir para 0[cite: 348, 392].
    */
    aux.x = 88;
    if (enfileira(minhaFila, &aux)) {
        printf("Enfileirou %d. Note que agora a cauda deve ter 'circulado'!\n", aux.x);
    }
    imprimir_estado(minhaFila);
    
    if (minhaFila->cauda < minhaFila->frente) {
        printf("Confirmado: cauda < frente, mas a fila NAO esta vazia! [cite: 330, 349]\n");
    }

    printf("\n--- Teste 5: Buscas ---\n");
    info f, c;
    buscaNaFrente(minhaFila, &f);
    buscaNaCauda(minhaFila, &c);
    printf("Busca Frente: %d | Busca Cauda: %d\n", f.x, c.x);

    printf("\n--- Teste 6: Esvaziando tudo ---\n");
    while (!testaVazia(minhaFila)) {
        desenfileira(minhaFila, &reg);
        printf("Removido: %d\n", reg.x);
    }
    
    if (testaVazia(minhaFila)) {
        printf("Fila Vazia com sucesso! [cite: 378, 420]\n");
    }

    // Limpeza final
    minhaFila = destroi(minhaFila);
    printf("\nMemoria liberada. Teste concluido.\n");

    return 0;
}