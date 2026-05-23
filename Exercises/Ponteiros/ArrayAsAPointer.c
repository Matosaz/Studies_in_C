#include <stdio.h>

int main() {
    
    int number[4] = {10, 20, 30, 40};
    int* ptr = &number[0];
    ptr = number;
    printf("%p\n", number);
    printf("%p\n", &number[0]);

    printf("%p\n", ptr);
    printf("%d\n", *number);
    printf("%d", *ptr);

    // Este desafio demonstra que o nome do array atua como um ponteiro
    // constante para o primeiro elemento, e que numbers, &numbers[0] e
    // ptr contêm o mesmo endereço de memória quando ptr recebe o nome do 
    // array.

    return 0;
}