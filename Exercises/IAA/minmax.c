#include <stdio.h>
#include <stdlib.h>


void minMax(int *v, int ini, int fim, int *min, int *max){
    if(ini == fim){
        if(v[ini] < *min) *min = v[ini];
        if(v[ini] > *max) *max = v[ini];
        
        return;
    }
    int meio = (ini + fim) / 2;
    minMax(v, ini, meio, min, max);
    minMax(v, meio + 1, fim, min, max);
}

int main(){
    int ini = 0; int fim = 0;
    int n = 10;
    int v[] = {49, 60, 12, 43, 47, 33, 94, 80, 74, 62};
    fim = n - 1;
    int min = v[0];
    int max = v[0];

    minMax(v, ini, fim, &min, &max);

    printf("Menor %d Maior %d", min, max);
    return 0;
}