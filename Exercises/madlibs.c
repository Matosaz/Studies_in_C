#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

int main()
{

    // Define locale do C
    setlocale(LC_ALL, ".UTF-8");

    char noun[50] = "";
    char verb[50] = "";
    char adjective1[50] = "";
    char adjective2[50] = "";
    char adjective3[50] = "";
    char adverb[50] = "";

    printf("Enter an adjective (description ): ");
    fgets(adjective1, sizeof(adjective1), stdin);
    adjective1[strlen(adjective1) - 1] = '\0';

    printf("Enter an noun (animal, person, whatever ): ");
    fgets(noun, sizeof(noun), stdin);
    noun[strlen(noun) - 1] = '\0';

    printf("enter and adjective (description): ");
    fgets(adjective2, sizeof(adjective2), stdin);
    adjective2[strlen(adjective2) - 1] = '\0';

    printf("Enter a verb(): ");
    fgets(verb, sizeof(verb), stdin);
    verb[strlen(verb) - 1] = '\0';

    printf("enter and adverb of mode(felizmente, relutantemente): ");
    fgets(adverb, sizeof(adverb), stdin);
    adverb[strlen(adverb) - 1] = '\0';

    printf("enter and adjective (description): ");
    fgets(adjective3, sizeof(adjective3), stdin);
    adjective3[strlen(adjective3) - 1] = '\0';

    printf("\nBella da Silva estava %s\n", verb);
    printf("\nem um %s petshop, quando repentinamente um(a) %s\n", adjective1, noun);
    printf("\n%s tentou atacar-lhe, porém ela %s defendeu-se e retornou a consumir sua %s ração\n", adjective2, adverb, adjective3);
    printf("á é í ó ú ç ã õ ê\n");
    return 0;
}