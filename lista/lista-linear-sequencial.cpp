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
    registro_t elementos_vet[MAX + 1];
    int numero_elem;
} lista_t;

void inicializar(lista_t *lista);
int tamanho(lista_t *lista);
void exibir(lista_t *lista);
int busca_sequencial(lista_t *lista, chave_t chave);
int busca_sentinela(lista_t *lista, chave_t chave);
int busca_binaria(lista_t *lista, chave_t chave);
bool inserir(lista_t *lista, registro_t elemento, int index);
bool inserir_ordenado(lista_t *lista, registro_t elemento);
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
        puts("3 - busca sequencial");
        puts("4 - busca sentinela");
        puts("5 - busca binaria");
        puts("6 - inserir");
        puts("7 - inserir ordenado");
        puts("8 - excluir");
        puts("9 - reiniciar");
        puts("0 - sair");

        int op;
        printf(">");
        scanf("%d", &op);
        limpar_tela();
        switch (op)
        {
        case 1:
            //tamanho
            printf("Tamanho:%d", tamanho(lista));
            break;

        case 2:
            //exibir
            exibir(lista);
            break;

        case 3:
            //buscar sequencial
            {
                chave_t chave;
                puts("pesquisar chave:");
                printf(">");
                scanf("%d", &chave);
                int result = busca_sequencial(lista, chave);
                result == -1 ? puts("não encontrado") : printf("resultado:%d", result);
                break;
            }
        case 4:
            //buscar sentinela
            {
                chave_t chave;
                puts("pesquisar chave:");
                printf(">");
                scanf("%d", &chave);
                int result = busca_sentinela(lista, chave);
                result == -1 ? puts("não encontrado") : printf("resultado:%d", result);
                break;
            }
        case 5:
            //buscar binaria
            {
                chave_t chave;
                puts("pesquisar chave:");
                printf(">");
                scanf("%d", &chave);
                int result = busca_binaria(lista, chave);
                result == -1 ? puts("não encontrado") : printf("resultado:%d", result);
                break;
            }
        case 6:
            //inserir
            {
                registro_t elemento;
                puts("digite uma chave:");
                printf(">");
                scanf("%d", &elemento.chave);
                int position;
                puts("digite uma posição:");
                printf(">");
                scanf("%d", &position);

                inserir(lista, elemento, position) ? puts("inserido") : puts("falha ao inserir");
                break;
            }
        case 7:
            //inserir ordenado
            {
                registro_t elemento;
                puts("digite uma chave:");
                printf(">");
                scanf("%d", &elemento.chave);

                inserir_ordenado(lista, elemento) ? puts("inserido") : puts("falha ao inserir");
                break;
            }
        case 8:
            //excluir
            {
                chave_t chave;
                puts("digite uma chave:");
                printf(">");
                scanf("%d", &chave);
                excluir(lista, chave) ? puts("deletado") : puts("falha ao deletar");
                break;
            }
        case 9:
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

int busca_sequencial(lista_t *lista, chave_t chave)
{
    for (int i = 0; i < lista->numero_elem; i++)
        if (chave == lista->elementos_vet[i].chave)
            return i;

    return -1;
}

int busca_sentinela(lista_t *lista, chave_t chave)
{
    int i;
    lista->elementos_vet[lista->numero_elem].chave = chave;

    for (i = 0; lista->elementos_vet[i].chave != chave; i++)
        ;

    return i == lista->numero_elem ? -1 : i;
}

int busca_binaria(lista_t *lista, chave_t chave)
{

    int esquerda, meio, direita;

    esquerda = 0;
    direita = lista->numero_elem;

    while (esquerda <= direita)
    {
        meio = (esquerda + direita) / 2;
        if (lista->elementos_vet[meio].chave = chave)
            return meio;

        if (lista->elementos_vet[meio].chave < chave)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }

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
bool inserir_ordenado(lista_t *lista, registro_t elemento)
{

    if (lista->numero_elem >= MAX)
        return false;
    int pos;

    for (pos = lista->numero_elem; pos > 0 && lista->elementos_vet[pos - 1].chave > elemento.chave; pos--)
        lista->elementos_vet[pos] = lista->elementos_vet[pos - 1];

    lista->elementos_vet[pos] = elemento;
    lista->numero_elem++;
    return true;
}
bool excluir(lista_t *lista, chave_t chave)
{

    int pos = busca_binaria(lista, chave);

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