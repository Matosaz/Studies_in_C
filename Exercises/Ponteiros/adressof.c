#include <stdio.h>

int main() {
    
    int number = 42;
    int* number_ptr = &number;

    char letter = 'X';
    char* char_ptr = &letter;


    printf("%p\n", number_ptr);
    printf("%p", char_ptr);

    return 0;
}