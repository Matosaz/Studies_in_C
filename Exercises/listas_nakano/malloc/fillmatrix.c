#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void preencher(int **mat, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            mat[i][j] = rand() % 10; 
        }
    }
};

void imprimir(int **mat, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%d ", mat[i][j]); 
        }
        printf("\n");
    }
    printf("\n");
};

int main(){

    srand(time(NULL));


    int linhas, colunas;

    printf("Linhas: \n");
    scanf("%d", &linhas);
    
    printf("Colunas: \n");
    scanf("%d", &colunas);

    int **matriz;
    matriz = (int **)calloc(linhas, sizeof(int*));
    for(int i = 0; i < linhas; i++){
        matriz[i]= calloc(colunas, sizeof(int));
    }

    if(matriz == NULL){
        printf("Erro na alocação\n");
        return 1;
    }   
    imprimir(matriz, linhas, colunas);
    preencher(matriz, linhas, colunas);
    imprimir(matriz, linhas, colunas);
    
    for(int i = 0; i < linhas; i++){
        free(matriz[i]);
    }

    free(matriz);
    matriz = NULL;

    return 0;
}