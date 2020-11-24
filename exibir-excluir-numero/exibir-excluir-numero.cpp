/*
1- Faça  um programa que cadastre 3 números inteiros. Pesquise Numero e exiba Numero.  Exclua Numero 

Com ponteiro
*/
//Pedro Marinho
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu();
void cadastrar(int *num1, int *num2, int *num3);
void exibir(int num1, int num2, int num3);
void excluir(int *num1, int *num2, int *num3);
void pesquisar(int *num1, int *num2, int *num3);
void alterar(int *num1, int *num2, int *num3);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    menu();
    return 0;
}

void menu()
{
    int num1=0, num2=0, num3=0;
    do
    {
        system("cls");
        printf("\n1-Ler números");
        printf("\n2-Exibir números");
        printf("\n3-Excluir número");
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
            cadastrar(&num1, &num2, &num3);
            break;
            //Exibir números
        case 2:
            exibir(num1, num2, num3);
            break;
            //Excluir número
        case 3:
            excluir(&num1, &num2, &num3);
            break;
        case 4:
            alterar(&num1, &num2, &num3);
            break;
        case 5:
            pesquisar(&num1, &num2, &num3);
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
void cadastrar(int *num1, int *num2, int *num3)
{
    printf("\nPrimeiro número:\n");
    printf(">");
    scanf("%d", num1);
    printf("\nsegundo número:\n");
    printf(">");
    scanf("%d", num2);
    printf("\nterceiro número:\n");
    printf(">");
    scanf("%d", num3);
}
void exibir(int num1, int num2, int num3)
{

    if (num1 != 'NULL')
        printf("\nA ->%d", num1);

    if (num2 != 'NULL')
        printf("\nB ->%d", num2);

    if (num3 != 'NULL')
        printf("\nC ->%d", num3);

    printf("\n");
    system("pause");
}
void excluir(int *num1, int *num2, int *num3)
{
    int op;
    printf("\nValores disponíveis:\n");

    if (*num1 != 'NULL')
        printf("\n1 -> A = %d", *num1);

    if (*num2 != 'NULL')
        printf("\n2 -> B = %d", *num2);
    
    if (*num3 != 'NULL')
        printf("\n3 -> C = %d", *num3);
    
    printf("\nSelecione uma letra:\n");
    printf(">");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        *num1 = 'NULL';
        printf("\nA excluído\n");
        break;
    case 2:
        *num2 = 'NULL';
        printf("\nB excluído\n");
        break;
    case 3:
        *num3 = 'NULL';
        printf("\nC excluído\n");
        break;

    default:
        break;
    }
    printf("\n");
    system("pause");
}
void pesquisar(int *num1, int *num2, int *num3)
{
    int pesquisa;
    printf("\nPesquisar:\n");
    printf(">");
    scanf("%d", &pesquisa);

    if (*num1 != 'NULL' && pesquisa == *num1)
        printf("\nNúmero %d encontrado na variavel A!!!\n", *num1);
    
    else if (*num1 != 'NULL' && pesquisa == *num2)
        printf("\nNúmero %d encontrado na variavel B!!!\n", *num2);
    
    else if (*num1 != 'NULL' && pesquisa == *num3)
        printf("\nNúmero %d encontrado na variavel C!!!\n", *num3);
    
    else
        printf("\nValor não encontrado\n");
    
    printf("\n");
    system("pause");
}
void alterar(int *num1, int *num2, int *num3)
{
    int op;
    printf("\nValores disponíveis:\n");
    if (*num1 != 'NULL')
        printf("\n1 -> A = %d", *num1);
    else
        printf("\n1 -> A = Sem Dados");
    
    if (*num2 != 'NULL')
        printf("\n2 -> B = %d", *num2);
    else
        printf("\n2 -> B = Sem Dados");

    if (*num3 != 'NULL')
    
        printf("\n3 -> C = %d", *num3);
    else
        printf("\n3 -> C = Sem Dados");
    
    printf("\nSelecione uma letra:\n");
    printf(">");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("\nalterar A:\n");
        printf(">");
        scanf("%d", num1);
        break;
    case 2:
        printf("\nalterar B:\n");
        printf(">");
        scanf("%d", num2);
        break;
    case 3:
        printf("\nalterar C:\n");
        printf(">");
        scanf("%d", num3);
        break;

    default:
        break;
    }
}
