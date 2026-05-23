#include <stdio.h>

int main() {
    
    int age = 25;
    int* pAge = &age;

    char grade = 'A';
    char* pGrade = &grade;

    float temperature = 98.6;
    float* pTemp = &temperature;


    printf("Age: %d\n", *pAge);
    printf("Grade: %c\n", *pGrade);
    printf("Temperature: %.1f\n", *pTemp);

    *pAge = 30;
    *pGrade = 'B';
    *pTemp = 99.5;

    printf("Age: %d\n", *pAge);
    printf("Grade: %c\n", *pGrade);
    printf("Temperature: %.1f\n", *pTemp);


    return 0;
}