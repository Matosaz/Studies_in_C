#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir(int arr[], int size){
    printf("(");
        for(int i = 0; i < size; i++){
            printf("%2d ", arr[i]);
        }
    printf(")\n");

}

int partition(int arr[], int low, int high);
void swap(int *x, int *y);
void quicksort_recursion(int arr[], int low, int high);
void quicksort(int arr[], int size);



int main() {
    
    int arr[] = {4, 5, 3, 56, 9, 10, 21, 7, 8};
    int size = sizeof(arr)/sizeof(arr[0]);
    imprimir(arr, size);

    quicksort(arr, size);
    imprimir(arr, size);


    return 0;
}


void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
};

int partition(int arr[], int low, int high){
    int pivot_index = low +(rand() % (high - low)); //valor aleatório no intervalo
    
    if(pivot_index != high){
        swap(&arr[pivot_index], &arr[high]);
    }

    int pivot_value = arr[high];

    int i = low;

    for(int j = low; j < high; j++){
        if(arr[j] <= pivot_value){
            swap(&arr[i], &arr[j]);
            i++;
        }
        
    }
    swap(&arr[i], &arr[high]);

    return i;
};


void quicksort_recursion(int arr[], int low, int high){

    if(low < high){
        int pivot_index = partition(arr, low, high);
        quicksort_recursion(arr, 0, pivot_index - 1); //Percorre do primeiro elemento até o pivo
        quicksort_recursion(arr,pivot_index + 1, high); //Percorre a direita do pivo até o último elemento
                    imprimir(arr, high);

    }

};


void quicksort(int arr[], int size){
    srand((time(NULL)));
    quicksort_recursion(arr, 0, size - 1);
};

