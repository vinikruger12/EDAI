#include "../arqPDE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    struct stack *stk = cria(100);
    char s[10];
    scanf("%s", &s);
    int flag = 1;
    for(int i = 0;i < s[i] != 0;i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            info reg = {s[i]};
            insert(&reg, stk);
        }
        else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
            if(first(stk) == '(' && s[i] != ')') flag = 0;
            else if(first(stk) == '[' && s[i] != ']') flag = 0;
            else if(first(stk) == '{' && s[i] != '}') flag = 0;
            else{
                pop(stk);
            }
        }
    }

    if(!flag || !vazia(stk)) printf("ERRADO\n");
    else printf("CERTO\n");
    

}