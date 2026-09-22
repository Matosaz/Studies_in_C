#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {

    char c;
    int n;
    scanf("%d", &n);
    char matriz[n][3];


    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            scanf(" %c", &matriz[i][j]);
        }
    }

    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}