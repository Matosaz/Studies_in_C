#include <stdio.h>

int main() {
    
    int array[6] = {5, 15, 25, 35, 45, 55};
    
    int *pArray = &array[0]; // Inicializa com o valor posicional de Array = [0]
    
    for(int i = 0; i<6; i++){

        printf("Element %d: %d\n",i, *(pArray + i));
    }
    printf("Third element via pointer: %d\n", *(pArray + 2));
    printf("Third element via array: %d\n", array[2]);

    return 0;
}