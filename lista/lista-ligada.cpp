#include <stdio.h>

#define MAX 50
#define INVALIDO -1

typedef int tipo_chave_t;

typedef struct
{
    tipo_chave_t chave;
} registro_t;

typedef struct
{
    registro_t registro;
    int proximo;
} elemento_t;

typedef struct
{
    elemento_t elemento_vet[MAX];
    int inicio;
    int disponivel;
} lista_t;

void inicializar_lista(lista_t *lista);
int tamanho(lista_t *lista);
void exibir_lista(lista_t *lista);
int busca_sequencial_ord(lista_t *lista, tipo_chave_t ch);
int obter_no(lista_t *lista);
bool inserir_elem_lista_ord(lista_t *lista, registro_t reg);
bool excluir_elem_lista(lista_t *lista, tipo_chave_t ch);
void devolver_no(lista_t *lista, int i);
void reinicializar_lista(lista_t *lista);

int main()
{
    lista_t lista;
    
    inicializar_lista(&lista);
    for (size_t i = 0; i < MAX*2; i = i+2)
    {
        registro_t reg = {.chave =(tipo_chave_t) i};
        inserir_elem_lista_ord(&lista,reg);
    }
    printf("\ninicializar lista e buscar por 20\n");
    printf("%d\n",tamanho(&lista));
    exibir_lista(&lista);
    printf("20 -> %d\n",busca_sequencial_ord(&lista,20));

    printf("\nexcluir 20\n");
    excluir_elem_lista(&lista,20);
    printf("%d\n",tamanho(&lista));
    printf("20 -> %d\n",busca_sequencial_ord(&lista,20));
    exibir_lista(&lista);

    printf("\nLimpar lista\n");
    reinicializar_lista(&lista);
    printf("%d\n",tamanho(&lista));
    printf("20 -> %d\n",busca_sequencial_ord(&lista,20));
    exibir_lista(&lista);

    return 0;
}

void inicializar_lista(lista_t *lista)
{
    for (int i; i < MAX; i++)
        lista->elemento_vet[i].proximo = i + 1;

    lista->elemento_vet[MAX - 1].proximo = INVALIDO;
    lista->inicio = INVALIDO;
    lista->disponivel = 0;
}

int tamanho(lista_t *lista)
{
    int i = lista->inicio;
    int tam = 0;

    while (i != INVALIDO)
    {
        tam++;
        i = lista->elemento_vet[i].proximo;
    }
    return tam;
}

void exibir_lista(lista_t *lista)
{
    int i = lista->inicio;
    printf("Lista: \" ");

    while (i != INVALIDO)
    {
        printf("%i ", lista->elemento_vet[i].registro.chave);
        i = lista->elemento_vet[i].proximo;
    }
    printf("\"\n");
}

int busca_sequencial_ord(lista_t *lista, tipo_chave_t ch)
{

    int i = lista->inicio;
    while (i != INVALIDO && lista->elemento_vet[i].registro.chave < ch)
        i = lista->elemento_vet[i].proximo;

    return i != INVALIDO && lista->elemento_vet[i].registro.chave == ch ? i : INVALIDO;
}

int obter_no(lista_t *lista)
{
    int resultado = lista->disponivel;

    if (lista->disponivel != INVALIDO)
        lista->disponivel = lista->elemento_vet[lista->disponivel].proximo;
    return resultado;
}

bool inserir_elem_lista_ord(lista_t *lista, registro_t reg)
{
    if (lista->disponivel == INVALIDO)
        return false;

    int ant = INVALIDO;
    int i = lista->inicio;
    tipo_chave_t ch = reg.chave;

    while ((i != INVALIDO) && (lista->elemento_vet[i].registro.chave < ch))
    {
        ant = i;
        i = lista->elemento_vet[i].proximo;
    }

    if (i != INVALIDO && lista->elemento_vet[i].registro.chave == ch)
        return false;

    i = obter_no(lista);
    lista->elemento_vet[i].registro = reg;
    if (ant == INVALIDO)
    {
        lista->elemento_vet[i].proximo = lista->inicio;
        lista->inicio = i;
    }
    else
    {
        lista->elemento_vet[i].proximo = lista->elemento_vet[ant].proximo;
        lista->elemento_vet[ant].proximo = i;
    }
    return true;
}

bool excluir_elem_lista(lista_t *lista, tipo_chave_t ch)
{
    int ant = INVALIDO;
    int i = lista->inicio;
    while ((i != INVALIDO) && (lista->elemento_vet[i].registro.chave < ch))
    {
        ant = i;
        i = lista->elemento_vet[i].proximo;
    }
    if (i == INVALIDO || lista->elemento_vet[i].registro.chave != ch)
        return false;

    if (ant == INVALIDO)
        lista->inicio = lista->elemento_vet[i].proximo;
    else
        lista->elemento_vet[ant].proximo = lista->elemento_vet[i].proximo;

    devolver_no(lista, i);

    return true;
}

void devolver_no(lista_t *lista, int i)
{
    lista->elemento_vet[i].proximo = lista->disponivel;
    lista->disponivel = i;
}
void reinicializar_lista(lista_t *lista)
{
    inicializar_lista(lista);
}