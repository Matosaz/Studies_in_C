#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

  typedef struct {
        int A;
        int B;
        int C;
        int D;
        float X;
    }Origem_t;
 


int **inicializar_matriz(int m){   
    int **matriz = (int **)malloc(m  * sizeof(int *));

    for(int i = 0; i < m; i++){
        matriz[i] = (int *)malloc(m * sizeof(int));
    }
    return matriz;
}
// linha_sup = (0, n)
// coluna_dir = (n, n-1) 
// linha_inf = linha(n-1, n)
// coluna_esq = coluna (n, 0)
void **preencher_matriz_div_conq(int **matriz, int linha_sup, int coluna_dir, int linha_inf, int coluna_esq, float rugosidade){
    if(linha_inf - linha_sup == 1 && coluna_dir - coluna_esq == 1){
        return false;
    };

    int meio_linha = (linha_sup + linha_inf)/2;
    int meio_coluna = (coluna_dir + coluna_esq)/2;  

    Origem_t origem;
    origem.A = matriz[linha_sup][coluna_esq];
    origem.B = matriz[linha_sup][coluna_dir];
    origem.C = matriz[linha_inf][coluna_esq];
    origem.D = matriz[linha_inf][coluna_dir];
    
    float altitude;
    float altitude_central = (((float)(origem.A + origem.B + origem.C + origem.D)/4) + rugosidade);

    origem.X = altitude_central;
    matriz[meio_linha][meio_coluna] = origem.X;

    float altitude_ab = ((origem.A + origem.B + origem.X)/3) + rugosidade;
    float altitude_ac = ((origem.A + origem.C + origem.X)/3) + rugosidade;
    float altitude_bd = ((origem.B + origem.D + origem.X)/3) + rugosidade;
    float altitude_cd = ((origem.C + origem.D + origem.X)/3) + rugosidade;

    matriz[meio_linha][coluna_esq] = altitude_ac;
    matriz[coluna_esq][linha_sup] = altitude_ab;
    matriz[meio_linha][coluna_dir] = altitude_bd;
    matriz[linha_inf][meio_coluna] = altitude_cd;
   

    //Preenche todo o canto superior esquerdo da matriz;
    preencher_matriz_div_conq(matriz, linha_sup, meio_coluna , linha_inf, meio_coluna, rugosidade);
    
    //Preenche todo o canto superior direito da matriz;
    preencher_matriz_div_conq(matriz, meio_coluna, coluna_dir, linha_inf, meio_linha, rugosidade);
    
    //Preenche todo o canto inferior esquerdo da matriz;
    preencher_matriz_div_conq(matriz, meio_linha, linha_sup, linha_inf, meio_coluna, rugosidade);
    
    //Preenche todo o canto inferior direito da matriz;
    preencher_matriz_div_conq(matriz, linha_sup, meio_linha, meio_coluna, coluna_dir ,rugosidade);

}
int main(){


    int n;
    scanf("%d", &n);
    int m = pow(2, n) + 1; //Tamanho da matriz;
    int **matriz = inicializar_matriz(m);
    //Cada elemtno Aij da matriz representa um pixel (A altitude do terreno no caso);
    //Cada pixel tem valor entre 0 e 255, sendo 0 o ponto mais baixo e 255 o ponto mais alto;
  
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            matriz[i][j] = 0;
        }
    }

    Origem_t origem;
  
    int seed = 0;
    scanf("%d", &seed); //Seed responsável pela randomização 
    srand(seed);

    float rugosidade = 0;
    scanf("%f", &rugosidade);
    printf("Rugosidade antes: %.2f\n", rugosidade);

    float max = rugosidade;
    float min = - rugosidade; //Definição da rugosidade como variação máxima e mínima do terreno;
    rugosidade = ((float)rand() / RAND_MAX) * (max - min) + min; 
 
 
    //Leitura das origens:
    scanf("%d %d %d %d", &origem.A, &origem.B, &origem.C, &origem.D);
    getchar(); 
    
    matriz[0][0] = origem.A;
    matriz[0][m-1] = origem.B;
    matriz[m-1][0] = origem.C; //Coordenadas das origens (Quatro Cantos + Centro);
    matriz[m-1][m-1] = origem.D;


    preencher_matriz_div_conq(matriz, 0, m-1, m-1, 0, rugosidade);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    // printf("Seed: %.2f \n Rugosidade depois: %.2f\n", seed, rugosidade);
    // printf("Origem A: %d \n Origem B: %d \n Origem C: %d \n Origem D: %d \n", origem.A, origem.B, origem.C, origem.D);
    // printf("Altitude Central: %f \n Rugosidade: %.2f\n", origem.X, rugosidade);


    return 0;
}