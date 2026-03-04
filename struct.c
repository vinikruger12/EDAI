#include <stdio.h>

struct book{
    char title[10];
    int year;
    double price;
};

int main(){
    struct book livro = {"Machado", 2022, 50};
    printf("%s %d %f \n", livro.title, livro.year, livro.price);


    struct book *p = NULL, *q = NULL, *w = NULL;

    p = &livro;
    printf("%f %f\n", (*p).price, p->price);

}