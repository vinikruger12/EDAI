#include <stdio.h>
#include <stdlib.h>
#include "arqFE.h"


Fila *cria(int tamVet){
    Fila *f = NULL;
    f = malloc(sizeof(Fila));
    
    if(f){
        f->tamVetor = tamVet;
        f->cauda = 0;
        f->frente = 0;
        f->tamanhoDaFila = 0;
        f->vetFila = malloc(sizeof(int) * tamVet);

        if(!f->vetFila){
            free(f);
            return NULL;
        }
    }
    else{
        free(f);
        f = NULL;
    }

    return f;

}

Fila * destroi(Fila *f){
    free(f);
    return NULL;
}

int enfileira(Fila *f, int *novo){
    if(testaCheia(f)) return 0;
    if(f->cauda == (f->tamVetor - 1) && !testaCheia(f)){
        if(f->vetFila[0] == -1){
            f->cauda = f->frente;
        }
    }

    f->vetFila[f->cauda] = *novo;
    f->cauda++;
    f->tamanhoDaFila++;

    return 1;
}

int desenfileira(Fila *f, int *reg){
    if(testaVazia(f)) return 0;

    *reg = f->vetFila[f->frente];
    f->vetFila[f->frente] = -1;
    f->frente++;
    f->tamanhoDaFila--;

    return 1;

}

int buscaNaFrente(Fila *f){
    if(testaVazia(f)) return 0;

    return f->vetFila[f->frente];
}

int buscaNaCauda(Fila *f){
    if(testaVazia(f)) return 0;
    
    return f->vetFila[f->cauda];
}

int testaVazia(Fila *f){
    return (f->tamanhoDaFila == 0);
}

int testaCheia(Fila *f){
    return (f->tamanhoDaFila == f->tamVetor);
}

int reinicializa(Fila *f){
    int *reg;
    while(!testaVazia(f)) desenfileira(f, reg);

    f->cauda = 0;
    f->frente = 0;
    f->tamanhoDaFila = 0;
    
    return 1;
}

