#include <stdio.h>




// Questão 01:
// char *texto = "https://support.microsoft.com/pt-br/topic/descri%C3%A7%C3%A3o-do-texto-lorem-ipsum-dolor-sit-amet-que-aparece-na-ajuda-do-windows-bf3b0a9e-8f6b-c2ab-edd9-41c1f9aa2ea0\n\nDescricao do texto \"Lorem ipsum dolor sit amet\" que aparece na Ajuda do Windows\n\nSumario\nA frase \"Lorem ipsum dolor sit amet consectetuer\" aparece na ajuda online do Microsoft Word. Essa frase parece ser originada de um idioma latino inteligente. Na verdade, eh uma tolice.\n\nMais Informacoes\nEmbora a frase seja tolice, ela tem uma historia longa. A frase foi usada por varios seculos por tipografos para...";

// // // Ajuste o programa abaixo para contar as ocorrˆencias de cada vogal
// // e, ao final da execu¸c˜ao, apresentar as contagens. Tanto mai´usculas
// // quanto min´usculas devem ser contadas. Na folha de respostas, reescreva
// // a fun¸c˜ao main incluindo os comandos que comp˜oe sua solu¸c˜ao 




// int main() {
//     int i = 0;
//     int contA = 0, contE= 0, contI = 0, contO = 0, contU = 0;
//     int contGeral = 0;
//     while (texto[i] != '\0') {
//         putchar(texto[i]); // escreve na tela o caracter passado como argumento

//         if(texto[i] == 'A' || texto[i] == 'a'){
//             contA++;
//             contGeral++;
//         }
//          if(texto[i] == 'E' || texto[i] == 'e'){
//             contE++; 
//             contGeral++;
//         }
//          if(texto[i] == 'O' || texto[i] == 'o'){
//             contO++; 
//             contGeral++;
//         }
//          if(texto[i] == 'U' || texto[i] == 'u'){
//             contU++;
//             contGeral++;
//         }
//          if(texto[i] == 'I' || texto[i] == 'i'){
//             contI++;
//             contGeral++;
//         }
//     i++;

//     }

//     int arr[5] = {1, 2, 3, 4, 5};


//     printf("\ncontagens: a(A): %d e(E): %d i(I): %d o(O): %d u(U): %d\n", contA, contE, contI, contO, contU);
//     printf("Contagem geral: %d", contGeral);

//     return 0 };







// Questão 02:

// Crie uma nova fun¸c˜ao que receba o array a como argumento (pode
// receber mais argumentos), some todos os valores contidos nos elementos
// de a e armazene essa soma como ´ultimo elemento de a. 2pt



// void nakanotenhapiedadedenosdasilva(int arr[], int na){
//     int sum = 0;
//     for(int i = 0; i <na; i++){
//         sum = sum + arr[i];
//     }
//         arr[4] = sum;
// }



// int main ( ) {
    
//     int a [] ={ 1 , 2 , 3 , 4 , 5 } ;
//     int na=5; // comprimento do a r r ay a
//              // chame a q u i a sua func a o

    

//  for(int i = 0; i <na; i++){
//         printf("%2d ",a[i]);
//     }

//     printf("\n");
    
//     nakanotenhapiedadedenosdasilva(a, na);
    
//  for(int i = 0; i <na; i++){
//         printf("%2d ",a[i]);
//     }
//     return 0 ;





// Questão 03:

// array p cont´em o pre¸co, em unidades monet´arias, de ´ıtens que podem
// ser comprados. Cada item ´e representado por um ´ındice. Por exemplo:
// o item de ´ındice 0 tem pre¸co 1, o item de ´ındice 1 tem pre¸co 2, o item
// de ´ındice 2 tem pre¸co 3, ..., o item de ´ındice 14 tem pre¸co 9.
// Em sua conta-corrente digital vocˆe tem 15 unidades monet´arias de saldo.
// Complete o programa para que se passe por todos os ´ıtens, verificando,
// a cada item, se este pode ser comprado com o saldo. Caso o item possa
// ser comprado, escreve na tela a mensagem ”item i comprado pelo pre¸co
// p[i]” com i e p[i] devidamente substitu´ıdos pelos valores do programa e
// o pre¸co do item deve ser subtra´ıdo do saldo. Caso o item n˜ao possa ser
// comprado, n˜ao faz nada. Em seguida, verifica o pr´oximo item, ... Isto
// deve ser repetido at´e que n˜ao haja mais ´ıtens a verificar. 2pt
// 1 #include <s t d i o . h>


//  int main ( ) {
            
//             // Indice  0      1      2       3       4       5       6       7       8       9        10    11  12  13  14

//  int p [ ] ={ 1 , 2 , 3 , 2 , 1 , 7 , 8 , 9 , 4 , 5 , 6 , 7 , 8 , 1 , 9 } ; // Custo
//  int np = 15; // comprimento do a r r ay p
//  int saldo = 15;

//     for(int i = 0; i <np;i++){
//         if(p[i] < saldo){
//             printf("Item %d comprado pelo preco %d\n ", i, p[i]);
//             saldo -= p[i];
//         }
//         else{
//             return 1;
//         }
//     }


//  return 0 ;
//  }






// Questão 04 e 05:

// O programa abaixo encontra o elemento de maior valor em p e imprime
// seu ´ındice. Explique como o programa funciona. Dica: responda as perguntas nos coment´arios e conecte essas respostas de maneira a explicar
// o programa. 2pt


// int busca(int p[], int indice, int i){
//     if(p[i] >= p[indice]){
//         indice = i;
//     }
//     return indice;
// }

//  int main ( ) {
//  int p [ ] ={ 1 , 2 , 3 , 2 , 1 , 7 , 8 , 9 , 4 , 5 , 6 , 7 , 8 , 1 , 9 } ;
//  int np=15; // comprimento do a r r ay p
//  int i = 1;
//  int indice = 0; // para que serve esta variavel? Para armazenar o índice do elemento do maior valor;
//         for (int i = 1; i < np ; i++) {
//              busca(p, indice, i);               
//              indice = i;
//             }  
        

//         // for (int i = 1; i < np ; i++) {
//         //     if (p[i] >= p[indice]) {    // para que serve esta comparacao? 
//         //                                 // A comparação realizada entre p[i] e p[indice] é utilizada para encontra o maior elemento dentre os dois; 
                                        
//         //             indice = i ; // para que serve esta atribuicao?.  
//         //         }                // A variável indice recebe uma nova atribuição a qual é dita como o índice do maior elemento atualizado.
//         // }
//     printf("%d\n", indice);
//  return 0 ;
//  }
    