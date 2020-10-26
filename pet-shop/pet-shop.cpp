/*
Pet Shop
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

const int MAX_PESSOA = 4;
const int MAX_ANIMAL = 3;

typedef struct _animal_t
{
    char nome[120];
    char raca[60];
    float peso;
    bool exist;
} animal_t;

typedef struct _client_t
{
    char nome[120];
    char telefone[20];
    animal_t animais[MAX_ANIMAL];
    bool exist;
} client_t;

void limpar_tela();
void pausar();

void menu();

void create_client(client_t client_vet[], int tam);
void read_client(client_t client_vet[], int tam);
void update_client(client_t client_vet[], int tam);
void delete_client(client_t client_vet[], int tam);

void create_animal(animal_t animal_vet[], int tam);
void read_animal(animal_t animal_vet[], int tam);
void update_animal(animal_t animal_vet[], int tam);
void delete_animal(animal_t animal_vet[], int tam);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    menu();
}

void limpar_tela()
{
    system("cls");
}
void pausar()
{
    printf("\n\n");
    system("pause");
}

void menu()
{
    client_t client_vet[MAX_PESSOA];
    do
    {
        limpar_tela();
        int op = 0;
        system("title Pet Shop Manager");
        printf("1 - Cadastrar\n");
        printf("2 - Pesquisar\n");
        printf("3 - Deletar\n");
        printf("4 - Alterar\n");
        printf("0 - Sair\n");

        bool isValid;
        do
        {
            printf(">");
            scanf("%d", &op);

            isValid = true;
            switch (op)
            {
            //Cadastrar
            case 1:
                limpar_tela();
                create_client(client_vet, MAX_PESSOA);
                pausar();
                break;

            //Pesquisar
            case 2:
                limpar_tela();
                read_client(client_vet, MAX_PESSOA);
                pausar();
                break;

            //Deletar
            case 3:
                limpar_tela();
                delete_client(client_vet, MAX_PESSOA);
                pausar();
                break;

            //Alterar
            case 4:
                limpar_tela();
                update_client(client_vet, MAX_PESSOA);
                pausar();
                break;

            //Sair
            case 0:
                limpar_tela();
                exit(0);
                break;

            default:
                isValid = false;
                break;
            }

        } while (!isValid);

    } while (true);
}
void menu_alterar_client(client_t client_vet[], int tam)
{
}
void menu_alterar_animal(animal_t animal_vet[], int tam)
{
}

void menu_deletar_client(client_t client_vet[], int tam)
{
}

void menu_deletar_animal(animal_t animal_vet[], int tam)
{
}

/*
ter duas ou mais funções/procedimento com o mesmo nome, mas com parametros diferentes

identificador = nome+parametros 

imprimir(){}
imprimir(int result){}
imprimir(char result){}

imprimir(); != imprimir(1);

*/

void _create_client(client_t *client)
{
    printf("Nome:\n");
    printf(">");
    fflush(stdin);
    gets(client->nome);
    printf("Telefone:\n");
    printf(">");
    fflush(stdin);
    gets(client->telefone);
    client->exist = true;
}

void create_client(client_t client_vet[], int tam)
{
    int i;
    int op = 0;
    for (i = 0; i < tam; i++)
    {
        if (i == 0)
        {
            _create_client(&client_vet[i]);
        }
        else
        {
            printf("\nDeseja cadastrar mais um cliente? 1->sim, 0->nao\n");
            printf(">");
            scanf("%d", &op);
            limpar_tela();
            if (op)
            {
                _create_client(&client_vet[i]);
            }
            else
            {
                client_vet[i].exist = false;
                break;
            }
        }
    }
}

void read_client(client_t client_vet[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        if (client_vet[i].exist)
        {
            printf("\n-----------%d-----------", i);
            printf("\nNome:%s", client_vet[i].nome);
            printf("\nTelefone:%s", client_vet[i].telefone);
        }
        
    }
}
void update_client(client_t client_vet[], int tam)
{
    read_client(client_vet, tam);

    int op;
    printf("\nEscolha um cliente para ser alterado:\n");

    do
    {
        printf(">");
        scanf("%d", &op);

    } while (!(op >= 0 && op < tam));

    if (client_vet[op].exist) // if (true ou false); (1==2) ==> valor => true ou false || 0 - false & 1 - true
    {

        _create_client(&client_vet[op]);

    }
    else
    {
        printf("\nCliente não existe");
    }
}
void delete_client(client_t client_vet[], int tam)
{
    read_client(client_vet, tam);

    int op;
    printf("\nEscolha um cliente para ser deletado:\n");

    do
    {
        printf(">");
        scanf("%d", &op);

    } while (!(op >= 0 && op < tam));

    if (client_vet[op].exist)
    {
        client_vet[op].exist = false;
        printf("\nCliente %s deletado\n", client_vet[op].nome);
    }
    else
    {
        printf("\nCliente não existe");
    }
}

void create_animal(animal_t animal_vet[], int tam)
{
}
void read_animal(animal_t animal_vet[], int tam)
{
}
void update_animal(animal_t animal_vet[], int tam)
{
}
void delete_animal(animal_t animal_vet[], int tam)
{
}
