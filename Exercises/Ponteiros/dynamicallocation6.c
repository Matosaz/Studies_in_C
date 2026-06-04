#include <stdio.h>
#include <stdlib.h>

int main(){

    int ROWS, COLS;
    scanf("%d%d", &ROWS, &COLS);


    int **array = malloc( ROWS * sizeof(int *));

    int sum = 0;
    int max_value = 0;
    double average = 0.00;


    for(int i = 0; i < ROWS; i++){
    array[i] = malloc(COLS * sizeof(int));
    
    if(array[i] == NULL || array == NULL){
        printf("Memory allocation failed. \n");
        return 1;
    }
    else{
        printf("Matrix of size [%d]x[%d] created. \n", ROWS, COLS);
    }
}

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j< COLS; j++){
            scanf("%d", &array[i][j]);
            sum += array[i][j];    
            
            if(array[i][j] > max_value){
                max_value = array[i][j];
                 }
          }
    }        

    
    average = (double)sum / (ROWS * COLS);

    int bytes_allocated = ((ROWS * sizeof(int *)) + (ROWS * COLS * sizeof(int)));

    printf("Sum: %d\n", sum);
    printf("Largest: %d\n", max_value);
    printf("Average: %.2lf\n", average);
    printf("Total memory allocated: %d bytes\n", bytes_allocated);


     for(int i = 0; i < ROWS; i++){
        free(array[i]);
    }
    free(array);
   


    return 0;
}