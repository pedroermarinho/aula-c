/*
faça sistema para controlar clinica medica
O sistema cadastrar especialidade: nome, código. 
O sistema cadastrar medico: nome, especialidade, crm, login, senha.
Obs: O  perfil administrador geral realiza tudo;
O perfil funcionario so cadastrar paciente;
Fazer o crud; 
cada cadastro 2 max;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>

#define MAX 2

typedef struct
{
    int cod;
    char nome[120];
} especialidade_t;

typedef struct
{
    char usuario[60];
    char senha[60];
} login_t;

typedef struct
{
    char crm[10];
    char nome[120];
    login_t login;
    especialidade_t especialidade;
    bool exist;
} medico_t;

typedef struct
{
    char matricula[10];
    char nome[120];
    login_t login;
    bool exist;
} funcionario_t;

typedef struct
{
    char nome[120];
    char cpf[20];
    char telefone[20];
    login_t login;
    bool exist;
} paciente_t;

void menu_login();
void menu_adm(funcionario_t funcionario_vet[],
              especialidade_t especialidade_vet[],
              medico_t medico_vet[],
              paciente_t paciente_vet[]);

login_t auth(login_t login);
bool auth(login_t login1, login_t login2);
bool auth_adm(login_t adm);
bool auth_funcionario(funcionario_t funcionario_vet[], int tam);

char *ler_string(char *string, int tam);

login_t create_login();
void create_function(funcionario_t funcionario_vet[], int tam);
void create_function(funcionario_t *funcionario);
int read_function(funcionario_t funcionario_vet[], int tam);
void read_function(funcionario_t funcionario);
void delete_function(funcionario_t funcionario_vet[], int tam);
void update_function(funcionario_t funcionario_vet[], int tam);

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    menu_login();

    printf("\n\n");
    return EXIT_SUCCESS;
}

char *ler_string(char *string, int tam)
{
    printf(">");
    fflush(stdin);
    bool valid;
    do
    {
        valid = true;

        if (fgets(string, tam, stdin) != NULL)
        {
            int ultima_letra = strlen(string) - 1;
            if (string[ultima_letra] == '\n')
            {
                string[ultima_letra] = '\0';
            }
        }

        if (strlen(string) == 0)
        {
            valid = false;
        }

    } while (!valid);

    return NULL;
}

void menu_login()
{
    do
    {

        login_t adm;
        funcionario_t funcionario_vet[MAX];
        especialidade_t especialidade_vet[MAX];
        medico_t medico_vet[MAX];
        paciente_t paciente_vet[MAX];

        sprintf(adm.usuario, "adm");
        sprintf(adm.senha, "123");

        printf("\n1-ADM");
        printf("\n2-Funcionario");
        printf("\n3-Medico");
        printf("\n4-Paciente");
        printf("\n0-Sair");

        bool isValid = true;
        int op = 0;
        do
        {

            printf("\n>");
            scanf("%d", &op);
            switch (op)
            {
            case 1:
                //ADM
                if (auth_adm(adm))
                {
                    menu_adm(funcionario_vet,
                             especialidade_vet,
                             medico_vet,
                             paciente_vet);
                }
                else
                {
                    printf("\nDados incorretos\n");
                }

                break;
            //Funcionario
void menu_login();
            case 2:
                if (auth_funcionario(funcionario_vet, MAX))
                {
                    printf("\nfuncionario passou\n");
                }
                else
                {
                    printf("\nDados incorretos\n");
                }
                break;
            case 3:

                break;
            case 4:

                break;
            case 0:
                exit(EXIT_SUCCESS);
                break;
            default:
                isValid = false;
                break;
            }
        } while (!isValid);

    } while (true);
}

login_t auth()
{

    login_t login_local;

    printf("\nUsuario:\n");
    ler_string(login_local.usuario, sizeof(login_local.usuario));

    printf("\nSenha:\n");
    ler_string(login_local.senha, sizeof(login_local.senha));

    return login_local;
}

bool auth(login_t login1, login_t login2)
{

    if (strcmp(login1.usuario, login2.usuario) == 0)
    {
        if (strcmp(login1.senha, login2.senha) == 0)
        {
            return true;
        }
    }
    return false;
}
bool auth_adm(login_t adm)
{
    login_t login = auth();

    return auth(login, adm);
}
bool auth_funcionario(funcionario_t funcionario_vet[], int tam)
{
    login_t login = auth();

    for (int i = 0; i < tam; i++)
    {
        if (funcionario_vet[i].exist)
        {
            if (auth(login, funcionario_vet[i].login))
            {
                return true;
            }
        }
    }
    return false;
}
void menu_adm(funcionario_t funcionario_vet[],
              especialidade_t especialidade_vet[],
              medico_t medico_vet[],
              paciente_t paciente_vet[])
{
    bool continuar = true;
    do
    {
        printf("\n1- Cadastro");
        printf("\n2- Exibir");
        printf("\n3- Deletar");
        printf("\n4- Alterar");
        printf("\n0- Sair");

        bool isValid = true;
        int op = 0;
        do
        {
            printf("\n>");
            scanf("%d", &op);

            switch (op)
            {
                //Cadastro
            case 1:
                create_function(funcionario_vet, MAX);
                break;
                //Exibir
            case 2:

                read_function(funcionario_vet[read_function(funcionario_vet, MAX)]);
                break;
                //Deletar
            case 3:
                delete_function(funcionario_vet, MAX);
                break;
                //Alterar
            case 4:
                update_function(funcionario_vet, MAX);
                break;
                //Sair
            case 0:
                continuar = false;
                break;
            default:
                isValid = false;
                break;
            }
        } while (!isValid);
    } while (continuar);
}

login_t create_login()
{

    login_t login;

    printf("\nUsuario:\n");
    ler_string(login.usuario, sizeof(login.usuario));
    printf("\nSenha:\n");
    ler_string(login.senha, sizeof(login.senha));

    return login;
}

/*
crud funcionario

*/

