#include <complex.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int valor;
    struct No* proximo;
} No;

void inserir(No** lista, int valor){
    No* novo = malloc(sizeof(No));

    if(novo == NULL){
        printf("Alocação falhou\n");
        return;
    }

    novo->valor = valor;
    novo->proximo = NULL;
    
    if(*lista == NULL){
        *lista = novo;
    } else{
        No* atual = *lista;                 // atual
                                       // 10 -> 23 -> NULL
        while(atual->proximo != NULL){ //Adiciona enquanto o elemento atual for diferente de NULL;
            atual = atual->proximo;
        }
        atual->proximo = novo; //Novo atual torna-se o próximo elemento;
    }
    printf("Valor %d inserido com sucessom\n", valor);
}

void listar(No* lista){
    if(lista == NULL){
        printf("A lista está vazia\n");
        return;
    }
    printf("Lista de elementos: \n");
    while(lista != NULL){
        printf("%d -> ", lista->valor);
        lista = lista->proximo;
    }
    printf("NULL\n");
}

void remover(No** lista, int valor){
    No* atual = *lista;
    No* anterior = NULL;
    
    while(atual != NULL && atual->valor != valor){
        anterior = atual;
        atual = atual->proximo;
    }
    
    if(atual == NULL){
        printf("Elemento %d, não encontrado", valor);
        return;
    }
    
    if(anterior == NULL){
        *lista = atual->proximo;
    }else{
        anterior->proximo = atual->proximo; // Mantém a ordem de apontamento correta; 
    }
    free(atual);
    printf("Valor %d removido com sucesso\n", valor);
}

int main() {
    
    No* lista = NULL;

    int opcao;
    int valor;

    do{
        printf("1 - Inserir elemento\n");
        printf("2 - Listar elemento\n");
        printf("3 - Remover elemento\n");
        printf("0 - Sair\n");
        
        printf("Insira sua opcao: \n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
            printf("Digite o valor para inserir: ");
            scanf("%d", &valor);
            
            inserir(&lista, valor);
            break;
            
            case 2:
            listar(lista);
            break;
            
            case 3:
            printf("Digite o valor para remover: ");
            scanf("%d",&valor);

            remover(&lista, valor);
            break;
            
            case 0:
            printf("Até mais!");
            break;

            default:
            printf("Erro durante a execução do código\n");
            break;
        }
        
    }while(opcao != 0);

    return 0;
}