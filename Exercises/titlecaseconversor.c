
#include <stdio.h>


void lowertoupper();
void uppertolower();

int main() {
  int option;
  printf("-------------------------\n");

printf("Escolha uma opção para converter\n");    

printf("1 - lower to UPPER\n");
printf("2 - UPPER to lower");
scanf("%d", &option);
getchar();
switch(option){
    case 1:
    lowertoupper();
    break;
    
    case 2:
    uppertolower();
    break;
    
    default:
    printf("Opção inválida!");
}
return 0;
}


void lowertoupper(){
      
   char str[100];

    printf("lower para UPPER selecionado\n");
    printf("Insira uma string para converter para UPPER: ");
    fgets(str, sizeof(str), stdin);
   
   for(int i = 0; str[i] != '\0'; i++){
    if(str[i] >='a' && str[i] <='z'){
        str[i] = str[i] - 32;
    }
   }
       printf("%s", str);

    

}

void uppertolower(){
    
     char str[100];
 printf("UPPER para lower selecionado\n");
    printf("Insira uma string em UPPER para converter em lower case: ");
    fgets(str, sizeof(str), stdin);
   
   for(int i = 0; str[i] != '\0'; i++){
    if(str[i] >='A' && str[i] <='Z'){
        str[i] = str[i] + 32;
    }
   }
       printf("%s", str);

    }