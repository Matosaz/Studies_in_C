#include <stdio.h>

int calculateSum(int *arr, int size);
int main() {

    int n, value;
    scanf("%d", &n);
    int arr[n] = {};
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    calculateSum(arr, n);    
    
    return 0;
}

int calculateSum(int *arr, int size){
    int sum = 0;
    int* ptr = arr;

    for(int i = 0; i < size; i++){
        sum += *(ptr + i);
    }

    printf("%d", sum);
    return sum;
};