#include <stdio.h>

long potencia(int base, int exp);
double fatorial(double n);
double aproximarEuler(int k);
int verificarVitoriaRodada(int j1, int j2);
int ehNarcisista(int n);
int melhorDeTres(int j1_r1, int j2_r1,
                 int j1_r2, int j2_r2,
                 int j1_r3, int j2_r3);

int main()
{
    double n;
    int option, base, exp, k, j1, j2;

    printf("Qual funcao voce deseja realizar?\n");

    printf(" 1 - Fatorial\n");
    printf(" 2 - Potencia\n");
    printf(" 3 - Euler\n");
    printf(" 4 - Pedra, Papel, Tesoura (1 Rodada)\n");
    printf(" 5 - Pedra, Papel, Tesoura (Melhor de três)\n");
    printf(" 6 - Número Narcisista\n");

    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("Insira um número: ");
        scanf("%lf", &n);
        fatorial(n);
        break;

    case 2:
        printf("Insira uma base:\n ");
        scanf("%d", &base);
        printf("Insira um expoente:\n ");
        scanf("%d", &exp);
        potencia(base, exp);
        break;

    case 3:
        printf("Insira o número de termos K que deseja utilizar no cálculo: ");
        scanf("%d", &k);
        aproximarEuler(k);
        break;

    case 4:
        printf("0 - PEDRA\t 1 - PAPEL\t 2 - TESOURA \n");

        printf("Insira a jogada do jogador 1: \n");
        scanf("%d", &j1);

        printf("Insira a jogada do jogador 2: \n");
        scanf("%d", &j2);

        verificarVitoriaRodada(j1, j2);
        break;

    case 5:
        int rodada = 1;
        int j1_r1, j1_r2, j1_r3, j2_r1, j2_r2, j2_r3;
        printf("0 - PEDRA\t 1 - PAPEL\t 2 - TESOURA (Melhor de três) \n");

        printf("Insira a 1º jogada do jogador 1: \n");
        scanf("%d", &j1_r1);

        printf("Insira a 1º jogada do jogador 2: \n");
        scanf("%d", &j2_r1);

        printf("Insira a 2º jogada do jogador 1: \n");
        scanf("%d", &j1_r2);

        printf("Insira a 2º jogada do jogador 2: \n");
        scanf("%d", &j2_r2);

        printf("Insira a 3º jogada do jogador 1: \n");
        scanf("%d", &j1_r3);

        printf("Insira a 3º jogada do jogador 2: \n");
        scanf("%d", &j2_r3);

        melhorDeTres(j1_r1, j2_r1, j1_r2, j2_r2, j1_r3, j2_r3);

        break;

    case 6:
        int n;
        printf("Insira um número para verificar se ele é narcisista:");
        scanf("%d", &n);
        ehNarcisista(n);

        break;
    }

    return 0;
}

long potencia(int base, int exp)
{
    long int result;
    for (int i = 0; i < exp; i++)
    {
        result = i * (base * base);
    }

    if (exp < 0)
    {
        result = -1;
    }
    else if (base == 0 && exp == 0)
    {
        result = -1;
    }
    else if (exp == 0)
    {
        result = 1;
    }

    printf("%ld\n", result);

    return result;
}

double fatorial(double n)
{

    for (int i = (n - 1); i > 0; i--)
    {
        n = (n * i);
    }
    if (n == 0)
    {
        n = 1;
    }
    else if (n < 0)
    {
        n = -1;
    }
    printf("%.2lf\n", n);

    return n;
    // n! = n * (n-1) * (n-2) *... + 1
}

double aproximarEuler(int k)
{
    double e;

    for (int i = 0; i <= (k - 1); i++)
    {

        e += (1 / fatorial(i));
    }
    if (k < 1)
    {
        e = -1;
    }
    printf("Aproximação de e: %.10lf\n", e);

    return e;

    // e = 1/0! + 1/1! + 1/2! + 1/2!
}

int verificarVitoriaRodada(int j1, int j2)
{
    int result;
    if (j1 == j2)
    {
        result = 0;
    }
    else if ((j1 == 0 && j2 == 2) || (j1 == 1 && j2 == 0) || (j1 == 2 && j2 == 1))
    {
        result = 1;
    }
    else
    {
        result = 2;
    }

    printf("%d\n", result);
    return result;
}

int melhorDeTres(int j1_r1, int j2_r1,
                 int j1_r2, int j2_r2,
                 int j1_r3, int j2_r3)
{
    int winPerRoundJ1 = 0;
    int winPerRoundJ2 = 0;

    int result;

    for (int rodada = 1; rodada <= 3; rodada++)
    {
        if (rodada == 1)
        {
            printf("Vencedor da rodada %d: %d\n", rodada, verificarVitoriaRodada(j1_r1, j2_r1));
            if (verificarVitoriaRodada(j1_r1, j2_r1) == 1)
            {
                winPerRoundJ1++;
            }
            else if (verificarVitoriaRodada(j1_r1, j2_r1) == 2)
            {
                winPerRoundJ2++;
            }
        }
        else if (rodada == 2)
        {
            printf("Vencedor da rodada %d: %d\n", rodada, verificarVitoriaRodada(j1_r2, j2_r2));
            if (verificarVitoriaRodada(j1_r2, j2_r2) == 1)
            {
                winPerRoundJ1++;
            }
            else if (verificarVitoriaRodada(j1_r2, j2_r2) == 2)
            {
                winPerRoundJ2++;
            }
        }
        else
        {
            printf("Vencedor da rodada %d: %d\n", rodada, verificarVitoriaRodada(j1_r3, j2_r3));
            if (verificarVitoriaRodada(j1_r3, j2_r3) == 1)
            {
                winPerRoundJ1++;
            }
            else if (verificarVitoriaRodada(j1_r3, j2_r3) == 2)
            {
                winPerRoundJ2++;
            }
        }
    }

    if (winPerRoundJ1 > winPerRoundJ2)
    {
        result = 1;
    }
    else if (winPerRoundJ2 > winPerRoundJ1)
    {
        result = 2;
    }
    else
    {
        result = 0;
    }

    printf("Resultado final %d", result);
}

int ehNarcisista(int n)
{
    // Quantidade de digitos = k;
    int soma = 0 , numDigitos = 0, result, k = 0, potencia = 1 ;

    int temp = n;

    while(temp > 0){
        k++;
        temp = temp /10;
    }
    int valoresSeparados[k];
    temp = n;

//Armazena os valores dos arrays em posições de índice [i];
for(int i = 0; i < k; i++){
    valoresSeparados[i] = temp % 10;
    temp /= 10;
}

//Array em ordem normal
for(int i = k -1; i>= 0; i--){
    printf("%d\n", valoresSeparados[i]);
    potencia = 1; // Reinicializa a cada iteração para não carregar o valor total da anterior.

    for(int j = 0; j < k; j++){
        potencia*= valoresSeparados[i];
    }
    soma += potencia;
    }

    
    printf("Numero de digitos: %d\n", k);
        printf("Soma: %d\n", soma);


        if(n == soma){
            printf("E narcisista!");
        }
        else
        printf("Nao e narcisista!");
    }