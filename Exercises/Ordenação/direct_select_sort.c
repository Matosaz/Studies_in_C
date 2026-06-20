#include <stdio.h>
#include <stdlib.h>

void imprimir(int *ptr, int size){
    printf("(");
    for(int i  = 0; i < size; i++){
        printf("%3d", ptr[i]);
    }
    printf(")\n");
}


void sort(int *ptr, int n){
    int aux;

    for(int i = n-1; i > 0; i--){ // Reduzindo o tamanho do array
        for(int j = 0; j < i; j++){
            if(ptr[j] > ptr[j+1]){
                aux = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = aux;
            }
        }
    }
}
int main(){
    int arr[]= {3, 0, 4, 5, 9, 2, 3, 7, 6, 5, 1};
   
    int n;
    n = sizeof(arr) / sizeof(arr[0]);
    imprimir(arr, n);
    sort(arr, n);
    imprimir(arr, n);
    return 0;
}