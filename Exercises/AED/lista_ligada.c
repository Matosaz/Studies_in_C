#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX 10
#define INV -1

typedef struct{
    int chave;
    // Nome, senha, idade...
    // Outros campos...
} reg_t;


typedef struct{
    reg_t reg;
    int prox;
} elo_t;

typedef struct {
    elo_t elo[MAX];
    int inicio;
    int livre;

} lista_t;




// Gerenciamento da estrutura:

bool inicializar(lista_t *l){
    l->inicio = INV;
    l->livre = 0;

    for(int i = 0; i < MAX - 1; i++){
        l->elo[i].prox = i + 1; // Cada elo da lista possui como valor de próx o elemento sucessor
        // Supondo que i = 0,   1,   2,   3,   4
  //elo[i].reg.chave =    10,  30,  50,  60,  90
//elo[i].prox = i + 1 =    1,   2,   3,   4,   X                 Armazena o índice da próxima posição do vetor
    }

    l->elo[MAX - 1].prox = INV; //Último elemento aponta para INV (nada)
    return true;
}

void exibir(lista_t *l){
    for(int i = l->inicio; i != INV; i = l->elo[i].prox){ // A iteração ocorre utiilizando aritmética de ponteiros "prox" 
                                                         // que contém os valores dos elementos correspondentes à i + 1 (Excali)
        printf("%d ", l->elo[i].reg.chave);
    }
    printf("\n");
}

//CH representa o elemento desejado: 10, 30, ...
int busca_maior_ou_eq(lista_t *l, int ch, int *ant){
    *ant = INV;
    int i = l->inicio;
    while(i != INV && l->elo[i].reg.chave < ch){

        *ant = i;// O elemento atual se torna anterior e avança para o próximo;
        i = l->elo[i].prox; //Avança para o próximo elemento
    }
    return i;
    // for(int i = l->inicio; i != INV && l->elo[i].reg.chave < ch; i = l->elo[i].prox){
    //     if(l->elo[i].reg.chave >= ch) {
    //         return false;
    //     }
        
    //     *ant = i;
    

    // if((i != INV) && l->elo[i].reg.chave == ch){
    //     return i; // Retorna o antecessor imediato
    //     i = l->elo[i].prox;// Passa o valor que queremos como o prox do ant, que nesse caso é o valor que queremos
    // }
    // else{
    //     return INV;
    // }
    //Outra forma com WHILE:



}

int count(lista_t *l){
    int count = 0;
    for(int i = l->inicio; i != INV; i = l->elo[i].prox){
        count++;
    }
    return count;
}

void devolverElo(lista_t *l, int i){
    l->elo[i].prox = l->livre;
    l->livre = i;
}

bool excluir(lista_t *l, int ch){
    int ant, i;
    i = busca_maior_ou_eq(l, ch, &ant);
    if(i == INV || l->elo[i].reg.chave != ch) return false;

    if(ant == INV){
        l->inicio = l->elo[i].prox;// Caso o valor a ser excluído seja o inicial, elo[0],
                                   // o novo valor de inicial passa para o prox apontado por elo[0], isto é, i[1], pois l->elo[i].prox = i +1
    }
    else{
    l->elo[ant].prox = l->elo[i].prox;
    // O valor apontado pelo anterior, outrora apontado para o elemento i(atual), passa a apontar para o prox de i, ou seja,
    // l->elo[ant].prox passa a apontar para o prox de i, saltando por i.
    }

    devolverElo(l,i);
    return true;
}

int obterElo(lista_t *l){
    int casa_livre = l->livre; // l->livre representa o índice da primeira posição livre do vetor
    if(l->livre != INV){
        l->livre = l->elo[l->livre].prox ;
    }
    return casa_livre;
}

