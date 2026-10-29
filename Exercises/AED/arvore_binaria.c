#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int chave;
} registro_t;

typedef struct aux{
    struct aux* esq;
    struct aux* dir;
    registro_t reg;
} no_t;

typedef enum{
    DIREITA,
    ESQUERDA
} lado_t;


typedef no_t *arvore_t;

no_t *criar_no(int chave){
    no_t *novo = malloc(sizeof(no_t));
    novo->reg.chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void inicializar_arvore(arvore_t *arvore, int ch){
    *arvore = criar_no(ch);
}

//Busca por elemento recursivamente:
no_t* busca(arvore_t raiz, int ch_busca){
    if(raiz == NULL) return NULL;
    if(raiz->reg.chave == ch_busca) return raiz; //Estamos retornando a referência à posição da árvore;

    no_t *achou_esquerda = busca(raiz->esq, ch_busca); //Se não encontrar na raíz, inicia a buscar pelos ramos da esquerda
    if(achou_esquerda != NULL) return achou_esquerda; //se não encontrar nos ramos da esquerda, busca pelos ramos da direita;

    return busca(raiz->dir, ch_busca);
}

bool inserir(arvore_t raiz, int ch_novo, int ch_pai, lado_t lado){
    no_t *pai = busca(raiz, ch_pai);

    if(pai == NULL) return false;

    no_t *novo = busca(raiz, ch_novo);
    if(novo != NULL) return false; //Não cria se o elemento já existir (evita duplicata)
    
    novo = criar_no(ch_novo);
    if(lado == ESQUERDA){
        novo->esq = pai->esq; //O filho à esquerda do novo aponta para o filho à esquerda que o pai apontava anteriormente (Geralmente NULL);
        pai->esq = novo; // O filho à esquerda do pai passa a ser o novo;
    }
    else if(lado == DIREITA){
        novo->dir = pai->dir;
        pai->dir = novo;
    }
    else{
        free(novo);
        printf("Lado inválido: %d\n", lado);
        return false;
    }
    return true;
}

void exibir_preordem(arvore_t raiz){
    if(raiz == NULL){
        printf("X");
        return;
    }
    printf("%d", raiz->reg.chave);
    printf("(");
    exibir_preordem(raiz->esq);
    printf("|");
    exibir_preordem(raiz->dir);
    printf(")");
}

void free_subarvore(arvore_t raiz){
    if(raiz == NULL) return;
    free_subarvore(raiz->esq);
    free_subarvore(raiz->dir);
    free(raiz);
}

bool excluir(arvore_t *raiz, int ch_excluir){
    if(*raiz == NULL) return false;
    if((*raiz)->reg.chave == ch_excluir){
        free_subarvore(*raiz);
        *raiz = NULL;
        return true;
    }
    bool deucerto = excluir(&(*raiz)->esq, ch_excluir);
    if(deucerto) return deucerto;
    return excluir(&(*raiz)->dir, ch_excluir);
}

void tenta_inserir(arvore_t raiz, int chave, int chave_pai, lado_t lado){
    printf("Tentando inserir %d a %s de %d\n", chave, (lado == ESQUERDA) ? "esquerda" : "direita", chave_pai);
    bool deucerto = inserir(raiz, chave, chave_pai, lado);
    
    if(deucerto) printf("\t Deu certo!\n\t");
    else printf("\tErro ao inserir\n\t");
    exibir_preordem(raiz);
    printf("\n");
}

void tenta_excluir(arvore_t *raiz, int chave){
    printf("Tentando excluir %d\n", chave);
    bool deucerto = excluir(raiz, chave);
    
    if(deucerto) printf("\t Deu certo!\n\t");
    else printf("\tErro ao inserir\n\t");
    exibir_preordem(*raiz);
    printf("\n");
}



int main() {
	arvore_t raiz;
	inicializar_arvore (&raiz, 1);
	printf("Raiz criada:\n\t");
	exibir_preordem(raiz);
	printf("\n");
	
	tenta_inserir(raiz, 2, 1, ESQUERDA);
	
	tenta_inserir(raiz, 3, 1, DIREITA);
	
	tenta_inserir(raiz, 20, 2, ESQUERDA);
	
	tenta_inserir(raiz, 40, 2, DIREITA);
	
	tenta_inserir(raiz, 30, 3, ESQUERDA);
	
	tenta_inserir(raiz, 60, 3, DIREITA);
	
	tenta_inserir(raiz, 100, 1, DIREITA);
	
	tenta_inserir(raiz, 200, 99, DIREITA);
	
	tenta_inserir(raiz, 100, 30, DIREITA);
	
	tenta_excluir(&raiz, 3);
	
	tenta_excluir(&raiz, 99);
	
	tenta_excluir(&raiz, 1);
	
	return 0;

}