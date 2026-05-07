// Online C compiler to run C program online
#include <stdio.h>

void removechar(char str[]);
void spongecase(char str[]);

int main()
{

    int option;
    char str[100];

    printf("Selecione a operação que deseja realizar: \n");
    printf("1 - Remover Caracteres: \n");
    printf("2 - Spongecase: ");
    scanf(" %d", &option);
    getchar();

    printf("Insira uma frase: ");
    fgets(str, sizeof(str), stdin);

    switch (option)
    {
    case 1:
        removechar(str);
        break;

    case 2:
        spongecase(str);
        break;

    default:
        printf("Selecione uma opção válida! ");
        break;
    }
}




void removechar(char str[])
{

    char char_to_remove;
    char new_str[100];
    int j = 0;

    printf("Selecione uma letra que deseja remover dela: ");
    scanf(" %c", &char_to_remove);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != char_to_remove)
        {
            new_str[j] = str[i];
            j++;

            new_str[j] = '\0';
        }
    }
    printf("%s", new_str);
}


void spongecase(char str[])
{
    int toogle = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')

        {
            if (toogle == 1)
            {
                if (str[i] >= 'a' && str[i] <= 'z')
                    str[i] = str[i] - 32;
            }
            else
            {

                if (str[i] >= 'A' && str[i] <= 'Z')
                    str[i] = str[i] + 32;
            }
            toogle = !toogle;
        }
    }
    printf(" %s", str);
}
