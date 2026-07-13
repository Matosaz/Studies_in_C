#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main() {
    // int *m;
    //  m = (int *)malloc(sizeof(int));
    

    //  printf("Digite um número inteiro: ");
    //  scanf("%d", &*m);

    //  printf("%d\n", *m);
     
    //  if(m == NULL){
    //     printf("Erro ao alocar memória. \n");
    //     return 1;
    //  }

    //  free(m);
    //  m = NULL; // boa prática: evitar dangling pointer
    //  return 0;


    //Ex 2:
    // int soma, produto;
    // int *m;
    // m = (int *) malloc(2 * sizeof(int));

    // for(int i = 0; i < 2; i++){
    //     printf("Digite um número inteiro: ");
    //     scanf("%d", &m[i]);
        
    //     soma = *m + m[i];
    //     produto = *m *  m[i];;
        
    //     if(*m > *(m+1)){
    //         printf("%d", *m);
    //     }
    //     else{
    //         printf("%d", m[i+1]);
    //     }
    // }
    // printf("\nSoma: %d\n", soma);
    // printf("Produto: %d\n", produto);
    
    // free(m);
    // m = NULL; // boa prática: evitar dangling pointer


    //Ex 3:

    // float *m;
    // m = (float *) malloc(sizeof(float));

    // scanf("%f", &*m);
    // if(m == NULL){
    //     printf("Erro ao alocar memória. \n");
    //     return 1;
    // }   

    // printf("%f\n", *m);
    // printf("%f\n", *m * 2);
    // printf("%f\n", *m / 2);

    // free(m);
    // m = NULL;




    //Ex 4:

    // int n;
    // scanf("%d", &n);

    // int *m;
    // m = (int *) malloc(n * sizeof(int));

    // for(int i = 0; i < n; i++){
    //     scanf("%d", &m[i]);
    // }

    // for(int i = 0; i < n; i++){
    //     printf("%d\n", m[i]);
    //     }
    
    // free(m);
    // m = NULL;


    //Ex 5:
    // int n;
    // int media, maior = 0, menor = INT_MAX, soma = 0;
    // scanf("%d", &n);

    // int *m;
    // m = (int *) malloc(n * sizeof(int));

    // for(int i = 0; i < n; i++){
    //     scanf("%d\n", &m[i]);
    // }

    
    // for(int i = 0; i < n; i++){
    //     if(m[i] > maior){
    //         maior = m[i];
    //     }
    //     if(m[i] < menor){
    //         menor = m[i];
    //     }

    //     soma += m[i];
    //     media = soma / n;
        
    //     printf("%d", m[i]);
    // }
    // printf("\nMaior: %d\n", maior);
    // printf("Menor: %d\n", menor);
    // printf("Média: %d\n", media);


    //Ex 6:
    // int n;
    // scanf("%d", &n);

    // int *m;
    // m = (int *)malloc(n * sizeof(int));

    // for(int i = 0; i < n; i++){
    //     scanf("%d", &m[i]);
    // }
    

    // for(int i = n-1; i >= 0; i--){
    //     printf("%d ", m[i]);
    // }

    // free(m);
    // m = NULL;



    //Ex 07:
    // int n_par = 0;
    // int n;
    // scanf("%d", &n);

    // int *m;
    // m = (int *)malloc(n * sizeof(int));

    // for(int i = 0; i < n; i++){
    //     m[i] = rand() % 100;
    // }

    // for(int i = 0; i < n; i++){
    // if(m[i] % 2 == 0){
    //     n_par++;
    // }

    // printf("%d ", m[i]);
    // }
    // printf("Pares: %d", n_par);


    //Ex 08:

//     int n;
//     scanf("%d", &n);

//     int *m;
//     m = (int *) malloc(n*sizeof(int));

//     int valor; //Valor buscado

//     valor = rand() % 100;

//     for(int i = 0; i < n; i++){
//         m[i] = rand() % 100;
//     }



//  for(int i = 0; i < n; i++){
//      if(m[i] == valor){
//         printf("\nMaior valor: %d na posição %d", valor, i);
//         break;
//     }
   
// }
    
}