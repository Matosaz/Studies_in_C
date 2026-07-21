#include <stdio.h>
#include <stdlib.h>

typedef struct{ 
      char nome[50];
      int idade;
 }Pessoa;

 typedef float ft;


int main() {
      
      int n;
      scanf("%d", &n);
            
      Pessoa *p;
      p = (Pessoa * )malloc(n * sizeof(Pessoa));
     
          if(p == NULL){
      printf("Deu ruim filhão!\n");
      return 1;
    }
      
            printf("Insira um nowme e idade: \n");
            
            for(int i = 0; i < n; i++){
                  scanf("%s %d", (p+i)->nome, &(p+i)->idade);
            }
              for(int i = 0; i < n; i++){
                  printf("%s - %d\n",(p+i)->nome, (p+i)->idade);
            }
      free(p);
      p = NULL;
}


