#include <stdio.h>


int main(){


    int rows = 0, cows = 0;
    char symbol = '\0';


    printf("Insert the number of rows: \n");
    scanf("%d", &rows);

    printf("Insert the number of cows: \n");
    scanf("%d", &cows);

    printf("Insert the symbol you want to use: \n");
    scanf(" %c", &symbol);

    for(int i = 0; i <= rows; i++){
        for(int j = 0; j <= cows; j++){
            printf("%c", symbol);
        }
        printf("\n");
    }
    
    
    return 0;
}