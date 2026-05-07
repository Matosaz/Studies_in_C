#include <stdio.h>
#include <string.h>


int main()
{

    int age = 0;
    float gpa = 0.0f;
    char grade = '\0';
    char name[30] = "";

    printf("Enter your age:");
    scanf("%d", &age);

    printf("Enter your GPA:");
    scanf("%f", &gpa);

    printf("Enter your grade:");
    scanf(" %c", &grade);


    getchar();
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';


    printf("----------------------------------\n");

    printf("Age: %d\n", age);
    printf("GPA: %.2f\n", gpa);
    printf("Grade: %c\n", grade);
    printf("Name: %s\n", name);

    return 0;
}