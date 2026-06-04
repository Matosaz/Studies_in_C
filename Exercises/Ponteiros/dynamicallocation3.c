#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);
    
    int *ptr_array = malloc( n * sizeof(int));

    
    int sum = 0;

    if(ptr_array == NULL){
            printf("Memory allocation failed. \n");
            return 1;
        }
        else{
            printf("Memory allocation sucessful. \n");
        }

    for(int i = 0; i < n; i++){
        scanf("%d", &ptr_array[i]);
        
        sum += ptr_array[i];

    }

    int sizeinbytes = n * sizeof(int);


    printf("Sum: %d\n", sum);
    printf("Bytes Allocated: %d\n", sizeinbytes);



    free(ptr_array);
    


    return 0;
}