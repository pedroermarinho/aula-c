#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 5

typedef struct 
{
    char nome[120];
    char matricula[5];
} funcionario_t;

typedef struct 
{
    char nprod[120];
    int quant;
    float valor;
    int vendidos;
} produto_t;

void limpar_tela();
void pausar_limpar_tela();
void cadastrar_produtos(produto_t produto_vet[MAX]);
void gerar_produtos(produto_t produto_vet[MAX]);
void cadastrar_funcionarios(funcionario_t funcionario_vet[MAX]);
void gerar_funcionarios(funcionario_t funcionario[MAX]);
void salvar_dados_produtos(produto_t produto_vet[MAX]);
int recuperar_dados_produtos(produto_t produto_vet[5]);
void salvarDadosFuncionarios(funcionario_t funcionario_vet[MAX]);
int recuperar_dados_funcionarios(funcionario_t funcionario_vet[5]);
void info_funcionario(funcionario_t funcionario);
void info_produto(produto_t produto);
void cadastrar_produtos(produto_t produto_vet[MAX]);
int select_adm_or_funcionario();

int main(void)
{ //inicio do algoritmo
    setlocale(LC_ALL, "Portuguese");
    produto_t produto_vet[MAX];
    funcionario_t funcionario_vet[MAX];

    int is_valid_produtos;
    int is_valid_funcionarios;

    int select_funcionario;
    int select_produto;

    if (recuperar_dados_produtos(produto_vet))
    {
        is_valid_produtos = 1;
    }

    if (recuperar_dados_funcionarios(funcionario_vet))
    {
        is_valid_funcionarios = 1;
    }

    int op_menu;
    int i;

    printf("\n_____________________________________________________\n");
    if (select_adm_or_funcionario())
    {
        int is_select_funcionario = 0;
        limpar_tela();

        do
        {

            printf("\n--Funcionario--\n");
            if (is_select_funcionario)
            {
                printf("\nFuncionario Selecionado: %s\n", funcionario_vet[select_funcionario].nome);
            }

            printf("\n1- Selecionar Funcionarios");
            printf("\n2- Sistema de Vendas");
            printf("\n3- Salvar Dados");
            printf("\n0- Sair ");

            int is_valid;
            do
            {
                is_valid = 1;
                printf("\nEscolha uma opção:");
                scanf("%d", &op_menu);

                switch (op_menu)
                {
                //3- Salvar dados
                case 1:
                    limpar_tela();
                    printf("\nFuncionarios\n");

                    for (i = 0; i < MAX; i++)
                    {
                        printf("\n%d - %s", i, funcionario_vet[i].nome);
                    }
                    do
                    {
                        printf("\nSelecione o funcionario do balcao: ");
                        scanf("%d", &select_funcionario);
                    } while ((select_funcionario > MAX - 1 || select_funcionario < 0));
                    is_select_funcionario = 1;
                    pausar_limpar_tela();
                    break;
                //2- Sistema de Vendas
                case 2:
                    limpar_tela();
                    printf("\nSistema de Vendas\n");
                    if (is_select_funcionario)
                    {

                        limpar_tela();
                        printf("\nDados do funcionario selecionado\n");

                        info_funcionario(funcionario_vet[select_funcionario]);

                        pausar_limpar_tela();

                        printf("\nProdutos\n");

                        for (i = 0; i < MAX; i++)
                        {
                            printf("\n%d - %s", i, produto_vet[i]);
                        }

                        do
                        {
                            printf("\nSelecione o funcionario do balcao: ");
                            scanf("%d", &select_produto);
                        } while ((select_produto > MAX - 1 || select_produto < 0));

                        limpar_tela();
                        printf("\nDados do produto selecionado\n");
                        info_produto(produto_vet[select_produto]);

                        printf("\n\n");

                        int quantidade_produto;
                        do
                        {
                            printf("\nQuantidade desejada:");
                            scanf("%d", &quantidade_produto);
                        } while (quantidade_produto < 0 || quantidade_produto > produto_vet[select_produto].quant);

                        produto_vet[select_funcionario].vendidos += quantidade_produto;
                        produto_vet[select_funcionario].quant -= quantidade_produto;

                        limpar_tela();
                        float valor_total = quantidade_produto * produto_vet[select_funcionario].valor;
                        printf("\nValor total: %.2f\n", valor_total);

                        float valor_pago;
                        do
                        {
                            printf("\nValor pago pelo cliente:");
                            scanf("%f", &valor_pago);
                            if (valor_pago < valor_total)
                            {
                                printf("\nO valor pago não pode ser menor que o valor total\n");
                            }

                        } while (valor_pago < valor_total);

                        float valorTroco = valor_pago - valor_total;
                        printf("\nValor do troco a ser devolvido ao cliente:%.2f", valorTroco);
                        pausar_limpar_tela();
                        /* code */
                    }
                    else
                    {
                        printf("\nNenhum funcionario_vet selecionado, volte ao menu principal e selecione um funcionario\n");
                        pausar_limpar_tela();
                    }

                    

                    break;
                //3- Salvar dados
                case 3:
                    limpar_tela();
                    salvar_dados_produtos(produto_vet);
                    salvarDadosFuncionarios(funcionario_vet);
                    pausar_limpar_tela();
                    break;
                //0- Sair
                case 0:
                    limpar_tela();
                    exit(1);
                    break;

                default:
                    is_valid = 0;
                    printf(" Opção invalida, escolha outra opção:");
                    break;
                }

            } while (!is_valid);

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

            int is_valid;
            do
            {
                is_valid = 1;
                printf("\nEscolha uma opção:");
                scanf("%d", &op_menu);

                switch (op_menu)
                {
                case 1:
                    limpar_tela();
                    printf("\n1- Produtos");
                    printf("\n2- Funcionarios");
                    printf("\n0- Sair");

                    do
                    {
                        is_valid = 1;
                        printf("\nEscolha uma opção:");
                        scanf("%d", &op_menu);
                        switch (op_menu)
                        {
                        //1- Produto
                        case 1:
                            limpar_tela();
                            printf("\n1- Gerar Produtos");
                            printf("\n2- Cadastrar Produtos");
                            printf("\n0- Sair");

                            do
                            {
                                is_valid = 1;
                                printf("\nEscolha uma opção:");
                                scanf("%d", &op_menu);
                                switch (op_menu)
                                {
                                //1- Gerar Produtos
                                case 1:
                                    limpar_tela();
                                    gerar_produtos(produto_vet);
                                    pausar_limpar_tela();
                                    break;
                                //2- Cadastrar Produtos
                                case 2:
                                    limpar_tela();
                                    cadastrar_produtos(produto_vet);
                                    pausar_limpar_tela();
                                    break;
                                //0- Sair
                                case 0:
                                    limpar_tela();

                                    break;
                                default:
                                    is_valid = 0;
                                    break;
                                }
                            } while (!is_valid);
                            break;
                        //2- Funcionario
                        case 2:
                            limpar_tela();
                            printf("\n1- Gerar Funcionarios");
                            printf("\n2- Cadastrar Funcionarios");
                            printf("\n0- Sair");

                            do
                            {
                                is_valid = 1;
                                printf("\nEscolha uma opção:");
                                scanf("%d", &op_menu);
                                switch (op_menu)
                                {
                                //1- Gerar Produtos
                                case 1:
                                    limpar_tela();
                                    gerar_funcionarios(funcionario_vet);
                                    pausar_limpar_tela();
                                    break;
                                //2- Cadastrar Produtos
                                case 2:
                                    limpar_tela();
                                    cadastrar_funcionarios(funcionario_vet);
                                    pausar_limpar_tela();
                                    break;
                                //0- Sair
                                case 0:
                                    limpar_tela();

                                    break;
                                default:
                                    is_valid = 0;
                                    break;
                                }
                            } while (!is_valid);
                            break;
                        //0- Sair
                        case 0:
                            limpar_tela();

                            break;
                        default:
                            is_valid = 0;
                            break;
                        }
                    } while (!is_valid);
                    break;
                //2- Informações
                case 2:
                    limpar_tela();
                    printf("\n1- Funcionarios");
                    printf("\n2- Produtos");
                    printf("\n0- Sair");

                    do
                    {
                        is_valid = 1;
                        printf("\nEscolha uma opção:");
                        scanf("%d", &op_menu);
                        switch (op_menu)
                        {
                        //1- Funcionarios
                        case 1:
                            limpar_tela();
                            int i;
                            for (i = 0; i < 5; i++)
                            {
                                printf("\n________________________\n");
                                info_funcionario(funcionario_vet[i]);
                            }
                            pausar_limpar_tela();
                            break;
                        //2- Produtos
                        case 2:
                            limpar_tela();
                            for (i = 0; i < 5; i++)
                            {
                                printf("\n________________________\n");
                                info_produto(produto_vet[i]);
                            }
                            pausar_limpar_tela();
                            break;
                        //0- Sair
                        case 0:
                            limpar_tela();

                            break;
                        default:
                            is_valid = 0;
                            break;
                        }
                    } while (!is_valid);
                    break;
                //3- Relatorios de vendas
                case 3:
                    limpar_tela();
                    printf("\nRelatorios de Vendas\n");
                    for (i = 0; i < MAX; i++)
                    {
                        if (produto_vet[i].vendidos > 0)
                        {
                            printf("\n--------------------------------------\n");
                            printf("\nProduto\t\t\t:%s", produto_vet[i].nprod);
                            printf("\nValor\t\t\t:%2.f", produto_vet[i].valor);
                            printf("\nQuantidade\t\t:%d", produto_vet[i].quant);
                            printf("\nQuantidade vendidos\t:%d", produto_vet[i].vendidos);
                            printf("\nValor total arrecadado\t:%.2f", produto_vet[i].valor * produto_vet[i].vendidos);
                        }
                    }

                    pausar_limpar_tela();
                    break;
                //3- Salvar dados
                case 4:
                    limpar_tela();
                    salvar_dados_produtos(produto_vet);
                    salvarDadosFuncionarios(funcionario_vet);
                    pausar_limpar_tela();
                    break;
                //0- Sair
                case 0:
                    limpar_tela();
                    exit(1);
                    break;

                default:
                    is_valid = 0;
                    printf("Opção invalida, escolha outra opção:");
                    break;
                }

            } while (!is_valid);

        } while (1);
    }

} //fim do main

