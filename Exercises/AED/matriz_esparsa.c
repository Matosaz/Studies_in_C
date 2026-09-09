#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct celula {
  int coluna;
  int valor;
  struct celula* prox;
} celula_t;

typedef struct {
  int lin, col;
  celula_t **linhas;
} matriz_t;

void inicializar (matriz_t *m, int lin, int col) {
  m->lin = lin;
  m->col = col;
  m->linhas = malloc(lin*sizeof(celula_t*));
  for (int i = 0; i < lin; i++) {
    m->linhas[i] = NULL;
  }
}

int get(matriz_t *m, int i, int j) {
  if (i < 0 || i >= m->lin || j < 0 || j >= m->col) {
    return 0; // valor padrao
  }
  
  celula_t *atual = m->linhas[i];
  while (atual != NULL && atual->coluna < j) {
    atual = atual->prox;
  }
  if (atual != NULL && atual->coluna == j) {
    return atual->valor;
  }
  return 0;
}

bool set(matriz_t *m, int i, int j, int v) {
  if (i < 0 || i >= m->lin || j < 0 || j >= m->col) {
    return false;
  }
  
  celula_t *atual = m->linhas[i];
  celula_t *anterior = NULL;
  while (atual != NULL && atual->coluna < j) {
    anterior = atual;
    atual = atual->prox;
  }
  
  if (atual != NULL && atual->coluna == j) {
    // celula existe
    if (v != 0) {
      atual->valor = v;
    } else { // v == 0
      // apagar a celula
      if (anterior != NULL) {
        anterior->prox = atual->prox;
      } else {
        m->linhas[i] = atual->prox;
      }
      free(atual);
    }
  } else {
    // celula nao existe
    if (v != 0) {
      celula_t *nova = malloc(sizeof(celula_t));
      if (nova == NULL) return false;
      nova->valor = v;
      nova->coluna = j;
      if (anterior != NULL) {
        nova->prox = anterior->prox; 
        anterior->prox = nova;
      } else {
        nova->prox = m->linhas[i];
        m->linhas[i] = nova;
      }
    } else { // v== 0
      // faz nada
    }
  }

  return true;
}

void exibir(matriz_t *m) {
  for (int i = 0; i < m->lin; i++) {
    printf("[%d] ", i);
    for (int j = 0; j < m->col; j++) {
      printf ("%4d", get(m, i, j));
    }
    printf("\n");
  }
  printf("\n");
}

int main( ) {
  matriz_t m;
  inicializar(&m, 4, 3);
  exibir(&m);
  
  if (!set(&m, 1, 1, 50)) printf("erro no set\n");
  exibir(&m);
  
  if (!set(&m, 3, 2, 60)) printf("erro no set\n");
  
  if (!set(&m, -1, 1, -1)) printf("erro no set (esperado)\n");
  if (!set(&m, 100, 1, -1)) printf("erro no set (esperado)\n");
  exibir(&m);
  
  
  if (!set(&m, 3, 1, 99)) printf("erro no set\n");
  exibir(&m);
  
  if (!set(&m, 3, 2, 0)) printf("erro no set\n");
  exibir(&m);
  
  if (!set(&m, 3, 1, 0)) printf("erro no set\n");
  exibir(&m);

  return 0;
}