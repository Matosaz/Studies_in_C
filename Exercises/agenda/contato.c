#include <stdio.h>
#define _GNU_SOURCE
#include <string.h> 
#include "contato.h"

void cadastrar(Contato lista[], int *total){

    if(*total >= MAX_CONTATOS){
        puts("Agenda lotada.");
        return;;
    }

    Contato novo;

    novo.id = (*total == 0) ? 1 : lista[*total - 1].id + 1; //Adiciona um valor único ao id distinto do anterior

    printf("Nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    
    printf("Telefone: ");
    fgets(novo.telefone, sizeof(novo.telefone), stdin);
    
    printf("Email: ");
    fgets(novo.email, sizeof(novo.email), stdin);
    
    lista[(*total)++] = novo;
    puts("Contato cadastrado com sucesso!");
};


//Gera uma listagem de todos os contatos existentes -> i<*total
void listar(const Contato lista[], int total){

    for(int i = 0; i<total; i++){
        printf("%-4d %-30s %-15s %-30s\n",
            lista[i].id,
            lista[i].nome,
            lista[i].telefone,
            lista[i].email);
    }

};


//Search by Name
void buscar(const Contato lista[], int total){
 
    char termo[TAM_NOME];
    printf("Buscar por nome: ");
    fgets(termo, sizeof(termo), stdin);

    int encontrado = 0;

    for(int i = 0; i < total; i++){
        if(strstr(lista[i].nome, termo)){
            printf("[%d] %s - %s\n",
            lista[i].id, lista[i].nome, lista[i].telefone);
            encontrado = 1;
        }
    }
    if(!encontrado) puts("Nenhum resultado encontrado.");
}


     

void editar(Contato lista[], int total){
    
    if(total == 0){
        puts("Nenhum contato encontrado.");
        return;
    }

    int id;

    printf("Insira o ID do contato a editar: \n");
    scanf("%d", &id);

    int idx = -1;

    for(int i = 0; i < total; i++){
        if(lista[i].id == id){
            idx = 1;
            break;
        }
    }

    if(idx == -1){
        puts("ID não encontrado.");
        return;
    }
    printf("\nContato atual:\n");
    printf("  Nome:     %s\n", lista[idx].nome);
    printf("  Telefone: %s\n", lista[idx].telefone);
    printf("  E-mail:   %s\n", lista[idx].email);


    int opcao;
    printf("\nQual alteração você deseja realizar?\n");
    printf("1 - Nome\n");
    printf("2 - Email\n");
    printf("3 - Telefone\n");
    printf("Opção: ");
    scanf(" %d", &opcao);
    getchar();

    switch (opcao) {
        case 1:
        printf("Novo nome: ");
        fgets(lista[idx].nome, sizeof(lista[idx].nome), stdin);
        break;

        case 2:
       printf("Novo email: ");
        fgets(lista[idx].email, sizeof(lista[idx].email), stdin);
        break;
          
        case 3:
           printf("Novo telefone: ");
        fgets(lista[idx].telefone, sizeof(lista[idx].telefone), stdin);
        break;
      


        default: 
        printf("Opção inválida. Nenhuma alteração executada.");
        break;
    }
    puts("Contato atualizado com sucesso!");
};


void remover(Contato lista[], int *total){
    int id;
    printf("Insira o ID do contato a remover: ");
    scanf("%d", &id);
       
    for(int i = 0; i < *total; i++){

        for(int j = i; j < *total - 1; j++){
            lista[j] = lista[j + 1];
            (*total)--;
            puts("Contato removido");
            return;
        }
    }
    puts("ID não encontrado.");
};