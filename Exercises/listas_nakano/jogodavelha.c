#include <stdio.h>
#include <stdlib.h>


void imprimir(char matriz[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){                    
            printf(" %c|", matriz[i][j]);
        }
        printf("\n");
    }
}

int isValid(char matriz[3][3], int linha, int coluna){
    if(matriz[linha][coluna] != ' ' || linha<0 || linha>2 || coluna<0 || coluna>2){
        return 1; // Não é válido
    }
    return 0; // É válido
}


void jogador_1(char matriz[3][3]){
    int linha, coluna;

    printf("Jogador 1 (X) - Digite a linha e coluna (0-2):\n");
    scanf("%d%d", &linha, &coluna);

    if(matriz[linha][coluna] == ' ' && isValid(matriz, linha, coluna) == 0){
        matriz[linha][coluna] = 'X';
    }
    else{
        printf("Posição inválida! Tente novamente.\n");
        jogador_1(matriz);
    }
}

void jogador_2(char matriz[3][3]){
    int linha, coluna;

    printf("Jogador 2 (O) - Digite a linha e coluna (0-2):\n");
    scanf("%d%d", &linha, &coluna);

    if(matriz[linha][coluna] == ' ' && isValid(matriz, linha, coluna) == 0){
        matriz[linha][coluna] = 'O'; 
    }
    else{
        printf("Posição inválida! Tente novamente.\n");
        jogador_2(matriz);
    }
}
    
   
void venceu(char matriz[3][3], int keep_playing){
        for(int i = 0; i < 3;i++){
            
            // Checa vitória por linha
            if(matriz[i][0]==matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][2] !=' ' ){
                printf("Jogador %c venceu!\n", matriz[i][0]);
                exit(1);
                keep_playing = 0;
            }

            //Checa vitória por coluna
            if(matriz[0][i]==matriz[1][i] && matriz[1][i] == matriz[2][i] && matriz[2][i] != ' '){
                printf("Jogador %c venceu!\n", matriz[0][i]);
                exit(1);
                keep_playing = 0;   
            }
            //Checa vitória por diagonal
            if((matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] && matriz[2][2] != ' ') ||
               (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0] && matriz[2][0] != ' ')){
                printf("Jogador %c venceu!\n", matriz[0][0]);
                exit(1);
                keep_playing = 0;
            }

            if(matriz[i][0] != ' ' && matriz[i][1] != ' ' && matriz[i][2] != ' ' &&
               matriz[0][i] != ' ' && matriz[1][i] != ' ' && matriz[2][i] != ' '){
                printf("Velha!\n");
                exit(1);
                keep_playing = 0;
            }
           
        } 

    }

int main(){

    char matriz[3][3] = {{' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '}
                        };
 

    int keep_playing = 1;


    while(keep_playing == 1){
        imprimir(matriz);
        jogador_1(matriz);
        imprimir(matriz);
        jogador_2(matriz);
        
        venceu(matriz, keep_playing);
        if(keep_playing != 1){
            imprimir(matriz);
            break;
    }

};
    return 0;
    
}