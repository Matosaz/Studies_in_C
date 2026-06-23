#include <stdio.h>

void imprimir(int arr[], int size){

    printf("(");
    for(int i = 0; i < size; i++){
        printf("%2d ", arr[i]);
    }
    printf(")\n");
}

int main(){
    
    int arr[] = {3, 5,2, 6, 38, 24, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    imprimir(arr, size);

    for(int i = 0; i < size - 1; i++){
        int temp;
        for(int j = 0; j<size - i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    imprimir(arr, size);

};