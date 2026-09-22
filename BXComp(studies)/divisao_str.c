#include <stdio.h>

int main() {
    char texto[50];
    int n;
    printf("Digite a entrada(ex: AAAAAAA 1312556): \n");
    scanf("%s %d", texto, &n);

    printf("Parte em texto: %s\n", texto);
    printf("Parte numérica: %d", n);

    return 0;
}