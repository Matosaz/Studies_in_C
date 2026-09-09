#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
typedef struct{
    int chave;
}reg_t;

typedef struct{
    int fim;
    int comeco;
    int quantidade;
    reg_t valores[MAX];
}fila_t;


int inicializar(fila_t *p){
    p->fim = 0;
    p->comeco = 0;
    p->quantidade = 0;
};

bool push(fila_t *p, reg_t ch){
    if(p->quantidade == MAX) return false;

    p->valores[p->fim] = ch;
    p->fim = (p->fim + 1) % MAX;
    p->quantidade++;
    return true;
}

bool pop(fila_t *p, reg_t *ch){
    if(p->quantidade == 0) return false;
    *ch = p->valores[p->comeco];
    p->comeco = (p->comeco + 1) % MAX;
    p->quantidade--;
    return true;
}

reg_t *peek(fila_t *p, reg_t *ch){
    if(p->quantidade == 0) return false;
    *ch = p->valores[p->comeco];
    return ch;
}

int count(fila_t *p){
    return p->quantidade;
}

bool is_empty(fila_t *p){
    return p->quantidade == 0; // Se retornar true está vazia, senão, não está
}

void exibir(fila_t *p){
    for(int i = 0; i < p->quantidade; i++){
        int aux = (p->comeco + i) % MAX;
        printf("%d\n", p->valores[aux].chave);
    }
    printf("\n");
}

int main(){
    fila_t p;
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