#include <stdio.h>

int main()
{
    int i, j, k, num, numFormado, parar = 0;
    printf("Digite um numero entre 000 e 999 que deseja atingir: ");
    scanf("%d", &num);

    for (i = 0; i < 10; i++) {
       if (parar) break;
            for (j = 0; j < 10; j++){
                if (parar) break;
                    for (k = 0; k < 10; k++){
                        numFormado = i * 100 + j * 10 + k;
                        printf("%d%d%d\n", i, j, k);

                        if (numFormado == num)
                        {
                            parar = 1;
                            break;
                        }
                    }
                }
            }
    return 0;
    }
