/* ============================================================================
    EP1 - Planilha Esparsa com Histórico de Alterações
    TEMPLATE - preencha os TODOs abaixo. Não altere assinaturas de função,
    nomes ou ordem de campos de struct.
 
    Uso: ./ep_XXXX arquivo_entrada.txt arquivo_saida.txt
 ============================================================================ */

#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>

#define INV -1
/* ----------------------------------------------------------------------
  Estruturas de dados (não altere nomes e ordem de campos)
 ---------------------------------------------------------------------- */

typedef struct celula {
    int linha;
    int coluna;
    int valor;
    struct celula *proxima_linha;
    struct celula *proxima_coluna;
} celula_t;

typedef struct fileira {
    int indice;
    celula_t* primeiro;
    struct fileira *proximo;
} fileira_t;

typedef struct {
    bool transposicao;
    int linha;
    int coluna;
    union {
        int valor_anterior;
        int tamanho;
    };
} operacao_t;

typedef struct elo_pilha {
    operacao_t op;
    struct elo_pilha *proximo;
} elo_pilha_t;

typedef struct {
    elo_pilha_t* topo;
} pilha_t;

typedef struct {
    fileira_t* primeira_linha;
    fileira_t* primeira_coluna;
    int total_celulas;
    pilha_t historico;
} planilha_t;

/* ---------------------------------------------------------------------- *
    Funções auxiliar para leitura das strings dos comandos
 ---------------------------------------------------------------------- */

int igual(char* a, char* b) {
    int i = 0;
    while (a[i] == b[i] && a[i] != '\0') i++;

    return (a[i] == b[i]);
}

/* ---------------------------------------------------------------------- *
    Funções obrigatórias (não altere as assinaturas)
 ---------------------------------------------------------------------- */

void inicializar_planilha(planilha_t *p) {
    // TODO: inicialize primeiraLinha, primeiraColuna, total_celulas e historico.topo
    
    p->primeira_coluna = NULL; //Quando está vazia aponta para NULL;
    p->primeira_linha =  NULL; //Quando está vazia aponta para NULL;
    p->total_celulas = 0; //Total de células não-nulas é inicialmente zero;
    p->historico.topo = NULL;

    fprintf(stderr, "Planilha inicializada. Total de células: %d\n", p->total_celulas);
}

celula_t* buscar_celula(planilha_t *p, int lin, int col,
                      celula_t** cel_ant_linha, celula_t** cel_ant_coluna,
                      fileira_t** fil_ant_linha, fileira_t** fil_ant_coluna) {
    /* TODO: localize a celula (lin,col), preencha os quatro antecessores 
        por referencia, retorne NULL se a celula nao existir */

    fprintf(stderr,"Buscnado célula\n");;
    fprintf(stderr,"Chergou aqui\n");

    *cel_ant_coluna = NULL;
    *cel_ant_linha = NULL;
    *fil_ant_coluna = NULL;
    *fil_ant_linha = NULL;

    bool fil_lin_encontrada = false;
    bool fil_col_encontrada = false;
    bool cel_lin_encontrada = false;
    bool cel_col_encontrada = false;

    
    fileira_t *fil_lin = p->primeira_linha;
    fileira_t *fil_col = p->primeira_coluna;
    celula_t *cel_atual_lin = NULL; //Elemento Aij qualquer na linha i
    celula_t *cel_atual_col = NULL; //Elemento Aij qualquer na coluna j

    if(lin < 0 || col < 0){
        return NULL;
    }

    //Linhas:
        while(fil_lin != NULL && fil_lin->indice < lin){ //Percorremos as fileiras de linhas até que o índice dela seja igual ao solicitado ou não seja encontrado
            *fil_ant_linha = fil_lin;
            fil_lin = fil_lin->proximo;
        }
        fil_lin_encontrada = (fil_lin != NULL && fil_lin->indice == lin); //Se encontrar a linha retorna true, senão false;
            fprintf(stderr, "TEste\n"); // Added \n for clean output


    if(fil_lin_encontrada){
        celula_t *atual= fil_lin->primeiro; //Elemento Aij qualquer atual na linha i
        while(atual != NULL && atual->coluna < col){
            *cel_ant_linha = atual;//Avançamos linhas, mantendo na mesma mesma coluna
            atual = atual->proxima_linha;
        }
            cel_lin_encontrada = (atual != NULL && atual->coluna == col);
            if(cel_lin_encontrada){
                cel_atual_lin = atual ; //linha da celula do atual = atual;
            }
            //Encontramos a cel_atual_lin, a linha do elemento que buscamos 
    }

    //Colunas:
        while(fil_col != NULL && fil_col->indice < col){//Percorremos as fileiras de colunas até que o índice dela seja igual ao solicitado ou não seja encontrado
            *fil_ant_coluna = fil_col;
            fil_col = fil_col->proximo;
        }    
            fil_col_encontrada = (fil_col != NULL && fil_col->indice == col);

        //Encontramos a cel_atual_col, a coluna do elemento que buscamos

    if(fil_col_encontrada){    
        celula_t *atual= fil_col->primeiro; //Elemento Aij qualquer na coluna j

        while(atual != NULL && atual->linha < lin){
            *cel_ant_coluna = atual;
            atual = atual->proxima_coluna; //Avançamos colunas, mantendo na mesma linha
        }    
            cel_col_encontrada = (atual != NULL && atual->linha == lin);
            if(cel_col_encontrada){
                cel_atual_col = atual ; //Coluna da celula do atual = atual;
            }
       }
    
        if(cel_col_encontrada && cel_lin_encontrada && fil_col_encontrada && fil_lin_encontrada){
            return cel_atual_col; // Retorna uma célula, e como está dentro do IF e_linha = lin; a linha buscada também é retornada
        }
    return NULL;
}

