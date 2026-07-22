#include <stdio.h>
#include <math.h>

#define IPCA 0.05
#define dataInicio 2026
#define valorInicial 20.0
#define impostoRenda 0.15 

typedef struct{
    int dataFinal;
    float taxaIPCA;
    float valorBruto;
    float valorLiquido;
    float impostoTotal;
} Estrategia;

int main() {
    Estrategia E1_01;
    Estrategia E1_02;
    E1_01.valorBruto = 0.0;
    E1_02.valorBruto = 0.0;

    E1_01.dataFinal = 2032;
    E1_01.taxaIPCA = IPCA + 8.08/100;
    E1_01.valorBruto += valorInicial *(pow((1+E1_01.taxaIPCA),E1_01.dataFinal - dataInicio));
    E1_01.impostoTotal =  ((E1_01.valorBruto - valorInicial) * impostoRenda);
    E1_01.valorLiquido = E1_01.valorBruto - E1_01.impostoTotal;

    E1_02.dataFinal = 2040;
    E1_02.taxaIPCA = IPCA + 7.51/100;
    E1_02.valorBruto += E1_01.valorLiquido *(pow((1+E1_02.taxaIPCA),E1_02.dataFinal - 2032));
    E1_02.impostoTotal =  ((E1_02.valorBruto - E1_01.valorLiquido) * impostoRenda);
    E1_02.valorLiquido = E1_02.valorBruto - E1_02.impostoTotal;

    Estrategia E2;
    E2.valorBruto = 0.0;
    E2.dataFinal= 2040;
    E2.taxaIPCA = IPCA + 7.51/100; 
    E2.valorBruto += valorInicial * (pow((1 + E2.taxaIPCA), E2.dataFinal - dataInicio));
    E2.impostoTotal =  ((E2.valorBruto - valorInicial) * impostoRenda);
    E2.valorLiquido = E2.valorBruto - E2.impostoTotal;
    
    
     printf("\t\tESTRATEGIA 1 - PARTE 01:\n");
     printf("======================================================\n");
     printf("Taxa Total: %.2f\n", E1_01.taxaIPCA * 100);
     printf("Data final: %d\n", E1_01.dataFinal);
     printf("Valor bruto: %.2f\t Imposto de renda em %d: %.2f\n", E1_01.valorBruto, E1_01.dataFinal,E1_01.impostoTotal);  
     printf("Valor inicial: %.2f\t Valor final: %.2f\n", valorInicial, E1_01.valorLiquido);
     printf("======================================================\n");
 
    
     printf("\t\tESTRATEGIA 1 - PARTE 02:\n");
     printf("======================================================\n");
     printf("Taxa Total: %.2f\n", E1_02.taxaIPCA * 100);
     printf("Data final: %d\n", E1_02.dataFinal);
     printf("Valor bruto: %.2f\t Imposto de renda em %d: %.2f\n", E1_02.valorBruto, E1_02.dataFinal,  E1_02.impostoTotal);  
     printf("Valor inicial: %.2f\t Valor final: %.2f\n", E1_01.valorLiquido, E1_02.valorLiquido);
     printf("======================================================\n");
  
    
     printf("\t\tESTRATEGIA 1 (TOTAL):\n");
     printf("======================================================\n");
     printf("Valor bruto: %.2f\t Imposto de renda total: %.2f\n",E1_02.valorBruto, (E1_01.impostoTotal + E1_02.impostoTotal));  
     printf("Valor final: %.2f\n", E1_02.valorLiquido);
     printf("======================================================\n");


    printf("\t\tESTRATEGIA 2:\n");
    printf("======================================================\n");
    printf("Taxa Total: %.2f\n", E2.taxaIPCA * 100);
    printf("Data final: %d\n", E2.dataFinal);
    printf("Valor bruto: %.2f\t Imposto de renda em %d: %.2f\n", E2.valorBruto, E2.dataFinal,E2.impostoTotal);  
    printf("Valor inicial: %.2f\t Valor final: %.2f\n", valorInicial, E2.valorLiquido);
    printf("======================================================\n");
   
    return 0;
}