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


static bool op_desfazer = false;
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
void liberar_tudo(planilha_t *p);
bool remover_celula(planilha_t *p, int lin, int col);
void exibir_planilha(planilha_t *p);
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
}

celula_t* buscar_celula(planilha_t *p, int lin, int col,
                      celula_t** cel_ant_linha, celula_t** cel_ant_coluna,
                      fileira_t** fil_ant_linha, fileira_t** fil_ant_coluna) {
    /* TODO: localize a celula (lin,col), preencha os quatro antecessores 
        por referencia, retorne NULL se a celula nao existir */

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
        while(fil_col != NULL && fil_col->indice < col){//Percorre as fileiras de colunas até que o índice dela seja igual ao solicitado ou não seja encontrado
            *fil_ant_coluna = fil_col;
            fil_col = fil_col->proximo;
        }    
            fil_col_encontrada = (fil_col != NULL && fil_col->indice == col);

        //Encontra a cel_atual_col,coluna do elemento buscado

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

elo_pilha_t *push(planilha_t *p, int lin, int col, int valor){
    elo_pilha_t *novo = malloc(sizeof(elo_pilha_t));
    if(novo == NULL) return false;
    
    novo->op.transposicao = false;
    novo->op.tamanho = 0;
    novo->op.linha = lin;
    novo->op.coluna = col;
    novo->op.valor_anterior = valor;
    
    novo->proximo = p->historico.topo;
    p->historico.topo = novo;
    
    return novo;
}

elo_pilha_t *pop(planilha_t *p){
    if(p->historico.topo == NULL){
        return NULL;
    }
    elo_pilha_t *free_ptr = p->historico.topo;

    p->historico.topo = p->historico.topo->proximo;

    free_ptr->proximo = NULL;
    return free_ptr;
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
    fileira_t *fileira_linha = p->primeira_linha;
  
   if(fileira_linha != NULL){
            for(fileira_linha = fileira_linha; fileira_linha && fileira_linha->indice <= linha_fim; fileira_linha = fileira_linha->proximo){
                if(fileira_linha->indice < linha_ini) continue; // Continua enquanto o índice não for encontrado
                for(celula_t *atual = fileira_linha->primeiro; atual != NULL && atual->coluna <= coluna_fim; atual = atual->proxima_linha){
                    if(atual->coluna >= coluna_ini){                    
                        soma += atual->valor;
                    }
                }
            }
        }

    return soma;
}

int contar_nao_nulas(planilha_t* p) {
    // TODO: retorne a quantidade de celulas nao nulas
    return p->total_celulas;
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
    // free(nova_fileira); Chamar função de free
    return nova_fileira;
}


bool definir_celula(planilha_t* p, int lin, int col, int valor) {
    /* TODO: implemente os 4 casos (atualizar/criar/remover/nulo),
       empilhando em p->historico quando houver alteracao efetiva.
       Retorna true se houve alteracao, false se foi operacao nula. */

    celula_t *cel_ant_coluna = NULL;
    celula_t *cel_ant_linha = NULL;
    fileira_t *fil_ant_coluna = NULL; 
    fileira_t *fil_ant_linha = NULL;

    celula_t* atual = buscar_celula(p, lin, col, &cel_ant_linha, &cel_ant_coluna, &fil_ant_linha, &fil_ant_coluna); 
    
    if((atual == NULL && valor == 0) || (atual != NULL && atual->valor == valor)) {
        return false;
    }//Evita duplicata e inserção em célula inexistente


  if(atual != NULL) {
    // celula existe e valor != 0 (ATUALIZAR);
    if(valor != 0) {
        if(!op_desfazer){
            elo_pilha_t *ultima_celula = push(p, lin, col, atual->valor);   
        }

        atual->valor = valor;
        return true;
    } 
    else { //Célula existe e valor = 0: (REMOVER)
      return remover_celula(p, lin, col);
        }
    return true;
  } 
  else {
    // celula nao existe e valor != 0 (CRIAR)
    if (valor != 0) { //CRIAR uma nova célula
        celula_t *nova = (celula_t *)malloc(sizeof(celula_t));
        if(!op_desfazer){
            elo_pilha_t *ultima_celula = push(p, lin, col, 0);   
        }
        if (nova == NULL) return false;

        nova->valor = valor;
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
        return true;

    } else { // v== 0 // Operação NULA
      // faz nada
      return false;
    }
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

    if(atual == NULL){
        return false;
    }
        if(!op_desfazer){
        elo_pilha_t *ultima_celula = push(p, lin, col, atual->valor);
    }


fileira_t *fil_linha = (fil_ant_linha != NULL) ? fil_ant_linha->proximo : p->primeira_linha; //Se a fileria anterior for NULL, é a primeira linha, senão, é uma linha com anterior válido.

        if(cel_ant_linha != NULL) {
            cel_ant_linha->proxima_linha = atual->proxima_linha;
        } else{
            fil_linha->primeiro = atual->proxima_linha;//Fileira atual nula é pulada (bypass)
        }

        if(fil_linha->primeiro == NULL){
            if(fil_ant_linha != NULL){
                fil_ant_linha->proximo = fil_linha->proximo;
            }
            else{
                p->primeira_linha = fil_linha->proximo;
            }
            free(fil_linha);
        }

fileira_t *fil_coluna = (fil_ant_coluna != NULL) ? fil_ant_coluna->proximo : p->primeira_coluna; //Se a fileria anterior for NULL, é a primeira linha, senão, é uma linha com anterior válido.

        if(cel_ant_coluna != NULL) {
            cel_ant_coluna->proxima_coluna = atual->proxima_coluna;
        } else{
            fil_coluna->primeiro = atual->proxima_coluna;//Fileira atual nula é pulada (bypass)
        }

        if(fil_coluna->primeiro == NULL){
            if(fil_ant_coluna != NULL){
                fil_ant_coluna->proximo = fil_coluna->proximo;
            }
            else{
                p->primeira_coluna = fil_coluna->proximo;
            }
            free(fil_coluna);
        }

            free(atual);
            p->total_celulas--;    
    return true;
}

bool desligar_celula(planilha_t * p, celula_t *atual){
    celula_t *cel_ant_coluna = NULL;
    celula_t *cel_ant_linha = NULL;
    fileira_t *fil_ant_coluna = NULL; 
    fileira_t *fil_ant_linha = NULL;

    buscar_celula(p, atual->linha, atual->coluna, &cel_ant_linha, &cel_ant_coluna, &fil_ant_linha, &fil_ant_coluna); 

    fileira_t *fil_linha = (fil_ant_linha != NULL) ? fil_ant_linha->proximo : p->primeira_linha; //Se a fileria anterior for NULL, é a primeira linha, senão, é uma linha com anterior válido.

        if(cel_ant_linha != NULL) {
            cel_ant_linha->proxima_linha = atual->proxima_linha;
        } else{
            fil_linha->primeiro = atual->proxima_linha;//Fileira atual nula é pulada (bypass)
        }

        if(fil_linha->primeiro == NULL){
            if(fil_ant_linha != NULL){
                fil_ant_linha->proximo = fil_linha->proximo;
            }
            else{
                p->primeira_linha = fil_linha->proximo;
            }
            free(fil_linha);
        }

    fileira_t *fil_coluna = (fil_ant_coluna != NULL) ? fil_ant_coluna->proximo : p->primeira_coluna; //Se a fileria anterior for NULL, é a primeira linha, senão, é uma linha com anterior válido.

        if(cel_ant_coluna != NULL) {
            cel_ant_coluna->proxima_coluna = atual->proxima_coluna;
        } else{
            fil_coluna->primeiro = atual->proxima_coluna;//Fileira atual nula é pulada (bypass)
        }

        if(fil_coluna->primeiro == NULL){
            if(fil_ant_coluna != NULL){
                fil_ant_coluna->proximo = fil_coluna->proximo;
            }
            else{
                p->primeira_coluna = fil_coluna->proximo;
            }
            free(fil_coluna);
        }

            return true;
}

bool inserir_celula_tranposicao(planilha_t *p, celula_t *atual){
        celula_t *cel_ant_coluna = NULL;
        celula_t *cel_ant_linha = NULL;
        fileira_t *fil_ant_coluna = NULL; 
        fileira_t *fil_ant_linha = NULL;
        buscar_celula(p, atual->linha, atual->coluna, &cel_ant_linha, &cel_ant_coluna, &fil_ant_linha, &fil_ant_coluna); 

        fileira_t *fil_linha = criar_fileiras(&p->primeira_linha, fil_ant_linha, atual->linha);
        fileira_t *fil_coluna = criar_fileiras(&p->primeira_coluna, fil_ant_coluna, atual->coluna);

        if(fil_linha == NULL || fil_coluna == NULL){
            return false;
        }
        if(cel_ant_linha != NULL){
            atual->proxima_linha = cel_ant_linha->proxima_linha;
            cel_ant_linha->proxima_linha = atual;
        }else{
            atual->proxima_linha = fil_linha->primeiro;
            fil_linha->primeiro = atual;
        }

        if(cel_ant_coluna != NULL){
            atual->proxima_coluna = cel_ant_coluna->proxima_coluna;
            cel_ant_coluna->proxima_coluna = atual;
        }else{
            atual->proxima_coluna = fil_coluna->primeiro;
            fil_coluna->primeiro = atual;
        }
        return true;

}
bool transpor(planilha_t* p, int lin, int col, int tamanho) {
    /* TODO: transpoe uma matriz quadrada que está localizada entre
       as linhas [lin, lin + tamanho) e colunas [col, col + tamanho). */
    // fileira_t *i = p->primeira_linha;
 
    if(tamanho <= 0) return false; 
    if((lin >= INT_MAX - tamanho)|| (col >= INT_MAX - tamanho)){
                    return false;
     }        
        int lin_fim = lin + tamanho;
        int col_fim = col + tamanho;
        
        int tam_transpor = 0;

        fileira_t *fil_atual = p->primeira_linha;
        
        if(fil_atual != NULL){
            for(fil_atual = fil_atual; fil_atual && fil_atual->indice < lin_fim; fil_atual = fil_atual->proximo){
                if(fil_atual->indice < lin) continue; // Continua enquanto o índice não for encontrado
                for(celula_t *atual = fil_atual->primeiro; atual != NULL && atual->coluna < col_fim; atual = atual->proxima_linha){
                    if(atual->coluna >= col){                    
                        tam_transpor++;
                    }
                }
            }
        }

        celula_t **celulas = NULL;
        fil_atual = p->primeira_linha;
        
        if(tam_transpor > 0){ //Se houver realmente alguma mudança
            celulas = malloc(tam_transpor * sizeof(*celulas));
            if(celulas == NULL) return false;

            int num_celulas = 0;
            if(fil_atual != NULL){
                for(fil_atual = fil_atual; fil_atual && fil_atual->indice < lin_fim; fil_atual = fil_atual->proximo){
                    if(fil_atual->indice < lin) continue; // Continua enquanto o índice não for encontrado
                    for(celula_t *atual = fil_atual->primeiro; atual != NULL && atual->coluna < col_fim; atual = atual->proxima_linha){
                        if(atual->coluna >= col){
                            celulas[num_celulas++] = atual;
                        }
                    }
                }
            }
        }
        
        for(int num_celulas = 0; num_celulas < tam_transpor; num_celulas++){
            celula_t *atual = celulas[num_celulas];
            desligar_celula(p, celulas[num_celulas]);
            
            celula_t submatriz;
            submatriz.linha = atual->linha - lin; // Para encontrar as coordenadas relativas a submatriz formada por lin e col
            submatriz.coluna = atual->coluna - col;
            
            int aux; 
            aux = submatriz.linha; //Transposição da submatriz;
            submatriz.linha = submatriz.coluna;
            submatriz.coluna = aux;
            
            atual->linha = lin + submatriz.linha; // Retorno os valores de posição da submatriz para a escala da matriz normal
            atual->coluna = col + submatriz.coluna;
        }
        
        for(int num_celulas = 0; num_celulas < tam_transpor; num_celulas++){
            inserir_celula_tranposicao(p, celulas[num_celulas]);
        }

        free(celulas);  


        if(!op_desfazer && tam_transpor > 0){       
            push(p, lin, col, 0);   

         if(p->historico.topo != NULL){
            p->historico.topo->op.transposicao = true;
            p->historico.topo->op.linha = lin;
            p->historico.topo->op.coluna = col;
            p->historico.topo->op.tamanho = tamanho;
         }
        }
        return true;
    
    return false;
}

bool desfazer(planilha_t* p) {
    /* TODO: desempilhe de p->historico e restaure o valor anterior.
       Retorna false se o historico estiver vazio, true caso contrario. */
    if(p == NULL) return false;

    if (p->historico.topo == NULL) {
        printf("HISTORICO VAZIO\n");
        return false;
    }
    elo_pilha_t* historico = pop(p);
    

    op_desfazer = true; // Define com true a operação para expressar que "desfazer" está sendo realizada para diferenciar na "definir"

    if(historico->op.transposicao == true){
        transpor(p, historico->op.linha, historico->op.coluna, historico->op.tamanho);
    }else{
        
        int lin = historico->op.linha;
        int col = historico->op.coluna;
        int valor_anterior = historico->op.valor_anterior;  
        
        elo_pilha_t *atual = p->historico.topo;
        
        if(valor_anterior == 0){
            remover_celula(p, lin, col);
        }
        else{
            definir_celula(p, lin, col, valor_anterior);
        }
    }
     
    op_desfazer = false;
    free(historico);
   
    return true;
}

void exibir_planilha(planilha_t *p) {
    /* TODO: imprima "linha coluna valor" por linha, em ordem crescente
       de linha e, dentro de cada linha, de coluna. Se vazia, imprima
       "PLANILHA VAZIA" */
    fileira_t *i = p->primeira_linha;

    if (contar_nao_nulas(p)) {
        printf("PLANILHA\n");
    } else {
        printf("PLANILHA VAZIA\n");
    }
   
    for(i = p->primeira_linha; i != NULL; i = i->proximo){
        for(celula_t *j = i->primeiro; j != NULL; j = j->proxima_linha){
            printf("%d %d %d\n", j->linha, j->coluna, j->valor);
        }
    }
       
}

void exibir_historico(planilha_t* p) {
    /* TODO: imprima "linha coluna valor_anterior" por linha, do topo
       para a base. Se vazio, imprima "HISTORICO VAZIO" */
        elo_pilha_t *atual = p->historico.topo;
        if(atual == NULL){
            printf("HISTORICO VAZIO\n");
            return;
        }

        printf( "HISTORICO\n");
        while(atual != NULL){
                if(atual->op.transposicao == true) printf("T ");
                printf("%d %d %d\n", atual->op.linha, atual->op.coluna, atual->op.valor_anterior);
                atual = atual->proximo;
            }
           
             
}

void reinicializar(planilha_t *p){
    inicializar_planilha(p);
}
void liberar_tudo(planilha_t* p) {
    // TODO: libere toda a memória alocada por fileira, celula, e pilha.
    //Liberar Definir
    //Liberar Push
    //Liberar Criar Fileiras
    fileira_t *fil_linha = p->primeira_linha;
    fileira_t *fil_coluna = p->primeira_coluna;

    while(fil_linha != NULL){
        celula_t *atual = fil_linha->primeiro;
        while(atual != NULL){
            celula_t *prox_linha = atual->proxima_linha;
            free(atual);
            atual = prox_linha;
        }
        fileira_t * prox_fil_linha = fil_linha->proximo;
        free(fil_linha); //Logo após fornecer free em todas as celulas de uma fileira, fornece free na fileira e segue para a prox;
        fil_linha = prox_fil_linha;
    }
    
    while(fil_coluna != NULL){
        fileira_t * prox_fil_col = fil_coluna->proximo;
        free(fil_coluna); //Logo após fornecer free em todas as celulas de uma fileira, fornece free na fileira e segue para a prox;
        fil_coluna = prox_fil_col;
    }

        p->primeira_linha = p->primeira_coluna = NULL;

    while(p->historico.topo != NULL){
        elo_pilha_t *free_ptr = p->historico.topo;

        p->historico.topo = p->historico.topo->proximo;
        free_ptr->proximo = NULL; 
        
        free(free_ptr);
    }
    reinicializar(p);
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

        } else if (igual(cmd, "SOMA")) {
            int li, lf, ci, cf;
            fscanf(entrada, "%d %d %d %d", &li, &lf, &ci, &cf);
            fprintf(saida, "SOMA %d %d %d %d %d\n", li, lf, ci, cf, somar_intervalo(&p, li, lf, ci, cf));
        } else if (igual(cmd, "CONT")) {
            fprintf(saida, "CONT %d\n", contar_nao_nulas(&p));
        
        } else if (igual(cmd, "DESFAZER")) {
            desfazer(&p);             
        } else if (igual(cmd, "EXIBIR")) {
                exibir_planilha(&p);
        } else if (igual(cmd, "HIST")) {
                exibir_historico(&p);
           
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
