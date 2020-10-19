/*
(2)faça programa que cadastre 3 números e exiba maior dentre eles

Com ponteiro
*/
//Pedro Marinhos
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void setNum(int *a, int *b, int *c);
void maiorNumero(int a, int b, int c, int *maior);
void imprimirMsg(int x);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    int a = 0, b = 0, c = 0, maior = 0;
    setNum(&a, &b, &c);
    maiorNumero(a, b, c, &maior);
    imprimirMsg(maior);
    getchar();
    return 0;
}
void setNum(int *a, int *b, int *c)
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
void maiorNumero(int a, int b, int c, int *maior)
{
    *maior = a;

    if (*maior < b)
    {
        *maior = b;
    }
    if (*maior < c)
    {
        *maior = c;
    }
}
void imprimirMsg(int x)
{
    printf("\n%d é o maior número encontrado\n", x);
}