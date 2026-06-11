#include <stdio.h>
#include <stdlib.h>
int main() {
        
    int valor = 0;
    int width = 0;
    int width_max = 0;
    int height = 0;
    char linha[100];
    do{
        fgets(linha, sizeof(linha), stdin);
        width = 0;
        for(int i = 0; linha[i] != '\0'; i++){

                if(linha[i] >= '0' && linha[i] <= '9'){
                    valor = linha[i] - '0';
                    if(valor == 3){
                        break;
                    }
                
            width++;
        }
    }
    

                if(width > 0){
                    height++;
                }
                if(width > width_max){
                    width_max = width;
                } 
               
        }while(valor != 3);

    printf("Height: %d", height);
    printf("Width: %d", width_max);

    





    return 0;
}