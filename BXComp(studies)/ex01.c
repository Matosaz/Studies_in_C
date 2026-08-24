#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int tamanho = 0;
    int a[100];
    int b[100];
    int c[100];

    double area[100];

    scanf("%d", &tamanho);

    for(int i = 0; i < tamanho; i++){
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);  
        scanf("%d", &c[i]);

        double s = (a[i] + b[i] + c[i])/2;
        area[i] = sqrt(s*(s-a[i]) * s*(s-b[i]) * s*(s-c[i]));
    }

    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(area[i] > area[j]){
                int temp1 = a[i];
                int temp2 = b[i];
                int temp3 = c[i];

                int tempA = area[i];


                a[j] = temp1;
                b[j] = temp2;
                c[j] = temp3;

                area[j] = tempA;
                matheus 

            }
        }
    }

    for(int i = 0; i < tamanho; i++){
        printf("%d %d %d %ld",a[i], b[i], c[i], area[i]);
    }
    return 0;
}