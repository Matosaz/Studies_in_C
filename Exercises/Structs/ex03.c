#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ano;
    char modelo[];
} Carro;

int main() {
    
    Carro c1;

    Carro *ptr_c = malloc(sizeof(Carro) + 50*sizeof(char)); 

    ptr_c -> ano = 2010;

    strcpy(ptr_c ->modelo,("Fiat Argo"));

    printf("%d\n", ptr_c->ano);
    printf("%s", ptr_c ->modelo);

    return 0;
}