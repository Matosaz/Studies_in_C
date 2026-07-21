#include <stdio.h>
#include <stdlib.h>


int main() {
    
    
    int **matriz;
    int linhas, colunas;
    
    printf("Quantas companhias aéreas terãovoos hoje? \n");
    scanf("%d", &linhas);
    
    matriz = malloc(linhas * sizeof(int*));
    
    int *colunas_per_line = malloc(linhas * sizeof(int)); //Aloca colunas de tamanhos distintos para cada linha;

    for(int i = 0; i < linhas; i++){
         printf("Quantos voos a companhia %d tera hoje? \n", i);
         scanf("%d", &colunas_per_line[i]);
         matriz[i] = malloc(colunas_per_line[i] * sizeof(int));
   }

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas_per_line[i]; j++){
            int hora = rand() % 24;
            int minuto = rand() % 60;

            matriz[i][j] = (hora * 100) + minuto;
        }
    }

    printf("\n---- Horários dos Voos ----\n");
    for(int i = 0; i < linhas; i++){
        printf("Companhia %d: ", i);
        for(int j = 0; j < colunas_per_line[i]; j++){
            int h = matriz[i][j] / 100;
            int m = matriz[i][j] % 100;
            
            printf("[%02d.%02d]", h, m);
        }
        printf("\n");
    }

    for(int i = 0; i < linhas; i++){
        free(matriz[i]);
    }
    free(matriz);
    free(colunas_per_line);


    return 0;
}