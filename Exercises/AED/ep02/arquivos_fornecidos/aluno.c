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


static void inserir_no_pontuacao(no_pontuacao_t **raiz, jogador_t *jogador){
    if(*raiz == NULL){
        no_pontuacao_t *novo = (no_pontuacao_t*)malloc(sizeof(no_pontuacao_t));
        if(novo == NULL) return;
        novo->jogador = jogador; //Atribui o jogador com a pontuação atualizada ao novo nó da árvore de pontuação;
        novo->esquerda = NULL;
        novo->direita = NULL;
        novo->meio = NULL;
        novo->dados_auxiliares = NULL;
        *raiz = novo;
        return;
    }
    if(jogador->pontuacao < (*raiz)->jogador->pontuacao) {//Compara a pontuação com a pontuação do jogador;
        inserir_no_pontuacao(&(*raiz)->esquerda, jogador);
        return;
    }
    else if(jogador->pontuacao > (*raiz)->jogador->pontuacao) {//Compara a pontuação com a pontuação do jogador
        inserir_no_pontuacao(&(*raiz)->direita, jogador);
        return;
    }
    else{ //Caso em que o elemento apresenta pontuação igual
        no_pontuacao_t *novo = (no_pontuacao_t*)malloc(sizeof(no_pontuacao_t));
        if(novo == NULL) return;
        novo->jogador = jogador;
        novo->esquerda = (*raiz)->esquerda;
        novo->direita = (*raiz)->direita;
        novo->meio = *raiz; //Antiga raíz vira o nó do meio com filhos NULOS
        novo->dados_auxiliares = NULL;
        (*raiz)->direita = (*raiz)->esquerda = NULL;
        *raiz = novo;
    }
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
    if(*raiz == NULL) return;
    int pontuacao = jogador->pontuacao;
    int atual = (*raiz)->jogador->pontuacao;
    no_pontuacao_t *subs;
    
    if(pontuacao < atual){
        remover_pontuacao(&(*raiz)->esquerda, jogador);
        return;
    }
    if(pontuacao > atual){
        remover_pontuacao(&(*raiz)->direita, jogador);
        return;
    }

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

    if(free_raiz->meio != NULL){
        no_pontuacao_t *prox = free_raiz->meio;
        prox->esquerda = free_raiz->esquerda;
        prox->direita = free_raiz->direita; //O Elemento sucessor do meio assume a posição do inicial
        *raiz = prox;
    }
    //Caso de nó com apenas um filho (Basta linkar)
    else if(free_raiz->esquerda == NULL){
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
            pai_subs = subs;
            subs = subs->esquerda;
        }
        if(pai_subs != free_raiz){
            pai_subs->esquerda = subs->direita;
            subs->direita = free_raiz->direita;
        }
        subs->esquerda = free_raiz->esquerda;
        *raiz = subs;
    }
    free(free_raiz);
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
static void imprimir_pont(no_pontuacao_t *n, int nivel) {
    if (n == NULL) return;
    imprimir_pont(n->direita, nivel + 1);

    for (int i = 0; i < nivel; i++) printf("        ");
    printf("%d [%s", n->jogador->pontuacao, n->jogador->nome);
    for (no_pontuacao_t *m = n->meio; m != NULL; m = m->meio)
        printf(" -> %s", m->jogador->nome);
    printf("]\n");

    imprimir_pont(n->esquerda, nivel + 1);
}

// void listar_top_k(ranking_t *ranking, int k) {
//     /*
//      * TODO: percorra os grupos da maior para a menor pontuacao e imprima
//      * todos os jogadores que ocupam as posicoes de 1 a k, incluindo todos
//      * os empatados na ultima posicao. k e numero de posicoes, nao de nomes.
//      * Use o formato
//      *   "<posicao>) <nome> - <pontuacao>"
//      * Lembre que jogadores empatados (cadeia "meio") tem a mesma posicao.
//      */
// }

// int consultar_posicao_jogador(ranking_t *ranking, const char *nome) {
//     /*
//      * TODO: use a arvore de nomes para achar o jogador e depois
//      * determine a posicao dele (1 + grupos com pontuacao distinta e
//      * estritamente maior). Retorne -1 se o jogador nao existir.
//      */
//     return -1;
// }
