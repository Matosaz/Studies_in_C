#include <stdio.h>
 

void birthday(int* age);

int main(){

    //Pointer: A variable that stores the memory addres of another variable.

    
    int age = 25;
    int *pAge = &age;

    
    printf("%p\n", &age);
    printf("%p", pAge);

    birthday(pAge);

    
    printf("You are %d years old", age);
    return 0;
}

void birthday(int* age){

    //Pass by reference;

    (*age)+=10;
};
