#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void exibir(int **matriz, int n, int m){
     for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int ** inicializar(int n, int m){

    int **matriz = (int **)calloc(n, sizeof(int *));
    
    for(int i = 0; i < n; i++){
        matriz[i] = (int *)calloc(m, sizeof(int));
    }

    if(matriz == NULL){
        printf("Alocação dinâmica falhou");
        exit(EXIT_FAILURE);
    }

    return matriz;
}

void clean(int **matriz, int n){
     for(int i = 0; i < n; i++){
        free(*(matriz + i));
    }
    free(matriz);
}

//realiza a inversão vertical da matriz
int **inverter_vert_matriz(int **matriz, int n, int m){
    int **vert_inv_matriz = inicializar(n, m);   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
             vert_inv_matriz[i][j] = matriz[n - 1 - i][j];

             // Define o valor de i = 0 da matriz invertida como o último elemento da matriz original
             // Invertida       Original
             // Se i = 0    recebe    i = 9
             //    i = 1    recebe    i = 8
             //    i = n - 1    recebe    i = n - 1 - i da invertida  //ÚLTIMO VALOR;
        }
    }
    return vert_inv_matriz;
}


//realiza a inversão horizontal da matriz
int **inverter_hor_matriz(int **matriz, int n, int m){
    int **hor_inv_matriz = inicializar(n, m);   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
             hor_inv_matriz[i][j] = matriz[i][m - 1 - j];

             // Define o valor de j = 0 da matriz invertida como o último elemento da matriz original
             // Invertida       Original
             // Se j = 0    recebe    j = 9
             //    j = 1    recebe    j = 8
             //    j = m - 1    recebe    j = m - 1 - j da invertida  //ÚLTIMO VALOR;
        }
    }
    return hor_inv_matriz;
}

int main() {
    srand(time(NULL));

    
    int n, m;

    scanf("%d%d", &n, &m);
    int ** matriz = inicializar(n, m);
    
    exibir(matriz, n, m);
    
    for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            matriz[i][j] = rand() % 10;
        }
    }

    printf("MATRIZ ORIGINAL:\n");

    exibir(matriz, n, m);
    
    printf("METADE DIAGONAL SUPERIOR ESQUERDA DA MATRIZ ORIGINAL:\n");
     for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("METADE DIAGONAL INFERIOR ESQUERDA DA MATRIZ ORIGINAL:\n");

     for(int i = n - 1; i >= 0; i--){
        for(int j = i; j < m; j++){
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }

    
    printf("METADE DIAGONAL SUPERIOR DIREITA DA MATRIZ ORIGINAL:\n");

     for(int i = 0; i < n; i++){
        for(int k = 0; k < i; k++){
            printf("   ");
        }
        for(int j = i; j < m; j++){
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("METADE DIAGONAL INFERIOR DIREITA DA MATRIZ ORIGINAL:\n");

     for(int i = 0; i < n; i++){
       for(int k = n - 1; k > i; k--){
            printf("   ");
        }
        for(int j = 0; j <= i; j++){
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }

     printf("INVERTIDA VERTICALMENTE:\n");
     
    //Inverter matriz verticalmente
    int **vert_inv_matriz = inverter_vert_matriz(matriz, n, m);
    exibir(vert_inv_matriz,n, m);
    printf("\n");
     
    printf("INVERTIDA HORIZONTALMENTE:\n");
    // //Inverter matriz horizontalmente
    int **hor_inv_matriz = inverter_hor_matriz(matriz, n, m);
    exibir(hor_inv_matriz,n, m);


    clean(matriz, n);
    clean(hor_inv_matriz, n);
    clean(vert_inv_matriz, n);

   
    return 0;
}