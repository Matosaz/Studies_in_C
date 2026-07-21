#include <stdio.h>
#include <stdlib.h>


void imprimir(float **matriz, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    
    float **matriz;
    int linhas, colunas;
    printf("Digite o número de linhas do painel: \n");
    scanf("%d", &linhas);

    printf("Digite o número de colunas do painel: \n");
    scanf("%d", &colunas);
    
    float maior = 0.0;
    float volts;
    float soma = 0;

    matriz = malloc(linhas * sizeof(float *)); 
    
    for(int i = 0; i < linhas; i++){
        matriz[i] = malloc(colunas * sizeof(float));
    }

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = (float)rand() / (float)RAND_MAX * 10;
            soma += matriz[i][j];
        }
    }
    float media = soma / (linhas * colunas);
   
 int maior_l;
 int maior_c;

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(matriz[i][j+1] > maior && j+1 < colunas){
                maior = matriz[i][j+1];
                maior_l = i;
                maior_c = j+1;
            }   
        }
    }

    printf("\n\n");

    imprimir(matriz, linhas, colunas);
    
    printf("Maior voltagem detectada %.2f V\t(Na linha %d, coluna %d)\n", maior, maior_l, maior_c);
    printf("Media: %.2f V", media );
    return 0;
}