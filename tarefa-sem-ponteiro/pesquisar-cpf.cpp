/*
(4) Faça programa que cadastre 2 pessoas:Nome, CPF,ano nascimento.Pesquise por CPF se existir exiba:Nome, CPF,idade e ano nascimento
*/
//Pedro Marinho
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct 
{
    char nome[120];
    char cpf[20];
    int ano_nascimento;
} pessoa_t;

void cadastrar();
void pesquisar(pessoa_t pessoa1,pessoa_t pessoa2);
void result_msg(pessoa_t pessoa);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    cadastrar();
    getchar();
    return 0;
}
void cadastrar()
{
    pessoa_t pessoa1;
    pessoa_t pessoa2;
    
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
    scanf("%d",&pessoa1.ano_nascimento);

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
    scanf("%d",&pessoa2.ano_nascimento);


    pesquisar(pessoa1, pessoa2);
}
void pesquisar(pessoa_t pessoa1,pessoa_t pessoa2)
{
    char cpf[20];
    printf("\nSistema de pesquisa\n");
    printf("\nCPF:\n");
    printf(">");
    fflush(stdin);
    gets(cpf);
    if (strcmp(cpf,pessoa1.cpf)==0)
    {
        result_msg(pessoa1);
    }
    if (strcmp(cpf,pessoa2.cpf)==0)
    {
        result_msg(pessoa2);
    }
    
}
void result_msg(pessoa_t pessoa)
{
    printf("\nInformações\n");
    printf("\nNome:%s",pessoa.nome);
    printf("\nCPF:%s",pessoa.cpf);
    printf("\nAno de Nascimento:%d",pessoa.ano_nascimento);
    printf("\nIdade:%d",(2019-pessoa.ano_nascimento));
}