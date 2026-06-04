#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){

    int n;
    scanf("%d", &n);
    
    int *ptr_array = malloc( n * sizeof(int));

    int minimum = INT_MAX;
    
    int sum = 0;

    double average = INT_MAX;

    int above_average = 0;

    int bytes_allocated = n * sizeof(int);
    
    if(ptr_array == NULL){
            printf("Memory allocation failed. \n");
            return 1;
        }
        else{
            printf("\nArray of size [%d] created successfully!\n", n);
        }

    for(int i = 0; i < n; i++){
        scanf("%d", &ptr_array[i]);
        
        sum += ptr_array[i];

        if(minimum > ptr_array[i]){
            minimum = ptr_array[i];
        }
    }

    average = (double)sum / n;

    for(int i = 0; i < n; i++){
        if(ptr_array[i] > average){
            above_average++;
        }
    }

    printf("Minimum: %d\n", minimum);

    printf("Sum: %d\n", sum);

    printf("Average: %.2f\n", average);

    printf("Above Average: %d\n", above_average);

    printf("Memory Used: %d\n", bytes_allocated);

    free(ptr_array);
    printf("Memory freed sucessfully!\n");
    


    return 0;
}