int obter_valor(planilha_t *p, int linha, int coluna) {
    // TODO: use buscarCelula; retorne 0 se a celula nao existir
    celula_t *cel_ant_coluna = NULL;
    celula_t *cel_ant_linha = NULL;
    fileira_t *fil_ant_coluna = NULL; 
    fileira_t *fil_ant_linha = NULL;
    celula_t *atual = buscar_celula(p, linha, coluna, &cel_ant_linha, &cel_ant_coluna, &fil_ant_linha, &fil_ant_coluna);

    if(atual == NULL) return 0;

    return atual->valor;    

    return 0;
}

int somar_intervalo(planilha_t* p, int linha_ini, int linha_fim, int coluna_ini, int coluna_fim) {
    // TODO: some os valores das celulas nao nulas no intervalo dado
    
    int soma = 0;
    fileira_t *fileira = p->primeira_linha; 

    while((fileira != NULL && fileira->primeiro != NULL) && linha_ini <= linha_fim){
        celula_t *atual = fileira->primeiro;

            while(atual != NULL){
                if(atual->coluna >= coluna_ini && atual->coluna <= coluna_fim){
                    soma += atual->valor;
                }
                atual = atual->proxima_linha; //Necessitar ser fora do if, caso contrário não avançaria
            }
        linha_ini++; 
        fileira = fileira->proximo; //Avança para a próxima fileira
    }
    return soma;
}

int contar_nao_nulas(planilha_t* p) {
    // TODO: retorne a quantidade de celulas nao nulas
    int num_celulas = 0;
    fileira_t *fileira = p->primeira_linha;

    while(fileira != NULL){
        celula_t *atual = fileira->primeiro;
        while(atual != NULL){
            num_celulas++;
            atual = atual->proxima_linha;
        }
        fileira = fileira->proximo;
    }
    return num_celulas;
}

//Função para criar novas fileiras e verificar se necessita caso já exista
fileira_t *criar_fileiras(fileira_t **fil_primeiro, fileira_t *fil_ant, int i){
    fileira_t *fileira_atual;

    if(fil_ant == NULL){
        fileira_atual = *fil_primeiro;
    }else{
        fileira_atual = fil_ant->proximo;  
    }   
    if(fileira_atual != NULL && fileira_atual->indice == i){ //Se a fileira já existe
        return fileira_atual;
    }
    fileira_t *nova_fileira = (fileira_t *)malloc(sizeof(fileira_t));

    if(nova_fileira == NULL) return NULL;

    nova_fileira->indice = i;
    nova_fileira->primeiro = NULL;
    nova_fileira->proximo = fileira_atual;

    if(fil_ant == NULL){
        *fil_primeiro = nova_fileira;
    }else{
        fil_ant->proximo = nova_fileira;
    }

    return nova_fileira;
}



        //TODO PESSOAL: Implementar o sistema de salvar no histórico
