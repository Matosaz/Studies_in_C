#include <stdio.h>


void imprimir(int arr[], int size){
    printf("(");
    for(int i = 0; i < size; i++){
        printf("%2d ", arr[i]);
    }
    printf(")\n");

}

void sorting(int arr[], int size, int j, int maior){
     while(arr[j] > maior && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
                arr[j+1] = maior;
}

void buscar(int arr[],int size){
 for(int i = 1; i < size; i++){
        int maior = arr[i];
        int j = i - 1;
        sorting(arr, size, j, maior);
    }

};

int main(){

    int arr[] = {8, 2, 4, 28, 52, 12, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    imprimir(arr, size);
    buscar(arr, size);
    imprimir(arr, size);

    return 0;
}