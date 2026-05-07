#include <stdio.h>
#include <string.h>

void HappyBirthday(char nome[], int age)
{

    printf("HAPPY BIRTHDAY\n");
    printf("HAPPY BIRTHDAY %s\n", nome);
    printf("YOU ARE %d YEARS OLD\n", age);
    printf("HAPPY BIRTHDAY!");
}

int main()
{
    int age = 0;
    char nome[50] = "";

    printf("Please, insert your name: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strlen(nome) - 1] = '\0';

    printf("Insert your age: ");
    scanf("%d", &age);

    HappyBirthday(nome, age);
    return 0;
}