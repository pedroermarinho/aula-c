/*
Pet Shop
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

const int MAX_PESSOA = 4;
const int MAX_ANIMAL = 3;

typedef struct
{
    char nome[120];
    char raca[60];
    float peso;
    bool exist;
} animal_t;

typedef struct
{
    char nome[120];
    char telefone[20];
    animal_t animais[MAX_ANIMAL];
    bool exist;
} client_t;

void limpar_tela();
void pausar();

void menu();
void menu_delete(client_t client_vet[], int tam);

void gerar_dados(client_t client_vet[], int tam);
void pesquisar(client_t client_vet[], int tam);

void create_client(client_t client_vet[], int tam);
void create_client(client_t *client);
void read_client(client_t client);
void read_client(client_t client_vet[], int tam);
void update_client(client_t client_vet[], int tam);
void delete_client(client_t client_vet[], int tam);

void create_animal(animal_t animal_vet[], int tam);
void create_animal(animal_t *animal);
void read_animal(animal_t animal_vet[], int tam);
void read_animal_simples(animal_t animal_vet[], int tam);
void update_animal(animal_t animal_vet[], int tam);
void delete_animal(client_t client_vet[], int tam);
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
        printf("5 - Gerar Dados\n");
        printf("0 - Sair\n");

        bool is_valid;
        do
        {
            printf(">");
            scanf("%d", &op);

            is_valid = true;
            switch (op)
            {
            //Cadastrar
            case 1:
                limpar_tela();
                create_client(client_vet, MAX_PESSOA);
                break;

            //Pesquisar
            case 2:
                limpar_tela();
                pesquisar(client_vet, MAX_PESSOA);
                pausar();
                break;

            //Deletar
            case 3:
                limpar_tela();
                menu_delete(client_vet, MAX_PESSOA);
                break;

            //Alterar
            case 4:
                limpar_tela();
                update_client(client_vet, MAX_PESSOA);
                pausar();
                break;

            //Gerar Dados
            case 5:
                limpar_tela();
                gerar_dados(client_vet, MAX_PESSOA);
                pausar();
                break;

            //Sair
            case 0:
                limpar_tela();
                exit(0);
                break;

            default:
                is_valid = false;
                break;
            }

        } while (!is_valid);

    } while (true);
}

void menu_delete(client_t client_vet[], int tam)
{
    system("title Menu Deletar");
    bool continuar = true;
    do
    {
        limpar_tela();
        int op = 0;
        system("title Pet Shop Manager");
        printf("1 - Cliente\n");
        printf("2 - Animais\n");
        printf("0 - Sair\n");

        bool is_valid;
        do
        {
            printf(">");
            scanf("%d", &op);

            is_valid = true;
            switch (op)
            {
            //Cliente
            case 1:
                limpar_tela();
                delete_client(client_vet, MAX_PESSOA);
                break;

            //Animais
            case 2:
                limpar_tela();
                delete_animal(client_vet, MAX_PESSOA);
                pausar();
                break;

            //Sair
            case 0:
                limpar_tela();
                continuar = false;
                break;

            default:
                is_valid = false;
                break;
            }
        } while (!is_valid);
    } while (continuar);
}
void gerar_dados(client_t client_vet[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        sprintf(client_vet[i].nome, "Clinte %d", i);
        sprintf(client_vet[i].telefone, "(11) 1111 111%d", i);
        client_vet[i].exist = true;
        for (int j = 0; j < MAX_ANIMAL; j++)
        {
            sprintf(client_vet[i].animais[j].nome, "Animal %d", j);
            sprintf(client_vet[i].animais[j].raca, "Raça %d", j);
            client_vet[i].animais[j].peso = j;
            client_vet[i].animais[j].exist = true;
        }
    }
    printf("\nDados Gerados\n");
}

void pesquisar(client_t client_vet[], int tam)
{
    system("title Pesquisa");
    read_client(client_vet, tam);

    int op;
    printf("\nEscolha um cliente para ver os dados:\n");

    do
    {
        printf(">");
        scanf("%d", &op);
    } while (!(op >= 0 && op < tam));

    if (!client_vet[op].exist) // if (true ou false); (1==2) ==> valor => true ou false || 0 - false & 1 - true
    {
        printf("\nCliente não existe");
        return;
    }

    limpar_tela();
    read_client(client_vet[op]);
}

void create_client(client_t *client)
{
    system("title Cadastro de Clientes");
    printf("Nome:\n");
    printf(">");
    fflush(stdin);
    gets(client->nome);
    printf("Telefone:\n");
    printf(">");
    fflush(stdin);
    gets(client->telefone);
    create_animal(client->animais, MAX_ANIMAL);
    client->exist = true;
}

void create_client(client_t client_vet[], int tam)
{
    int op = 0;
    for (int i = 0; i < tam; i++)
    {
        if (i == 0)
        {
            create_client(&client_vet[i]);
            continue;
        }

        printf("\nDeseja cadastrar mais um cliente? 1->sim, 0->nao\n");
        printf(">");
        scanf("%d", &op);
        limpar_tela();
        if (!op)
        {
            client_vet[i].exist = false;
            break;
        }

        create_client(&client_vet[i]);
    }
}

void read_client(client_t client)
{
    if (!client.exist)
        return;

    printf("\nNome:%s", client.nome);
    printf("\nTelefone:%s", client.telefone);
    printf("\n\n--Dados dos animais--");
    read_animal(client.animais, MAX_ANIMAL);
}
void read_client(client_t client_vet[], int tam)
{
    for (int i = 0; i < tam; i++)
        if (client_vet[i].exist)
            printf("\n%d - Nome:%s", i, client_vet[i].nome);
}
void update_client(client_t client_vet[], int tam)
{
    system("title Atualizar de Cadastros");
    read_client(client_vet, tam);

    int op;
    printf("\nEscolha um cliente para ser alterado:\n");

    do
    {
        printf(">");
        scanf("%d", &op);
    } while (!(op >= 0 && op < tam));

    if (!client_vet[op].exist) // if (true ou false); (1==2) ==> valor => true ou false || 0 - false & 1 - true
    {
        printf("\nCliente não existe");
        return;
    }

    create_client(&client_vet[op]);
}
void delete_client(client_t client_vet[], int tam)
{
    system("title Deleta de Clientes");
    read_client(client_vet, tam);

    int op;
    printf("\nEscolha um cliente para ser deletado:\n");

    do
    {
        printf(">");
        scanf("%d", &op);

    } while (!(op >= 0 && op < tam));

    if (!client_vet[op].exist)
    {
        printf("\nCliente não existe");
        return;
    }

    client_vet[op].exist = false;
    printf("\nCliente %s deletado\n", client_vet[op].nome);
}

void create_animal(animal_t *animal)
{

    system("title Cadastro de Animais");
    printf("Nome:\n");
    printf(">");
    fflush(stdin);
    gets(animal->nome);
    printf("Raça:\n");
    printf(">");
    fflush(stdin);
    gets(animal->raca);
    printf("Peso:\n");
    printf(">");
    fflush(stdin);
    scanf("%f", &animal->peso);
    animal->exist = true;
}

void create_animal(animal_t animal_vet[], int tam)
{
    limpar_tela();
    int op = 0;
    for (int i = 0; i < tam; i++)
    {
        if (i == 0)
        {
            create_animal(&animal_vet[i]);
            continue;
        }

        printf("\nDeseja cadastrar mais um animal? 1->sim, 0->nao\n");
        printf(">");
        scanf("%d", &op);
        limpar_tela();
        if (!op)
        {
            animal_vet[i].exist = false;
            break;
        }

        create_animal(&animal_vet[i]);
    }
}

void read_animal(animal_t animal_vet[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (!animal_vet[i].exist)
            continue;

        printf("\n-----------%d-----------", i);
        printf("\nNome:%s", animal_vet[i].nome);
        printf("\nRaça:%s", animal_vet[i].raca);
        printf("\nPeso:%.2f", animal_vet[i].peso);
    }
}
void read_animal_simples(animal_t animal_vet[], int tam)
{
    for (int i = 0; i < tam; i++)
        if (animal_vet[i].exist)
            printf("\n%d - Nome:%s", i, animal_vet[i].nome);
}
void update_animal(animal_t animal_vet[], int tam)
{
    system("title Atualizar de Animais");
    read_animal_simples(animal_vet, tam);

    int op;
    printf("\nEscolha um animal para ser deletado:\n");

    do
    {
        printf(">");
        scanf("%d", &op);

    } while (!(op >= 0 && op < tam));

    if (!animal_vet[op].exist)
    {
        printf("\nAnimal não existe");
        return;
    }

    animal_vet[op].exist = false;
    printf("\nAnimal %s deletado\n", animal_vet[op].nome);
}
void delete_animal(client_t client_vet[], int tam)
{

    system("title Deleta de Animais");

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
        printf("\nCliente não existe");
        return;
    }

    delete_animal(client_vet[op].animais, MAX_ANIMAL);
}
void delete_animal(animal_t animal_vet[], int tam)
{

    read_animal_simples(animal_vet, tam);

    int op;
    printf("\nEscolha um animal para ser deletado:\n");

    do
    {
        printf(">");
        scanf("%d", &op);

    } while (!(op >= 0 && op < MAX_ANIMAL));

    if (animal_vet[op].exist)
    {
        printf("\nAnimal não existe");
        return;
    }

    animal_vet[op].exist = false;
    printf("\nAnimal %s deletado\n", animal_vet[op].nome);
}
