#include <stdio.h>
#include "contato.h"


void salvar(const Contato lista[], int total);
int carregar(Contato lista[]);

int main(void){

    Contato lista[MAX_CONTATOS];
    int total = carregar(lista);

    int opcao;

    do{ 
        printf("\n=== AGENDA DE CONTATOS ===\n");
        printf("1. Cadastrar\n");
        printf("2. Listar\n");
        printf("3. Buscar\n");
        printf("4. Editar\n");
        printf("5. Remover\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf(" %d", &opcao);
        getchar();


        switch(opcao){
            case 1: cadastrar(lista, &total); break;
            case 2: listar(lista, total); break;
            case 3: buscar(lista, total); break;
            case 4: editar(lista, total); break;
            case 5: remover(lista, &total); break;
            case 0: puts("Saindo..."); break;

            default:
            puts("Opção inválida"); break;
        }
        if(opcao != 0)
        salvar(lista, total);
        
    } while (opcao != 0);

    return 0;
}
