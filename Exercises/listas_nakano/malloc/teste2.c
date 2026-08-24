#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int** alocar(int linhas, int colunas){
//     int ** m = (int **)malloc(linhas * sizeof(int *));
//         for(int i = 0; i < linhas; i++){
//             m[i] = malloc(colunas * sizeof(int));
//         }
//     return m;
// };

void preencher(int **m, int linhas, int colunas){
   for(int i = 0; i <linhas; i++){
    for(int j = 0; j < colunas; j++){
        m[i][j] = rand() % 10;
    }
   }
};

void imprimir(int **m, int linhas, int colunas){
   for(int i = 0; i <linhas; i++){
    for(int j = 0; j < colunas; j++){
      printf("%d ", m[i][j]);
    }
    printf("\n");
   }
   printf("\n");
};

int main(){
    srand(time(NULL));


    int linhas;
    int colunas;
    
    printf("Linhas: \n");
    scanf("%d", &linhas);

    printf("Colunas: \n");
    scanf("%d", &colunas);


    
    // int **matriz = alocar(linhas, colunas);

   int **matriz = (int **)malloc(linhas * sizeof(int*));

   for(int i = 0; i < linhas; i++){
    matriz[i] = (int *)malloc(colunas * sizeof(int));
   }
    
    imprimir(matriz, linhas, colunas);
    preencher(matriz, linhas, colunas);
    imprimir(matriz, linhas, colunas);

    for(int i = 0; i < linhas; i++){
        free(matriz[i]);
    }

    free(matriz);
    
    
    return 0;
}