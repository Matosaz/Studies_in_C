#include <stdio.h>

int imprimir(int arr[], int size){
    printf("(");
    for(int i = 0; i < size; i++){
        printf("%2d ", arr[i]);
    }
    printf(")\n");
};


void sorting(int arr[], int i, int maior){
            int temp = arr[maior];
            arr[maior] = arr[i];
            arr[i] = temp;
};

void buscar(int arr[], int size){
    for(int i = size - 1; i > 0; i--){
        int maior = i;
        for(int j = 0; j < i; j++){
            if(arr[maior] < arr[j]){
                maior = j;
            }
        }
        sorting(arr, i, maior);
    }
};

int main(){
    int arr[] = {1,4, 5, 2, 65, 9,10};

    int size = sizeof(arr) / sizeof(arr[0]);
    imprimir(arr, size);
    buscar(arr, size);
    imprimir(arr, size);
    

}