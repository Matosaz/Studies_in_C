#include <stdio.h>

int main(){


    int value = 75;
    float price = 19.99;

    int* value_prt = &value;
    float* price_prt = &price;

    printf("%d\n", *value_prt);
    printf("%.2f", *price_prt);

    return 0;
}