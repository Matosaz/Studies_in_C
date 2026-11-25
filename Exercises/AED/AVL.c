typedef struct aux{
    int valor;
    int altura;
    struct aux *esq;
    struct aux *dir; 

}no_t;

typedef no_t* arvore_t;

int altura(no_t *no){
    if(no == NULL) return 0;

    return no->altura;
}

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int fator_balanceamento(no_t *no){
    if(no == NULL) return 0;
    return altura(no->dir) - altura(no->esq); 
}

void atualizar_altura(no_t *no){
    if(no == NULL) return;

    return 1 + max(altura(no->dir), altura(no->esq)); //Pega a altura do ramo com maior profundidade e inclui a raiz
}

no_t *criar_no(int ch){
    no_t *novo = (no_t *)malloc(sizeof(no_t));
    if(novo == NULL) return NULL;
    novo->altura = 0;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->valor = ch;
    return novo;
}

void rotacao_esq(arvore_t *a){ //RR
    no_t *u = (*a)->dir;
    (*a)->dir = u->esq;
    u->esq = (*a);
    atualizar_altura(*a);
    atualizar_altura(u);
    *a = u; 
}

void rotacao_dir(arvore_t *a){ // RR
    no_t *u = (*a)->esq;
    (*a)->esq = u->dir;
    u->dir = *a;
    atualizar_altura(*a);
    atualizar_altura(u);
    *a = u;
}

void balancear(arvore_t *a){
    no_t *p = *a;

    atualizar_altura(p);//Atualiza altura para que p herde a altura de a;
    int bal = fator_balanceamento(p); //Obtém o balanceamento inicial da árvore;
    if(bal < -1){//Árvore desbalanceada para a ESQUERDA
        if(fator_balanceamento(p->esq) > 0){ //É LR?
            rotacao_esq(&(p->esq));
        }
        rotacao_dir(p);
    }
    else if(bal > 1){//Árvore desbalanceada para a DIREITA
        if(fator_balanceamento(p->dir) < 0){ //É RL?
            rotacao_dir(&(p->dir));
        }
        rotacao_esq(p); 
    }
    else return; //Não necessita de rotação
}

void inserir(arvore_t *a, int ch){
    if(*a == NULL){
        *a = criar_no(ch);
        return;
    }

    if(ch < (*a)->valor){
        inserir(&(*a)->esq, ch);
    }
    else if(ch > (*a)->valor){
        inserir(&(*a)->dir, ch);
    }
    else return;
    balancear(a); //Realiza o balanceamento sempre após inserir um elemento
}

void remover(arvore_t *a, int ch){
    no_t *aux = *a;
    if(aux == NULL) return NULL;

    if(ch < (aux)->valor){
        remover(&aux->esq, ch); 
    }
    else if(ch > aux->valor){
        remover(&aux->dir, ch);
    }
    if(aux->esq == NULL || aux->dir == NULL){
        if(aux->esq == NULL) *a = aux->dir;
        else *a = aux->esq;
    }
    else{

        no_t *subs = aux->dir;
        while(subs->esq != NULL){
            subs = subs->esq;
        }
        aux->valor = subs->valor;
        remover(&aux->dir, aux->valor);
    }
    free(aux);
    balancear(a);
}