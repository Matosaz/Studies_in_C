#include <stdio.h>
#include "contato.h"

//utilizei o sistema de escrita e arquivos binário para evitar parsing e para
// assegurar maior eficiência no processamento de escrita e leitura das structs;

#define ARQUIVO "agenda.dat"

void salvar(const Contato lista[], int total){

    FILE *file = fopen(ARQUIVO, "wb");
    if(!file){
        perror("Erro ao abrir arquivo de escrita");
        return;
    }

    fwrite(&total, sizeof(int), 1, file);
    fwrite(lista, sizeof(Contato), total, file);

    fclose(file);
}


    int carregar(Contato lista[]) {
        FILE *file = fopen(ARQUIVO, "rb");

           if(!file) return 0;

           int total = 0;
           fread(&total, sizeof(int), 1 , file);
           fread(lista, sizeof(Contato), total, file);

           fclose(file);

 
    }