#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Lista ligada circular com nó cabeça


// Possuimos um ponteiro para o nó cabeça que aponta para o primeiro elemento 
// da lista. Ele não armazena nenhum dado ou ocupa qualquer posição na lista lógica.

//Cada nó da lista possui um ponteiro apontando para o próximo nó e o último nó aponta para 
// o nó cabeça, formando um ciclo.

typedef struct {
    int chave;
    // outros campos;
} registro_t;

typedef struct aux{
    registro_t reg;
    struct aux *prox;
} elo_t;

typedef struct{
    elo_t *cabeca;
}lista_t;



void inicializar(lista_t *l){
    l->cabeca  = (elo_t *) malloc(sizeof(elo_t));
    l->cabeca->prox = l->cabeca ; //O no aponta para ele mesmo quando a lista é vazia;
}

int tamanho(lista_t *l){
    int count= 0;
    // elo_t *i = l->cabeca->prox;
    // while(i != l->cabeca ){
    //     count++;
    //     i = i->prox;
    // }
    for(elo_t *i = l->cabeca->prox; i != l->cabeca; i = i->prox){
        count++;
    }
    return count;
}


void exibir(lista_t *l){
    printf("Lista: \n");
    for(elo_t *i = l->cabeca->prox; i != l->cabeca; i = i->prox){
        printf("%2d ", i->reg.chave);
    }
    printf("\n");
}

elo_t* busca(lista_t *l, int ch, elo_t **ant){
    elo_t *i = l->cabeca->prox;
    *ant = l->cabeca;
    l->cabeca->reg.chave = ch; //Elemento que estamos buscando;

    while(i->reg.chave < ch){ //Assumimos que a lista está ordenada;
        *ant = i;
        i = i->prox;   
    }
    if(i == l->cabeca){ //Se passarmos por todos os elementos e não encontrarmos, o el não existe. 
        return NULL;
    }
    return i;
}

elo_t *pegarElo(lista_t *l){
    return malloc(sizeof(elo_t)); //Retorna um novo espaço livre;
}


bool devolverElo(lista_t *l, elo_t *e){
    free(e);
    return true;
}

bool inserir(lista_t *l, registro_t reg){
    elo_t *ant;
    elo_t * i = busca(l, reg.chave, &ant);

    if(i != NULL && i->reg.chave == reg.chave){
        return false; //Elemento já existe;
    }

    elo_t *novo = pegarElo(l);
    if(novo == NULL) return false;

    novo->prox = ant->prox;
    ant->prox = novo;

    novo->reg = reg;
    return true;
}

bool excluir(lista_t *l, int ch){
    elo_t *ant;
    elo_t *i = busca(l, ch, &ant);

    if(i == NULL || i->reg.chave != ch){
        return false; //Elemento não existe;
    }

    ant->prox = i->prox; // O próximo do elemento anterior passa a ser o prox do atual;
    devolverElo(l, i);
    return true;
}

void reinicializar(lista_t *l){
    elo_t *i = l->cabeca->prox;
        while(i != l->cabeca){
            elo_t *ptr_to_free = i;
            i = i->prox;
            devolverElo(l, ptr_to_free);
    }
    l->cabeca->prox = l->cabeca;
}


bool eh_crescente(lista_t *l){
    for(elo_t *i = l->cabeca->prox; i != l->cabeca; i = i->prox){
        elo_t *j = i->prox; //Elemento sucessor i + 1;
        if(j->reg.chave <= i->reg.chave) return false;
    }
        return true;
}




int main(){
    lista_t l;
    inicializar(&l);
    exibir(&l);

    
    // reinicializar(&l);

    for(int i = 0; i < 10; i++){
        registro_t reg;
        reg.chave = rand() % 100;
        bool ret;

        printf("Inserindo %d\n", reg.chave);
        ret = inserir(&l, reg);
        if(ret) printf("Inserido com sucesso\n");
        else printf("Erro ao inserir\n");
        exibir(&l);
        printf("\n");
    }
    registro_t reg;
    reg.chave = 50;
    printf("Inserindo %d\n", reg.chave);
    inserir(&l, reg);
    exibir(&l);
    return 0;
}

