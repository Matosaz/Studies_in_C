#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int ini, int meio, int fim){
    int size1 = meio - ini + 1;
    int size2 = fim - meio;

    int *esq = malloc(size1 * sizeof(int)); //Aloca um vetor com size1 * 4 para a parte esquerda;
    int *dir = malloc(size2 * sizeof(int)); //Aloca um vetor com tamanho size2 * 4 para a parte direita;

    int i, j, k;

    for(i = 0; i < size1; i++){
        esq[i] = v[ini + i]; //Preenche o vetor da esquerda com os elementos do inicio até a metade(meio) (Parte esquerda)
    }
    for(j = 0; j < size2; j++){
        dir[j] = v[meio + 1 + j]; //Preenche o vetor da direita a partir do elementos sucessor ao meio (meio + 1) até fim
    }
    i = 0;
    j = 0;
    k = ini;
    while(i < size1 && j < size2){
        if(esq[i] < dir[j]){ //Compara cada elemento da parte esquerda com um elementos da direta até que um elemento maior na esquerda seja encontrado
            v[k] = esq[i];
            i++;
        }
        else{
            v[k] = dir[j];
            j++;
        }
        k++;
    }

    //Loop´s para preencher os elementos remanescentes em caso de uma das partes ser maior que a outra;
    while(i < size1){
        v[k] = esq[i];
        i++; k++;
    }

    while(j < size2){
        v[k] = dir[j];
        j++; k++;
    }

    free(esq);
    free(dir);
}

void mergeSort(int *v, int ini, int fim){
    if(ini >= fim) return;

    int meio = (ini + fim)/2;

    mergeSort(v, ini, meio);
    mergeSort(v, meio + 1, fim);
    merge(v, ini, meio, fim);
}

void exibir(int *v, int fim){
    for(int i = 0; i <= fim; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){

    int ini = 0; int fim = 0;
    int n = 10 ;
    int v[] = {49, 60, 12, 43, 47, 33, 94, 80, 74, 62};
    fim = n - 1;

    exibir(v, fim);
    mergeSort(v, ini, fim);
    exibir(v, fim);
    return 0;
}