
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);
    int **matriz;
    int linhas, colunas;

    matriz = malloc(linhas * sizeof(int *));
    for(int i = 0; i < n; i++){
        matriz[i] = malloc(colunas * sizeof(int));
    }
    
    for(int i = 0; i < n; i++){
        for(int k = n - 1; k > i ; k--){
            printf(" ");
        }
        for(int j = 0; j < i + 1; j++){
            if(j == 0 || j == i){
                matriz[i][j] = 1;
            }
            else{
            matriz[i][j] = matriz[i-1][j] + matriz[i-1][j-1];
            }
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

