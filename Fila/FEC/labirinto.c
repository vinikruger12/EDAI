#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int i;
    int j;
} info;

typedef struct {
    info *vetFila;
    int tamVetor;
    int frente; /* indexa o início da Fila */
    int cauda; /*indexa o final da Fila */
    int tamanhoDaFila; /*num de elementos*/
} Fila;

Fila * cria(int tamVet, int tam);
Fila * destroi(Fila *p);
int buscaNaFrente(Fila *p, info *reg);
int buscaNaCauda(Fila *p, info *reg);
int testaVazia(Fila *p);
int testaCheia(Fila *p);
int reinicializa(Fila *p);
int enfileira(Fila *p, info *novo);
int desenfileira(Fila *p, info *reg); 

Fila *cria(int tamVet, int tam){

    Fila *f = NULL;
    f = malloc(sizeof(Fila));
    if(f){
        f->tamVetor = tamVet;
        f->cauda = -1;
        f->frente = 0;
        f->tamanhoDaFila = 0;
        f->vetFila = malloc(tamVet * tam);    
    }else{
        free(f);
        f = NULL;
    }

    return f;
}

Fila *destroi(Fila *f){
    free(f->vetFila);
    free(f);
    return NULL;
}

int enfileira(Fila *f, info *novo){

    if(testaCheia(f)) return 0;

    f->cauda = (f->cauda + 1) % f->tamVetor;

    f->vetFila[f->cauda] = *novo;
    f->tamanhoDaFila++;

    return 1;
}

int desenfileira(Fila *f, info *reg){

    if(testaVazia(f)) return 0;

    *reg = f->vetFila[f->frente];
    f->frente = (f->frente+1) % f->tamVetor;
    f->tamanhoDaFila--;

    return 1;
}

int buscaNaFrente(Fila *f, info *reg){

    if(testaVazia(f)) return 0;
    *reg = f->vetFila[f->frente];
    return 1;
}

int buscaNaCauda(Fila *f, info *reg){

    if(testaVazia(f)) return 0;
    *reg = f->vetFila[f->cauda];
    return 1;
}

int testaVazia(Fila *f){
    return (f->tamanhoDaFila == 0);
}

int testaCheia(Fila *f){
    return (f->tamanhoDaFila == f->tamVetor);
}

int reinicializa(Fila *f){

    f->cauda = -1;
    f->frente = 0;
    f->tamanhoDaFila = 0;

    return 1;
}



int main(){
    Fila *caminho = cria(1000005, sizeof(info));

    int n, m; scanf("%d %d", &n, &m);

    static char labirinto[1005][1005];
    static int vis[1005][1005];
    static char letras[1005][1005];

    info inicio = {0,0}, final = {0,0};

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf(" %c", &labirinto[i][j]);
            if(labirinto[i][j] == 'A'){
                inicio.i = i;
                inicio.j = j;
            }
            if(labirinto[i][j] == 'B'){
                final.i = i;
                final.j = j;
            }
            vis[i][j] = 0;
            letras[i][j] = 'O';
        }
    }

    

    int achou = 0;
    int i = inicio.i, j = inicio.j;

    enfileira(caminho, &inicio);
    vis[i][j] = 1;
    letras[i][j] = 'I';

    int dx[4] = {0, 1, 0, -1}; // direita, baixo, esquerda, cima
    int dy[4] = {1, 0, -1, 0};

    while(!achou && !testaVazia(caminho)){
        info aux;
        desenfileira(caminho, &aux);
        i = aux.i;
        j = aux.j;        

        for(int k = 0;k < 4;k++){
            if((i + dx[k] < 0 || i + dx[k] >= n) || (j + dy[k] < 0 || j + dy[k] >= m)) continue;
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(labirinto[ni][nj] == 'B'){
                info b = {ni, nj};
                if(ni - 1 == i) letras[ni][nj] = 'D';
                else if(ni + 1 == i) letras[ni][nj] = 'U';
                else if(nj - 1 == j) letras[ni][nj] = 'L';
                else if(nj + 1 == j) letras[ni][nj] = 'R';
                enfileira(caminho, &b);
                achou = 1;
            }

            if(ni >= 0 && ni < n && nj >= 0 && nj < m && labirinto[ni][nj] != '#' && vis[ni][nj] == 0){
                info a = {ni, nj};
                enfileira(caminho, &a);
                vis[ni][nj] = 1;
                if(ni - 1 == i) letras[ni][nj] = 'D';
                else if(ni + 1 == i) letras[ni][nj] = 'U';
                else if(nj - 1 == j) letras[ni][nj] = 'R';
                else if(nj + 1 == j) letras[ni][nj] = 'L';
            }
        }
    }


    if(!achou){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        char casa[1000005];
        int add = 0;

        i = final.i;
        j = final.j;

        while(letras[i][j] != 'I'){
            casa[add] = letras[i][j];
            add++;

            if(letras[i][j] == 'L') j++;
            else if(letras[i][j] == 'R') j--;
            else if(letras[i][j] == 'U') i++;
            else if(letras[i][j] == 'D') i--;
        }

        printf("%d\n", add);
        for(int l = add-1;l >= 0;l--){
            printf("%c", casa[l]);
        } 
        printf("\n");
    }


}