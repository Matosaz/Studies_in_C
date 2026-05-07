// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    int porta_aberta = 0, winStaying = 0, lostStaying = 0, winChanging = 0, lostChanging = 0;

    float total_changing = 0.0, total_staying = 0.0;

    for (int i = 0; i < 1000; ++i)
    {
        int escolha_inicial = rand() % 3 + 1;
        int premio = rand() % 3 + 1;
        int trocar = rand() % 2;
        int escolha_final = 0;

        do
        {
            porta_aberta = rand() % 3 + 1;
        } while (porta_aberta == escolha_inicial || porta_aberta == premio);
        printf("Porta aberta: %d\t Escolha inicial:%d\t Porta com Premio: %d\n", porta_aberta, escolha_inicial, premio);

        if (trocar == 1)
        {
            total_changing++;
            for (int j = 1; j <= 3; j++)
            {
                if (j != porta_aberta && j != escolha_inicial)
                {
                    escolha_final = j;
                }
            }
            if (escolha_final == premio)
            {
                winChanging += 1;
            }
            else
            {
                lostChanging += 1;
            }
        }
        else
        {
            total_staying++;
            if (escolha_inicial == premio)
            {
                winStaying += 1;
            }

            else
            {
                lostStaying += 1;
            }
        }
    }

    float porcentWC = (winChanging / total_changing) * 100;
    float porcentLC = (lostChanging / total_changing) * 100;
    float porcentWS = (winStaying / total_staying) * 100;
    float porcentLS = (lostStaying / total_staying) * 100;

    printf("------------------------------------------------------------------\n");
    printf("Vitorias trocando: %d\t Porcentagem: %.2f%%\n", winChanging, porcentWC);
    printf("Derrotas trocando: %d\t Porcentagem: %.2f%%\n", lostChanging, porcentLC);
    printf("------------------------------------------------------------------\n");
    printf("Vitorias sem trocar: %d\t Porcentagem: %.2f%%\n", winStaying, porcentWS);
    printf("Derrotas sem trocar: %d\t Porcentagem: %.2f%%\n", lostStaying, porcentLS);

    return 0;
}