#include "../arqPSE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//INSERCTION SORT
int main(){
    int v[10] = {8, 29, 12, 13, 10, 7, 1, 30, 20, 55};
    struct stack *principal = cria(10);
    struct stack *aux = cria(10);

    info a = {v[0]};
    insert(&a, principal);
    
    for(int i = 1;i < 10;i++){

        while(!vazia(principal) && v[i] > first(principal)){
            int a = first(principal);
            info aa = {a};
            insert(&aa, aux);
            pop(principal);
        }

        info b = {v[i]};
        insert(&b, principal);

        while(!vazia(aux)){
            info c = {first(aux)};
            insert(&c, principal);
            pop(aux);
        }

    }

    while(!vazia(principal)){
        int d = first(principal);
        printf("%d\n", d);
        pop(principal);
    }


}