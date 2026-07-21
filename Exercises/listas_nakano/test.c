#include <stdio.h>
#include <stdlib.h>



void imprimir(int *m, int quant){
    for(int i = 0; i < quant; i++){
        printf("%d ", m[i]);
    }
}

int main() {
    
    int capacidade = 2; 
    int quant = 0; // Quantidade
    
    int *m;
    m = (int *) malloc(capacidade * sizeof(int));
    

        if(m == NULL){
                printf("Deu ruim paizão");
                return 1;
        }
        
        // capacidade 2       quant 0
        // capacidade 2       quant 1
        // capacidade 2       quant 2
        // capacidade 4       quant 3 
        // capacidade 4       quant 4
        // capacidade 8       quant 5
        
        while(1){
            scanf("%d", &m[quant]);
            // m[0]
            // m[1]
            // m[2]
 
            if(m[quant] == -1){
                imprimir(m, quant);
                break;
            }
            
            if(capacidade == quant){
                capacidade *= 2;
                
                int *temp = (int *)realloc(m, capacidade * sizeof(int));

                if(temp == NULL){
                    printf("Deu ruim paizão");
                    return 1;
                }
                m = temp;
            }
            quant++;
        }   

    return 0;
}