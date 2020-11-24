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

        void (*func[])(float, float, float *) = {
            soma,
            sub,
            mult,
            div,
            pow};

        printf("\nMenu de Operações\n");
        printf("\n0 - soma");
        printf("\n1 - subtração");
        printf("\n2 - multiplicação");
        printf("\n3 - divisão");
        printf("\n4 - potencia");
        printf("\n5 - sair");

        int op;
        do
        {

            printf("\nEscolha uma opção:\n");
            printf(">");
            scanf("%d", &op);
            /* code */
        } while (op < 0 || op > 5);

        if (op == 5)
            exit(1);

        cadastrar(&num1, &num2, op);
        func[op](num1, num2, &result);
        result_msg(result);

        system("pause");
    } while (1);
}

void cadastrar(float *num1, float *num2, int op)
{
    printf("\nDigite um número\n");
    printf(">");
    scanf("%f", num1);
    printf(op == 5 ?"\nDigite o expoente\n":"\nDigite outro número\n");
    printf(">");
    scanf("%f", num2);
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
        printf("\nNão existe divisão por 0\n");
    else
        *result = num1 / num2;
    
}

void pow(float num1, float num2, float *result)
{
    printf("\nPotencia\n");
    *result = num1;
    for (int i = 1; i < num2; i++)
        *result *= num1;

    if (num2 == 0)
        *result = 1;
}

void result_msg(float result)
{
    printf("\nO resultado é:%.2f\n", result);
}