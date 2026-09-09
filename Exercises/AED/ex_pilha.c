#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
#define INV -1
typedef struct{
    int chave;
}reg_t;

typedef struct{
    int topo;
    reg_t valores[MAX];
}pilha_t;


int inicializar(pilha_t *p){
    p->topo = INV;
};

bool push(pilha_t *p, reg_t ch){
    if(p->topo == MAX - 1) return false;

    p->topo++;
    p->valores[p->topo] = ch;
    return true;
}

bool pop(pilha_t *p, reg_t *ch){
    if(p->topo == INV) return false;
    p->valores[p->topo] = *ch;
    p->topo--;
    return true;
}

reg_t *peek(pilha_t *p, reg_t *ch){
    if(p->topo == INV) return false;
    *ch = p->valores[p->topo];
    return ch;
}

int count(pilha_t *p){
    return p->topo + 1;
}

bool is_empty(pilha_t *p){
    return p->topo == INV; // Se retornar true está vazia, senão, não está
}

void exibir(pilha_t *p){
    for(int i = 0; i < p->topo; i++){
        printf("%d\n", p->valores[i].chave);
    }
    printf("\n");
}

int main(){
    pilha_t p;
    reg_t reg;
    inicializar(&p);

    for(int i = 0; i < MAX;i++){
        reg.chave = rand() % 100;
        push(&p, reg);
        exibir(&p);
    }

    printf("Removendo...\n\n");

    while(!is_empty(&p)){
        pop(&p, &reg);
        exibir(&p);
    }

    
    return 0;
}