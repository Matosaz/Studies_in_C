#include <stdio.h>


void soma(int* n){
        (*n)+= 5; // Modificando o valor da variável "idade" utilizando ponteiro
}

int main(){

    int idade = 20;
    printf("Idade antes da soma:%d\n", idade);
    soma(&idade); // Passando o endereço da variável para a função soma
    printf("Idade depois da soma: %d\n", idade);
    return 0;
}