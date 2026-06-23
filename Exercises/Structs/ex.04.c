#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int n_conta;
    float saldo;
} ContaBancaria;

void operacao(int opcao, ContaBancaria *c);
void opcoes();



int main() {
    int opcao; 

    ContaBancaria *c = malloc(sizeof(ContaBancaria)); 

    c -> saldo = 500;

    printf("\n");
    printf("Bem vindo ao banco Master!");
    printf("Como podemos lhe auxiliar: \n");
    while(1){
   
    opcoes();
    scanf("%d", &opcao);

    if(opcao == 4){
        printf("Até breve!\n");
        free(c);
        return 0;
    }

    operacao(opcao, c);
    }
   
    return 0;
}


void operacao(int opcao, ContaBancaria *c){
    float saque;
    switch(opcao){
        case 1:
        printf("Saldo atual: %.2f\n", c->saldo);
        break;


        case 2:
        printf("Insira a quantia que deseja sacar: ");
        scanf("%f", &saque);
        
        if(saque > c->saldo){
            printf("Saldo insuficiente.\n");
            break;
        }
        else if(saque < 0){
            printf("Não foi possível realizar essa operação\n");
            break;
        }
        else{
            c->saldo -= saque;
            printf("Saque de %.2f realizado com sucesso!\n", saque);
        }
        break;
        
        case 3:
        float valor;
        printf("Qual quantia você almeja depositar?");
        scanf("%f", &valor);
    
        if(valor < 0){
            printf("Não foi possível realizar essa operação\n");
            break;
        }
        else{
            c->saldo += valor;
            printf("Depósito de %.2f realizado com sucesso!\n", valor);
        }
        break;

        default:
        printf("Selecione uma operação válida.\n");
        break;
    }
  
}

void opcoes(){
    printf("1 - Extrato\t 2 - Sacar\n");
    printf("3 - Depositar\t 4 - Sair\n");

}