void limpar_tela()
{
#ifdef __WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar_limpar_tela()
{
    printf("\n\n");
#ifdef __WIN32
    system("pause");
#else
    system("read -p \"Pressione enter para continuar\" saindo");
#endif

    limpar_tela();
}

void info_produto(produto_t produto)
{
    printf("\nNome produto\t\t: %s", produto.nprod);
    printf("\nValor do produto\t: %.2f", produto.valor);
    printf("\nQuantidade\t\t: %d", produto.quant);
}

void info_funcionario(funcionario_t funcionario)
{
    printf("\nNome do funcionario\t:  %s", funcionario.nome);
    printf("\nMatricula\t\t:  %s", funcionario.matricula);
}

void cadastrar_produtos(produto_t produto_vet[MAX])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("\n___________________________________________\n");
        printf("Nome\t\t:");
        scanf("%s", &produto_vet[i].nprod);

        do
        {
            printf("Valor\t\t:");
            scanf("%f", &produto_vet[i].valor);
            if (produto_vet[i].valor <= 0)
            {
                printf("O valor tem que ser maior que 0\n");
            }
        } while (produto_vet[i].valor <= 0);

        do
        {
            printf("Quantidade\t:");
            scanf("%d", &produto_vet[i].quant);
            if (produto_vet[i].quant <= 0)
            {
                printf("A quantidade tem que ser maior que 0\n");
            }
        } while (produto_vet[i].quant <= 0);

        produto_vet[i].vendidos = 0;
    }
}

