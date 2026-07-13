#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int play_game(int switch_door) {

    int portas[3] = {0, 0, 0}; //Defino três portas iniciais(Todas sem prêmios)

    int porta_premiada = rand() % 3; // Sorteio uma porta para armazenar o prêmio;

    portas[porta_premiada] = 1; // Atribuo o valor da porta premiada como True = 1;

    
    int player_choice = rand() % 3; // Randomizo a escolha do player para escolher a porta;

    int host_revealed;
    for(int i = 0; i <3; i++){
        if(i != player_choice && portas[i] != 1){ //Sendo diferente da escolha do jogador e da porta que contém o prêmio; 
            host_revealed = i;
            break;
        };  
}

    if(switch_door == 1){ // Se o jogador decidiu alternar de porta: 
        for(int i = 0; i < 3; i++){
            if(i != player_choice && i != host_revealed){ // Sendo diferente da porta já escolhida e da exibida pelo entrevistador;
                player_choice = i;
                break;
            }
        }
    }


    return portas[player_choice] == 1;
}


int main(){
        
    srand(time(NULL));

    int stay_wins = 0;
    int switch_wins = 0;

    for(int i = 0; i < 1000; i++){
        if(play_game(0)){
            stay_wins++;
        }
        if(play_game(1)){
            switch_wins++;
        }
    }

    printf("Vitórias com portas mantidas: %.2f\n", (float)stay_wins / 1000 * 100);
    printf("Vitórias com portas trocadas: %.2f\n", (float)switch_wins / 1000 * 100);

    return 0;
}