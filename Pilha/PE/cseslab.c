#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_str(char *s, int len){
    for(int i = 0; i < len/2; i++){
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

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
int menor(int a , int b){
    if(b < a)return b;
    else return a;
}
int main(){

    int n, m; scanf("%d %d", &n, &m);
    struct stack *caminho = cria(n * m);
    info inicio;
    char labirinto[n][m], vis[n][m];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf(" %c", &labirinto[i][j]);
            if(labirinto[i][j] == 'A'){
                inicio.x = i;
                inicio.y = j;
            }
            vis[i][j] = 0;
        }
    }


    info posicaoDeSaida = {m, n};
    int menorCaminho = 0;
    int achou = 0;
    int i = inicio.x, j = inicio.y;
    empilha(&inicio, caminho);
    vis[i][j] = 1;

    int dx[4] = {0, 1, 0, -1}; // direita, baixo, esquerda, cima
    int dy[4] = {1, 0, -1, 0};

    while(!vazia(caminho)){

        if(labirinto[i][j] == 'B'){
            achou = 1;
            menorCaminho = menor((caminho->topo) +1, menorCaminho);
        } 
        
        int moveu = 0;
        for(int k = 0;k < 4;k++){
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && ni < n && nj >= 0 && nj < m && (labirinto[ni][nj] == '.' || labirinto[ni][nj] == 'B') && vis[ni][nj] == 0){
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

    if(!achou){
    printf("NO\n");
}
else{
    int ko = caminho->topo + 1;
    printf("YES\n");
    printf("%d\n", menorCaminho);

    char s[n * m];
    int idx = 0;

    info reg;
    busca(&reg, caminho);
    int a = reg.x;
    int b = reg.y;

    while(!vazia(caminho)){
        desempilha(caminho);
        if(vazia(caminho)) break;

        busca(&reg, caminho);

        if(reg.x == a - 1) s[idx++] = 'D';
        else if(reg.x == a + 1) s[idx++] = 'U';
        else if(reg.y == b - 1) s[idx++] = 'R';
        else if(reg.y == b + 1) s[idx++] = 'L';

        a = reg.x;
        b = reg.y;
    }

    s[idx] = '\0';
    reverse_str(s, idx);
    printf("%s\n", s);
}
    

}