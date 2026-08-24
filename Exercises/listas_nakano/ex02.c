#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
} Usuario;


void imprimir(Usuario *user, int quantidade){
    for(int i = 0; i < quantidade; i++){
        printf("%s - %d\n", user[i].nome, user[i].idade);
    }
}

int main(){

    int capacidade = 2;
    int quantidade = 0;
    Usuario *user = (Usuario *)malloc(capacidade * sizeof(Usuario));

    if(user == NULL){
        printf("Alocação de memória falhou.\n");
        return 1;
    }

    printf("Insira um nome e idade (ou 'out' para sair): \n");

    while(1){

        if(capacidade == quantidade){
            capacidade *= 2;
            Usuario *temp = (Usuario *)realloc(user, capacidade * sizeof(Usuario));
            
            if(temp == NULL){
                printf("Alocação de memória falhou.\n");
                return 1;
            }
            user = temp;
        }
       
        scanf("%s", user[quantidade].nome);
           if(strcmp(user[quantidade].nome, "out") == 0){
                    break;
        }
        scanf("%d", &user[quantidade].idade);
        
      

        quantidade++;

    }
    printf("Elementos da tabela: \n");
    imprimir(user, quantidade);

    free(user);
    user = NULL;
}