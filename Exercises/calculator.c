#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char ext_operation[50] = "";
    char operation = '\0';
    double num1 = 0.0;
    double num2 = 0.0;
    double result = 0.0;

    printf("Insert the first number: \n");
    scanf("%lf", &num1);

    printf("(+) -> Sum \t (-) -> Subtract\n");
    printf("(*) -> Multiply \t (/) -> Divide\n");
    printf("(^) -> pow\n");
    printf("Enter the operation you wanna use:\n");
    scanf(" %c", &operation);

    switch (operation)
    {
    case '+':
        strcpy(ext_operation, "Soma");
        break;
    case '-':
        strcpy(ext_operation, "Subtracao");
        break;
    case '*':
        strcpy(ext_operation, "Multiplicacao");
        break;
    case '/':
        strcpy(ext_operation, "Divisao");
        break;
    case '^':
        strcpy(ext_operation, "Potencia");
    }
    printf("Operação selecionada: %s\n", ext_operation);

    printf("Now select the second number: \n");
    scanf("%lf", &num2);

    switch (operation)
    {
    case '+':
        result = num1 + num2;
        break;

    case '-':
        result = num1 - num2;
        break;

    case '*':
        result = num1 * num2;
        break;

    case '/':
        result = num1 / num2;
        break;

    case '^':
        result = pow(num1, num2);
        break;

    default:
        printf("Insert a valid operation!");
        break;
    };

    printf("%.2lf %c %.2lf = %.2lf ",num1, operation, num2, result);
    return 0;
}