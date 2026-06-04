#include <stdio.h>


int secondLargest();
int swapIndex();
int edgeMatrixSum();


int main(){

    int opcao;

    printf("Qual função de vetores você deseja testar: \n");
    printf("1 - Alternar os valores de índices de uma matriz \n");
    printf("2 - Calcular a soma dos valores nas bordas de uma matriz de tamanho N \n");
    printf("3 - Encontrar o segundo maior número em um array \n");
    scanf("%d", &opcao);

    switch(opcao){

        case 1:
        swapIndex();
        break;
        
        case 2:
        edgeMatrixSum();
        break;

        case 3:
        secondLargest();
        break;

        // case 4:
        // swapIndex();
        // break;
        
        default:
        printf("Insira uma opção válida: ");
        break;

    }
    return 0;
};




//     int size, value;
    
//     printf("Insert the numbers of elements in the array: ");
//     scanf("%d", &size);
//     int arr[size];

//     for(int value = 0;value < size; value++){
//         printf("Insert the #%d value: ", value + 1);
//         scanf("%d", &arr[value]);
//     }

//   for(int i; i < size; i++){
//         printf("%d\n", arr[i]);
//     }

int edgeMatrixSum(){

    int soma = 0;
    int cows, rows;
    printf("Insira o tamanho da matriz 2D que deseja utilizar: ");
    scanf("%d", &cows);
    scanf("%d", &rows);
    int matriz[rows][cows];
    int counter = 1;
    
    for(int i = 0;i < rows; i++){
        for(int j = 0;j < cows; j++){
                 matriz[i][j] = counter++;
        }
    }

    for(int i = 0; i <rows; i++){
        for(int j = 0; j <cows;j++){
            printf("%d", matriz[i][j]);
            if(i == 0 || i==(rows - 1) || j==0 || j==(cows - 1)){
            soma += matriz[i][j];

            }
    
        }

        printf("\n");
    }
 printf("Soma: %d", soma);

 return 0;

}


int secondLargest(){ 
    
    int size, n, seclargest, temp, count = 0, largest;

    printf("Informe o número de elementos que deseja inserir");
    scanf("%d", &n);

    int array[n];

    size = sizeof(array) / sizeof(array[0]);
    for(int i = 0; i < size; i++){
    printf("Insira valor para o #%d elemento: \n", i);
    scanf("%d", &array[i]);

            if(array[i] >= largest){
            seclargest = largest; 
            largest = array[i];
        }
    }

        for(int i = 0; i < size; i++){
        printf("%d\n", array[i]);
        }
        
        printf("Second largest: %d\n", seclargest);
        
        return 0;
}
   


    int swapIndex(){
    int n = 0;
    int index1,index2;

    // printf("insira o número de elementos que deseja inserir: ");
    // scanf("%d", &n);

    int array[5] = {10, 20, 30, 40, 50};
    int size = sizeof(array) / sizeof(array[0]);

    // for(int i = 0; i <= n; i++){
    //     printf("Insira o valor #%d: ", i + 1);
    //     scanf("%d", &array[i]);
    // }

    printf("Quais índices você deseja alternar?\n");
    printf("Primeiro valor de índice:");
    scanf("%d", &index1);


    printf("Segundo valor de índice:");
    scanf("%d", &index2);


    if(array[index1] == array[index2]){
        printf("trocar o mesmo valor não gerará alterações");
    };


    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
    
    for(int i = 0; i <= size; i++){

    printf("%d\n", array[i]);
    return 0;
    }
}

