/*
Calculadora:soma, subtração, multiplicação, divisão e potencia 
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu();
void soma(float a, float b);
void sub(float a, float b);
void mult(float a, float b);
void div(float a, float b);
void pow(float a, float b);
void imprimirMsg(float result);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    menu();
    getchar();
    return 0;
}

void menu()
{
    float a,b;
    printf("\nMenu de Operações\n");
    printf("\n1 - soma");
    printf("\n2 - subtração");
    printf("\n3 - multiplicação");
    printf("\n4 - divisão");
    printf("\n5 - potencia");
    int op;
    printf("\nEscolha uma opção:\n");
    printf(">");
    scanf("%d",&op);

    if (op==5)
    {
        printf("\nDigite um número\n");
        printf(">");
        scanf("%f",&a);
        printf("\nDigite outro número\n");
        printf(">");
        scanf("%f",&b);
    }else
    {
        printf("\nDigite um número\n");
        printf(">");
        scanf("%f",&a);
        printf("\nDigite outro número\n");
        printf(">");
        scanf("%f",&b);
    }
    
    

    switch (op)
    {
        //1 - soma
    case 1:
        soma(a,b);
        break;
        //2 - subtração
    case 2:
        sub(a,b);
        break;
        //3 - multiplicação
    case 3:
        mult(a,b);
        break;
        //4 - divisão
    case 4:
        div(a,b);
        break;
        //5 - potencia
    case 5:
        pow(a,b);
        break;
    
    default:
        break;
    }

    
}

void soma(float a, float b)
{
    printf("\nSoma\n");
    float result = 0;
    result = a+b;
    imprimirMsg(result);
}

void sub(float a, float b)
{
    printf("\nSubtração\n");
    float result = 0;
    result = a-b;
    imprimirMsg(result);
}

void mult(float a, float b)
{
    printf("\nMultiplicação\n");
    float result = 0;
    result = a*b;
    imprimirMsg(result);
}

void div(float a, float b)
{
    printf("\nDivisão\n");
    if (b ==0)
    {
      printf("\nNão existe divisão por 0\n");
    }else{
    float result = 0;
    result = a/b;
    imprimirMsg(result);
    }
}

void pow(float a, float b)
{
    printf("\nPotencia\n");
    float result = a;
    for (int i = 1; i < b; i++)
    {
        result *=a;
    }
    if (b ==0)
    {
        result = 1;
    }
    
    imprimirMsg(result);
}

void imprimirMsg(float result)
{
    printf("\nO resultado é:%.2f\n",result);
}