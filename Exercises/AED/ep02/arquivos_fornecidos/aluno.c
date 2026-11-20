#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estrutura.h"

/*
 * Numero USP: ________
 *
 * ============================================================
 *  ESTE E O UNICO ARQUIVO QUE VOCE DEVE MODIFICAR E ENTREGAR.
 *
 *  Implemente aqui o ranking: uma ARVORE DE PONTUACAO (ABB com
 *  ponteiro "meio" para os empatados) e uma ARVORE DE NOMES (ABB
 *  para achar um jogador pelo nome). Leia com atencao os comentarios
 *  de estrutura.h: eles descrevem os structs e o que cada funcao
 *  deve fazer. Na arvore de pontuacao, valores menores ficam a
 *  esquerda e valores maiores ficam a direita.
 *
 *  Voce pode (e deve) criar funcoes auxiliares "static" neste arquivo
 *  para organizar a recursao. NAO altere as assinaturas das funcoes
 *  declaradas em estrutura.h.
 *
 *  Ao criar um no, inicialize seu campo dados_auxiliares com NULL. Esse
 *  campo e opcional e existe apenas para extensoes de bonus.
 * ============================================================
 */

/* ---------- funcoes auxiliares (escreva as que precisar aqui) ---------- */

/* Sugestoes de assinaturas que provavelmente vao ser uteis:
 *
 * static no_nome_t *inserir_no_nome(no_nome_t *raiz, jogador_t *jogador);
 * static jogador_t *buscar_jogador(no_nome_t *raiz, const char *nome);
 *
 * static no_pontuacao_t *inserir_no_pontuacao(no_pontuacao_t *raiz, jogador_t *jogador);
 * static no_pontuacao_t *remover_no_pontuacao(no_pontuacao_t *raiz, jogador_t *jogador);
 */

typedef struct no_pilha{
    no_pontuacao_t *raiz;
    struct no_pilha *prox_no;
}no_pilha_t;

typedef struct{
    no_pilha_t *topo;
}pilha_t;

typedef struct{
    int tamanho;
}auxiliar_t;
 
static int tamanho(no_pontuacao_t *no) {
    if(no == NULL) return 0;
    auxiliar_t *no_aux= no->dados_auxiliares;
    return no_aux->tamanho;
}

static void atualizar(no_pontuacao_t *no){
    if(no == NULL) return;
    auxiliar_t *no_aux = no->dados_auxiliares;
    no_aux->tamanho = 1 + tamanho(no->esquerda) + tamanho(no->direita); //Encontra o tamanho da subárvore;
}

static void diminuir_tamanho(no_pontuacao_t *no){
    auxiliar_t *no_aux = no->dados_auxiliares;
    no_aux->tamanho--;
}

static void inicializar_pilha(pilha_t *p){
    p->topo = NULL;
};

static void push(pilha_t *p, no_pontuacao_t *no){
    no_pilha_t *novo = (no_pilha_t *)malloc(sizeof(no_pilha_t));
    if(novo == NULL) return;

    novo->raiz = no;
    novo->prox_no = p->topo; //O novo elemento aponta para o antigo topo;
    p->topo = novo; //O novo elemento passa a estar no topo;
}

static void pop(pilha_t *p){
    if(p->topo == NULL) return;
    no_pilha_t *temp = p->topo;
    p->topo = p->topo->prox_no; //Efetua o bypass do elemento do topo, de modo que o topo passa a ser o elemento "abaixo" dele
    free(temp);
}

static no_pontuacao_t *peek(pilha_t *p){
    if(p->topo == NULL) return NULL;
    return p->topo->raiz; //Retorno o no que está no topo;
};


static no_pontuacao_t *novo_no(jogador_t *jogador){
    no_pontuacao_t *novo = (no_pontuacao_t *)malloc(sizeof(no_pontuacao_t) + sizeof(auxiliar_t));
    if(novo == NULL) return NULL;
    novo->jogador = jogador; //Atribui o jogador com a pontuação atualizada ao novo nó da árvore de pontuação;
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->meio = NULL;
    novo->dados_auxiliares = novo + 1;
    atualizar(novo); //Atualiza o tamanho da subárvore;
    return novo;
}

static int inserir_no_pontuacao(no_pontuacao_t **raiz, jogador_t *jogador){
    int criou;
    if(*raiz == NULL){
        *raiz = novo_no(jogador); 
        return (*raiz != NULL);// 1 se raiz foi criada, 0 se não foi criada
    }
    if(jogador->pontuacao < (*raiz)->jogador->pontuacao) {//Compara a pontuação com a pontuação do jogador;
        criou = inserir_no_pontuacao(&(*raiz)->esquerda, jogador);
    }
    else if(jogador->pontuacao > (*raiz)->jogador->pontuacao) {//Compara a pontuação com a pontuação do jogador
        criou =inserir_no_pontuacao(&(*raiz)->direita, jogador);
    }  
    else{ //Caso em que o elemento apresenta pontuação igual -> Substitui a pontuação antiga pela nova;
        no_pontuacao_t *novo = novo_no(jogador);
        if(novo == NULL) return 0;
        novo->jogador = jogador;
        novo->esquerda = (*raiz)->esquerda;
        novo->direita = (*raiz)->direita;
        novo->meio = *raiz; //Antiga raíz vira o nó do meio com filhos NULOS
        (*raiz)->direita = (*raiz)->esquerda = NULL;
        atualizar(novo);
        *raiz = novo;
        return 0;
    }
    if(criou) atualizar(*raiz);
    return criou;
}

