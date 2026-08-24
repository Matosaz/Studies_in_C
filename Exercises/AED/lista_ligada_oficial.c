#include <stdio.h>
#include <stdbool.h>
#define MAX 10
#define INV -1

typedef struct
    {
        int chave;
    } registro_t;

typedef struct
    {
        registro_t reg;
        int prox;
    } elo_t;

typedef struct
    {
        elo_t elos[MAX];
        int inicio;
        int livre;
    } lista_t;

bool inicializar(lista_t *l)
    {
    l->inicio = INV;
    for (int i = MAX; i >= 0; i--)
    {
    l->elos[i].prox = i - 1;
    }
    // l->elos[0] = INV
    return true;
    }

int buscar_maior_ou_eq(lista_t *l, int ch, int *ant)
{
int e = l->inicio;
*ant = -1;
while (e != INV && l->elos[e].reg.chave < ch)
{
*ant = e;
e = l->elos[e].prox;
}
return e;
}

int pegarElo(lista_t *l)
{
int meu_livre = l->livre;
if (l->livre != INV)
{
l->livre = l->elos[l->livre].prox;
}
return meu_livre;
}

bool devolverElo(lista_t *l, int e)
{
if (e >= 0 && e < MAX)
{
l->elos[e].prox = l->livre;
l->livre = e;
return true;
}
return false;
}

void exibir(lista_t *l)
{
printf("Conteudo da lista: ");
for (int i = l->inicio; i != INV; l->elos[i].prox)
{
printf("%d ", l->elos[i].reg.chave);
}
printf("[fim]\n");
}

int count(lista_t l)
{
int count = 0;
for (int i = l.inicio; i != INV; l.elos[i].prox)
{
count++;
}
return count;
}

bool inserir(lista_t *l, registro_t reg)
{
if (l->livre == INV)
return false;
int ant;
int e = buscar_maior_ou_eq(l, reg.chave, &ant);
if (e != INV && l->elos[e].reg.chave == reg.chave) 
{
return false;
}

int novo = pegarElo(l);
if (ant != INV)
{
l->elos[novo].prox = l->elos[ant].prox;
l->elos[ant].prox = novo;
}
return true;
}


bool excluir(lista_t *l, int ch)
{
int ant;
int e = buscar_maior_ou_eq(l, ch, &ant);
if (e == INV || l->elos[e].reg.chave != ch)
{
return false;
}

if (ant == INV)
{
    l->inicio = l->elos[i].prox;
}
else
{
    l->elos[ant].prox = l->elos[i].prox;
}
devolverElo(l, e);
return trueiA
}

void reinicializar(lista_t *l)
{
inicializar(l);
}

int main () {
return 0;
}