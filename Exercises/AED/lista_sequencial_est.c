#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5


typedef struct{
    int chave;
    int size;
    void *data;
} elemento_t;

typedef struct{
    elemento_t els[MAX + 1];
    int size;
} lista_t;


void inicializar(lista_t *l){
    l->size = 0;
}

void reinicializar(lista_t *l){
    l->size = 0;
}

int count(lista_t *l){
    return l->size;
}

void exibir(lista_t *l){
    printf("Conteúdo da lista: ");
    for(int i = 0; i < l->size; i++){
        printf("%d ", (l->els[i]).chave);
    }
    printf("\nTotal de elementos: %d\n", l->size);
}

bool inserir_ordenado(lista_t *l, elemento_t el){
    if(l->size >= MAX){
        return false;
    }
    int i;
    for(i = l->size - 1; i >= 0 && (l->els[i]).chave > el.chave; i--){
        l->els[i+1] = l->els[i];
    }

    //Atribuir em pos
    l->els[i+1] = el;
    l->size++;
    return true;
}

int buscar(lista_t *l, int chave){
    l->els[l->size].chave = chave; //sentinela
   
    for(int i = 0; i < l->els[i].chave != chave; i++){
        if(i == l->size){
             return -1;
        }
        return i;
    }
    
}

int busca_binaria(lista_t *l, int chave){
    int esq, dir, meio;

    esq = 0;
    dir = l->size -1;

    while(esq < dir){
        meio = (esq + dir) / 2;
        if(l->els[meio].chave == chave){
           return meio;
        }else if(l->els[meio].chave < chave){
            dir = meio + 1; //l->els[meio].chave = meio + i;
        }else{
            esq = meio - 1; 
        }

    }
}

bool remover(lista_t *l, int chave, int pos){
    int indice = buscar(l, chave);
    if(pos < 0) return false;
    l->size--;

    for(int i = pos; i < l->size; i++){
        l->els[i] = l->els[i+1];
    }
    return true;

}
int main(){
    lista_t l;
    inicializar(&l);

    for(int i = 0; i < MAX; i++){
       elemento_t el;
       bool ret;
       int chave = i * i;
       el.chave = chave;
       int pos = i/2;

       ret = inserir_ordenado(&l, el);
       if(ret) printf("Foi possível inserir elemento %d\n", chave);
         else printf("Não foi possível inserir elemento %d\n", chave);
         exibir(&l);
         }
    return 0;
}