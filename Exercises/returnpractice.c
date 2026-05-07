#include <stdio.h>
#include <stdbool.h>

int getMax(int x, int y)
{
  
    if (x > y)
    {
        printf("%d is greater than %d\n", x, y);
    }
    else if (x < y)
    {
        printf("%d is greater than %d\n", y, x);
    }
    else
    {
        printf("%d = %d\n", x, y);
    }
}


double square(double num)
{
    return num * num;
}

double cube(double num)
{
    return num * num * num;
}

bool ageCheck(int age)
{
    if (age >= 18)
    {
        return true;
    }
    else
        false;
}

int main()
{
    int age = 17;
    double x = square(2);
    double y = square(5);
    double z = square(10);

    double w = cube(2);
    double a = cube(5);
    double b = cube(10);

    printf("QUADRADO:\n", x);

    printf("%.2lf\n", x);
    printf("%.2lf\n", y);
    printf("%.2lf\n", z);
    printf("--------------------------------------------\n", x);
    printf("CUBO:\n", x);
    printf("%.2lf\n", w);
    printf("%.2lf\n", a);
    printf("%.2lf\n", b);

    printf("--------------------------------------------\n", x);
    int max = getMax(7, 7);

    printf("--------------------------------------------\n", x);

    if (ageCheck(age))
    {
        printf("DE MAIOR PAIZÃO!");
    }
    else
    {
        printf("LEI FELCA IRÁ LHE PEGAR...");
    }
    return 0;
}