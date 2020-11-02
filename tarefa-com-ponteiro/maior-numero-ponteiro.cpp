/*
(2)faça programa que cadastre 3 números e exiba maior dentre eles

Com ponteiro
*/
//Pedro Marinhos
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void cadastrar(int *a, int *b, int *c);
void maior_numero(int a, int b, int c, int *result);
void result_msg(int result);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int a = 0, b = 0, c = 0, result = 0;
    cadastrar(&a, &b, &c);
    maior_numero(a, b, c, &result);
    result_msg(result);
    getchar();
    return 0;
}
void cadastrar(int *a, int *b, int *c)
{

    printf("\nDigite um número:\n");
    printf(">");
    scanf("%d", a);
    printf("\nDigite outro número:\n");
    printf(">");
    scanf("%d", b);
    printf("\nDigite mais um número:\n");
    printf(">");
    scanf("%d", c);
}
void maior_numero(int a, int b, int c, int *result)
{
    *result = a;

    if (*result < b)
    {
        *result = b;
    }
    if (*result < c)
    {
        *result = c;
    }
}
void result_msg(int result)
{
    printf("\n%d é o maior número encontrado\n", result);
}