#include <complex.h>
#include <stdio.h>


// int sort(int arr[], int size, int i,int maior){
//         int temp = arr[maior];
//         arr[maior] = arr[i];
//         arr[i] = temp;
// }

// int buscar(int arr[], int size){
//         for(int i = size - 1; i > 0;i--){
//             int maior = i;
//                 for(int j = 0; j < i; j++){
//                     if(arr[maior] < arr[j]){
//                         maior = j; //Maior é o índice do J;
//                     }
//                 } 
//             sort(arr, size, i, maior);
//         }
//     }

//  i   j 
//  0   1
//  1   2
//  2   3
//  
// 

//for(int i  = size - 1; i > 0; i--){
//      int maior = i;
//          for(int j = 0; j < i; j++){
//              if(arr[j] > arr[maior]){
//                  maior = j; //Define o elemento j(atual) da lista como maior
//              }    
//          }
//          int temp = arr[maior]; (armazena o valor contido no índice j após ser definido como maior)
//              arr[maior] = arr[i];
//              arr[i] = temp;
//  }           
// 
// 

// void buscar(int arr[], int size){
//     for(int i = 0; i < size - 1; i++){
//         int maior = i;
//             for(int j = i + 1; j < size; j++){
//                 if(arr[maior] > arr[j]){
//                     maior = j;
//                 }
//             }
//             int temp = arr[maior];
//             arr[maior] = arr[i];
//             arr[i] = temp;
//     }
// }

// void sort(int arr[], int size, int maior, int i){
//     int temp = arr[maior];
//     arr[maior] = arr[i];
//     arr[i] = temp;
// }
// void buscar(int arr[], int size){
//     for(int i = size - 1; i > 0; i--){
//         int menor = i;
//             for(int j = 0; j < i; j++){
//                 if(arr[menor] > arr[j]  ){
//                     menor = j;
//                 }
//             }
//            sort(arr, size, menor,  i);
//     }
// }



void sort(int arr[], int size, int maior, int i){
    int temp = arr[maior];
    arr[maior] = arr[i];
    arr[i] = temp;
}
void buscar(int arr[], int size){
    for(int i = size - 1; i > 0; i--){
        int menor = i;
            for(int j = 0; j < i; j++){
                if(arr[menor] > arr[j]){
                    menor = j;
                }
        }
        sort(arr, size, menor, i);
    }
}
void imprimir(int arr[], int size){
    printf("(");
        for(int i = 0; i < size; i++){
            printf("%2d ", arr[i]);
        }
    printf(")\n");
}


int main() {
    // int size;
    // printf("Tamanho da lista: \n");
    // scanf("%d", &size);

    // int arr[size];

    int arr[] = {2, 6, 7, 3, 12};
    int size = sizeof(arr)/ sizeof(arr[0]); 

    // for(int i = 0; i < size; i++){
    //     printf("Insira o %dº elemento: \n", i+1);
    //     scanf("%d", &arr[i]);
    // }

    buscar(arr,  size);
    imprimir(arr, size);
    return 0;
}



