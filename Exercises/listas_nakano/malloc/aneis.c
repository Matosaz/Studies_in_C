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
// J = 0 || J = colunas - 1         // I = 0 || i = linhas - 1;
// j = 1 || j = colunas - 2         // i = 1 || i = linhas - 2;
void preenche(int **mat, int linhas, int colunas){
    
    int camadas = (linhas < colunas ? linhas : colunas) / 2;
    for(int camada = 0; camada < camadas; camada++){
        for(int i = camada; i < linhas - camada; i++){
            for(int j = camada; j <colunas - camada; j++){
                if(j == camada ||  j == colunas - camada - 1 || i == camada || i == linhas - camada - 1) {
                    mat[i][j] = camada;
                }
                else{
                    mat[i][j] = camada + 1;

                }
            }
        }
    }    
};

int main() {
   int **mat;
   int linhas;
   int colunas;

   printf("Insira o número de linhas: \n");
   scanf("%d", &linhas);
   
   printf("Insira o número de colunas: \n");
   scanf("%d", &colunas);
   
   mat = (int **) calloc(linhas, sizeof(int *));

   for(int i = 0; i < linhas; i++){
    mat[i] = (int *) calloc(colunas, sizeof(int));
   }
    preenche(mat,  linhas,  colunas);
    imprime(mat, linhas, colunas); // ERRO de compilação

    for(int i = 0; i < linhas; i++){
        free(mat[i]);
    }

    free(mat);
    mat = NULL;
    
    return 0;
}