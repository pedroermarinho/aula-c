#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 20

typedef struct Funcionario
{
    char nome[10];
    char matricula;
} Funcionario;

typedef struct Produto
{
    char nprod[10];
    int quant;
    float valor;
} Produto;

void limparPausarTela();
void limparTela();
void cadastrarProdutos(Produto produtos[MAX]);
void gerarProdutos(Produto produtos[MAX]);
void cadastrarFuncionarios(Funcionario funcionarios[MAX]);
void gerarFuncionario(Funcionario funcionario[MAX]);
void salvarDadosProduto(Produto produtos[MAX]);
void salvarDadosProduto(Produto produtos[MAX]);
int recuperarDadosProdutos(Produto produtos[5]);
void salvarDadosFuncionarios(Funcionario funcionarisos[MAX]);
int recuperarDadosFuncionarios(Funcionario funcionarios[5]);

int main(void)
{ //inicio do algoritmo
    setlocale(LC_ALL, "Portuguese");
    Produto produtos[MAX];
    Funcionario funcionarios[MAX];

    int isValidProdutos;
    int isValidFuncionarios;

    recuperarDadosProdutos(produtos);
    recuperarDadosFuncionarios(funcionarios);


    int opMenu;

    printf("\n_____________________________________________________\n");
    do
    {

        printf("\n1- Cadastros");
        printf("\n2- Sistema de Vendas");
        printf("\n0- Sair ");

        int isValid;
        do
        {
            isValid = 1;
            printf("\nEscolha uma opção:");
            scanf("%d", &opMenu);

            switch (opMenu)
            {
            case 1:
                limparTela();
                printf("\n1- Produtos");
                printf("\n2- Funcionarios");
                printf("\n0- Sair");

                do
                {
                    isValid = 1;
                    printf("\nEscolha uma opção:");
                    scanf("%d", &opMenu);
                    switch (opMenu)
                    {
                    //1- Produto
                    case 1:
                        limparTela();
                        printf("\n1- Gerar Produtos");
                        printf("\n2- Cadastrar Produtos");
                        printf("\n0- Sair");

                        do
                        {
                            isValid = 1;
                            printf("\nEscolha uma opção:");
                            scanf("%d", &opMenu);
                            switch (opMenu)
                            {
                            //1- Gerar Produtos
                            case 1:
                                limparTela();
                                gerarProdutos(produtos);
                                limparPausarTela();
                                break;
                            //2- Cadastrar Produtos
                            case 2:
                                limparTela();
                                cadastrarProdutos(produtos);
                                limparPausarTela();
                                break;
                            //0- Sair
                            case 0:
                                limparTela();

                                break;
                            default:
                                isValid = 0;
                                break;
                            }
                        } while (!isValid);
                        limparPausarTela();
                        break;
                    //2- Funcionario
                    case 2:
                        limparTela();
                        printf("\n1- Gerar Funcionarios");
                        printf("\n2- Cadastrar Funcionarios");
                        printf("\n0- Sair");

                        do
                        {
                            isValid = 1;
                            printf("\nEscolha uma opção:");
                            scanf("%d", &opMenu);
                            switch (opMenu)
                            {
                            //1- Gerar Produtos
                            case 1:
                                limparTela();
                                gerarFuncionarios(funcionarios);
                                limparPausarTela();
                                break;
                            //2- Cadastrar Produtos
                            case 2:
                                limparTela();
                                cadastrarFuncionarios(funcionarios);
                                limparPausarTela();
                                break;
                            //0- Sair
                            case 0:
                                limparTela();

                                break;
                            default:
                                isValid = 0;
                                break;
                            }
                        } while (!isValid);
                        limparPausarTela();
                        break;
                    //0- Sair
                    case 0:
                        limparTela();

                        break;
                    default:
                        isValid = 0;
                        break;
                    }
                } while (!isValid);

                break;
            //2- Sistema de Vendas
            case 2:
                limparTela();
                printf("indisponivel");
                limparPausarTela();
                break;
            //0- Sair
            case 0:
                limparTela();
                exit(1);
                break;

            default:
                isValid = 0;
                printf("Opção invalida, escolha outra opção:");
                break;
            }

        } while (!isValid);

    } while (1);

} //fim do main

void limparPausarTela()
{
    printf("\n\n");
    system("pause");
    system("CLS");
}

