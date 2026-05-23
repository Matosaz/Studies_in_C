#ifndef CONTATO_H

#define CONTATO_H
#define MAX_CONTATOS 100
#define TAM_NOME 50
#define TAM_FONE 20
#define TAM_EMAIL 60

typedef struct {
    int id; 
    
    char nome[TAM_NOME]; 
    char telefone[TAM_FONE];
    char email[TAM_EMAIL];
} Contato;



// FUNÇÕES DO CRUD;
void cadastrar(Contato lista[], int *total);
void listar(const Contato lista[], int total);
void buscar(const Contato lista[], int total);
void editar(Contato lista[], int total);
void remover(Contato lista[], int *total);

#endif