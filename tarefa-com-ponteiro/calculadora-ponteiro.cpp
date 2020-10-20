/*
Calculadora:soma, subtração, multiplicação, divisão e potencia 

Com ponteiro
*/
//Pedro Marinho
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu();
void setNum(float *a, float *b, int op);
void soma(float a, float b, float *result);
void sub(float a, float b, float *result);
void mult(float a, float b, float *result);
void div(float a, float b, float *result);
void pow(float a, float b, float *result);
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
    float a, b, result;
    do
    {
        a = 0;
        b = 0;
        result = 0;
        int isValid = 1;
        system("cls");

        printf("\nMenu de Operações\n");
        printf("\n1 - soma");
        printf("\n2 - subtração");
        printf("\n3 - multiplicação");
        printf("\n4 - divisão");
        printf("\n5 - potencia");
        printf("\n6 - sair");

        int op;
        printf("\nEscolha uma opção:\n");
        printf(">");
        scanf("%d", &op);
        
        if (op !=6)
        {
           setNum(&a,&b,op);
        }
        
        

        switch (op)
        {
            //1 - soma
        case 1:
            soma(a, b, &result);
            break;
            //2 - subtração
        case 2:
            sub(a, b, &result);
            break;
            //3 - multiplicação
        case 3:
            mult(a, b, &result);
            break;
            //4 - divisão
        case 4:
            div(a, b, &result);
            break;
            //5 - potencia
        case 5:
            pow(a, b, &result);
            break;
            //6 - sair
        case 6:
            exit(1);
            break;

        default:
            isValid = 0;
            break;
        }
        if (isValid)
        {
            imprimirMsg(result);
        }

        system("pause"); 
    } while (1);
}

void setNum(float *a, float *b, int op)
{
    
    if (op == 5)
    {
        printf("\nDigite um número\n");
        printf(">");
        scanf("%f",a);
        printf("\nDigite o expoente\n");
        printf(">");
        scanf("%f",b);
    }
    else
    {
        printf("\nDigite um número\n");
        printf(">");
        scanf("%f", a);
        printf("\nDigite outro número\n");
        printf(">");
        scanf("%f", b);
    }
 
}

void soma(float a, float b, float *result)
{
    printf("\nSoma\n");
    *result = a + b;
}

void sub(float a, float b, float *result)
{
    printf("\nSubtração\n");
    *result = a - b;
}

void mult(float a, float b, float *result)
{
    printf("\nMultiplicação\n");
    *result = a * b;
}

void div(float a, float b, float *result)
{
    printf("\nDivisão\n");
    if (b == 0)
    {
        printf("\nNão existe divisão por 0\n");
    }
    else
    {
        *result = a / b;
    }
}

void pow(float a, float b, float *result)
{
    printf("\nPotencia\n");
    *result = a;
    for (int i = 1; i < b; i++)
    {
        *result *= a;
    }
    if (b == 0)
    {
        *result = 1;
    }
}

void imprimirMsg(float result)
{
    printf("\nO resultado é:%.2f\n", result);
}