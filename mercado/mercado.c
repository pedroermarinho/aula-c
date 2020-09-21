#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 5

typedef struct Funcionario
{
    char nome[120];
    char matricula[5];
} Funcionario;

typedef struct Produto
{
    char nprod[120];
    int quant;
    float valor;
    int vendidos;
} Produto;

void limparTela();
void limparPausarTela();
void cadastrarProdutos(Produto produtos[MAX]);
void gerarProdutos(Produto produtos[MAX]);
void cadastrarFuncionarios(Funcionario funcionarios[MAX]);
void gerarFuncionarios(Funcionario funcionario[MAX]);
void salvarDadosProdutos(Produto produtos[MAX]);
int recuperarDadosProdutos(Produto produtos[5]);
void salvarDadosFuncionarios(Funcionario funcionarisos[MAX]);
int recuperarDadosFuncionarios(Funcionario funcionarios[5]);
void infoFuncionario(Funcionario funcionario);
void infoProduto(Produto produto);
void cadastrarProdutos(Produto produtos[MAX]);
int selectAdmOrFuncionario();

int main(void)
{ //inicio do algoritmo
    setlocale(LC_ALL, "Portuguese");
    Produto produtos[MAX];
    Funcionario funcionarios[MAX];

    int isValidProdutos;
    int isValidFuncionarios;

    int selectFuncionario;
    int selectProduto;

    if (recuperarDadosProdutos(produtos))
    {
        isValidProdutos = 1;
    }

    if (recuperarDadosFuncionarios(funcionarios))
    {
        isValidFuncionarios = 1;
    }

    int opMenu;
    int i;

    printf("\n_____________________________________________________\n");
    if (selectAdmOrFuncionario())
    {
        int isSelectFuncionario = 0;
        limparTela();

        do
        {

            printf("\n--Funcionario--\n");
            if (isSelectFuncionario)
            {
                printf("\nFuncionario Selecionado: %s\n", funcionarios[selectFuncionario].nome);
            }

            printf("\n1- Selecionar Funcionarios");
            printf("\n2- Sistema de Vendas");
            printf("\n3- Salvar Dados");
            printf("\n0- Sair ");

            int isValid;
            do
            {
                isValid = 1;
                printf("\nEscolha uma opção:");
                scanf("%d", &opMenu);

                switch (opMenu)
                {
                //3- Salvar dados
                case 1:
                    limparTela();
                    printf("\nFuncionarios\n");

                    for (i = 0; i < MAX; i++)
                    {
                        printf("\n%d - %s", i, funcionarios[i].nome);
                    }
                    do
                    {
                        printf("\nSelecione o funcionario do balcao: ");
                        scanf("%d", &selectFuncionario);
                    } while ((selectFuncionario > MAX - 1 || selectFuncionario < 0));
                    isSelectFuncionario = 1;
                    limparPausarTela();
                    break;
                //2- Sistema de Vendas
                case 2:
                    limparTela();
                    printf("\nSistema de Vendas\n");
                    if (isSelectFuncionario)
                    {

                        limparTela();
                        printf("\nDados do funcionario selecionado\n");

                        infoFuncionario(funcionarios[selectFuncionario]);

                        limparPausarTela();

                        printf("\nProdutos\n");

                        for (i = 0; i < MAX; i++)
                        {
                            printf("\n%d - %s", i, produtos[i]);
                        }

                        do
                        {
                            printf("\nSelecione o funcionario do balcao: ");
                            scanf("%d", &selectProduto);
                        } while ((selectProduto > MAX - 1 || selectProduto < 0));

                        limparTela();
                        printf("\nDados do produto selecionado\n");
                        infoProduto(produtos[selectProduto]);

                        printf("\n\n");

                        int quantidadeProduto;
                        do
                        {
                            printf("\nQuantidade desejada:");
                            scanf("%d", &quantidadeProduto);
                        } while (quantidadeProduto < 0 || quantidadeProduto > produtos[selectProduto].quant);

                        produtos[selectFuncionario].vendidos += quantidadeProduto;
                        produtos[selectFuncionario].quant -= quantidadeProduto;

                        limparTela();
                        float valorTotal = quantidadeProduto * produtos[selectFuncionario].valor;
                        printf("\nValor total: %.2f\n", valorTotal);

                        float valorPago;
                        do
                        {
                            printf("\nValor pago pelo cliente:");
                            scanf("%f", &valorPago);
                            if (valorPago < valorTotal)
                            {
                                printf("\nO valor pago não pode ser menor que o valor total\n");
                            }

                        } while (valorPago < valorTotal);

                        float valorTroco = valorPago - valorTotal;
                        printf("\nValor do troco a ser devolvido ao cliente:%.2f", valorTroco);
                        limparPausarTela();
                        /* code */
                    }
                    else
                    {
                        printf("\nNenhum funcionarios selecionado, volte ao menu principal e selecione um funcionario\n");
                        limparPausarTela();
                    }

                    

                    break;
                //3- Salvar dados
                case 3:
                    limparTela();
                    salvarDadosProdutos(produtos);
                    salvarDadosFuncionarios(funcionarios);
                    limparPausarTela();
                    break;
                //0- Sair
                case 0:
                    limparTela();
                    exit(1);
                    break;

                default:
                    isValid = 0;
                    printf(" Opção invalida, escolha outra opção:");
                    break;
                }

            } while (!isValid);

        } while (1);
    }
    else
    {

        do
        {
            printf("\n--Administrador--\n");

            printf("\n1- Cadastros");
            printf("\n2- Informações");
            printf("\n3- Relatorios de Vendas");
            printf("\n4- Salvar Dados");
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
                //2- Informações
                case 2:
                    limparTela();
                    printf("\n1- Funcionarios");
                    printf("\n2- Produtos");
                    printf("\n0- Sair");

                    do
                    {
                        isValid = 1;
                        printf("\nEscolha uma opção:");
                        scanf("%d", &opMenu);
                        switch (opMenu)
                        {
                        //1- Funcionarios
                        case 1:
                            limparTela();
                            int i;
                            for (i = 0; i < 5; i++)
                            {
                                printf("\n________________________\n");
                                infoFuncionario(funcionarios[i]);
                            }
                            limparPausarTela();
                            break;
                        //2- Produtos
                        case 2:
                            limparTela();
                            for (i = 0; i < 5; i++)
                            {
                                printf("\n________________________\n");
                                infoProduto(produtos[i]);
                            }
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
                //3- Relatorios de vendas
                case 3:
                    limparTela();
                    printf("\nRelatorios de Vendas\n");
                    for (i = 0; i < MAX; i++)
                    {
                        if (produtos[i].vendidos > 0)
                        {
                            printf("\n--------------------------------------\n");
                            printf("\nProduto\t\t\t:%s", produtos[i].nprod);
                            printf("\nValor\t\t\t:%2.f", produtos[i].valor);
                            printf("\nQuantidade\t\t:%d", produtos[i].quant);
                            printf("\nQuantidade vendidos\t:%d", produtos[i].vendidos);
                            printf("\nValor total arrecadado\t:%.2f", produtos[i].valor * produtos[i].vendidos);
                        }
                    }

                    limparPausarTela();
                    break;
                //3- Salvar dados
                case 4:
                    limparTela();
                    salvarDadosProdutos(produtos);
                    salvarDadosFuncionarios(funcionarios);
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
    }

} //fim do main

void limparTela()
{
#ifdef __WIN32
    system("cls");
#else
    system("clear");
#endif
}

void limparPausarTela()
{
    printf("\n\n");
#ifdef __WIN32
    system("pause");
#else
    system("read -p \"Pressione enter para continuar\" saindo");
#endif

    limparTela();
}

void infoProduto(Produto produto)
{
    printf("\nNome produto\t\t: %s", produto.nprod);
    printf("\nValor do produto\t: %.2f", produto.valor);
    printf("\nQuantidade\t\t: %d", produto.quant);
}

void infoFuncionario(Funcionario funcionario)
{
    printf("\nNome do funcionario\t:  %s", funcionario.nome);
    printf("\nMatricula\t\t:  %s", funcionario.matricula);
}

void cadastrarProdutos(Produto produtos[MAX])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("\n___________________________________________\n");
        printf("Nome\t\t:");
        scanf("%s", &produtos[i].nprod);

        do
        {
            printf("Valor\t\t:");
            scanf("%f", &produtos[i].valor);
            if (produtos[i].valor <= 0)
            {
                printf("O valor tem que ser maior que 0\n");
            }
        } while (produtos[i].valor <= 0);

        do
        {
            printf("Quantidade\t:");
            scanf("%d", &produtos[i].quant);
            if (produtos[i].quant <= 0)
            {
                printf("A quantidade tem que ser maior que 0\n");
            }
        } while (produtos[i].quant <= 0);

        produtos[i].vendidos = 0;
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

        printf("Matricula\t:");
        scanf("%s", &funcionarios[i].matricula);
    }
}
void gerarProdutos(Produto produtos[MAX])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        sprintf(produtos[i].nprod, "Produto %d", i);
        produtos[i].quant = i + 10;
        produtos[i].valor = i + 100;
        produtos[i].vendidos = 0;
    }
    printf("\nProdutos gerados Automaticamente\n");
}

