#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} info;

struct stack{
    int tam;
    info *vet;
    int topo;
};

int cheia(struct stack *stk){
    if((stk->topo) >= (stk->tam-1)) return 1;
    return 0;
}

int vazia(struct stack *stk){
    if(stk->topo < 0) return 1;
    return 0;
}

struct stack *cria(int tam){
    struct stack *stk = NULL;
    stk = malloc(sizeof(struct stack));

    if(stk){
        stk->vet = malloc(sizeof(info) * tam);
        if(stk->vet){
            stk->topo = -1;
            stk->tam = tam;
        }
        else{
            free(stk);
            stk = NULL;
        }
    }
    return stk;
}

int empilha(info *reg, struct stack *stk){
    
    if(!cheia(stk)){
        (stk->topo)++;
        memcpy(&(stk->vet[stk->topo]), reg, sizeof(info));
        return 1;    
    }
    return 0;
}

int desempilha(struct stack *stk){
    if(!vazia(stk)){
        (stk->topo)--;
        return 1;
    }
    return 0;
}

int busca(info *reg,struct stack *stk){
    if(!vazia(stk)){
        *reg = stk->vet[stk->topo];
        return 1;
    }
    return 0;
}

struct stack *destroi(struct stack *stk){
    
    if(stk){
        free(stk->vet);
        free(stk);
    }
    return NULL;
}

int main(){
    struct stack *caminho = cria(100);

    int labirinto[10][10], vis[10][10];
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            scanf("%d", &labirinto[i][j]);
            vis[i][j] = 0;
        }
    }

    int m, n;
    scanf("%d %d", &m, &n);
    info posicaoDeSaida = {m, n};
    int achou = 0;

    int i = 0, j = 0;
    info first = {i, j};
    empilha(&first, caminho);
    vis[0][0] = 1;

    int dx[4] = {0, 1, 0, -1}; // direita, baixo, esquerda, cima
    int dy[4] = {1, 0, -1, 0};

    while(!achou && !vazia(caminho)){

        if(caminho->vet[caminho->topo].x == posicaoDeSaida.x 
        && caminho->vet[caminho->topo].y == posicaoDeSaida.y) achou = 1;
        
        int moveu = 0;
        for(int k = 0;k < 4;k++){
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && ni < 10 && nj >= 0 && nj < 10 && labirinto[ni][nj] == 0 && vis[ni][nj] == 0){
                j = nj;
                i = ni;

                info a = {i, j};
                empilha(&a, caminho);
                vis[i][j] = 1;
                moveu = 1;
                break;
            }
        }
        if(!moveu){
            desempilha(caminho);
            if(vazia(caminho)) break;

            info topo;
            busca(&topo, caminho);
            i = topo.x;
            j = topo.y;
        }
    }

    printf("Voce teve que andar %d casas até conseguir sair do labirinto\n", caminho->topo);

}