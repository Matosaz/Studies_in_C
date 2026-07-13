#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;

    int *ptr_n = malloc(sizeof(int));

    if(ptr_n == NULL){
        printf("Memory allocation failed. \n");
        return 1;
    }

    printf("D'igite um número inteiro: ");
    scanf("%d", ptr_n);


    int square = (*ptr_n) * (*ptr_n);
//
    printf("Stored Value: %d\n", *ptr_n);
    printf("Squared Value: %d\n", square);

    free(ptr_n);

    return 0;


}