#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int stay_win = 0;
int switch_win = 0;

int playgame(int switch_door,int *result){
    int portas[3] = {0, 0, 0}; //Defino três portas iniciais(Todas sem prêmios)

    int porta_premiada = rand() % 3; // Sorteio uma porta para armazenar o prêmio;

    portas[porta_premiada] = 1; // Atribuo o valor da porta premiada como True = 1;

    int escolha_player = rand() % 3; // Randomizo a escolha do player para escolher a porta;
   

    int porta_revelada;
    for(int i = 0; i <3; i++){
        if(i != escolha_player && portas[i] != 1){ //Sendo diferente da escolha do jogador e da porta que contém o prêmio; 
            porta_revelada = i;
            break;
        };  
}

    if(switch_door == 1){
        for(int i = 0; i < 3; i++){
            if(i != escolha_player &&  i != porta_revelada){
                escolha_player = i;
                 if(porta_premiada == escolha_player){
                switch_door++;
            }
                break;
            }
        }
    }

     if(porta_premiada == escolha_player){
                stay_win++;
            }
    
    result[0] = stay_win;
    result[1] = switch_win;

    return *result;
}


int main(){
        srand(time(NULL));
    int result[2];
    int *ptr;
    
    for(int i = 0; i < 1000; i++){
        if(playgame(0, result)){
            int stay_win = result[0];
        };
        if (playgame(1, result)){
            int switch_win = result[1];
        }
    }

    printf("Vitórias com portas mantidas: %.2f\n", (float)result[0] / 1000 * 100);
    printf("Vitórias com portas trocadas: %.2f\n", (float)result[1] / 1000 * 100);

}