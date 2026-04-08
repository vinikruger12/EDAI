#include "arqPSE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int n, m;
    printf("Digite o tamanho da matriz\n");
    printf("Digite N\n");
    scanf("%d", &n);

    printf("Digite M\n");
    scanf("%d", &m);

    struct stack *stk = cria(n*m);
    int mat[n][m];

    printf("A seguir digite a matriz \n");

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%d", &mat[i][j]);
        }
    }
    
    int vis[n][m];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            vis[i][j] = 0;
        }
    }

    int multiplicador = 2;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){

            if(mat[i][j] == 1 && !vis[i][j]){
                vis[i][j] = multiplicador;

                int dx[4] = {1, 0, 0, -1};
                int dy[4] = {0, 1, -1, 0};
                info reg = {i, j};
                insert(&reg, stk);
                int ii = i, jj = j;
                while(!vazia(stk)){
                    int achou = 0;
                    for(int k = 0;k < 4;k++){
                        int ni = ii + dx[k];
                        int nj = jj + dy[k];

                        if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && mat[ni][nj]){
                            info aux = {ni, nj};
                            insert(&aux, stk);
                            vis[ni][nj] = multiplicador;
                            achou = 1;
                            ii = ni;
                            jj = nj;
                        }
                    }
                    if(!achou){
                        pop(stk);
                        info kk = first(stk);
                        ii = kk.x;
                        jj = kk.y;
                    }
                }
                multiplicador++;
            }
            
        }
    }


    int vector[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(vis[i][j] != 0 && vis[i][j] != 1) vector[vis[i][j]]++;
        }
    }

    printf("\n");
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            printf("%d ", vis[i][j]);
        }
        printf("\n");
    }

    int indiceMaior = 0;
    int aux = vector[0];
    for(int i = 0;i < 20;i++){
        if(vector[i] > aux){
            indiceMaior = i;
            aux = vector[i];
        }
    }

    printf("A maior caixa é a caixa do %d\n", indiceMaior);


}