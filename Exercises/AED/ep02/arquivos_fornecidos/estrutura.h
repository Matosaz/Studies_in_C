#ifndef ESTRUTURA_H
#define ESTRUTURA_H

/*
 * ============================================================
 *  NAO ALTERE ESTE ARQUIVO.
 *  Ele define as estruturas e a interface que a sua implementacao
 *  (aluno.c) deve respeitar. A correcao automatica depende dessas
 *  assinaturas e desses structs permanecerem exatamente como estao.
 * ============================================================
 */

#define TAM_NOME 50   /* nome: ate 49 caracteres + o '\0' final */

/* Dados de um jogador. Cada jogador existe UMA unica vez na memoria:
 * as duas arvores abaixo guardam ponteiros para o mesmo jogador_t. */
typedef struct jogador {
    char nome[TAM_NOME];
    int pontuacao;
} jogador_t;

/*
 * No da ARVORE DE PONTUACAO.
 *   - esquerda: subarvore com pontuacoes MENORES
 *   - direita:  subarvore com pontuacoes MAIORES
 *   - meio:     proximo jogador com a MESMA pontuacao (cadeia de empatados)
 *   - dados_auxiliares: uso opcional para extensoes; inicialize com NULL
 *
 * Todos os jogadores com a mesma pontuacao formam uma cadeia ligada por
 * "meio". Somente o PRIMEIRO no da cadeia esta ligado a arvore; os demais
 * nos da cadeia tem esquerda == direita == NULL.
 */
typedef struct no_pontuacao {
    jogador_t *jogador;
    void *dados_auxiliares;
    struct no_pontuacao *esquerda;
    struct no_pontuacao *meio;
    struct no_pontuacao *direita;
} no_pontuacao_t;

/*
 * No da ARVORE DE NOMES: ABB ordenada pelo nome (strcmp).
 *   - esquerda: nomes menores
 *   - direita:  nomes maiores
 *   - dados_auxiliares: uso opcional para extensoes; inicialize com NULL
 * Serve para achar um jogador pelo nome sem percorrer a arvore de pontuacao.
 * O no aponta para o mesmo jogador_t usado na arvore de pontuacao.
 */
typedef struct no_nome {
    jogador_t *jogador;
    void *dados_auxiliares;
    struct no_nome *esquerda;
    struct no_nome *direita;
} no_nome_t;

typedef struct ranking {
    no_pontuacao_t *raiz_pontuacao;
    no_nome_t *raiz_nome;
    int total_jogadores;
} ranking_t;

/* ---------- Funcoes que o ALUNO deve implementar (em aluno.c) ---------- */

/* Cria e retorna um ranking vazio. */
ranking_t *criar_ranking(void);

/*
 * Registra a pontuacao informada para um jogador (pontos > 0).
 *
 *  - Jogador NOVO: cria o jogador e o insere nas duas arvores.
 *  - Jogador JA EXISTENTE (mesmo nome): substitui a pontuacao antiga pelo
 *    valor informado. Como a pontuacao organiza a primeira arvore, o jogador
 *    deve ser removido usando a pontuacao antiga e inserido com a nova. A
 *    arvore de nomes nao muda e o total de jogadores permanece igual.
 *
 * Regra de empate: todo jogador inserido em um grupo passa a ser o primeiro
 * da cadeia "meio", inclusive quando uma atualizacao mantem a mesma pontuacao.
 */
void inserir_pontuacao(ranking_t *ranking, const char *nome, int pontos);

/*
 * Imprime todos os jogadores que ocupam as posicoes de 1 a k, um por linha,
 * no formato:
 *   "<posicao>) <nome> - <pontuacao>"
 * Ordem: da maior para a menor pontuacao; dentro de um grupo de empatados,
 * na ordem da cadeia "meio". Jogadores empatados tem a MESMA posicao. A
 * posicao conta grupos de pontuacoes distintas: o grupo seguinte recebe a
 * posicao seguinte, independentemente de quantos jogadores houve no empate.
 * k indica a ultima posicao a imprimir, nao o numero de jogadores. Imprime
 * todos os jogadores nas posicoes de 1 a k, incluindo todos os empatados em
 * cada posicao. Se k <= 0, nao imprime nada.
 */
void listar_top_k(ranking_t *ranking, int k);

/*
 * Retorna a posicao do jogador no ranking, ou -1 se ele nao existir.
 * posicao = 1 + (numero de pontuacoes distintas ESTRITAMENTE maiores).
 * Exemplo: cinco jogadores empatados em primeiro ocupam a posicao 1, e o
 * proximo grupo de pontuacao ocupa a posicao 2.
 */
int consultar_posicao_jogador(ranking_t *ranking, const char *nome);

#endif
