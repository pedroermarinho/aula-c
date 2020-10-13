/*
(1)Faça um programa que cadastre 2 números,pesquise número se existir exiba,senão exiba mensagem número não cadastrado 
*/
//Pedro Marinho
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void setNum();
void pesquisar(int a, int b);
void imprimirMsg(int x);
void imprimirMsg();

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    setNum();
    getchar();
    return 0;
}

void setNum()
{
    int a;
    int b;
    printf("\nDigite um número:\n");
    printf(">");
    scanf("%d", &a);
    printf("\nDigite outro número:\n");
    printf(">");
    scanf("%d", &b);
    pesquisar(a, b);
}
void pesquisar(int a, int b)
{
    int pesquisa;
    printf("\nDigite um número para ser pesquisado:\n");
    printf(">");
    scanf("%d", &pesquisa);
    if (pesquisa == a || pesquisa == b)
    {
        imprimirMsg(pesquisa);
    }
    else
    {
        imprimirMsg();
    }
}
void imprimirMsg(int x)
{
    printf("\nNúmero %d encontrado\n", x);
}
void imprimirMsg()
{
    printf("\nNúmero não encontrado\n");
}