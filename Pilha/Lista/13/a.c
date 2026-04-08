#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../arqPSE.h"
#include <math.h>

int main(){
    struct stack *stk = cria(100);
    char s[20];
    scanf("%s", s);
    for(int i = 0;s[i] != '\0';i++){
        if(s[i] == '+'){
            int a = first(stk);
            pop(stk);
            int b = first(stk);
            pop(stk);
            int ans = a + b;
            info ans2 = {ans};
            insert(&ans2, stk);
        }
        else if(s[i] == '-'){
            int a = first(stk);
            pop(stk);
            int b = first(stk);
            pop(stk);
            int ans = b - a;
            info ans2 = {ans};
            insert(&ans2, stk);
        }
        else if(s[i] == '^'){
            int a = first(stk);
            pop(stk);
            int b = first(stk);
            pop(stk);
            int ans = pow(b, a);
            info ans2 = {ans};
            insert(&ans2, stk);
        }
        else if(s[i] == '/'){
            int a = first(stk);
            pop(stk);
            int b = first(stk);
            pop(stk);
            int ans = b/a;
            info ans2 = {ans};
            insert(&ans2, stk);
        }
        else if(s[i] == '*'){
        int a = first(stk);
            pop(stk);
            int b = first(stk);
            pop(stk);
            int ans = a*b;
            info ans2 = {ans};
            insert(&ans2, stk);
        }
        else{
            int x = (s[i] - '0');
            info a = {x};
            insert(&a, stk);
        }
    }

    printf("%d\n", first(stk));

}

