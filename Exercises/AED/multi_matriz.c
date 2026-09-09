#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int linhas, colunas;
    int **M; //Matriz propriamente dita;
}matriz_t;

matriz_t *inicializar(matriz_t *matriz, int linhas, int colunas){
    if(linhas <= 0 || colunas <= 0) return NULL;
    matriz->linhas = linhas;
    matriz->colunas = colunas;

    matriz->M = (int **) calloc(linhas, sizeof(int*));

    for(int i = 0; i < linhas; i++){
        matriz->M[i] = (int *) calloc(colunas, sizeof(int));
    }
    return matriz;
}


void exibir(matriz_t *matriz, int linhas, int colunas){
     matriz->linhas = linhas;
     matriz->colunas = colunas;

     for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%2d ", matriz->M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

matriz_t *multiplicarMatrizes(matriz_t *A, matriz_t *B){
    if(A->colunas != B->linhas) return NULL;

    matriz_t *C = (matriz_t *) malloc(sizeof(matriz_t));
    inicializar(C, A->linhas, B->colunas);
    int i,k,j;
    int valor;

    for(i = 0; i < A->linhas; i++){
        for(j = 0; j < B->colunas; j++){
            valor = 0;
            for(k = 0; k < A->colunas; k++){
                valor += A->M[i][k] * B->M[k][j]; 
            }
            C->M[i][j] = valor;
        }
    }
    return C;
}


void inserir(matriz_t *matriz, int linhas, int colunas){
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz->M[i][j] = rand() % 10;
        }
    }
}

void flush(matriz_t *matriz){
    for(int i = 0; i < matriz->linhas; i++){
        free(matriz->M[i]);
    }
    free(matriz->M);
}


int main(){
    matriz_t *M1 = (matriz_t *) malloc(sizeof(matriz_t)); //alocar espaço para a struct;

    M1->linhas = 2; //M23
    M1->colunas = 3;
    inicializar(M1, M1->linhas, M1->colunas);
    inserir(M1, M1->linhas, M1->colunas);
    exibir(M1, M1->linhas, M1->colunas);
    

    
    matriz_t *M2 = (matriz_t *) malloc(sizeof(matriz_t)); //alocar espaço para a struct;
    M2->linhas = 3, //M31
    M2->colunas = 1,
    inicializar(M2, M2->linhas, M2->colunas);
    inserir(M2, M2->linhas, M2->colunas);
    exibir(M2, M2->linhas, M2->colunas);



    matriz_t *C = multiplicarMatrizes(M1, M2);

    if(C!= NULL) printf("Matriz resultante: \n");{
    exibir(C, C->linhas, C->colunas);

    flush(C);
    free(C);
    }

    free(M1);
    free(M2);
    return 0;
}