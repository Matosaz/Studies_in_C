#include <stdio.h>

float deposito();
float sacar(float balance);
void status(float balance);

int main()
{
    int option = 0;
    float balance = 0.0f;
    printf("*** WELCOME TO THE BANK *** \n");

    do
    {
        printf("1 - Checar status da conta\n");
        printf("2 - Depositar\n");
        printf("3 - Sacar\n");
        printf("4 - Sair\n");
        printf("Chose the operation you wanna do: \n");
        scanf("%d", &option);
    
    
    switch (option)
    {
    case 1:
        status(balance);
        break;

    case 2:
        balance += deposito();
        break;

    case 3:
        balance -= sacar(balance);
        break;

    case 4:
    printf("Agradecemos amplamente pela preferência!\n");
        break;

    default:
    printf("Select a valid operation!\n");
    }
    
    }while (option != 4);

    return 0;

}

void status(float balance)
{
    printf("Conta corrente: %.2f\n", balance);
}

float deposito()
{
    float quantia = 0.00;
    printf("Insira a quantia que voce almeja depositar: \n");
    scanf("%f", &quantia);

    if (quantia < 0)
    {
        printf("A quantia não pode ser inferior à 0.00R$\n");
        return 0.0f;
    }
    else
    {
        printf("Deposito de %.2f realizado com sucesso!\n", quantia);
        return quantia;
    }
};

float sacar(float balance){
    float quantia;
    printf("Insira a quantia que voce deseja sacar: \n");
    scanf("%f", &quantia);

    if(quantia < -0){
        printf("A quantia não pode ser inferior à 0.00R$\n");
        return 0.0f;
    }

    else if(quantia > balance){
        printf("O valor do saque não pode exceder a quantia em conta correte!\n");
        return 0.0f;
    }
    else{

        printf("Saque de %.2f realizado com sucesso!\n", quantia);
    return quantia;
    }
}