void create_function(funcionario_t funcionario_vet[], int tam)
{
    for (size_t i = 0; i < tam; i++)
    {
        create_function(&funcionario_vet[i]);
    }
}
void create_function(funcionario_t *funcionario)
{
    printf("\n----------------------------------\n");
    printf("\nMatricula:\n");
    ler_string(funcionario->matricula, sizeof(funcionario->matricula));
    printf("\nNome:\n");
    ler_string(funcionario->nome, sizeof(funcionario->nome));
    funcionario->login = create_login();
    funcionario->exist = true;
}
int read_function(funcionario_t funcionario_vet[], int tam)
{
    int op;
    for (int i = 0; i < tam; i++)
    {
        if (funcionario_vet[i].exist)
        {
            printf("\n%d - %s", i, funcionario_vet[i].nome);
        }
    }
    printf("\n----------------------------------\n");
    printf("\nSelecione um Funcionario\n");
    do
    {
        printf(">");
        scanf("%d", &op);
    } while (op < 0 || op > tam);
    return op;
}
void read_function(funcionario_t funcionario)
{
    if (funcionario.exist)
    {
        printf("\n----------------------------------");
        printf("\nMatricula:%s", funcionario.matricula);
        printf("\nNome:%s", funcionario.nome);
        printf("\nUsuário:%s", funcionario.login.usuario);
        printf("\n----------------------------------\n");
    }
    else
    {
        printf("\nFuncionario não existe\n");
    }
}
void delete_function(funcionario_t funcionario_vet[], int tam)
{

    int op = read_function(funcionario_vet, tam);

    if (funcionario_vet[op].exist)
    {
        funcionario_vet[op].exist = false;
        printf("\nFuncionario %s foi deletado\n", funcionario_vet[op].nome);
    }
    else
    {
        printf("\nFuncionario não existe\n");
    }
}

void update_function(funcionario_t funcionario_vet[], int tam)
{
    int op = read_function(funcionario_vet, tam);

    if (funcionario_vet[op].exist)
    {
        create_function(&funcionario_vet[op]);
        printf("\nFuncionario %s foi atualizado\n", funcionario_vet[op].nome);
    }
    else
    {
        printf("\nFuncionario não existe\n");
    }
}
