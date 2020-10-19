/*
(3) Faça um programa que cadastre nome, peso,altura de uma pessoa e exiba os dados e I.M.C e a classificação

Com ponteiro
*/
//Pedro Marinho
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Pessoa
{
    char nome[120];
    float peso;
    float altura;
    float imc;
} Pessoa;

void cadastrar(Pessoa *pessoa);
void calcIMC(Pessoa *pessoa);
void imprimirMsgIMC(Pessoa pessoa);
void imprimirMsg(Pessoa pessoa);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Pessoa pessoa;
    cadastrar(&pessoa);
    calcIMC(&pessoa);
    imprimirMsgIMC(pessoa);
    imprimirMsg(pessoa);
    getchar();
    return 0;
}
void cadastrar(Pessoa *pessoa)
{
    
    
    printf("\nNome:\n");
    printf(">");
    fflush(stdin);
    gets(pessoa->nome);
    printf("\nAltura:\n");
    printf(">");
    scanf("%f",&pessoa->altura);
    printf("\nPeso:\n");
    printf(">");
    scanf("%f",&pessoa->peso);
    
}
void calcIMC(Pessoa *pessoa)
{
    pessoa->imc = pessoa->peso /(pessoa->altura*pessoa->altura);
}
void imprimirMsgIMC(Pessoa pessoa)
{
    printf("\nSeu IMC é %.1f\n",pessoa.imc);
}
void imprimirMsg(Pessoa pessoa)
{
    printf("\nOla %s, seu status está logo a baixo\n",pessoa.nome);
    if (pessoa.imc<18.5)
    {
        printf("\nAbaixo do peso\n");
    }else if(pessoa.imc >= 18.5 && pessoa.imc < 25){
        printf("\nPeso normal\n");
    }else if(pessoa.imc >= 25 && pessoa.imc < 30){
        printf("\nSobrepeso\n");
    }else if(pessoa.imc >= 30 && pessoa.imc < 35){
        printf("\nObesidade grau 1\n");
    }else if(pessoa.imc >= 35 && pessoa.imc < 40){
        printf("\nObesidade grau 2\n");
    }else if(pessoa.imc >= 40){
        printf("\nObesidade grau 3\n");
    }
    
}