/*
1- Faça  um programa que cadastre 3 números inteiros. Pesquise Numero e exiba Numero.  Exclua Numero 

Com ponteiro
*/
//Pedro Marinho
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu();
void cadastrar(int *a, int *b, int *c);
void exibir(int a, int b, int c);
void excluir(int *a, int *b, int *c);
void pesquisar(int *a, int *b, int *c);
void alterar(int *a, int *b, int *c);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    menu();
    return 0;
}

void menu()
{
    int a=0, b=0, c=0;
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
            cadastrar(&a, &b, &c);
            break;
            //Exibir números
        case 2:
            exibir(a, b, c);
            break;
            //Excluir número
        case 3:
            excluir(&a, &b, &c);
            break;
        case 4:
            alterar(&a, &b, &c);
            break;
        case 5:
            pesquisar(&a, &b, &c);
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
void cadastrar(int *a, int *b, int *c)
{
    printf("\nPrimeiro número:\n");
    printf(">");
    scanf("%d", a);
    printf("\nsegundo número:\n");
    printf(">");
    scanf("%d", b);
    printf("\nterceiro número:\n");
    printf(">");
    scanf("%d", c);
}
void exibir(int a, int b, int c)
{

    if (a != 'NULL')
    {
        printf("\nA ->%d", a);
    }
    if (b != 'NULL')
    {
        printf("\nB ->%d", b);
    }
    if (c != 'NULL')
    {
        printf("\nC ->%d", c);
    }
    printf("\n");
    system("pause");
}
void excluir(int *a, int *b, int *c)
{
    int op;
    printf("\nValores disponíveis:\n");
    if (*a != 'NULL')
    {
        printf("\n1 -> A = %d", *a);
    }
    if (*b != 'NULL')
    {
        printf("\n2 -> B = %d", *b);
    }
    if (*c != 'NULL')
    {
        printf("\n3 -> C = %d", *c);
    }
    printf("\nSelecione uma letra:\n");
    printf(">");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        *a = 'NULL';
        printf("\nA excluído\n");
        break;
    case 2:
        *b = 'NULL';
        printf("\nB excluído\n");
        break;
    case 3:
        *c = 'NULL';
        printf("\nC excluído\n");
        break;

    default:
        break;
    }
    printf("\n");
    system("pause");
}
void pesquisar(int *a, int *b, int *c)
{
    int pesquisa;
    printf("\nPesquisar:\n");
    printf(">");
    scanf("%d", &pesquisa);

    if (*a != 'NULL' && pesquisa == *a)
    {
        printf("\nNúmero %d encontrado na variavel A!!!\n", *a);
    }
    else if (*a != 'NULL' && pesquisa == *b)
    {
        printf("\nNúmero %d encontrado na variavel B!!!\n", *b);
    }
    else if (*a != 'NULL' && pesquisa == *c)
    {
        printf("\nNúmero %d encontrado na variavel C!!!\n", *c);
    }
    else
    {
        printf("\nValor não encontrado\n");
    }
    printf("\n");
    system("pause");
}
void alterar(int *a, int *b, int *c)
{
    int op;
    printf("\nValores disponíveis:\n");
    if (*a != 'NULL')
    {
        printf("\n1 -> A = %d", *a);
    }else
    {
        printf("\n1 -> A = Sem Dados");
    }
    
    if (*b != 'NULL')
    {
        printf("\n2 -> B = %d", *b);
    }else{
        printf("\n2 -> B = Sem Dados");
    }
    if (*c != 'NULL')
    {
        printf("\n3 -> C = %d", *c);
    }else
    {
        printf("\n3 -> C = Sem Dados");
    }
    
    printf("\nSelecione uma letra:\n");
    printf(">");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        printf("\nalterar A:\n");
        printf(">");
        scanf("%d", a);
        break;
    case 2:
        printf("\nalterar B:\n");
        printf(">");
        scanf("%d", b);
        break;
    case 3:
        printf("\nalterar C:\n");
        printf(">");
        scanf("%d", c);
        break;

    default:
        break;
    }
}
