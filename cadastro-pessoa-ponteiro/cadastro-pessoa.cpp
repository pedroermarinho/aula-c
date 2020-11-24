/*
Faça Programa que cadastre 3 pessoas Nome, cpf, ano nascimento e idade  Pesquise por CPF caso exista exiba: Nome,cpf, ano nascimento e idade. Altere os dados, Recebe Cpf, realiza a busca caso encontre O usuário poderá alterar qualquer dado cadastrado. Exclua os dados, recebe CPF se cadastra existir, exclua o cadastro da pessoa

Com ponteiro
*/
//Pedro Marinho

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct 
{
    char cpf[20];
    char nome[120];
    int ano_nascimento;
    int idade;
    bool is_valid;
} pessoa_t;

void menu();
void cadastrar(pessoa_t *pessoa1, pessoa_t *pessoa2, pessoa_t *pessoa3);
void cadastrar_pessoa(pessoa_t *pessoa);
void exibir(pessoa_t pessoa1, pessoa_t pessoa2, pessoa_t pessoa3);
void exibir_info(pessoa_t pessoa);
void excluir(pessoa_t *pessoa1, pessoa_t *pessoa2, pessoa_t *pessoa3);
void pesquisar(pessoa_t pessoa1, pessoa_t pessoa2, pessoa_t pessoa3);
void alterar(pessoa_t *pessoa1, pessoa_t *pessoa2, pessoa_t *pessoa3);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    menu();
    return 0;
}

void menu()
{
    pessoa_t pessoa1, pessoa2, pessoa3;
    do
    {
        system("cls");
        printf("\n1-Cadastrar");
        printf("\n2-Exibir");
        printf("\n3-Excluir");
        printf("\n4-Alterar");
        printf("\n5-Pesquisar");
        printf("\n0-Sair");
        printf("\n>");
        int op;
        scanf("%d", &op);
        system("cls");
        switch (op)
        {
            //Ler números
        case 1:
            cadastrar(&pessoa1, &pessoa2, &pessoa3);
            break;
            //Exibir números
        case 2:
            exibir(pessoa1, pessoa2, pessoa3);
            break;
            //Excluir número
        case 3:
            excluir(&pessoa1, &pessoa2, &pessoa3);
            break;
        case 4:
            alterar(&pessoa1, &pessoa2, &pessoa3);
            break;
        case 5:
            pesquisar(pessoa1, pessoa2, pessoa3);
            break;
            //Sair
        case 0:
            exit(1);
            break;
        default:
            break;
        }

    } while (1);
}
void cadastrar(pessoa_t *pessoa1, pessoa_t *pessoa2, pessoa_t *pessoa3)
{
    cadastrar_pessoa(pessoa1);
    cadastrar_pessoa(pessoa2);
    cadastrar_pessoa(pessoa3);
}
void cadastrar_pessoa(pessoa_t *pessoa)
{
    printf("\n----------------------------\n");
    printf("\nNome:\n");
    printf(">");
    fflush(stdin);
    gets(pessoa->nome);
    printf("\nCPF:\n");
    printf(">");
    fflush(stdin);
    gets(pessoa->cpf);
    printf("\nAno Nascimento\n");
    printf(">");
    scanf("%d", &pessoa->ano_nascimento);
    pessoa->idade = 2020 - pessoa->ano_nascimento;
    pessoa->is_valid = true;
}
void exibir(pessoa_t pessoa1, pessoa_t pessoa2, pessoa_t pessoa3)
{

    if (pessoa1.is_valid)
        exibir_info(pessoa1);

    if (pessoa2.is_valid)
        exibir_info(pessoa2);
    
    if (pessoa3.is_valid)
        exibir_info(pessoa3);
    
    printf("\n");
    system("pause");
}
void exibir_info(pessoa_t pessoa)
{
    printf("\n----------------------------\n");
    printf("\nNome:%s", pessoa.nome);
    printf("\nCPF:%s", pessoa.cpf);
    printf("\nAno de Nascimento:%d", pessoa.ano_nascimento);
    printf("\nIdade:%d", pessoa.idade);
}
void excluir(pessoa_t *pessoa1, pessoa_t *pessoa2, pessoa_t *pessoa3)
{
    int op;
    printf("\nValores disponíveis:\n");
    if (pessoa1->is_valid)
        printf("\n1 -> %s", pessoa1->nome);
    
    if (pessoa2->is_valid)
        printf("\n2 -> %s", pessoa2->nome);
    
    if (pessoa3->is_valid)
        printf("\n3 -> %s", pessoa3->nome);
    
    printf("\nSelecione uma letra:\n");
    printf(">");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        pessoa1->is_valid = false;
        printf("\n%s excluído\n", pessoa1->nome);
        break;
    case 2:
        pessoa2->is_valid = false;
        printf("\n%s excluído\n", pessoa2->nome);
        break;
    case 3:
        pessoa3->is_valid = false;
        printf("\n%s excluído\n", pessoa3->nome);
        break;

    default:
        break;
    }
    printf("\n");
    system("pause");
}
void pesquisar(pessoa_t pessoa1, pessoa_t pessoa2, pessoa_t pessoa3)
{
    char pesquisa[20];
    printf("\nPesquisar:\n");
    printf(">");
    fflush(stdin);
    gets(pesquisa);

    if (pessoa1.is_valid && strcmp(pesquisa, pessoa1.cpf) == 0)
    {
        printf("\n %s encontrado na variavel pessoa1!!!\n", pessoa1.nome);
        exibir_info(pessoa1);
    }
    else if (pessoa2.is_valid && strcmp(pesquisa, pessoa2.cpf) == 0)
    {
        printf("\n %s encontrado na variavel pessoa2!!!\n", pessoa2.nome);
        exibir_info(pessoa2);
    }
    else if (pessoa3.is_valid && strcmp(pesquisa, pessoa3.cpf) == 0)
    {
        printf("\n %s encontrado na variavel pessoa3!!!\n", pessoa3.nome);
        exibir_info(pessoa3);
    }
    else
        printf("\nValor não encontrado\n");

    printf("\n");
    system("pause");
}
void alterar(pessoa_t *pessoa1, pessoa_t *pessoa2, pessoa_t *pessoa3)
{
    int op;
    printf("\nValores disponíveis:\n");
    if (pessoa1->is_valid)
        printf("\n1 -> %s", pessoa1->nome);
    else
        printf("\n1 -> A = Sem Dados");

    if (pessoa2->is_valid)
        printf("\n1 -> %s", pessoa2->nome);
    else
        printf("\n2 -> B = Sem Dados");

    if (pessoa3->is_valid)
        printf("\n1 -> %s", pessoa3->nome);
    else
        printf("\n3 -> C = Sem Dados");

    printf("\nSelecione uma letra:\n");
    printf(">");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("\nalterar %s:\n", pessoa1->nome);
        printf(">");
        cadastrar_pessoa(pessoa1);
        break;
    case 2:
        printf("\nalterar %s:\n", pessoa2->nome);
        printf(">");
        cadastrar_pessoa(pessoa2);
        break;
    case 3:
        printf("\nalterar %s:\n", pessoa3->nome);
        printf(">");
        cadastrar_pessoa(pessoa3);
        break;

    default:
        break;
    }
}
