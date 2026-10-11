#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

  typedef struct {
        float A;
        float B;
        float C;
        float D;
        float X;
    }Origem_t;
 

float **inicializar_matriz(int m){   
    float **matriz = (float **)malloc(m  * sizeof(float *));

    for(int i = 0; i < m; i++){
        matriz[i] = (float *)malloc(m * sizeof(float));
    }
    return matriz;
}
// linha_sup = (0, n)
// coluna_dir = (n, n-1) 
// linha_inf = linha(n-1, n)
// coluna_esq = coluna (n, 0)

void converter(float **matriz, int m){
    float min = matriz[0][0];
    float max = matriz[0][0];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(matriz[i][j] < min){
                min = matriz[i][j];
            }
            if(matriz[i][j] > max){
                max = matriz[i][j];
            }
        }
    } //Obtenho os maiores e menores valores da matriz para normalizar entre 0 e 255;


    float temp = min; 
    min = max; //Realizo essa inversão de maior por menor para que os mairoes valores estejam mais próximos de preto (0) e os menores mais próximos de branco(255);
    max = temp;

    if(min == max){
        return;
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            float resultado = ((matriz[i][j] - min) / ((max - min)) * 255.0  );
            matriz[i][j] = (resultado > (int)resultado ? (int)resultado + 1 : (int)resultado);
        }
    }
    
}


void exibir(float **matriz, int m){
    printf("%d %d\n", m, m);
    printf("255\n");
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", (int)matriz[i][j]);
        }
        printf("\n");
    }
}

float randf(float rugosidade){
    float max = rugosidade;
    float min = - rugosidade; //Definição da rugosidade como variação máxima e mínima do terreno;
    return ((float)rand() / RAND_MAX) * (max - min) + min;
}

void preencher_matriz_div_conq(float **matriz, int linha_sup, int coluna_dir, int linha_inf, int coluna_esq, float rugosidade){
    if(linha_inf - linha_sup == 1 && coluna_dir - coluna_esq == 1){
        return;
    }

    float varicacao = randf(rugosidade);
 
    int meio_linha = (linha_sup + linha_inf)/2;
    int meio_coluna = (coluna_dir + coluna_esq)/2;  

    Origem_t origem;
    origem.A = matriz[linha_sup][coluna_esq];
    origem.B = matriz[linha_sup][coluna_dir];
    origem.C = matriz[linha_inf][coluna_esq];
    origem.D = matriz[linha_inf][coluna_dir];
    
    float altitude_central = (((float)(origem.A + origem.B + origem.C + origem.D)/4) + varicacao);

    origem.X = altitude_central; 
    matriz[meio_linha][meio_coluna] = origem.X;

    
    varicacao = randf(rugosidade);
    float altitude_ab = ((origem.A + origem.B + origem.X)/3) + varicacao;
    varicacao = randf(rugosidade);
    float altitude_cd = ((origem.C + origem.D + origem.X)/3) + varicacao;
    varicacao = randf(rugosidade);
    float altitude_ac = ((origem.A + origem.C + origem.X)/3) + varicacao;
    varicacao = randf(rugosidade);
    float altitude_bd = ((origem.B + origem.D + origem.X)/3) + varicacao;

    matriz[meio_linha][coluna_esq] = altitude_ac;
    matriz[linha_sup][meio_coluna] = altitude_ab;
    matriz[meio_linha][coluna_dir] = altitude_bd;
    matriz[linha_inf][meio_coluna] = altitude_cd;
    
    
    //Preenche todo o canto superior esquerdo da matriz;
    preencher_matriz_div_conq(matriz, linha_sup, meio_coluna , meio_linha, coluna_esq, rugosidade);
    
    //Preenche todo o canto superior direito da matriz;
    preencher_matriz_div_conq(matriz, linha_sup, coluna_dir, meio_linha, meio_coluna, rugosidade);
    
    //Preenche todo o canto inferior esquerdo da matriz;
    preencher_matriz_div_conq(matriz, meio_linha, meio_coluna, linha_inf, coluna_esq, rugosidade);
    
    //Preenche todo o canto inferior direito da matriz;
    preencher_matriz_div_conq(matriz, meio_linha, coluna_dir, linha_inf, meio_coluna ,rugosidade);

}


int main(){


    int n;
    scanf("%d", &n);
    int m = (1 << n) + 1; //Tamanho da matriz;
    float **matriz = inicializar_matriz(m);
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

    //Leitura das origens:
    scanf("%f %f %f %f", &origem.A, &origem.B, &origem.C, &origem.D);
    getchar(); 
    
    matriz[0][0] = origem.A;
    matriz[0][m-1] = origem.B;
    matriz[m-1][0] = origem.C; //Coordenadas das origens (Quatro Cantos + Centro);
    matriz[m-1][m-1] = origem.D;


    preencher_matriz_div_conq(matriz, 0, m-1, m-1, 0, rugosidade);
    exibir(matriz,  m);
    converter(matriz,  m);
    printf("\n");
    exibir(matriz,  m);
    
    free(matriz);
    // printf("Seed: %.2f \n Rugosidade depois: %.2f\n", seed, rugosidade);
    // printf("Origem A: %d \n Origem B: %d \n Origem C: %d \n Origem D: %d \n", origem.A, origem.B, origem.C, origem.D);
    // printf("Altitude Central: %f \n Rugosidade: %.2f\n", origem.X, rugosidade);


    return 0;
}