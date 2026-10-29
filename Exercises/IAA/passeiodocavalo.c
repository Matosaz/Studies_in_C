#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define N 8
int i, j;
int t[N][N];
int pos_a[N] = {2, 1, -1, -2, -2, -1, 1, 2};
int pos_b[N] = {1, 2, 2, 1, -1, -2, -2, -1};
bool deucerto;

typedef enum {a, b, c, d, e, f, g, h} Colunas;

int contarmovimentos(int x, int y){
    int count = 0;
    for(int i = 0; i < N; i++){
        int u = x + pos_a[i];
        int v = y + pos_b[i];
        if((u >= 0 && u < N && v >= 0 && v < N) && t[u][v] == 0){
            count++;
        } 
    }
    return count;
}

bool tenta(int i, int x, int y){
    if(i > N * N){
        deucerto = true;
        return true;
    }

    int movimentos[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int acessos[8];

    for(int k = 0; k < 8; k++){
        int u = x + pos_a[k];
        int v = y + pos_b[k];

        if((u >= 0 && u < N && v >= 0 && v < N) && t[u][v] == 0){
                acessos[k] = contarmovimentos(u, v);
        }else{
            acessos[k] = 9;
        }
    }

    for(int c = 0; c < 7; c++){
        for(int d = c + 1; d < 8; d++){
            if(acessos[movimentos[c]] > acessos[movimentos[d]]){
                int temp = movimentos[c];
                movimentos[c] = movimentos[d];
                movimentos[d] = temp;
            }
        }
    }
    
    for(int k = 0; k < 8; k++){
        int idx = movimentos[k];
        int u = x + pos_a[idx];
        int v = y + pos_b[idx];

        if(acessos[idx] == 9) break;
        t[u][v] = i;
        if(tenta(i+1, u, v)) return true;
        t[u][v] = 0;
    }
    return false;
}


void exibir(){
     int count = 8;
     for(int i = 0; i < N; i++){
        printf("%2d |", count);
        for(int j = 0; j < N; j++){
            printf("%5d", t[i][j]);
        }
        count--;
        printf("\n");
    }
    printf("    ----------------------------------------------\n");
    printf("        a    b    c    d    e    f    g    h\n");
}


int main(){

    char entrada[10];
    int colunaChar;
    int linhaXadrez;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            t[i][j] = 0;
        }
    }

    //Posição inicial:
    exibir();
    printf("Escolha uma posição inicial no tabuleiro (Ex: e4): \n");
    if(scanf("%9s", entrada) != 1) return  1;

    if(sscanf(entrada, " %c%d", &colunaChar, &linhaXadrez) != 2){
        printf("Formato inválido\n");
        return 1;
    }

    int coluna = (colunaChar >= 'a') ? (colunaChar - 'a') : (colunaChar - 'A');
    int linha = 8 - linhaXadrez;

    if(coluna < 0 || coluna >= N || linha < 0 || linha >= N){
        printf("Posição inválida! Utilize valores de a1 até h8!\n");
    }

    t[linha][coluna] = 1;
    tenta(2, linha, coluna);
    if(!deucerto){
        printf("Sem solução!\n");
        return 0;
    }
    exibir();
    return 0;
}