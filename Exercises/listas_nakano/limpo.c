#include <stdio.h>
#include <stdlib.h>

void imprime(int **m, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
   int **mat;
   int linhas = 3;
   int colunas = 4;
   mat = (int **) malloc(linhas * sizeof(int *));

   for(int i = 0; i < linhas; i++){
    mat[i] = (int *) malloc(colunas * sizeof(int));
   }

    imprime(mat, linhas, colunas); // ERRO de compilação

    for(int i = 0; i < linhas; i++){
        free(mat[i]);
    }

    free(mat);
    mat = NULL;
    
    return 0;
}