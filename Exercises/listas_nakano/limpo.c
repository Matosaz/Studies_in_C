#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

struct Endereco{
    char cidade[20];
};

struct Pessoa{
    char *nome;
    struct Endereco *endereco;
};
 
void mudaAll(struct Pessoa *p, char *novoNome, char *novaCidade){

    strcpy(p->nome, novoNome);
    strcpy(p->endereco->cidade, novaCidade);
};

int main(){
    
    struct Endereco end1 = {"Osasco"};
    char p[25] = "Ana Isabela";

    struct Pessoa p1 = {p, &end1};
    
    printf("%s\n",p1.endereco->cidade);
    printf("%s\n",p1.nome);

    struct Pessoa p2 = p1;
    printf("%s %s\n",p2.nome,p2.endereco->cidade);

    mudaAll(&p2,"Fernando", "Sao Paulo");

    printf("%s %s\n",p1.nome,p1.endereco->cidade);
 
    return 0;
}