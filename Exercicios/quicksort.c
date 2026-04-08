#include <stdlib.h>
#include <stdio.h>

int isSorted(int v[]){
    for(int i = 1;i < 10;i++){
        if(v[i-1] > v[i]) return 0;
    }
    return 1;
}

void quicksort(int v[], int inicio, int final){
    
    if(inicio >= final) return;

    int j = inicio - 1;
    for(int i = inicio;i <= final;i++){
        if(v[final] >= v[i]){
            j++;
            if(i == j) continue;
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux; 
        }
    }

    quicksort(v, inicio, j-1);
    quicksort(v, j+1, final);

}

int main(){
    int v[10] = {5,9,2,1,8,3,7,6,4};
    quicksort(v, 0, 9);

    for(int i = 0;i < 10;i++){
        printf("%d\n", v[i]);
    }
}