void limparTela()
{
    system("cls");
}

void infoProduto(Produto produto)
{
    printf("\nNome produto %s", produto.nprod);
    printf("\nValor do produto %f", produto.valor);
    printf("\nQuantidade solicitada %d", produto.quant);
}

void infoFuncionario(Funcionario funcionario)
{
    printf("\nNome do funcionario:  %s", funcionario.nome);
    printf("\nMatricula:  %f", funcionario.matricula);
}

void cadastrarProdutos(Produto produtos[MAX])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("\n___________________________________________\n");
        printf("Nome\t\t:");
        scanf("%s", &produtos[i].nprod);

        printf("Valor\t\t:");
        scanf("%f", &produtos[i].valor);

        printf("Quantidade solicitada\t:");
        scanf("%d", &produtos[i].quant);
    }
}

void cadastrarFuncionarios(Funcionario funcionarios[MAX])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("\n___________________________________________\n");
        printf("Nome\t\t:");
        scanf("%s", &funcionarios[i].nome);

        printf("Matricula\t\t:");
        scanf("%d", &funcionarios[i].matricula);
    }
}
void gerarProdutos(Produto produtos[MAX])
{
    int i;
    for (i = 0; i < 20; i++)
    {
        sprintf(produtos[i].nprod, "Produto %d", i);
        produtos[i].quant = i;
        produtos[i].valor = i;
    }
}

void gerarFuncionario(Funcionario funcionario[MAX])
{
    int i;
    for (i = 0; i < 20; i++)
    {
        sprintf(funcionario[i].nome, "Funcionario %d", i);
        funcionario[i].matricula = i;
    }
}

void salvarDadosProduto(Produto produtos[MAX])
{
    FILE *arquivo;
    arquivo = fopen("protudos.bin", "wb");
    if (arquivo != NULL)
    {
        int i;
        for (i = 0; i < 5; i++)
        {
            fwrite(&produtos[i], sizeof(Produto), sizeof(produtos[i]), arquivo);
        }
        fclose(arquivo);
        printf("\nDados dos Carros salvos\n");
    }
    else
    {
        printf("\nErro ao salvar os dados dos Pr\n");
    }
}

int recuperarDadosProdutos(Produto produtos[5])
{

    FILE *arquivo = fopen("produtos.bin", "rb"); //criando um arquivo para salvar nossos dados

    if (arquivo != NULL) //se o arquivo existir
    {
        int i;
        for (i = 0; i < 5; i++)
        {
            Produto produto;

            int tamanhoArquivo = fread(&produto, sizeof(Produto), 1, arquivo);

            if (tamanhoArquivo < 1)
                break;
            else
                produtos[i] = produto;
        }
        fclose(arquivo); // fecha o arquivo
        printf("\nDados dos Produtos recuperados\n");
        return 1; 
    }
    else //se o arquivo nao existir
    {
        printf("\nErro ao ler os dados dos produto\n");
        return 0;
    }
}

void salvarDadosFuncionarios(Funcionario funcionarisos[MAX])
{
    FILE *arquivo;
    arquivo = fopen("funcionarios.bin", "wb");
    if (arquivo != NULL)
    {
        int i;
        for (i = 0; i < 5; i++)
        {
            fwrite(&funcionarisos[i], sizeof(Funcionario), sizeof(funcionarisos[i]), arquivo);
        }
        fclose(arquivo);
        printf("\nDados dos Funcionarios salvos\n");
    }
    else
    {
        printf("\nErro ao salvar os dados dos Funcionarios\n");
    }
}

int recuperarDadosFuncionarios(Funcionario funcionarios[5])
{

    FILE *arquivo = fopen("funcionarios.bin", "rb");

    if (arquivo != NULL)
    {
        int i;
        for (i = 0; i < 5; i++)
        {
            Funcionario funcionario;

            int tamanhoArquivo = fread(&funcionario, sizeof(Funcionario), 1, arquivo);

            if (tamanhoArquivo < 1)
                break;
            else
                funcionarios[i] = funcionario;
        }
        fclose(arquivo); // fecha o arquivo
        printf("\nDados dos Produtos recuperados\n");
        return 1;
    }
    else
    {
        printf("\nErro ao ler os dados dos protudo\n");
        return 0;
    }
}
