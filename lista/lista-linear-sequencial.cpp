#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX 5

typedef int chave_t;

typedef struct
{
    chave_t chave;

} registro_t;

typedef struct
{
    registro_t elementos_vet[MAX];
    int numero_elem;
} lista_t;

void inicializar(lista_t *lista);
int tamanho(lista_t *lista);
void exibir(lista_t *lista);
int buscar_sequencial(lista_t *lista, chave_t chave);
bool inserir(lista_t *lista, registro_t elemento, int index);
bool excluir(lista_t *lista, chave_t chave);
void reiniciar(lista_t *lista);
void limpar_tela();
void pausar_limpar_tela();
int main()
{

    lista_t *lista = (lista_t *)malloc(sizeof(lista_t));

    inicializar(lista);

    do
    {

        puts("1 - tamanho");
        puts("2 - exibir");
        puts("3 - buscar");
        puts("4 - inserir");
        puts("5 - excluir");
        puts("6 - reiniciar");
        puts("0 - sair");

        int op;
        printf(">");
        scanf("%d", &op);
        limpar_tela();
        switch (op)
        {
        case 1:
        //tamanho
            printf("Tamanho:%d",tamanho(lista));
            break;
     
        case 2:
        //exibir
            exibir(lista);
            break;
        
        case 3:
        //buscar
        {
            chave_t chave;
            puts("pesquisar chave:");
            printf(">");
            scanf("%d",&chave);
            int result = buscar_sequencial(lista,chave);
            result == -1?puts("não encontrado"):printf("resultado:%d",result);
            break;
        }
        case 4:
        //inserir
        {
            registro_t elemento;
            puts("digite uma chave:");
            printf(">");
            scanf("%d",&elemento.chave);
            int position;
            puts("digite uma posição:");
            printf(">");
            scanf("%d",&position);

            inserir(lista,elemento,position)?puts("inserido"):puts("falha ao inserir");
            break;
        }
        case 5:
        //excluir
        {
            chave_t chave;
            puts("digite uma chave:");
            printf(">");
            scanf("%d",&chave);
            excluir(lista,chave)?puts("deletado"):puts("falha ao deletar");
            break;
        }
        case 6:
        //reiniciar
            reiniciar(lista);
            break;
        
        case 0:
        //sair
            exit(0);
            break;
        
        }

        pausar_limpar_tela();
    } while (true);

    return 0;
}

void limpar_tela()
{
    !__unix__ ? system("cls") : system("clear");

} //fim procedimento limpar_tela

void pausar_limpar_tela()
{
    printf("\n\n");
    !__unix__ ? system("pause") : system("read -p \"Pressione enter para continuar\" saindo");
    limpar_tela();
} //fim procedimento pausar_limpar_tela

void inicializar(lista_t *lista)
{
    lista->numero_elem = 0;
}
int tamanho(lista_t *lista)
{
    return lista->numero_elem;
}

void exibir(lista_t *lista)
{

    printf("Lista: \" ");
    for (int i = 0; i < lista->numero_elem; i++)
        printf("%i, ", lista->elementos_vet[i].chave);

    printf("\"\n");
}

int buscar_sequencial(lista_t *lista, chave_t chave)
{

    for (int i = 0; i < lista->numero_elem; i++)
        if (chave == lista->elementos_vet[i].chave)
            return i;

    return -1;
}

bool inserir(lista_t *lista, registro_t elemento, int index)
{

    if ((lista->numero_elem == MAX) || (index < 0) || (index > lista->numero_elem))
        return false;

    for (int i = lista->numero_elem; i > index; i--)
        lista->elementos_vet[i] = lista->elementos_vet[i - 1];

    lista->elementos_vet[index] = elemento;
    lista->numero_elem++;

    return true;
}

bool excluir(lista_t *lista, chave_t chave)
{

    int pos = buscar_sequencial(lista, chave);

    if (pos == -1)
        return false;

    for (int i = pos; i < lista->numero_elem - 1; i++)
        lista->elementos_vet[i] = lista->elementos_vet[i + 1];

    lista->numero_elem--;
    return true;
}

void reiniciar(lista_t *lista)
{
    lista->numero_elem = 0;
}