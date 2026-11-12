#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000

typedef struct{
    int chave;
    //outros campos;
}registro_t;

typedef struct no_t{
    registro_t reg;
    struct no_t *esq;
    struct no_t *dir;
} no_t;

typedef no_t* arvore_t;


//Funções:
no_t *cria_no(registro_t reg){
    no_t *novo = malloc(sizeof(no_t));
    novo->reg = reg;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void inicializar(arvore_t *arvore){
    *arvore = NULL; //Define o ponteiro da árvore como NULL, indicando que a árvore está vazia. Equivale a um ponteiro para ponteiro de no_t
}


bool inserir(arvore_t *a, registro_t novo_reg){
    if(*a == NULL){
        *a = cria_no(novo_reg);
        return true;
    }
    if(novo_reg.chave < (*a)->reg.chave){
        return inserir(&(*a)->esq, novo_reg);    
    }
    if(novo_reg.chave > (*a)->reg.chave){
        return inserir(&(*a)->dir, novo_reg);
    }
    return false; //Chave já existente;
}

int tamanho(arvore_t a){
    if(a == NULL) return 0;
    return 1 + tamanho(a->esq) + tamanho(a->dir); 
}

int altura(arvore_t a){
    if(a == NULL) return -1;

    int altura_esq = altura(a->esq);
    int altura_dir = altura(a->dir);

    if(altura_esq > altura_dir){
        return altura_esq + 1;
    }
    else{
        return altura_dir + 1;
    }
}


//Theta(log n)
//Consome mais memória, pois cada chamada recursiva é armazenada na pilha de execução
no_t* buscar(no_t *no, int chave){
    if(no == NULL) return NULL;
    if(no->reg.chave == chave) return no;
    
    if(chave < no->reg.chave){
        return buscar(no->esq, chave); 
    }
    else{
        return buscar(no->dir, chave);
    }
}
    
//Ou, de forma iterativa:
//Theta (log n)
//Consome menos memória, pois não há chamadas recursivas -> Mais eficiente.
no_t *buscar_iterativo(no_t *no, int chave){
    while(no != NULL){
        if(no->reg.chave == chave) return no;
        if(chave < no->reg.chave){
            no = no->esq;
        }
        if(chave > no->reg.chave){
            no = no->dir;
        }
    }    
    return NULL;
}


no_t *buscar_com_pai(arvore_t a, int chave, arvore_t *pai){
    *pai = NULL;
    while(a != NULL){
        if(a->reg.chave == chave) return a;

        *pai = a;
        if (chave < a->reg.chave){
            a = a->esq;
        }
        if(chave > a->reg.chave){
            a = a->dir;
        }
    }
    return NULL;
}


bool excluir(arvore_t *a, int chave){
    if(*a == NULL) return false;
    no_t *no, *pai, *substituto;

    no = buscar_com_pai(*a, chave, &pai);
    if(no == NULL) return false;
    
    if(no->dir == NULL){
        substituto = no->esq;
    }
    else if(no->esq == NULL){
        substituto = no->dir;
    }
    else{
        no_t *pai_substituto = no;
        substituto = no->esq;

        while(substituto->dir != NULL){ //Pega o elemento mais à direita da subárvore esquerda (Mais próximo do elemento que desejamos)
            pai_substituto = substituto; //Atualiza o pai conforme o valor do no_substituto 
            substituto = substituto->dir;
        }
        if(pai_substituto != no){
            pai_substituto->dir = substituto->esq;
            substituto->esq = no->esq;
        }
        substituto->dir = no->dir;
    }

    if(pai == no){
        free(no);
        *a = substituto;
    }
	
    else{
        if(pai->esq != NULL && pai->esq->reg.chave == no->reg.chave){
            pai->esq = substituto;
        }
        else{
            pai->dir = substituto;
        }
        free(no);
    }
    return true;
}
void exibir_preordem(arvore_t a) {
	if (a == NULL) return;

	printf("%d ( ", a->reg.chave);
	exibir_preordem(a->esq);
	exibir_preordem(a->dir);
	printf(") ");
}

void exibir_emordem(arvore_t a) {
	if (a == NULL) return;

	exibir_emordem(a->esq);
	printf("%d ", a->reg.chave);
	exibir_emordem(a->dir);
}

void exibir_posordem(arvore_t a) {
	if (a == NULL) return;

	exibir_posordem(a->esq);
	exibir_posordem(a->dir);
	printf("%d ", a->reg.chave);
}

// implementacao simplificada de uma fila
typedef struct {
	int comeco;
	int fim;
	bool vazia;
	no_t *nos[MAX];
} fila_t;

void init_fila(fila_t *f) {
	f->comeco = 0;
	f->fim = 0;
	f->vazia = true;
}

void enqueue(fila_t *f, no_t *no) {
	f->nos[f->fim++] = no;
	f->fim = f->fim % MAX;
	f->vazia = false;
}

no_t* dequeue(fila_t *f) {
	no_t* aux = f->nos[f->comeco];
	f->comeco = (f->comeco + 1) % MAX;
	if (f->comeco == f->fim) f->vazia = true;
	return aux;
}

void exibir_em_nivel (no_t *a) {
	fila_t f;
	init_fila(&f);
	enqueue(&f, a);
	printf("%d\n", f.vazia);
	while (!f.vazia) {
		no_t* aux;
		aux = dequeue(&f);
		printf("%d ", aux->reg.chave);

		if (aux->esq != NULL) enqueue(&f, aux->esq);
		if (aux->dir != NULL) enqueue(&f, aux->dir);
	}
	printf("\n");
}

void imprime_nivel(no_t* a, int nivel_alvo, int nivel_atual) {
	if (a == NULL) return;

	if (nivel_atual == nivel_alvo) {
		printf("%d ", a->reg.chave);
	} else {
		imprime_nivel(a->esq, nivel_alvo, nivel_atual + 1);
		imprime_nivel(a->dir, nivel_alvo, nivel_atual + 1);
	}
}

void exibir_em_nivel_pseudorecursivo(no_t *a) {
	int h = altura(a);

	for (int i = 1; i <= h; i++) {
		imprime_nivel(a, i, 1);
	}
	printf("\n");
}

bool validar(no_t* arvore) {
	// completar! https://leetcode.com/problems/validate-binary-search-tree/
	// dica: uma das possiveis solucoes usa uma funcao auxiliar com mais parametros...
	return false;
}


int main() {
	no_t* minha_arvore;
	bool resultado;
	registro_t myreg;
	
	inicializar(&minha_arvore);
	// minha_arvore = inicializar2(); // alternativa
	
	myreg.chave = 50;
	printf("Tentando inserir %d ...\t", myreg.chave);
	resultado = inserir(&minha_arvore, myreg);
	if (resultado) printf("sucesso!\n"); else printf("falhou :(\n");
	
	myreg.chave = 25;
	printf("Tentando inserir %d ...\t", myreg.chave);
	resultado = inserir(&minha_arvore, myreg);
	if (resultado) printf("sucesso!\n"); else printf("falhou :(\n");
	
	myreg.chave = 75;
	printf("Tentando inserir %d ...\t", myreg.chave);
	resultado = inserir(&minha_arvore, myreg);
	if (resultado) printf("sucesso!\n"); else printf("falhou :(\n");
	
	myreg.chave = 25;
	printf("Tentando inserir %d ...\t", myreg.chave);
	resultado = inserir(&minha_arvore, myreg);
	if (resultado) printf("sucesso!\n"); else printf("falhou :(\n");
	
	printf("tamanho %d\n", tamanho(minha_arvore));
	exibir_preordem(minha_arvore);
	printf("\n");
	exibir_emordem(minha_arvore);
	printf("\n");
	
	no_t* no_busca = buscar_iterativo(minha_arvore, minha_arvore->reg.chave);
	if (no_busca) printf("achou: %d\n", no_busca->reg.chave);
	else printf("Nao achou\n");
	
	no_busca = buscar_iterativo(minha_arvore, minha_arvore->dir->reg.chave);
	if (no_busca) printf("achou: %d\n", no_busca->reg.chave);
	else printf("Nao achou\n");
	
	no_busca = buscar_iterativo(minha_arvore, minha_arvore->dir->esq->reg.chave);
	if (no_busca) printf("achou: %d\n", no_busca->reg.chave);
	else printf("Nao achou\n");
	
	no_busca = buscar_iterativo(minha_arvore, -1);
	if (no_busca) printf("achou: %d\n", no_busca->reg.chave);
	else printf("nao achou: -1\n");
	
	printf("teste excluir -1 ...\t");
	resultado = excluir(&minha_arvore, -1);
	if (resultado) printf("sucesso!\n"); else printf("falhou :(\n");
	exibir_preordem(minha_arvore);
	printf("\n");
	
	printf("teste excluir 12 ... \t");
	resultado = excluir(&minha_arvore, 12);
	if (resultado) printf("sucesso!\n"); else printf("falhou :(\n");
	exibir_preordem(minha_arvore);
	printf("\n");
	
	exibir_preordem(minha_arvore);
	printf("\n");
	printf("Validar(minha_arvore) %d\n", validar(minha_arvore));
	
	no_t* arvore_binaria_comum = cria_no( (registro_t){.chave = 10} );
	arvore_binaria_comum->esq = cria_no( (registro_t){.chave = 1} ) ;
	arvore_binaria_comum->dir = cria_no( (registro_t){.chave = 20} );
	
	arvore_binaria_comum->esq->esq = cria_no( (registro_t){.chave = 0} );
	arvore_binaria_comum->esq->dir = cria_no( (registro_t){.chave = 8} );
	
	arvore_binaria_comum->dir->esq = cria_no( (registro_t){.chave = 5} );
	arvore_binaria_comum->dir->dir = cria_no( (registro_t){.chave = 30} );
	exibir_emordem(arvore_binaria_comum);
	printf("\n");
	printf("Validar(arvore_binaria_comum) %d\n", validar(arvore_binaria_comum));
	
	return 0;
}