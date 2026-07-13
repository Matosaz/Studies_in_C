#include <stdio.h>
#include <string.h>


// A execu¸c˜ao do programa abaixo resultou na “Captura de tela” que segue
// sua listagem. Por que as mensagens escritas na tela pela execu¸c˜ao de
// cmp() aparecem antes da mensagem do printf(...) 0,5pt? O que ´e
// cmp(); na linha 3 e por que ele ´e necess´ario 1,0pt? Por que os casos
// impressos pelos testes na fun¸c˜ao main() e na fun¸c˜ao cmp() s˜ao diferentes,
// dado que as condi¸c˜oes testadas s˜ao iguais 1,0pt?


// int cmp (); // Escopo da função.

// int a =-9, b=7;

// int main(){
//         int a=2, b ;
//         if ((a<0)&&(b>0)) {
//             puts ( "caso 1" );
//         } else {
//             puts ( "caso 2" );
//         }                                       //
//             puts ( "caso 3" );          //

//         printf( "caso do cmp ( ) %d . \n" , cmp ());

//  return 0;
//  }

//  int cmp(){
//         int a, b;
//         if ((a<0)&&(b>0)){
//             puts( "caso 1" );
//         }else {
//             puts( "caso 2" ) ;
//         }
//             puts( "caso 3" ) ;
//  return 0 ;


// caso 2
// caso 3
// caso 1 
// caso 3
// caso do cmp() 0.

// }




// int main(){

//     char perguntas[3][100] = {"Qual seu nome?", "Qual o nome completo do Nakano(Eliminatória)", 
//                               "Quantos Ânus você tem?"};
//     char respostas[3][100];


//     for(int i = 0; i < 3; i++){
//         printf("%s", perguntas[i]);
//         fgets(respostas[i], sizeof(respostas), stdin);       
//    }
   
//      for(int i = 0; i < 3; i++){
//         if(strcmp(respostas[1], "Fabio Nakano") != 0){
//             printf("Menos 10 mil de aura(SEU BETA)");
//             break;
//         }
//         printf("\n\n%s", respostas[i]);
    
//     }
// }



int dobros(int a){
    int dobro = 2 * a;
    return dobro;
}

void teste(int *ptr){
       *ptr= 2;
}

int main(){
    int a = 27;

    int *ptr = &a;
    int dobro = dobros(a);


    teste(ptr);
    printf("%d\n", dobro);
    printf("%d", *ptr);


}