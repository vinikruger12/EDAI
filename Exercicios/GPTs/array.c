#include <stdio.h>

int main(){
    int v[5] = {1,2,3,4,5};
    int *p = v;
    for(int i = 0;i < 5;i++){
        printf("v[%d] = %d\n", i, *(p++));
    }
}