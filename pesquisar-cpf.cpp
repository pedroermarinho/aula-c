/*
(4) Faça programa que cadastre 2 pessoas:Nome, CPF,ano nascimento.Pesquise por CPF se existir exiba:Nome, CPF,idade e ano nascimento
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct Pessoa
{
    char nome[120];
    char cpf[20];
    int anoNascimento;
} Pessoa;

void cadastrar();
void pesquisar(Pessoa pessoa1,Pessoa pessoa2);
void imprimirMsg(Pessoa pessoa);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    cadastrar();
    getchar();
    return 0;
}
void cadastrar()
{
    Pessoa pessoa1;
    Pessoa pessoa2;
    
    printf("\n-------------------------\n");
    printf("\nNome:\n");
    printf(">");
    fflush(stdin);
    gets(pessoa1.nome);
    printf("\nCPF:\n");
    printf(">");
    fflush(stdin);
    gets(pessoa1.cpf);
    printf("\nAno de nascimento:\n");
    printf(">");
    scanf("%d",&pessoa1.anoNascimento);

    printf("\n-------------------------\n");
    printf("\nNome:\n");
    printf(">");
    fflush(stdin);
    gets(pessoa2.nome);
    printf("\nCPF:\n");
    printf(">");
    fflush(stdin);
    gets(pessoa2.cpf);
    printf("\nAno de nascimento:\n");
    printf(">");
    scanf("%d",&pessoa2.anoNascimento);


    pesquisar(pessoa1, pessoa2);
}
void pesquisar(Pessoa pessoa1,Pessoa pessoa2)
{
    char cpf[20];
    printf("\nSistema de pesquisa\n");
    printf("\nCPF:\n");
    printf(">");
    fflush(stdin);
    gets(cpf);
    if (strcmp(cpf,pessoa1.cpf)==0)
    {
        imprimirMsg(pessoa1);
    }
    if (strcmp(cpf,pessoa2.cpf)==0)
    {
        imprimirMsg(pessoa2);
    }
    
}
void imprimirMsg(Pessoa pessoa)
{
    printf("\nInformações\n");
    printf("\nNome:%s",pessoa.nome);
    printf("\nCPF:%s",pessoa.cpf);
    printf("\nAno de Nascimento:%d",pessoa.anoNascimento);
    printf("\nIdade:%d",(2019-pessoa.anoNascimento));
}