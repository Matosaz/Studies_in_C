#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[60];
    int idade;
} Usuario;


void imprimir(Usuario *m, int quant){
    for(int i = 0; i < quant; i++){
        printf("%s - %d\n", m[i].nome, m[i].idade);
    }
}

int main() {
    
    int capacidade = 2;
    int quant = 0;
    // scanf("%d", &n);
    
    Usuario *user;
    user = (Usuario *)malloc(capacidade * sizeof(Usuario));

    printf("Digite o nome e a idade(ou 'out' para sair): \n");

    while(1){
        
        if(capacidade == quant){
            capacidade *= 2;

            Usuario *temp = (Usuario *)realloc(user, capacidade * sizeof(Usuario)); 
            
            if(temp == NULL){
            printf("A alocação de memória falhou.\n");
            return 1;
            }

            user = temp;
        }
        
            fgets(user[quant].nome, sizeof(user[quant].nome), stdin); 
            user[quant].nome[strcspn(user[quant].nome, "\n")] = '\0';
            
            if(strcmp(user[quant].nome,"out") == 0){    
            break;
            }
                                        
            scanf("%d", &user[quant].idade );
            
        
        quant++;
    }
 
    imprimir(user,quant);



    //Error handling:
    if(user == NULL){
        printf("A alocação de memória falhou.\n");
        return 1;
    }

    free(user);
    user = NULL;
    return 0;
}