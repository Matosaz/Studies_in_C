#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    char choice = '\0';
    float fahrenheit = 0.0f;
    float celsius = 0.0f;

    printf("Temperatura Conversion Programm:\n");
    printf("Is the temp in Celsius(C) or Fahrenheit(F)?: ");

    scanf("%c", &choice);

    if (choice == 'C')
    {
        printf("Enter the temperatura in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 1.8) + 32;
        printf("%.2f Celsius is equal to: %.2f Fahrenheit ", celsius,fahrenheit);
        
    }
    else if (choice == 'F')
    {
        printf("Enter the temperatura in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32) / 1.8;
        printf("%.2f Fahrenheit is equal to: %.2f Celsius", fahrenheit, celsius);
    }
    else
        printf("Invalid choice! Please select C or F\n");

    return 0;
};