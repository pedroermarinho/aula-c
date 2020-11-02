/*
Calculadora:soma, subtração, multiplicação, divisão e potencia 
*/
//Pedro Marinho
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu();
void soma(float num1, float num2);
void sub(float num1, float num2);
void mult(float num1, float num2);
void div(float num1, float num2);
void pow(float num1, float num2);
void result_msg(float result);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    menu();
    getchar();
    return 0;
}

void menu()
{
    float num1,num2;
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
        scanf("%f",&num1);
        printf("\nDigite o expoente\n");
        printf(">");
        scanf("%f",&num2);
    }else
    {
        printf("\nDigite um número\n");
        printf(">");
        scanf("%f",&num1);
        printf("\nDigite outro número\n");
        printf(">");
        scanf("%f",&num2);
    }
    
    

    switch (op)
    {
        //1 - soma
    case 1:
        soma(num1,num2);
        break;
        //2 - subtração
    case 2:
        sub(num1,num2);
        break;
        //3 - multiplicação
    case 3:
        mult(num1,num2);
        break;
        //4 - divisão
    case 4:
        div(num1,num2);
        break;
        //5 - potencia
    case 5:
        pow(num1,num2);
        break;
    
    default:
        break;
    }

    
}

void soma(float num1, float num2)
{
    printf("\nSoma\n");
    float result = 0;
    result = num1+num2;
    result_msg(result);
}

void sub(float num1, float num2)
{
    printf("\nSubtração\n");
    float result = 0;
    result = num1-num2;
    result_msg(result);
}

void mult(float num1, float num2)
{
    printf("\nMultiplicação\n");
    float result = 0;
    result = num1*num2;
    result_msg(result);
}

void div(float num1, float num2)
{
    printf("\nDivisão\n");
    if (num2 ==0)
    {
      printf("\nNão existe divisão por 0\n");
    }else{
    float result = 0;
    result = num1/num2;
    result_msg(result);
    }
}

void pow(float num1, float num2)
{
    printf("\nPotencia\n");
    float result = num1;
    for (int i = 1; i < num2; i++)
    {
        result *=num1;
    }
    if (num2 ==0)
    {
        result = 1;
    }
    
    result_msg(result);
}

void result_msg(float result)
{
    printf("\nO resultado é:%.2f\n",result);
}