bool inserir(lista_t *l, int ch){
    int ant, i;
    if(l->livre == INV) return false;

    i = busca_maior_ou_eq(l, ch, &ant);
    if(i != INV && l->elo[i].reg.chave == ch){ //Proíbe que hajam elementos repetidos
        return false;
    }
    int novo = obterElo(l);
    if(l->livre == INV){
        printf("Lista cheia fih\n");
        return false;
    }
    if(ant != INV){
        l->elo[novo].prox = l->elo[ant].prox;
        l->elo[ant].prox = novo; //
    }
    
    else{
        l->elo[novo].prox = l->inicio;
        l->inicio = novo;
    }
    l->elo[novo].reg.chave = ch;
    
    return true;

}

void ordenacao(lista_t *l){

    for(int i = l->inicio; i != INV; i = l->elo[i].prox){
        for(int j = l->elo[i].prox; j != INV; j = l->elo[j].prox){
            if(l->elo[j].reg.chave <  l->elo[i].reg.chave){
                int temp = l->elo[i].reg.chave;
                l->elo[i].reg.chave = l->elo[j].reg.chave;
                l->elo[j].reg.chave = temp;
            }
        }
    }
}


int main(){
    lista_t l;

    inicializar(&l);
    exibir(&l);

    printf("==================TESTE 1=====================\n");
    for(int i = 0; i < MAX; i++){
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

    ordenacao(&l);
    exibir(&l);


    printf("==================== TESTE 3 =======================\n");
    int ant;
    int pos = busca_maior_ou_eq(&l, 777, &ant);
    printf("Registro maior ou igual a 777 na pos: %d", pos);
    if(pos != INV) printf("\t Valor: %d\n", l.elo[pos].reg.chave);

    pos = busca_maior_ou_eq(&l, 383, &ant);
    printf("Registro maior ou igual a 777 na pos: %d", pos);
    if(pos != INV) printf("\t Valor: %d\n", l.elo[pos].reg.chave);

    pos = busca_maior_ou_eq(&l, 382, &ant);
    printf("Registro maior ou igual a 777 na pos: %d", pos);
    if(pos != INV) printf("\t Valor: %d\n", l.elo[pos].reg.chave);

    pos = busca_maior_ou_eq(&l, 999, &ant);
    printf("Registro maior ou igual a 777 na pos: %d", pos);
    if(pos != INV) printf("\t Valor: %d\n", l.  elo[pos].reg.chave);


//     srand(time(NULL));

//   printf("\n=============== TESTE 4 ==================\n");
//   printf("\tFazendo varias insercoes aleatorias...\n");
//   bool fail = false;
//   inicializar(&l);
//   for (int n_tests = 0; n_tests < 1; n_tests++) {
//     //printf("%d\n", n_tests);
//     int chaves[MAX];
//     for (int i = 0; i < MAX; i++) {
//       int ch = rand()%10000;
//       chaves[i] = ch;
//       int e = busca_maior_ou_eq(&l, ch, &ant);

//       bool existe = (e != INV && l.elo[e].reg.chave == ch);

//       bool inseriu = inserir(&l, ch);

//       if (existe && inseriu) {
//         fail = true;
//         printf("erro: chave %d repetida foi inserida!\n", ch);
//       }
//       else if (!existe && !inseriu){
//         fail = true;
//         printf("erro: não foi possível inserir %d\n", ch);
//       }
//     }
    
//     // verificando se todos os registros estao presentes
//     // e excluindo
//     for (int i = 0; i < MAX; i++) {
//       int e = busca_maior_ou_eq(&l, chaves[i], &ant);
//       if (e == INV || l.elo[e].reg.chave != chaves[i]) {
//         fail = true;
//         printf("registro com chave %d inserido mas nao encontrado!\n", chaves[i]);
//         exibir(&l);      
//       }
//     }
    
//     for (int i = 0; i < MAX; i++) {
//       excluir(&l, chaves[i]);
//     }
//     if (count(&l)) {
//       fail = true;
//       printf("Lista nao vazia apos excluir tudo!\n");
//     }
    
//   }
//   if (fail)
//     printf("\tTeste falhou :(\n");
//   else 
//     printf("\tTeste bem sucedido!!\n");


}