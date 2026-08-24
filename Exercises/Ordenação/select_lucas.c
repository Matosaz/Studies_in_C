#include <stdio.h>

void imprimir(int arr[], int size){
    printf("( ");
    for(int i=0; i<size; i++){
        printf("%2d ", arr[i]);
    }
    printf(")");
}

int buscar(int arr[], int size){
    int indiceMaior = 0;
    for(int i = 0; i < size + 1; i++){
        if(arr[indiceMaior] < arr[i]){
            indiceMaior = i;
        }
    }
    return indiceMaior;
}

void sorting(int arr[], int size){
    for(int i = size - 1; i > 0; i--){ //Como o tamanho é reduzido a cada iteração, o novo "size" passado para busca é o valor de i;
        int indiceMaior = buscar(arr,  i);
        if(arr[indiceMaior] != arr[i]){
            int temp = arr[indiceMaior];
            arr[indiceMaior] = arr[i];
            arr[i] = temp;
        }
    }
}

int main(){
    int arr[] = {1, 4, 6, 8, -20};
    int size = sizeof(arr) / sizeof(arr[0]);

    imprimir(arr, size);
    sorting(arr, size);

    imprimir(arr, size);


    return 0;
}
