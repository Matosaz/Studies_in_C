#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "debug.h"

#define LIMITE_NOME_ROTULO_DEBUG 20u
#define LIMITE_RECUO_COMPACTO_DEBUG 20

typedef struct {
    const no_pontuacao_t *pontuacao;
    const no_nome_t *nome;
    size_t pai, esquerda, direita, coluna, largura;
    int nivel;
    char *rotulo;
} no_visual_t;

static size_t contar_nos_visuais(const no_pontuacao_t *p, const no_nome_t *n) {
    if (p != NULL) return 1 + contar_nos_visuais(p->esquerda, NULL)
                            + contar_nos_visuais(p->direita, NULL);
    if (n != NULL) return 1 + contar_nos_visuais(NULL, n->esquerda)
                            + contar_nos_visuais(NULL, n->direita);
    return 0;
}

static size_t preencher_visual(const no_pontuacao_t *p, const no_nome_t *n, no_visual_t *v, size_t *proximo, size_t pai, int nivel, int por_pontos) {
    size_t atual;
    if (por_pontos ? p == NULL : n == NULL) return (size_t)-1;
    atual = (*proximo)++;
    v[atual].pai = pai;
    v[atual].nivel = nivel;
    v[atual].pontuacao = por_pontos ? p : NULL;
    v[atual].nome = por_pontos ? NULL : n;
    v[atual].esquerda = preencher_visual(por_pontos ? p->esquerda : NULL,
        por_pontos ? NULL : n->esquerda, v, proximo, atual, nivel + 1, por_pontos);
    v[atual].direita = preencher_visual(por_pontos ? p->direita : NULL,
        por_pontos ? NULL : n->direita, v, proximo, atual, nivel + 1, por_pontos);
    v[atual].largura = 0;
    v[atual].rotulo = NULL;
    return atual;
}

static void resumir_nome_debug(const char *nome, char *resumo, size_t tamanho) {
    size_t comprimento = strlen(nome);
    if (comprimento <= LIMITE_NOME_ROTULO_DEBUG) {
        snprintf(resumo, tamanho, "%s", nome);
    } else {
        snprintf(resumo, tamanho, "%.*s...", (int)(LIMITE_NOME_ROTULO_DEBUG - 3), nome);
    }
}

static void montar_rotulo(no_visual_t *v, size_t total, int por_pontos) {
    size_t i;
    for (i = 0; i < total; i++) {
        char nome_resumido[LIMITE_NOME_ROTULO_DEBUG + 1];
        size_t tamanho = TAM_NOME + 48;
        const no_pontuacao_t *empate;
        v[i].rotulo = (char *)malloc(tamanho);
        if (v[i].rotulo == NULL) return;
        if (!por_pontos) {
            resumir_nome_debug(v[i].nome->jogador->nome, nome_resumido, sizeof(nome_resumido));
            snprintf(v[i].rotulo, tamanho, "[%s]", nome_resumido);
        } else {
            size_t quantidade = 1;
            resumir_nome_debug(v[i].pontuacao->jogador->nome, nome_resumido, sizeof(nome_resumido));
            for (empate = v[i].pontuacao->meio; empate != NULL; empate = empate->meio)
                quantidade++;
            if (quantidade == 1) {
                snprintf(v[i].rotulo, tamanho, "[%d] %s",
                    v[i].pontuacao->jogador->pontuacao, nome_resumido);
            } else {
                snprintf(v[i].rotulo, tamanho, "[%d] %s (+%zu empatados)",
                    v[i].pontuacao->jogador->pontuacao, nome_resumido, quantidade - 1);
            }
        }
        v[i].largura = strlen(v[i].rotulo);
    }
}

static void posicionar_em_ordem(no_visual_t *v, size_t indice, size_t *cursor) {
    if (indice == (size_t)-1) return;
    posicionar_em_ordem(v, v[indice].esquerda, cursor);
    v[indice].coluna = *cursor;
    *cursor += v[indice].largura + 4;
    posicionar_em_ordem(v, v[indice].direita, cursor);
}

