#include <stdio.h>

int main(){
    int *p = NULL, **pp = NULL, x = 29, y = -33;
    p = &x;
    pp = &p;

    printf("%d %d %d \n",*p, &p, p);
    printf("%d %d %d %d", pp, **pp, *pp,&p);

}