#include <stdio.h>

typedef struct{
    int code;
    int quantidade;
    char descricao[100];
} Produto;

int main(){

    Produto p1;
    
    printf("Insira o código do produto: ");
    scanf("%d", &p1.code);
    getchar();

    printf("Insira uma descricao para o produto: ");
    fgets(p1.descricao, sizeof(p1.descricao), stdin);

    printf("Insira a quantidade: ");
    scanf("%d",&p1.quantidade);

    printf("============================================================\n");

    
    printf("%d\n", p1.code);
    printf("%s\n", p1.descricao);
    printf("%d\n", p1.code);


    return 0;
}