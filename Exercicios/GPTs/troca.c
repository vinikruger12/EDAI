#include <stdio.h>

void troca(int *p, int *q){
    int aux = *p;
    *p = *q;
    *q = aux;
}

int main(){
    int x = 10, y = 20;
    troca(&x, &y);

    printf("x: %d, y: %d \n", x, y);

}