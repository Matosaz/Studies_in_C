#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 10
#define INV NULL

typedef struct{
    int chave;
    // Nome, senha, idade...
    // Outros campos...
} reg_t;



typedef struct elo_aux{
    reg_t reg;
   struct elo_aux *prox;
} elo_t;

typedef struct {
    elo_t *inicio;
} lista_t;




// Gerenciamento da estrutura:

bool inicializar(lista_t *l){
  l->inicio = INV;
  return true;
}


void exibir(lista_t *l){
    for(elo_t *i = l->inicio; i != INV; i = i->prox){
        printf("%d ", i->reg.chave);
    }
    printf("\n");
}

//CH representa o elemento desejado: 10, 30, ...
elo_t *busca_maior_ou_eq(lista_t *l, int ch, elo_t **ant){
    elo_t *e = l->inicio;
    *ant = INV;
    
    while(e != INV && e->reg.chave < ch){
        *ant = e;// O elemento atual se torna anterior e avança para o próximo;
        e = e->prox; //Avança para o próximo elemento
    }
    return e;
}

int count(lista_t *l){
    int count = 0;
    for(elo_t *i = l->inicio; i != INV; i = i->prox){
        count++;
    }
    return count;
}

bool devolverElo(lista_t *l, elo_t *e){
    free(e);
    return true;
}

elo_t *obterElo(lista_t *l){
    return malloc(sizeof(elo_t)); //Aloca o tamanho, em bytes, de uma struct caso necessite de espaço livre;
}

bool excluir(lista_t *l, int ch){
    elo_t *ant;
    elo_t *e = busca_maior_ou_eq(l, ch, &ant);
    if(e == INV || e->reg.chave != ch){
        return false;
    } 

    if(ant == INV){
        l->inicio = e->prox;// Caso o valor a ser excluído seja o inicial, elo[0],
                                   // o novo valor de inicial passa para o prox apontado por elo[0], isto é, i[1], pois l->elo[i].prox = i +1
    }
    else{
    ant->prox = e->prox;
    // O valor apontado pelo anterior, outrora apontado para o elemento e(atual), passa a apontar para o prox de e (e->prox), ou seja,
    // ant->prox passa a apontar para o prox de e, saltando por e.
    }
    devolverElo(l,e);
    return true;
}


