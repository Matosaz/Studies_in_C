#include <stdio.h>
#include <stdlib.h>

int main(){
    int newNumber = 0;
    int number = 0;
    printf("Enter the number of prices: ");
    scanf("%d", &number);

    float *prices = malloc(number * sizeof(float));

    if(prices == NULL){
        printf("Memory Allocation failed!\n");
        return 1;
    }


    for(int i = 0; i < number; i++){
        printf("Enter the #%d price: ", i + 1);
        scanf("%f", &prices[i]);
    }
    
    printf("Enter a new number of prices");
    scanf("%d", &newNumber);

    float *temp = realloc(prices, newNumber * sizeof(float));

    if(temp == NULL){
        printf("Memory Reallocation failed!\n");
    }
    else{
        prices = temp;
        temp = NULL;
     
          for(int i = number; i < newNumber; i++){
        printf("Enter the #%d price: ", i + 1);
        scanf("%f", &prices[i]);
    }

       for(int i = 0; i < newNumber; i++){
        printf("R$%.2f\t", prices[i]);
    }
    }

 

    free(prices);
    prices = NULL;
    return 0;
}