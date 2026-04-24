#include "arqPDE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int n, m;
    printf("Digite N e M: ");
    scanf("%d %d", &n, &m);

    FILE *entrada = fopen("entrada.txt", "r");
    if(entrada == NULL){
        printf("Erro ao abrir o arquivo de entrada!\n");
        return 1;
    }

    int mat[n][m];
    char linha[1000];

    for(int i = 0; i < n; i++) {
        fgets(linha, sizeof(linha), entrada);
        for(int j = 0; j < m; j++) {
            mat[i][j] = linha[j] - '0';
        }
    }

    fclose(entrada);

    struct stack *stk = cria();
    
    int vis[n][m];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            vis[i][j] = 0;
        }
    }

    int pintor = 2;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){

            if(mat[i][j] == 1 && !vis[i][j]){
                vis[i][j] = pintor;

                int dx[4] = {1, 0, 0, -1};
                int dy[4] = {0, 1, -1, 0};
                info reg = {i, j};
                insert(&reg, stk);
                int auxI = i, auxJ = j;

                while(!vazia(stk)){
                    int achou = 0;
                    for(int k = 0;k < 4;k++){
                        int ni = auxI + dx[k];
                        int nj = auxJ + dy[k];

                        if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && mat[ni][nj]){
                            info aux = {ni, nj};
                            insert(&aux, stk);
                            vis[ni][nj] = pintor;
                            achou = 1;
                            auxI = ni;
                            auxJ = nj;
                            break;
                        }
                    }
                    if(!achou) {
                        pop(stk);

                        if(!vazia(stk)){ 
                            info temp = first(stk);
                            auxI = temp.x;
                            auxJ = temp.y;
                        }

                    }
                }
                pintor++;
            }
            
        }
    }

    int totalObjetos = pintor - 2;
    int vector[totalObjetos];

    for(int i = 0; i < totalObjetos; i++) vector[i] = 0;
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(vis[i][j] >= 2) vector[vis[i][j] - 2]++;
        }
    }

    int indiceMaior = 0;

    for(int i = 1; i < totalObjetos; i++){
        if(vector[i] > vector[indiceMaior]) indiceMaior = i;
    }

    printf("No total tem %d objetos\n", totalObjetos);
    
    for(int i = 0 ; i < totalObjetos; i++){
        printf("O objeto %d tem tamanho %d\n", i+1, vector[i]);
    }


    int menorI = -1, menorJ = -1, maiorI = -1, maiorJ = -1;
    for(int i = 0;i < n;i++){

        for(int j = 0;j < m;j++){
            
            if(vis[i][j] == indiceMaior + 2 && pintor != 2){
                vis[i][j] = 1;
                if(menorI > i || menorI == -1) menorI = i;
                if(maiorI < i || maiorI == -1) maiorI = i; 

                if(menorJ > j || menorJ == -1) menorJ = j;
                if(maiorJ < j || maiorJ == -1) maiorJ = j;

            } 
            else vis[i][j] = 0;
        }
    }

    int somaI = 0, somaJ = 0;
    for(int i = menorI;i <= maiorI;i++){
        somaI += i;
    }
    for(int j = menorJ;j <= maiorJ;j++){
        somaJ += j;
    }

    int centroI = somaI / (maiorI - menorI + 1);
    int centroJ = somaJ / (maiorJ - menorJ + 1);
    
    if (vis[centroI][centroJ] == 0) printf("Esse objeto não possui um centro especifico!\n");
    else {
        if (totalObjetos == 0) printf("Como não tem objetos, não tem centro!");
        else printf("Centro do maior objeto: linha %d, coluna %d\n", centroI, centroJ);
    }
    
    FILE *saida = fopen("Saida.txt", "w");
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo de saída!\n");
        return 1;
    }

    for(int i = 0;i < n;i++){
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 1 && totalObjetos != 0) fprintf(saida, "1");
            else fprintf(saida, "0");
        }
        fprintf(saida, "\n");
    }

    fclose(saida);
    destroy(stk);

    return 0;
}

