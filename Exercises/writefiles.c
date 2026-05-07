#include <stdio.h>
#include <stdlib.h>

void showMenu();
int readoption();
int writeFile(const char *mode);
int readFile();
FILE *openFile(const char *mode);

#define FILE_PATH "C:\\Users\\Matheus\\Desktop\\output.txt"



//COORDENA O FLUXO DE EXECUÇÃO
int main()
{
        int option = 0;
        
        while(option != 5){

        showMenu();
        option = readoption();
        switch (option)
        {
        case 1:
            writeFile("w");
            break;

        case 2:
            writeFile("a");
            break;

             case 3:
            readFile();
            break;

        case 4:
            system("cls");
            break;

        case 5:
        printf("Encerrando programa...\n");
        break;

        default:
            printf("Please, select a valid operation!\n");
            break;
    }    
}
}
//REALIZA A ESCRITA(REGISTRO) DO CONTEÚDO.
int writeFile(const char *mode)
{
    char text[200];

    FILE *file = openFile(mode);

    if (file == NULL)
    {
        printf("Error opening the file\n");
        return 1;
    }

    printf("\nInsira a frase que almeja registrar: \n");
    fgets(text, sizeof(text), stdin);

    fprintf(file, "%s", text);
 
    fclose(file);
}


//REALIZA LEITURA DO CONTEÚDO.
int readFile()
{

    FILE *file = openFile("r");
    char buffer[1024] = {0};

    if (file == NULL)
    {
        printf("Error opening the file\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(file);
}


//RESPONSÁVEL PELO GERENCIAMENTO DO MODO DE EXECUÇÃO (LEITURA OU ESCRITA)
FILE *openFile(const char *mode)
{
    FILE *file = fopen(FILE_PATH, mode);
    if (file == NULL)
    {
        printf("Error opening the file\n");
        return NULL;
    }
    return file;
}


void showMenu(){
    printf("\n====================================\n");
    printf("        FILE MANAGER TERMINAL        \n");
    printf("====================================\n");
    printf("1 - Sobrescrever arquivo\n");
    printf("2 - Adicionar ao arquivo\n");
    printf("3 - Ler arquivo\n");
    printf("4 - Limpar tela\n");
    printf("5 - Sair\n");
    printf("------------------------------------\n");
    printf("Escolha uma opcao: ");

}

int readoption(){
       int option;

    if (scanf("%d", &option) != 1)
    {
        while (getchar() != '\n');
        return -1;
    }

    while (getchar() != '\n');

    return option;

}