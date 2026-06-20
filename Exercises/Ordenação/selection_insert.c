#include <stdio.h>

void imprimir(int arr[], int size){

    printf("(");
    for(int i = 0; i < size; i++){
        printf("%2d ", arr[i]);
    }
    printf(")\n");

}

void sorting(int arr[], int size, int maior, int i){
            int temp = arr[maior];
            arr[maior] = arr[i];
            arr[i] = temp;

}


// int busca(int arr[], int size){
//     for(int i = 0; i < size - 1; i++){
//        int maior = i;
//         for(int j = i + 1; j< size; j++){
//             if(arr[maior] > arr[j]){
//             maior = j;
//             }
//         } 
//         sorting(arr, size, maior, i);
//     }
// }


int busca(int arr[], int size){
    for(int i = size - 1; i > 0; i--){
       int maior = i;
        for(int j = 0; j< i; j++){
            if(arr[maior] < arr[j]){
            maior = j;
            }
        } 
        sorting(arr, size, maior, i);
    }
}


int main(){
    int arr[] = {2, 4, 5, 1, 58, 16, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    imprimir(arr, size);
    busca(arr, size);
    // sorting(arr, size, maior);
    imprimir(arr, size);

    return 0;
}