bool definir_celula(planilha_t* p, int lin, int col, int valor) {
    /* TODO: implemente os 4 casos (atualizar/criar/remover/nulo),
       empilhando em p->historico quando houver alteracao efetiva.
       Retorna true se houve alteracao, false se foi operacao nula. */

    fprintf(stderr, "DEfinir: (%d,%d) = %d\n", lin, col, valor);
    celula_t *cel_ant_coluna = NULL;
    celula_t *cel_ant_linha = NULL;
    fileira_t *fil_ant_coluna = NULL; 
    fileira_t *fil_ant_linha = NULL;

    celula_t* atual = buscar_celula(p, lin, col, &cel_ant_linha, &cel_ant_coluna, &fil_ant_linha, &fil_ant_coluna); 


  if(atual != NULL) {
    fprintf(stderr, "Celula existe. Valor: %d", atual->valor);

    // celula existe e valor != 0 (ATUALIZAR);
    if(valor != 0) {
        atual->valor = valor;
        fprintf(stderr, "Valor atualizado para: %d", valor);
        p->total_celulas++;
    } 
    else { //Célula existe e valor = 0: (REMOVER)
        if (cel_ant_linha != NULL && cel_ant_coluna != NULL) {
            cel_ant_linha->proxima_linha = atual->proxima_linha;
            cel_ant_coluna->proxima_coluna = atual->proxima_coluna;
            p->total_celulas--;
        } 
        else if(p->primeira_linha == NULL && p->primeira_coluna == NULL){ //Exclui fileiras que não possuem elementos
                fil_ant_linha->proximo = p->primeira_linha->proximo;//Fileira atual nula é pulada (bypass)
                fil_ant_coluna->proximo = p->primeira_coluna->proximo;//Fileira atual nula é pulada (bypass)
            }
        else {
            free(atual);
            atual = atual->proxima_linha;
            p->total_celulas--;
        }
    }
    return true;
  } 
  else {
    // celula nao existe e valor != 0 (CRIAR)
    if (valor != 0) { //CRIAR uma nova célula
      
        celula_t *nova = (celula_t *)malloc(sizeof(celula_t));
        if (nova == NULL) return false;
            fprintf(stderr, "Chegou aqui e é nulo\n");

        nova->valor = valor;
        fprintf(stderr, "Nova valor: %d\n\n", nova->valor);
        nova->coluna = col;
        nova->linha = lin;

        fileira_t *fil_linha = criar_fileiras(&p->primeira_linha, fil_ant_linha, lin);
        fileira_t *fil_coluna = criar_fileiras(&p->primeira_coluna, fil_ant_coluna, col);;

        if(fil_linha == NULL || fil_coluna == NULL){
            free(nova);
            return false;
        }
        if(cel_ant_linha != NULL){
            nova->proxima_linha = cel_ant_linha->proxima_linha;
            cel_ant_linha->proxima_linha = nova;
        }else{
            nova->proxima_linha = fil_linha->primeiro;
            fil_linha->primeiro = nova;
        }

        if(cel_ant_coluna != NULL){
            nova->proxima_coluna = cel_ant_coluna->proxima_coluna;
            cel_ant_coluna->proxima_coluna = nova;
        }else{
            nova->proxima_coluna = fil_coluna->primeiro;
            fil_coluna->primeiro = nova;
        }
           p->total_celulas++;

    } else { // v== 0 // Operação NULA
      // faz nada
    }
    return true;
  }
    return false;
}

bool remover_celula(planilha_t* p, int lin, int col) {
    // TODO: remova a celula (lin,col)
    celula_t *cel_ant_coluna = NULL;
    celula_t *cel_ant_linha = NULL;
    fileira_t *fil_ant_coluna = NULL; 
    fileira_t *fil_ant_linha = NULL;

    celula_t* atual = buscar_celula(p, lin, col, &cel_ant_linha, &cel_ant_coluna, &fil_ant_linha, &fil_ant_coluna); 

    if(cel_ant_linha != NULL && cel_ant_coluna != NULL) {
            cel_ant_linha->proxima_linha = atual->proxima_linha;
            cel_ant_coluna->proxima_coluna = atual->proxima_coluna;
            p->total_celulas--;
        } else {
            free(atual);
            atual = atual->proxima_linha;
            p->total_celulas--;
        }    
        //TODO PESSOAL: Implementar o sistema de salvar no histórico
    return false;
}

