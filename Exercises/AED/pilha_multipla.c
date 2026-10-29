#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// tamanho do vetor de registros
#define MAX 17

// numero de pilhas
// (poderia ser um campo da struct pilha_multipla_t, passado no momento da inicializacao)
#define NP 4 

typedef struct {
  int chave;
  // outros campos
} registro_t;

typedef struct {
  registro_t regs[MAX];
  int bases[NP+1];
  int topos[NP];
} pilha_multipla_t;

void inicializar(pilha_multipla_t *p){
  for (int i = 0; i < NP ; i++){
    p->bases[i] = (i * (MAX / NP));
    p->topos[i] = p->bases[i] - 1;
  }
  p->bases[NP] = MAX;
}

void reinicializar(pilha_multipla_t *p){
  inicializar(p);
}

int tamanho_k(pilha_multipla_t *p, int k) {
  if (k < 0 || k >= NP) return -1;
  return p->topos[k] - p->bases[k] + 1;
}

int tamanho_total(pilha_multipla_t *p) {
  int tamanho = 0;
  for (int i=0; i<NP; i++)
    tamanho += tamanho_k(p, i);
  return tamanho;
}

bool pilha_cheia(pilha_multipla_t *p, int k) {
  if (k < 0 || k >= NP) return true;
  return (p->topos[k] == p->bases[k + 1] - 1);
}

bool deslocar_dir(pilha_multipla_t *p, int k) {
  if (k < 1 || k >= NP)  return false;
  if (pilha_cheia(p, k)) return false;
  printf("%s (%d)\n", __func__, k);
  
  for (int i = p->topos[k]; i >= p->bases[k]; i--) {
    p->regs[i+1] = p->regs[i];
  }
  p->topos[k]++;
  p->bases[k]++;
  return true;
}


bool deslocar_esq(pilha_multipla_t *p, int k) {
  if (k < 1 || k >= NP)    return false;
  if (pilha_cheia(p, k-1)) return false;
  printf("%s (%d)\n", __func__, k);
  
  for (int i = p->bases[k]; i <= p->topos[k]; i++) {
    p->regs[i-1] = p->regs[i];
  }
  p->topos[k]--;
  p->bases[k]--;
  return true;
}

bool push(pilha_multipla_t *p, int k, registro_t r) {
  if (k < 0 || k >= NP) return false;
  if (pilha_cheia(p,k)){
    // desloca p/ direita todas as pilhas de [k+1..NP-1] em ordem reversa
    for(int j = NP-1; j > k; j--) { deslocar_dir(p, j); }
    if(pilha_cheia(p, k)){ // se a pilha continua cheia
      // desloca p/ esquerda todas as pilhas de [1..k] (pilha 0 nunca desloca)
      for(int j = 1; j <= k; j++) { deslocar_esq(p, j); }
      // se pilha continuar cheia, acabou espaco no vetor
      if(pilha_cheia(p, k)) return false;
    }
  }
  p->topos[k]++;
  p->regs[p->topos[k]] = r;
  return true;
}


bool deslocar_dir_rec(pilha_multipla_t *p, int k) {
  if (k < 1 || k >= NP)  return false;
  if(!pilha_cheia(p, k) || deslocar_dir_rec(p, k+1)){
    printf("%s (%d)\n", __func__, k);
    for(int i = p->topos[k]; i >= p->bases[k]; i--) p->regs[i+1] = p->regs[i];
    p->topos[k]++;
    p->bases[k]++;
    return true;
  }
  return false;
}

bool deslocar_esq_rec(pilha_multipla_t *p, int k) {
  if (k < 1 || k >= NP)  return false;
  if(!pilha_cheia(p, k-1) || deslocar_esq_rec(p, k-1)) {
    printf("%s (%d)\n", __func__, k);
    for(int i = p->bases[k]; i <= p->topos[k]; i++) p->regs[i-1] = p->regs[i];
    p->topos[k]--;
    p->bases[k]--;
    return true;
  }
  return false;
}

bool push_rec(pilha_multipla_t *p, int k, registro_t r) {
  if (k < 0 || k >= NP) return false;
  if (pilha_cheia(p,k) && !deslocar_dir_rec(p, k+1) && !deslocar_esq_rec(p, k)) return false;
  
  p->topos[k]++;
  p->regs[p->topos[k]] = r;
  return true;
}

bool pop(pilha_multipla_t *p, int k, registro_t *r) {
  if (k < 0 || k >= NP) return false;
  if (p->topos[k] < p->bases[k]) return false;

  *r = p->regs[p->topos[k]];
  p->topos[k]--;
  return true;
}

bool peek(pilha_multipla_t *p, int k, registro_t *r) {
  if (k < 0 || k >= NP) return false;
  if (p->topos[k] < p->bases[k]) return false;
  
  *r = p->regs[p->topos[k]];
  return true;
}

void exibir(pilha_multipla_t *p) {
  for (int i = 0; i < NP; i++) {
    printf("Pilha %d:", i);
    for (int j = p->bases[i]; j <= p->topos[i]; j++) {
      printf(" %d", p->regs[j].chave);
    }
    printf(" [topo]\n");
  }
}

int main (int argc, char *argv[]) {
  pilha_multipla_t p1, p2;
  registro_t r1, r2;
  int k;
  bool ret;
  srand(1989);
  
  inicializar(&p1);
  inicializar(&p2);
  
  do {
    r1.chave = rand() % 1000;
    k = rand() % NP;
    printf("Inserindo valor %d na pilha %d\n", r1.chave, k);
    ret = push(&p1, k, r1);
    push_rec(&p2, k, r1);
  } while(ret);
 
  printf("\n");
  printf("Tamanhos totais: %d %d\n\n", tamanho_total(&p1), tamanho_total(&p2));
  exibir(&p1);
  printf("\n");
  exibir(&p2);
  
  return 0;
}