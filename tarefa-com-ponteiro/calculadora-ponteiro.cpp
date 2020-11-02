/*
Calculadora:soma, subtração, multiplicação, divisão e potencia 

Com ponteiro
*/
//Pedro Marinho
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu();
void cadastrar(float *num1, float *num2, int op);
void soma(float num1, float num2, float *result);
void sub(float num1, float num2, float *result);
void mult(float num1, float num2, float *result);
void div(float num1, float num2, float *result);
void pow(float num1, float num2, float *result);
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
    float num1, num2, result;
    do
    {
        num1 = 0;
        num2 = 0;
        result = 0;
        int is_valid = 1;
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
           cadastrar(&num1,&num2,op);
        }
        
        

        switch (op)
        {
            //1 - soma
        case 1:
            soma(num1, num2, &result);
            break;
            //2 - subtração
        case 2:
            sub(num1, num2, &result);
            break;
            //3 - multiplicação
        case 3:
            mult(num1, num2, &result);
            break;
            //4 - divisão
        case 4:
            div(num1, num2, &result);
            break;
            //5 - potencia
        case 5:
            pow(num1, num2, &result);
            break;
            //6 - sair
        case 6:
            exit(1);
            break;

        default:
            is_valid = 0;
            break;
        }
        if (is_valid)
        {
            result_msg(result);
        }

        system("pause"); 
    } while (1);
}

void cadastrar(float *num1, float *num2, int op)
{
    
    if (op == 5)
    {
        printf("\nDigite um número\n");
        printf(">");
        scanf("%f",num1);
        printf("\nDigite o expoente\n");
        printf(">");
        scanf("%f",num2);
    }
    else
    {
        printf("\nDigite um número\n");
        printf(">");
        scanf("%f", num1);
        printf("\nDigite outro número\n");
        printf(">");
        scanf("%f", num2);
    }
 
}

void soma(float num1, float num2, float *result)
{
    printf("\nSoma\n");
    *result = num1 + num2;
}

void sub(float num1, float num2, float *result)
{
    printf("\nSubtração\n");
    *result = num1 - num2;
}

void mult(float num1, float num2, float *result)
{
    printf("\nMultiplicação\n");
    *result = num1 * num2;
}

void div(float num1, float num2, float *result)
{
    printf("\nDivisão\n");
    if (num2 == 0)
    {
        printf("\nNão existe divisão por 0\n");
    }
    else
    {
        *result = num1 / num2;
    }
}

void pow(float num1, float num2, float *result)
{
    printf("\nPotencia\n");
    *result = num1;
    for (int i = 1; i < num2; i++)
    {
        *result *= num1;
    }
    if (num2 == 0)
    {
        *result = 1;
    }
}

void result_msg(float result)
{
    printf("\nO resultado é:%.2f\n", result);
}