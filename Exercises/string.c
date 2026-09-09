#include <stdio.h>

int main() {
    char frase[64] = "Comi mamao na feira";
    char *mesmaFrase = frase; 
    int size = sizeof(frase) / sizeof(frase[0]);

    int contador = 0;
    for(int i = 0; i < size; i++){
        if(frase[i] == mesmaFrase[i]){    
           contador++;
        }
    }

    if(contador == size){
        printf("As frases são idênticas");
    }
    else{
        printf("São diferentes");
    }
    return 0;
}