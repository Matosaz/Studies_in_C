#include <stdio.h>

int main()
{

    char dayOfWeek = '\0';
    printf("\tDays of the week:\n");
    printf("M - Monday \t T - Tuesday\n");
    printf("W - Wednesday \t R - Thursday\n");
    printf("F - Friday \t S - Saturday \t \n");
    printf("U - Sunday\n");
    printf("Enter the day of the week:\n");

    scanf("%c", &dayOfWeek);

    switch (dayOfWeek){
    case 'M':
        printf("It is Monday");
        break;

    case 'T':
        printf("It is Tuesday");
        break;

    case 'W':
        printf("It is Wednesday");
        break;

    case 'R':
        printf("It is Thursday");
        break;

    case 'F':
        printf("It is Friday");
        break;

    case 'S':
        printf("It is Saturday");
        break;

    case 'U':
        printf("It is Sunday");
        break;

  default:
        printf("Please, enter only numbers beetween 1 and 7");
        break;
        
    }

    return 0;
}