static void desenhar_arvore(FILE *saida, const no_pontuacao_t *p, const no_nome_t *n, int por_pontos) {
    size_t total = contar_nos_visuais(p, n), i, proximo = 0, largura = 2;
    size_t altura = 1, linhas, celulas;
    no_visual_t *v;
    char *tela;
    if (total == 0) { fputs("(vazia)\n", saida); return; }
    v = (no_visual_t *)calloc(total, sizeof(*v));
    if (v == NULL) { fputs("(sem memoria para desenhar)\n", saida); return; }
    preencher_visual(p, n, v, &proximo, (size_t)-1, 0, por_pontos);
    montar_rotulo(v, total, por_pontos);
    for (i = 0; i < total; i++) {
        if (v[i].rotulo == NULL) { fputs("(sem memoria para desenhar)\n", saida); goto fim; }
        if ((size_t)v[i].nivel + 1 > altura) altura = (size_t)v[i].nivel + 1;
    }
    /* A ordem em percurso simetrico conserva esquerda/raiz/direita e evita
       a explosao exponencial de espacos do posicionamento por potencias de 2. */
    {
        size_t cursor = 1;
        posicionar_em_ordem(v, 0, &cursor);
        largura = cursor + 1;
    }
    linhas = altura * 3 - 2;
    celulas = largura * linhas;
    tela = (char *)malloc(celulas);
    if (tela == NULL) { fputs("(sem memoria para desenhar)\n", saida); goto fim; }
    memset(tela, ' ', celulas);
    for (i = 0; i < total; i++) {
        size_t linha = (size_t)v[i].nivel * 3, centro = v[i].coluna + v[i].largura / 2;
        memcpy(tela + linha * largura + v[i].coluna, v[i].rotulo, v[i].largura);
        if (v[i].pai != (size_t)-1) {
            size_t pc = v[v[i].pai].coluna + v[v[i].pai].largura / 2;
            size_t pl = (size_t)v[v[i].pai].nivel * 3;
            tela[(pl + 1) * largura + pc] = '|';
            for (size_t c = pc < centro ? pc : centro; c <= (pc > centro ? pc : centro); c++)
                tela[(pl + 2) * largura + c] = '-';
            tela[(pl + 2) * largura + pc] = '+';
            tela[(pl + 2) * largura + centro] = '+';
        }
    }
    for (i = 0; i < linhas; i++) {
        size_t fim_linha = largura;
        while (fim_linha > 0 && tela[i * largura + fim_linha - 1] == ' ') fim_linha--;
        fwrite(tela + i * largura, 1, fim_linha, saida);
        fputc('\n', saida);
    }
    free(tela);
fim:
    for (i = 0; i < total; i++) free(v[i].rotulo);
    free(v);
}

static void imprimir_empates_rec(const no_pontuacao_t *no, FILE *saida) {
    const no_pontuacao_t *empate;
    int indice;
    if (no == NULL) return;

    imprimir_empates_rec(no->esquerda, saida);
    if (no->meio != NULL) {
        fprintf(saida, "Pontuacao %d:\n", no->jogador->pontuacao);
        indice = 1;
        for (empate = no; empate != NULL; empate = empate->meio, indice++) {
            fprintf(saida, "  %d. %s\n", indice, empate->jogador->nome);
        }
    }
    imprimir_empates_rec(no->direita, saida);
}

static int possui_empates(const no_pontuacao_t *no) {
    if (no == NULL) return 0;
    return no->meio != NULL || possui_empates(no->esquerda) || possui_empates(no->direita);
}

void depurar_ranking(const ranking_t *ranking, FILE *saida) {
    fprintf(saida, "Ranking (%d jogadores)\n", ranking->total_jogadores);
    fputs("Arvore de pontuacao (esquerda = menos pontos; direita = mais pontos)\n", saida);
    desenhar_arvore(saida, ranking->raiz_pontuacao, NULL, 1);
    if (possui_empates(ranking->raiz_pontuacao)) {
        fputs("\nDetalhes dos grupos empatados (ordem da cadeia meio):\n", saida);
        imprimir_empates_rec(ranking->raiz_pontuacao, saida);
    }
    fputs("\nArvore auxiliar de nomes (esquerda = nome menor)\n", saida);
    desenhar_arvore(saida, NULL, ranking->raiz_nome, 0);
}
