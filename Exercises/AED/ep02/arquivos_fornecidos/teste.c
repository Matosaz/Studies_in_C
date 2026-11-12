// teste.c
#include "aluno.c"

#define INS(r, nome, pts) do {                          \
    printf(">> inserir_pontuacao(%s, %d)\n", nome, pts); \
    inserir_pontuacao(r, nome, pts);                    \
    imprimir_pont(r->raiz_pontuacao, 0);                \
    printf("total = %d\n\n", r->total_jogadores);       \
} while (0)

int main(void) {
    ranking_t *r = criar_ranking();

    puts("=== dois filhos, sucessor fundo ===");
    INS(r, "A", 50); INS(r, "B", 30); INS(r, "C", 70);
    INS(r, "D", 60); INS(r, "E", 80);
    INS(r, "A", 1);          // remove a raiz: o 60 deve assumir

    puts("=== cabeça com meio ===");
    r = criar_ranking();
    INS(r, "N30", 30); INS(r, "N70", 70);
    INS(r, "Ana", 50); INS(r, "Bia", 50); INS(r, "Caio", 50);
    INS(r, "Caio", 5);       // Bia deve herdar os filhos
    return 0;
}