bool transpor(planilha_t* p, int lin, int col, int tamanho) {
    /* TODO: transpoe uma matriz quadrada que está localizada entre
       as linhas [lin, lin + tamanho) e colunas [col, col + tamanho). */
    return false;
}

bool desfazer(planilha_t* p) {
    /* TODO: desempilhe de p->historico e restaure o valor anterior.
       Retorna false se o historico estiver vazio, true caso contrario. */
    return false;
}

void exibir_planilha(planilha_t *p) {
    /* TODO: imprima "linha coluna valor" por linha, em ordem crescente
       de linha e, dentro de cada linha, de coluna. Se vazia, imprima
       "PLANILHA VAZIA" */
       fileira_t *i = p->primeira_linha;

       for(i = p->primeira_linha; i != NULL; i = i->proximo){
        for(celula_t *j = i->primeiro; j != NULL; j = j->proxima_linha){
        printf("%d %d %d\n", j->linha, j->coluna, j->valor);
        }
       }
}

void exibir_historico(planilha_t* p) {
    /* TODO: imprima "linha coluna valor_anterior" por linha, do topo
       para a base. Se vazio, imprima "HISTORICO VAZIO" */
}

void liberar_tudo(planilha_t* p) {
    // TODO: libere toda a memória alocada por fileira, celula, e pilha.
    

}

/* ---------------------------------------------------------------------- *
    Main para leitura de arquivos (já pronta no caso, pode ser que na versão final deixemos sem)
 ---------------------------------------------------------------------- */

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso do comando eh: %s arquivo_entrada.txt arquivo_saida.txt\n", argv[0]);
        return 1;
    }
    
    FILE* entrada = fopen(argv[1], "r");
    FILE* saida = freopen(argv[2], "w", stdout);

    if (!entrada || !saida) {
        fprintf(stderr, "Erro ao tentar abrir os arquivos.\n");
        return 1;
    }

    planilha_t p;
    inicializar_planilha(&p);
    
    // int n;
    // fscanf(entrada, "%d", &n);
    // fprintf(stderr, "[debug] n lido: %d\n", n);
    char cmd[20];

    while (fscanf(entrada, "%s", cmd) != EOF) {
 
        if (igual(cmd, "DEF")) {
            int lin, col, valor;
            fscanf(entrada, "%d %d %d", &lin, &col, &valor);
            definir_celula(&p, lin, col, valor);
        } else if (igual(cmd, "REM")) {
            int lin, col;
            fscanf(entrada, "%d %d", &lin, &col);
            remover_celula(&p, lin, col);
        } else if (igual(cmd, "GET")) {
            int lin, col;
            fscanf(entrada, "%d %d", &lin, &col);
            fprintf(saida, "GET %d %d %d\n", lin, col, obter_valor(&p, lin, col));
                fprintf(stderr, "[debug] GET %d %d %d\n", lin, col, obter_valor(&p, lin, col));

        } else if (igual(cmd, "SOMA")) {
            int li, lf, ci, cf;
            fscanf(entrada, "%d %d %d %d", &li, &lf, &ci, &cf);
            fprintf(saida, "SOMA %d %d %d %d %d\n", li, lf, ci, cf, somar_intervalo(&p, li, lf, ci, cf));
        } else if (igual(cmd, "CONT")) {
            fprintf(saida, "CONT %d\n", contar_nao_nulas(&p));
        } else if (igual(cmd, "DESFAZER")) {
            if (!desfazer(&p)) {
                fprintf(saida, "HISTORICO VAZIO\n");
            }
        } else if (igual(cmd, "EXIBIR")) {
            if (contar_nao_nulas(&p)) {
                printf("PLANILHA\n");
                exibir_planilha(&p);
            } else {
                printf("PLANILHA VAZIA\n");
            }
        } else if (igual(cmd, "HIST")) {
            if (p.historico.topo) {
                printf("HISTORICO\n");
                exibir_historico(&p);
            }
            else {
                printf("HISTORICO VAZIO\n");
            }
        } else if (igual(cmd, "TRANS")) {
            int lin, col, tam;
            fscanf(entrada, "%d %d %d", &lin, &col, &tam);
            transpor(&p, lin, col, tam);
        }
    }

    fclose(entrada);
    fclose(saida);

    liberar_tudo(&p);
    return 0;
}
