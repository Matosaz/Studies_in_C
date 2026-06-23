#include <stdio.h>
#include <stdlib.h>


typedef struct{
    float lateral;
    float cquarto;
}Casa;

int main() {
    
    Casa casa01;
    casa01.lateral = 20;
    casa01.cquarto = 40;

    float casa_area = casa01.lateral * casa01.cquarto;


    printf("Area da casa: %.2f", casa_area);
    return 0;
}