#include <stdio.h>



void print_func(int X[], int n){
    printf("(");
    for(int i = 0; i < n; i++){
        printf("%3d ", X[i]);
    }
        printf(")\n");

}

void ordbubb(int V[], int n){
    int aux;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-i-1; j++){
        if(V[j] > V[j+1]){
            aux = V[j];
            V[j] = V[j+1];
            V[j+1] = aux;
            }            
        }
    }
}
int main(void){
    int arr[] = {4, 2, 3, 0, 9, 3, 5, 8};
    print_func(arr, 8);
    ordbubb(arr, 8);
    print_func(arr, 8);
}

