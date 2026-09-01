#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX 10
#define INV -1

typedef struct{
    int chave;
}registro_t;

typedef struct{
    int topo;
    registro_t valores[MAX];
}pilha_t;

void inicializar(pilha_t *p){
    p->topo = INV;
}

void reinicializar(pilha_t *p){
    inicializar(p);
}

bool push(pilha_t *p, registro_t reg){

    if(p->topo == MAX - 1) return false;
    p->topo++;
    p->valores[p->topo] = reg;

    return true;
}

bool pop(pilha_t *p, registro_t *reg){

    if(p->topo == INV) return false;
    *reg = p->valores[p->topo]; //Define o valor da chave como o valor do topo da pilha;

    p->topo--;

    return true;
}

bool peek(pilha_t *p, registro_t *reg){
    if(p->topo == INV) return false;

    *reg  = p->valores[p->topo];
    return true;
}

int count(pilha_t *p){
    return p->topo + 1;
}

int is_empty(pilha_t *p){
    return p->topo == INV;
}

void exibir(pilha_t *p){
    printf("Pilha [topo]: ");
    for(int i = p->topo; i >= 0; i--){
        printf("%d ", p->valores[i].chave);
    }
    printf("\n");
}


int main(){
    pilha_t p;
    registro_t r;

    inicializar(&p);
    for(int i = 0; i < MAX; i++){
        r.chave = i * i;
        if(push(&p, r)){
            printf("Inserido: %d\n", r.chave);
        }
        else{
            printf("Não foi possível inserir: %d\n", r.chave);

        }
        exibir(&p);
    }

    while(!is_empty(&p)){
        if(pop(&p, &r)){
            printf("Pop ok! Registro retornado: %d\n", r.chave);
        }
        else{
            printf("Pop de %d failed!\n", r.chave);

        }
    }
    
    if(pop(&p, &r)){
            printf("Pop ok! Registro retornado: %d\n", r.chave);
        }
        else{
            printf("Pop de %d failed!\n", r.chave);
        printf("Pop ok! Registro retornado: %d\n", r.chave);
    }

    return 0;
}