#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int idade;
    char nome[50];
} Pessoa;

int main(){
    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));

    p->idade = 25;
    
    printf("%d\n", p->idade);

    free(p);
    return 0;
}