#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);
    
    double *ptr_array = malloc( n * sizeof(double));

    double max_value = ptr_array[0];
    
    double average = 0;


    if(ptr_array == NULL){
        printf("Memory allocation failed. \n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        scanf("%lf", &ptr_array[i]);
        
        average += ptr_array[i] / n;

        
        if(ptr_array[i] > max_value){
            max_value = ptr_array[i];
        }
        

    }

    int sizeinbytes = n * sizeof(double);


    printf("Memory Allocated: %d bytes\n", sizeinbytes);
    printf("Average: %.2lf\n", average);
    printf("Largest: %.2lf\n", max_value);


    free(ptr_array);
    


    return 0;
}