void gerarFuncionarios(Funcionario funcionario[MAX])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        sprintf(funcionario[i].nome, "Funcionario %d", i);
        sprintf(funcionario[i].matricula, "%d%d%d", i, i, i);
    }
    printf("\nFuncionarios gerados Automaticamente\n");
}

void salvarDadosProdutos(Produto produtos[MAX])
{
    FILE *arquivo;
    arquivo = fopen("produtos.bin", "wb");
    if (arquivo != NULL)
    {
        int i;
        for (i = 0; i < MAX; i++)
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

int recuperarDadosProdutos(Produto produtos[MAX])
{

    FILE *arquivo = fopen("produtos.bin", "rb"); //criando um arquivo para salvar nossos dados

    if (arquivo != NULL) //se o arquivo existir
    {
        int i;
        for (i = 0; i < MAX; i++)
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
        for (i = 0; i < MAX; i++)
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

int recuperarDadosFuncionarios(Funcionario funcionarios[MAX])
{

    FILE *arquivo = fopen("funcionarios.bin", "rb");

    if (arquivo != NULL)
    {
        int i;
        for (i = 0; i < MAX; i++)
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

int selectAdmOrFuncionario()
{
    printf("\nLongar como:");
    printf("\n1 - Administrador");
    printf("\n2 - Funcionario");
    printf("\n0 - Sair");
    int op;
    int isValid;
    do
    {
        isValid = 1;
        printf("\nSelecione uma opção:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            limparTela();
            return 0;
            break;
        case 2:
            limparTela();
            return 1;
            break;
        case 0:
            limparTela();
            exit(0);
            break;
        default:
            isValid = 0;
            break;
        }
    } while (!isValid);
}
