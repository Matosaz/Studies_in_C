#include <stdio.h>
#include <stdlib.h>

int *soma_e_zera(int *v, int resultado_esperado, int n){
    int *indice = malloc(2 *sizeof(int));
    for(int i = 0; i < n; i++){ // A cada iteração de i, percorre-se n vezes o valor de j, resultando em uma complexidade de O(n^2);
        for(int j = i + 1; j < n; j++){
            if(v[i] + v[j] == resultado_esperado){
                indice[0] = i;
                indice[1] = j;
                return indice;
            }
        }
    }
    free(indice);
    return NULL;
};


int main(){
    int v[13] = {1,2, 2,3,4,5, 5,6,7, 5,8,9,10};
    int resultado_esperado = 18;
    int n = 13;
    printf("Resultado esperado: %d\n", resultado_esperado);
    int *indice = soma_e_zera(v, resultado_esperado, n);

    printf("Indices encontrados: %d e %d\n", indice[0], indice[1]);


    

    free(indice);
}