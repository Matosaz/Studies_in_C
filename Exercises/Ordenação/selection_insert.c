#include <stdio.h>

void imprimir(int arr[], int size){
    for(int i = 0;i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// void sorting(int arr[], int i, int maior){
//     int temp = arr[maior];
//     arr[maior] = arr[i];
//     arr[i] = temp;
// }

// void busca(int arr[], int size){
// int maior = 0;
//    for(int i = size - 1; i > 0; i--){
//     for(int j = 0; j < i; j++){
//         if(arr[maior] < arr[j]){
//             maior = j;
//         }
//     }
//     sorting(arr, i, maior);
//    }
// }

int buscar(int arr[], int size){
    int IndiceMaior = 0;
    for(int i = 0; i < size + 1; i++){
        if(arr[IndiceMaior] < arr[i]){
            IndiceMaior = i;
        }
    }
    return IndiceMaior;
}

void sorting(int arr[], int size){
    for(int i = size - 1; i > 0; i--){
        int IndiceMaior = buscar(arr, i);
        if(arr[IndiceMaior] != arr[i]){
            int temp = arr[IndiceMaior];
            arr[IndiceMaior] = arr[i];
            arr[i] = temp;
        }
    }
}


// void sorting(int arr[], int i, int maior){
// 	int temp = arr[maior];
// 	arr[maior] = arr[i];
// 	arr[i] = temp;
// }

// void busca(int arr[], int size){
// 	for(int i = size - 1; i > 0; i--){
//         int maior = i;
// 		for(int j = 0; j < i; j++){
// 			if(arr[maior] < arr[j]){
// 				maior = j;
// 			}
// 		}
// 		sorting(arr, i, maior);
// 	}
	
// }





int main(){

    int arr[8] = {2, 6, 32, 8, 9, 10, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    imprimir(arr, size);
    busca(arr, size);
    imprimir(arr, size);
    return 0;
}