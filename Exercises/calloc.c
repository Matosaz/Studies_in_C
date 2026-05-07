#include <stdio.h>
#include <stdlib.h>

int main (){


    // Calloc: Contiguous Allocation
    // Allocates memory dynamically and sets all allocated bytes to 0;
    // malloc() is faster, but calloc() leads to less bugs
    // calloc(#, size);

    int number = 0;
    printf("Insert the number of players: \n");
    scanf("%d", &number);

    int *scores = calloc(number, sizeof(int));

    if(scores == NULL){
        printf("Memory allocation failed!\n");
    }


    
    for(int i = 0; i < number; i++){
        printf("Enter the score #%d: ",i+1);
        scanf(" %i", &scores[i]);
    }

    
    for(int i = 0; i < number; i++){
        printf("%d ", scores[i]);
    }

    free(scores);
    scores = NULL;

    return 0;
}