static void inserir_no_nome(no_nome_t **raiz, jogador_t *jogador){
    while(*raiz != NULL){
        int cmp = strcmp(jogador->nome, (*raiz)->jogador->nome);
        if(cmp == 0) return;
        raiz = (cmp < 0) ? &(*raiz)->esquerda : &(*raiz)->direita;
    }
    
    no_nome_t *novo = (no_nome_t*)malloc(sizeof(no_nome_t));
    if(novo == NULL) return;
    novo->jogador = jogador;//Atribui o jogador com o nome atualizado ao novo nó da árvore de nomes;
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->dados_auxiliares = NULL;
    *raiz = novo;
}


static jogador_t *cria_jogador(const char *nome, int pontos){
    jogador_t *novo = (jogador_t *)malloc(sizeof(jogador_t));
    if(novo == NULL) return NULL;
    strncpy(novo->nome, nome, (TAM_NOME - 1)); //Remove o caracter nulo do final da string para evitar problemas de buffer;
    novo->nome[TAM_NOME - 1] = '\0'; // Garante que a string esteja terminada em nulo;
    novo->pontuacao = pontos;
    return novo;
}


static jogador_t *buscar_jogador(no_nome_t *raiz, const char *nome){
    while(raiz != NULL){
        char *nome_jogador = raiz->jogador->nome;
        int cmp = strcmp(nome, nome_jogador);
        if(cmp == 0){
            return raiz->jogador;
        }
        else if(cmp < 0){
            raiz = raiz->esquerda;
        }
        else if(cmp > 0){
            raiz = raiz->direita;
        }
    }
    return NULL;
}


static void remover_pontuacao(no_pontuacao_t **raiz, jogador_t *jogador){
    int pontuacao = jogador->pontuacao;
    no_pontuacao_t **inicio = raiz;
    no_pontuacao_t *subs;
    
    while(*raiz != NULL && (*raiz)->jogador->pontuacao != pontuacao){
        int atual = (*raiz)->jogador->pontuacao;
        if(pontuacao < atual){
            raiz = &(*raiz)->esquerda;
        }
        else{
            raiz = &(*raiz)->direita;
        }
    }
    if(*raiz == NULL) return;
     
    //Se caímos no caso de meio e o jogador que iremos excluir não é o inicial
    if(((*raiz)->jogador) != jogador){
        no_pontuacao_t *aux = *raiz;
        while(aux->meio != NULL && aux->meio->jogador != jogador){
            aux = aux->meio;
        }
        if(aux->meio == NULL) return;
        no_pontuacao_t *no_excluir = aux->meio; //Encontramos o nó que desejamos excluir do meio;
        aux->meio = no_excluir->meio; //O meio de aux passa a apontar para o meio do no prester a ser excluído
        free(no_excluir);
        return;
    }

    no_pontuacao_t *free_raiz = *raiz;

    if(free_raiz->meio != NULL){// Se desejamos remover o nó inicial do meio -> substituimos ele pelo sucessor do meio
        no_pontuacao_t *prox = free_raiz->meio;
        prox->esquerda = free_raiz->esquerda;
        prox->direita = free_raiz->direita; //O Elemento sucessor do meio assume a posição do inicial
        atualizar(prox);
        *raiz = prox;
        free(free_raiz);
        return;
    }

    no_pontuacao_t *no = *inicio;
    //Como removemos um elemento, necessitamos reduzir o tamanho da árvore
    while(no != free_raiz){
        diminuir_tamanho(no);
        if(pontuacao < no->jogador->pontuacao) no = no->esquerda;
        else no = no->direita;
    } // *free_raiz = anterior da raiz, pois removemos raiz que ela apontava
    
    //Caso de nó com apenas um filho (Basta linkar)
    if(free_raiz->esquerda == NULL){
        *raiz = free_raiz->direita;
    }
    else if(free_raiz->direita == NULL){
        *raiz = free_raiz->esquerda;
    }
    else{
        //Caso de nós com dois filhos:
        no_pontuacao_t *pai_subs = free_raiz;
        subs = free_raiz->direita;
        while(subs->esquerda != NULL){
            diminuir_tamanho(subs); //Reuduz o tamanho dos nós acima do subs
            pai_subs = subs;
            subs = subs->esquerda;
        }
        if(pai_subs != free_raiz){
            pai_subs->esquerda = subs->direita;
            subs->direita = free_raiz->direita;
        }
        subs->esquerda = free_raiz->esquerda;
        atualizar(subs); //Atualiza o tamanho da subárvore após a exclusão
        *raiz = subs;
    }
    free(free_raiz);
}

