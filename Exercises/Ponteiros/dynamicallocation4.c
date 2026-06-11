#include <stdio.h>
#include <stdlib.h>

int main(){

  
    int n;

    int sum = 0;

    scanf("%d", &n);

    int *p_array = calloc(n, sizeof(int));
    

    if(p_array == NULL){
            printf("Memory allocation failed. \n");
            return 1;
        }
        else{
            printf("\nMemory allocated and initialized to zero. \n");
        }


        printf("Initial Values: ");
        for(int i = 0; i < n; i++){
            printf("%d ", p_array[i]);
        }

        for(int i = 0; i < n; i++){
            scanf("%d", &p_array[i]);
            sum += p_array[i];
            printf("Updated Values: %d\n", p_array[i]);

        }

        printf("Sum: %d\n", sum);
        free(p_array);
        printf("Memory freed!\n");

    return 0;
}