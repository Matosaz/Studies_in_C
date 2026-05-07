#include <stdio.h>

int add(int x, int y)
{
    int result = x + y;

    return result;
}

int subtract(int x, int y)
{
    int result = x - y;

    return result;
}

int multiply(int x, int y)
{
    int result = x * y;

    return result;
}

int divide(int x, int y)
{
    int result = x / y;

    return result;
}

int main()
{

    int num1, num2, result;
    char operation = '\0';

    printf("Insira o primeiro número:");
    scanf("%d", &num1);
    printf("Insira a operação que deseja realizar: *, -, +, /");
    scanf(" %c", &operation);
    printf("Insira o segundo número:");
    scanf("%d", &num2);

    switch (operation)
    {
    case '+':
        result = add(num1, num2);
        break;
    case '-':
        result = subtract(num1, num2);
        break;

    case '*':
        result = multiply(num1, num2);
        break;

    case '/':
     if (num2 == 0)
    {
        printf("Por zero não pode paizão!");
        return 0;
    }
        result = divide(num1, num2);
        break;
    default:
        printf("Insira uma operação válida!");
        break;
    }


    printf("%d %c %d = %d", num1, operation, num2, result);
    return 0;
}