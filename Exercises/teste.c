
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

char *find_substring(char *a, char *b) {
    
    char *substring = strstr(a, b);
    if(substring == NULL){
        return false;
    }
    return substring;
}


int main(){
    
    char a[20] = "Comi feijao na feira";
    char b[20] = "feijao";
    char *resultado = find_substring(a, b);
    printf("%s", resultado);
}