#include <stdio.h>

int sumBoundary(int matrix[100][100], int size) {
   //seu codigo 
   int i, j;
   int soma1 = 0;
   int soma2 = 0;
   int soma3 = 0;
   int somaFinal;
   
   for (j=0;j<size+1;j++){
    soma1 = soma1 + matrix[0][j];

   }

   for (j=0;j<size;j++){
    soma2 = soma2 + matrix[size-1][j];

   }

   for (i=1;i<size-1;i++){
    soma3 = soma3 + matrix[i][0] + matrix[i][size-1];

   }

   printf("%d\n", soma1);
   printf("%d\n", soma2);
   printf("%d\n", soma3);

   somaFinal = soma1 + soma2 + soma3;


   return somaFinal;

}

int main() {
    int size;
    scanf("%d", &size);
    
    int matrix[100][100];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int result = sumBoundary(matrix, size);
    printf("%d\n", result);
    
    return 0;
}