void cadastrar_funcionarios(funcionario_t funcionario_vet[MAX])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("\n___________________________________________\n");
        printf("Nome\t\t:");
        scanf("%s", &funcionario_vet[i].nome);

        printf("Matricula\t:");
        scanf("%s", &funcionario_vet[i].matricula);
    }
}
void gerar_produtos(produto_t produto_vet[MAX])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        sprintf(produto_vet[i].nprod, "Produto %d", i);
        produto_vet[i].quant = i + 10;
        produto_vet[i].valor = i + 100;
        produto_vet[i].vendidos = 0;
    }
    printf("\nProdutos gerados Automaticamente\n");
}

void gerar_funcionarios(funcionario_t funcionario_vet[MAX])
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        sprintf(funcionario_vet[i].nome, "Funcionario %d", i);
        sprintf(funcionario_vet[i].matricula, "%d%d%d", i, i, i);
    }
    printf("\nFuncionarios gerados Automaticamente\n");
}

void salvar_dados_produtos(produto_t produto_vet[MAX])
{
    FILE *arquivo;
    arquivo = fopen("produtos.bin", "wb");
    if (arquivo != NULL)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            fwrite(&produto_vet[i], sizeof(produto_t), sizeof(produto_vet[i]), arquivo);
        }
        fclose(arquivo);
        printf("\nDados dos Carros salvos\n");
    }
    else
    {
        printf("\nErro ao salvar os dados dos Pr\n");
    }
}

int recuperar_dados_produtos(produto_t produto_vet[MAX])
{

    FILE *arquivo = fopen("produtos.bin", "rb"); //criando um arquivo para salvar nossos dados

    if (arquivo != NULL) //se o arquivo existir
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            produto_t produto;

            int tamanho_arquivo = fread(&produto, sizeof(produto_t), 1, arquivo);

            if (tamanho_arquivo < 1)
                break;
            else
                produto_vet[i] = produto;
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

void salvarDadosFuncionarios(funcionario_t funcionario_vet[MAX])
{
    FILE *arquivo;
    arquivo = fopen("funcionario.bin", "wb");
    if (arquivo != NULL)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            fwrite(&funcionario_vet[i], sizeof(funcionario_t), sizeof(funcionario_vet[i]), arquivo);
        }
        fclose(arquivo);
        printf("\nDados dos Funcionarios salvos\n");
    }
    else
    {
        printf("\nErro ao salvar os dados dos Funcionarios\n");
    }
}

int recuperar_dados_funcionarios(funcionario_t funcionario_vet[MAX])
{

    FILE *arquivo = fopen("funcionario.bin", "rb");

    if (arquivo != NULL)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            funcionario_t funcionario;

            int tamanho_arquivo = fread(&funcionario, sizeof(funcionario_t), 1, arquivo);

            if (tamanho_arquivo < 1)
                break;
            else
                funcionario_vet[i] = funcionario;
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

int select_adm_or_funcionario()
{
    printf("\nLongar como:");
    printf("\n1 - Administrador");
    printf("\n2 - Funcionario");
    printf("\n0 - Sair");
    int op;
    int is_valid;
    do
    {
        is_valid = 1;
        printf("\nSelecione uma opção:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            limpar_tela();
            return 0;
            break;
        case 2:
            limpar_tela();
            return 1;
            break;
        case 0:
            limpar_tela();
            exit(0);
            break;
        default:
            is_valid = 0;
            break;
        }
    } while (!is_valid);
}