bool inserir(lista_t *l, int ch){
    elo_t *ant;
    elo_t *e = busca_maior_ou_eq(l, ch, &ant);
    
    
    if(e != INV && e->reg.chave == ch){ //Proíbe que hajam elementos repetidos
        return false;
    }
    elo_t *novo = obterElo(l);
    if(novo == NULL){
        return false;
    }
    if(ant != INV){
        novo->prox = ant->prox; // O próximo do novo é próximo do anterior dele
        ant->prox = novo; // O proximo do anterior agora é o novo.
    }
    
    else{
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    novo->reg.chave = ch;
    
    return true;

}

void reinicializar(lista_t *l){
    elo_t *e = l->inicio;
    while(e != INV){
        elo_t *ptr_to_free = e; //Fornece free na primeira struct (e = l->inicio)
        e = e->prox; // Avança para a pŕoxima struct elo_t e E fornece o free;
        devolverElo(l, ptr_to_free);
    }
    l->inicio = INV; // Limpa a lista fornecendo free para cada struct utilizada;
}

// void ordenacao(lista_t *l){

//     for(elo_t *i = l->inicio; i != INV; i = e->prox){
//         for(elo_t j* = e->prox; j != INV; j = j->prox){
//             if(j->reg.chave <  i->reg.chave){
//                 elo_t *temp = i->reg.chave;
//                 i->reg.chave; = j->reg.chave;
//                 j->reg.chave;= temp;
//             }
//         }
//     }
// }


int main(){
    lista_t l;

    inicializar(&l);
    exibir(&l);

    printf("==================TESTE 1=====================\n");
    for(int i = 0; i < MAX + 1; i++){
        reg_t reg;
        bool retur;
        int chave = rand() % 1000;
        reg.chave = chave;

        printf("Inserindo chave: %d\n", chave);
        retur = inserir(&l, chave);
        if(retur) printf("Foi possível inserir: %d\n", chave);
        else printf("Não foi possível inserir %d\n", chave);


        retur = inserir(&l, chave);
        if(retur) printf("Elemento repetido inserido, inesperado");
        exibir(&l);
        printf("\n");
    }


    printf("==================== TESTE 2 =======================\n");
    int chave_to_del = 335;
    if(excluir(&l, chave_to_del)) printf("Removeu %d\n", chave_to_del);
    else printf("Não foi possível remover: %d\n", chave_to_del);
    exibir(&l);

    chave_to_del = 492;
    if(excluir(&l, chave_to_del)) printf("Removeu %d\n", chave_to_del);
    else printf("Não foi possível remover: %d\n", chave_to_del);
    exibir(&l);

    inserir(&l, 382);

    chave_to_del = 500;
    if(excluir(&l, chave_to_del)) printf("Removeu %d\n", chave_to_del);
    else printf("Não foi possível remover: %d\n", chave_to_del);
    exibir(&l);

    // ordenacao(&l);
    exibir(&l);


    printf("==================== TESTE 3 =======================\n");
    elo_t *ant;
    elo_t *pos = busca_maior_ou_eq(&l, 777, &ant);
    printf("Registro maior ou igual a 777 na pos: %d", pos);
    if(pos != INV) printf("\t Valor: %d\n", pos->reg.chave);

    pos = busca_maior_ou_eq(&l, 383, &ant);
    printf("Registro maior ou igual a 777 na pos: %d", pos);
    if(pos != INV) printf("\t Valor: %d\n",  pos->reg.chave);

    pos = busca_maior_ou_eq(&l, 382, &ant);
    printf("Registro maior ou igual a 777 na pos: %d", pos);
    if(pos != INV) printf("\t Valor: %d\n",  pos->reg.chave);

    pos = busca_maior_ou_eq(&l, 999, &ant);
    printf("Registro maior ou igual a 777 na pos: %d", pos);
    if(pos != INV) printf("\t Valor: %d\n",  pos->reg.chave );


    srand(time(NULL));

  printf("\n=============== TESTE 4 ==================\n");
  printf("\tFazendo varias insercoes aleatorias...\n");
  bool fail = false;
  reinicializar(&l);
  inicializar(&l);
  for (int n_tests = 0; n_tests < 10000; n_tests++) {
    //printf("%d\n", n_tests);
    int chaves[MAX];
    for (int i = 0; i < MAX; i++) {
      int ch = rand()%10000;
      chaves[i] = ch;
      elo_t *e = busca_maior_ou_eq(&l, ch, &ant);

      bool existe = (e != INV && e->reg.chave == ch);

      bool inseriu = inserir(&l, ch);

      if (existe && inseriu) {
        fail = true;
        printf("erro: chave %d repetida foi inserida!\n", ch);
      }
      else if (!existe && !inseriu){
        fail = true;
        printf("erro: não foi possível inserir %d\n", ch);
      }
    }
    
    // verificando se todos os registros estao presentes
    // e excluindo
    for (int i = 0; i < MAX; i++) {
      elo_t *e = busca_maior_ou_eq(&l, chaves[i], &ant);
      if (e == INV || e->reg.chave != chaves[i]) {
        fail = true;
        printf("registro com chave %d inserido mas nao encontrado!\n", chaves[i]);
        exibir(&l);      
      }
    }
    
    for (int i = 0; i < MAX; i++) {
      excluir(&l, chaves[i]);
    }
    if (count(&l)) {
      fail = true;
      printf("Lista nao vazia apos excluir tudo!\n");
      exibir(&l);
    }
    
  }
  if (fail)
    printf("\tTeste falhou :(\n");
  else 
    printf("\tTeste bem sucedido!!\n");


}