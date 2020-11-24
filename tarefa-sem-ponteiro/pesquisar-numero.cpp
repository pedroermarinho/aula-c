/*
(1)Faça um programa que cadastre 2 números,pesquise número se existir exiba,senão exiba mensagem número não cadastrado 
*/
//Pedro Marinho
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void cadastrar();
void pesquisar(int num1, int num2);
void result_msg(int result);
void result_msg();

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    cadastrar();
    getchar();
    return 0;
}

void cadastrar()
{
    int num1;
    int num2;
    printf("\nDigite um número:\n");
    printf(">");
    scanf("%d", &num1);
    printf("\nDigite outro número:\n");
    printf(">");
    scanf("%d", &num2);
    pesquisar(num1, num2);
}
void pesquisar(int num1, int num2)
{
    int pesquisa;
    printf("\nDigite um número para ser pesquisado:\n");
    printf(">");
    scanf("%d", &pesquisa);
    if (pesquisa == num1 || pesquisa == num2)
        result_msg(pesquisa);
    else
        result_msg();
}
void result_msg(int result)
{
    printf("\nNúmero %d encontrado\n", result);
}
void result_msg()
{
    printf("\nNúmero não encontrado\n");
}