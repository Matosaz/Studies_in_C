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
 
int main(){


    int n;
    scanf("%d", &n);
    int m = pow(2, n) + 1; //Tamanho da matriz;
    int matriz[m][m];
    //Cada elemtno Aij da matriz representa um pixel (A altitude do terreno no caso);
    //Cada pixel tem valor entre 0 e 255, sendo 0 o ponto mais baixo e 255 o ponto mais alto;
  
    Origem_t origem;
    origem.A = matriz[0][0];
    origem.B = matriz[0][m-1];
    origem.C = matriz[m-1][0]; //Coordenadas das origens (Quatro Cantos + Centro);
    origem.D = matriz[m-1][m-1];
    origem.X = (float)matriz[m/2][m/2];

    float seed = 0;
    scanf("%f", &seed); //Seed responsável pela randomização 
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

    float altitude;
    float altitude_central = (float)(((origem.A + origem.B + origem.C + origem.D)/4) + rugosidade);

    origem.X = altitude_central;

    float altitude_ab = (float)((origem.A + origem.B + origem.X)/3) + rugosidade;
    float altitude_ac = (float)((origem.A + origem.C + origem.X)/3) + rugosidade;
    float altitude_bd = (float)((origem.B + origem.C + origem.X)/3) + rugosidade;
    float altitude_cd = (float)((origem.C + origem.D + origem.X)/3) + rugosidade;



    printf("Seed: %.2f \n Rugosidade depois: %.2f\n", seed, rugosidade);
    printf("Origem A: %d \n Origem B: %d \n Origem C: %d \n Origem D: %d \n", origem.A, origem.B, origem.C, origem.D);
    printf("Altitude Central: %f \n Rugosidade: %.2f\n", origem.X, rugosidade);

    
    return 0;
}