static int pegar_posicao(no_pontuacao_t *no, int pontuacao){
    int maiores = 0;
    while(no != NULL){
        int atual = no->jogador->pontuacao;
        if(pontuacao < atual){
            maiores += 1 + tamanho(no->direita); //Armazena o número de elementos com pontuação maior;
            no = no->esquerda;
        }
        else if(pontuacao > atual){
            no = no->direita;
        }
        else{
            return 1 + maiores + tamanho(no->direita); //Retorna a posição do elemento buscado
        }
    }
    return -1;
}


/* ---------- funcoes da interface (obrigatorias) ---------- */

ranking_t *criar_ranking(void) {
    /* TODO: aloque e inicialize o ranking (as duas raizes em NULL e
     * total_jogadores = 0). */
    
    ranking_t *ranking = (ranking_t *)malloc((sizeof(ranking_t)));

    if(ranking == NULL){
        return NULL;
    }
    ranking->raiz_pontuacao = NULL;
    ranking->raiz_nome = NULL;
    ranking->total_jogadores = 0;
    return ranking;
}

void inserir_pontuacao(ranking_t *ranking, const char *nome, int pontos) {
    /*
     * TODO:
     *  1. Procure o jogador na arvore de nomes.
     *  2. Se existir: remova-o da arvore de pontuacao usando a pontuacao
     *     antiga, substitua-a por 'pontos' e reinsira-o. A arvore de nomes
     *     nao muda; o jogador fica no inicio do grupo da nova pontuacao.
     *  3. Se nao existir: crie UM jogador_t e insira-o nas duas arvores
     *     (os nos das duas arvores apontam para o mesmo jogador_t).
     *
     * Ao remover um no com dois filhos, use o sucessor em ordem: o no mais
     * a esquerda da subarvore direita.
     */
    jogador_t *jogador = buscar_jogador(ranking->raiz_nome, nome);
    if(jogador != NULL){
        remover_pontuacao(&ranking->raiz_pontuacao, jogador); //Remove o jogador da árvore de pontuação utilizando a pontuação antiga;
        jogador->pontuacao = pontos; //Atualiza a pontuação do jogador para a nova;
        inserir_no_pontuacao(&ranking->raiz_pontuacao, jogador); //Reinsere o jogador na árvore de pontuação com a pontuação atualizada;
    }else{
        jogador = cria_jogador(nome, pontos);
        if(jogador == NULL) return;

        inserir_no_nome(&ranking->raiz_nome, jogador); //Insere o jogador na árvore de nomes ao criá-lo
        inserir_no_pontuacao(&ranking->raiz_pontuacao, jogador); //Insere o jogador na árvore de pontuação;
        ranking->total_jogadores++; //Incrementa o total de jogadores no ranking;
    }
}

void listar_top_k(ranking_t *ranking, int k) {
    /*
     * TODO: percorra os grupos da maior para a menor pontuacao e imprima
     * todos os jogadores que ocupam as posicoes de 1 a k, incluindo todos
     * os empatados na ultima posicao. k e numero de posicoes, nao de nomes.
     * Use o formato
     *   "<posicao>) <nome> - <pontuacao>"
     * Lembre que jogadores empatados (cadeia "meio") tem a mesma posicao.
     */
    if(ranking == NULL || k <= 0) return;
    no_pontuacao_t *no_atual = ranking->raiz_pontuacao;
    pilha_t pilha;
    int posicao = 1;

    inicializar_pilha(&pilha);
    while((no_atual != NULL || pilha.topo != NULL) && posicao <= k){

        while(no_atual != NULL){
            push(&pilha, no_atual); //Inicia a salvar a partir da raíz e encerra quando estiver no maior elemento;
            no_atual = no_atual->direita;
        }
        no_pontuacao_t *no_topo = peek(&pilha);
        no_pontuacao_t *temp_topo = no_topo;
        pop(&pilha);
        printf("%d) %s - %d\n",posicao, no_topo->jogador->nome,no_topo->jogador->pontuacao);
        
        while(temp_topo->meio != NULL){
            temp_topo= temp_topo->meio;
            printf("%d) %s - %d\n",posicao, temp_topo->jogador->nome,temp_topo->jogador->pontuacao);
        }
        if(posicao == k && no_atual == NULL){
            while(pilha.topo != NULL) pop(&pilha);
        }
        posicao++;
        no_atual = no_topo->esquerda;
    }    
}

int consultar_posicao_jogador(ranking_t *ranking, const char *nome) {
    /*
     * TODO: use a arvore de nomes para achar o jogador e depois
     * determine a posicao dele (1 + grupos com pontuacao distinta e
     * estritamente maior). Retorne -1 se o jogador nao existir.
     */
    if(ranking == NULL || nome == NULL) return -1;
    jogador_t *jogador = buscar_jogador(ranking->raiz_nome, nome);
    if(!jogador) return -1;

    return pegar_posicao(ranking->raiz_pontuacao, jogador->pontuacao);
}
