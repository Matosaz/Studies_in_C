#include <stdio.h>
#include <string.h>
#include "estrutura.h"

#ifdef DEBUG
#include "debug.h"
#endif

/*
 * ============================================================
 *  NAO ALTERE ESTE ARQUIVO.
 *
 *  Esta e a main fixa do EP: ela le comandos da entrada padrao e chama
 *  as suas funcoes (implementadas em aluno.c) na ordem em que os
 *  comandos aparecem. E este arquivo que sera usado na correcao.
 *
 *  Formato dos comandos (um por linha, tokens separados por espaco;
 *  o nome do jogador tem ate 49 caracteres e nao tem espacos):
 *
 *    I <nome> <pontos>   -> cadastra ou substitui a pontuacao do jogador
 *    T <k>               -> lista as posicoes de 1 a k, incluindo empates
 *    P <nome>            -> consulta a posicao de um jogador
 *    D                   -> grava as duas arvores em ranking_debug.txt (-DDEBUG)
 *
 *  A entrada termina no EOF (fim de arquivo / Ctrl+D).
 * ============================================================
 */

int main(void) {
    ranking_t *ranking = criar_ranking();
    if (ranking == NULL) {
        fprintf(stderr, "Erro: criar_ranking() retornou NULL\n");
        return 1;
    }

    char comando[8];
    char nome[TAM_NOME];
    int pontos, k, posicao;

    while (scanf("%7s", comando) == 1) {
        if (strcmp(comando, "I") == 0) {
            if (scanf("%49s %d", nome, &pontos) != 2) break;
            inserir_pontuacao(ranking, nome, pontos);

        } else if (strcmp(comando, "T") == 0) {
            if (scanf("%d", &k) != 1) break;
            listar_top_k(ranking, k);

        } else if (strcmp(comando, "P") == 0) {
            if (scanf("%49s", nome) != 1) break;
            posicao = consultar_posicao_jogador(ranking, nome);
            if (posicao == -1) {
                printf("Jogador nao encontrado\n");
            } else {
                printf("%s esta na posicao %d\n", nome, posicao);
            }

#ifdef DEBUG
        } else if (strcmp(comando, "D") == 0) {
            FILE *saida = fopen("ranking_debug.txt", "w");
            if (saida == NULL) {
                fprintf(stderr, "Erro: nao foi possivel criar ranking_debug.txt\n");
            } else {
                depurar_ranking(ranking, saida);
                if (fclose(saida) == 0)
                    fprintf(stderr, "Debug salvo em ranking_debug.txt\n");
                else
                    fprintf(stderr, "Erro ao gravar ranking_debug.txt\n");
            }
#endif

        } else {
            fprintf(stderr, "Comando desconhecido: %s\n", comando);
        }
    }

    return 0;
}
