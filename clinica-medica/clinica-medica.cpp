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
    bool exist;
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

void menu_login(login_t adm, funcionario_t funcionario_vet[],
                especialidade_t especialidade_vet[],
                medico_t medico_vet[],
                paciente_t paciente_vet[]);
void menu_adm(funcionario_t funcionario_vet[],
              especialidade_t especialidade_vet[],
              medico_t medico_vet[],
              paciente_t paciente_vet[]);

void menu_adm_create(funcionario_t funcionario_vet[],
                     especialidade_t especialidade_vet[],
                     medico_t medico_vet[],
                     paciente_t paciente_vet[]);
void menu_adm_read(funcionario_t funcionario_vet[],
                   especialidade_t especialidade_vet[],
                   medico_t medico_vet[],
                   paciente_t paciente_vet[]);
void menu_adm_delete(funcionario_t funcionario_vet[],
                     especialidade_t especialidade_vet[],
                     medico_t medico_vet[],
                     paciente_t paciente_vet[]);
void menu_adm_update(funcionario_t funcionario_vet[],
                     especialidade_t especialidade_vet[],
                     medico_t medico_vet[],
                     paciente_t paciente_vet[]);

void menu_funcionario(paciente_t paciente_vet[], int tam);
void menu_medico(paciente_t paciente_vet[], int tam);

void limpar_tela();
void pausar_limpar_tela();
void gerar_dados(funcionario_t funcionario_vet[],
                 especialidade_t especialidade_vet[],
                 medico_t medico_vet[],
                 paciente_t paciente_vet[]);

void inicializador(login_t *adm, funcionario_t funcionario_vet[],
                   especialidade_t especialidade_vet[],
                   medico_t medico_vet[],
                   paciente_t paciente_vet[]);

login_t auth(login_t login);
bool auth(login_t login1, login_t login2);
bool auth_adm(login_t adm);
bool auth_funcionario(funcionario_t funcionario_vet[], int tam);
bool auth_medico(medico_t medico_vet[], int tam);

char *ler_string(char *string, int tam);

login_t create_login();

void create_funcionario(funcionario_t funcionario_vet[], int tam);
void create_funcionario(funcionario_t *funcionario);
int read_funcionario(funcionario_t funcionario_vet[], int tam);
void read_funcionario(funcionario_t funcionario);
void delete_funcionario(funcionario_t funcionario_vet[], int tam);
void update_funcionario(funcionario_t funcionario_vet[], int tam);

void create_paciente(paciente_t paciente_vet[], int tam);
void create_paciente(paciente_t *paciente);
int read_paciente(paciente_t paciente_vet[], int tam);
void read_paciente(paciente_t paciente);
void delete_paciente(paciente_t paciente_vet[], int tam);
void update_paciente(paciente_t paciente_vet[], int tam);

void create_especialidade(especialidade_t especialidade_vet[], int tam);
void create_especialidade(especialidade_t *especialidade);
int read_especialidade(especialidade_t especialidade_vet[], int tam);
void read_especialidade(especialidade_t especialidade);
void delete_especialidade(especialidade_t especialidade_vet[], int tam);
void update_especialidade(especialidade_t especialidade_vet[], int tam);

void create_medico(medico_t medico_vet[], int tam_medico_vet, especialidade_t especialidade_vet[], int tam_especialidade_vet);
void create_medico(medico_t *medico, especialidade_t especialidade_vet[], int tam);
int read_medico(medico_t medico_vet[], int tam);
void read_medico(medico_t medico);
void delete_medico(medico_t medico_vet[], int tam);
void update_medico(medico_t medico_vet[], int tam_medico_vet, especialidade_t especialidade_vet[], int tam_especialidade_vet);

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    login_t adm;
    funcionario_t funcionario_vet[MAX];
    especialidade_t especialidade_vet[MAX];
    medico_t medico_vet[MAX];
    paciente_t paciente_vet[MAX];

    inicializador(&adm,
                  funcionario_vet,
                  especialidade_vet,
                  medico_vet,
                  paciente_vet);

    menu_login(adm,
               funcionario_vet,
               especialidade_vet,
               medico_vet,
               paciente_vet);

    printf("\n\n");
    return EXIT_SUCCESS;
}

void limpar_tela()
{
    __WIN32 ? system("cls") : system("clear");

} //fim procedimento limpar_tela

void pausar_limpar_tela()
{
    printf("\n\n");
     __WIN32 ? system("pause") :system("read -p \"Pressione enter para continuar\" saindo");
    limpar_tela();
} //fim procedimento pausar_limpar_tela

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
    printf("\nUsuario padrão:adm\n");
    printf("\nSenha padrão:123\n");
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
bool auth_medico(medico_t medico_vet[], int tam)
{
    login_t login = auth();

    for (int i = 0; i < tam; i++)
    {
        if (medico_vet[i].exist)
        {
            if (auth(login, medico_vet[i].login))
            {
                return true;
            }
        }
    }
    return false;
}
paciente_t auth_paciente(paciente_t paciente_vet[], int tam)
{
    login_t login = auth();

    for (int i = 0; i < tam; i++)
    {
        if (paciente_vet[i].exist)
        {
            if (auth(login, paciente_vet[i].login))
            {
                return paciente_vet[i];
            }
        }
    }
    paciente_t paciente_falso;
    paciente_falso.exist = false;
    return paciente_falso;
}

void menu_login(login_t adm, funcionario_t funcionario_vet[],
                especialidade_t especialidade_vet[],
                medico_t medico_vet[],
                paciente_t paciente_vet[])
{
    do
    {
        limpar_tela();

        printf("\n1-ADM");
        printf("\n2-Funcionario");
        printf("\n3-Medico");
        //printf("\n4-Paciente");
        printf("\n0-Sair");

        bool is_valid = true;
        int op = 0;
        do
        {

            printf("\n>");
            scanf("%d", &op);
            switch (op)
            {
            case 1:
                //ADM
                limpar_tela();
                if (auth_adm(adm))
                    menu_adm(funcionario_vet,
                             especialidade_vet,
                             medico_vet,
                             paciente_vet);
                else
                    printf("\nDados incorretos\n");

                break;
                //Funcionario
                void menu_login();
            case 2:
                limpar_tela();
                if (auth_funcionario(funcionario_vet, MAX))
                    menu_funcionario(paciente_vet, MAX);
                else
                    printf("\nDados incorretos\n");

                break;
            case 3:
                limpar_tela();
                limpar_tela();
                if (auth_medico(medico_vet, MAX))
                    menu_medico(paciente_vet, MAX);
                else
                    printf("\nDados incorretos\n");

                break;
                //  case 4:
                //    limpar_tela();
                //paciente_t paciente = auth_paciente(paciente_vet, MAX);
                //if (paciente.exist)
                //{
                //    printf("\nfuncionario passou\n");
                // }
                // else
                //{
                //    printf("\nDados incorretos\n");
                //}
                //  break;
            case 0:
                limpar_tela();
                exit(EXIT_SUCCESS);
                break;
            default:
                is_valid = false;
                break;
            }
        } while (!is_valid);

    } while (true);
}

//Menus adm

void menu_adm(funcionario_t funcionario_vet[],
              especialidade_t especialidade_vet[],
              medico_t medico_vet[],
              paciente_t paciente_vet[])
{
    bool continuar = true;
    do
    {
        limpar_tela();
        printf("\n1- Cadastro");
        printf("\n2- Exibir");
        printf("\n3- Deletar");
        printf("\n4- Alterar");
        printf("\n0- Sair");

        bool is_valid = true;
        int op = 0;
        do
        {
            printf("\n>");
            scanf("%d", &op);

            switch (op)
            {
                //Cadastro
            case 1:
                limpar_tela();
                menu_adm_create(funcionario_vet,
                                especialidade_vet,
                                medico_vet,
                                paciente_vet);
                break;
                //Exibir
            case 2:
                limpar_tela();
                menu_adm_read(funcionario_vet,
                              especialidade_vet,
                              medico_vet,
                              paciente_vet);
                break;
                //Deletar
            case 3:
                limpar_tela();
                menu_adm_delete(funcionario_vet,
                                especialidade_vet,
                                medico_vet,
                                paciente_vet);
                break;
                //Alterar
            case 4:
                limpar_tela();
                menu_adm_update(funcionario_vet,
                                especialidade_vet,
                                medico_vet,
                                paciente_vet);
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

void menu_adm_create(funcionario_t funcionario_vet[],
                     especialidade_t especialidade_vet[],
                     medico_t medico_vet[],
                     paciente_t paciente_vet[])
{
    bool continuar = true;
    do
    {
        limpar_tela();
        printf("\n1-Especialidade");
        printf("\n2-Funcionario");
        printf("\n3-Medico");
        printf("\n4-Paciente");
        printf("\n5-Gerar Dados");
        printf("\n0-Sair");

        bool is_valid = true;
        int op = 0;
        do
        {
            printf("\n>");
            scanf("%d", &op);

            switch (op)
            {
                //Especialidade
            case 1:
                limpar_tela();
                create_especialidade(especialidade_vet, MAX);
                break;
                //Funcionario
            case 2:
                limpar_tela();
                create_funcionario(funcionario_vet, MAX);
                break;
                //Medico
            case 3:
                limpar_tela();
                create_medico(medico_vet, MAX, especialidade_vet, MAX);
                break;
                //Paciente
            case 4:
                limpar_tela();
                create_paciente(paciente_vet, MAX);
                break;
                //Gerar Dados
            case 5:
                limpar_tela();
                gerar_dados(funcionario_vet,
                            especialidade_vet,
                            medico_vet,
                            paciente_vet);
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
void menu_adm_read(funcionario_t funcionario_vet[],
                   especialidade_t especialidade_vet[],
                   medico_t medico_vet[],
                   paciente_t paciente_vet[])
{
    bool continuar = true;
    do
    {
        limpar_tela();
        printf("\n1-Especialidade");
        printf("\n2-Funcionario");
        printf("\n3-Medico");
        printf("\n4-Paciente");
        printf("\n0-Sair");

        bool is_valid = true;
        int op = 0;
        do
        {
            printf("\n>");
            scanf("%d", &op);

            switch (op)
            {
                //Especialidade
            case 1:
                limpar_tela();
                read_especialidade(especialidade_vet[read_especialidade(especialidade_vet, MAX)]);
                break;
                //Funcionario
            case 2:
                limpar_tela();
                read_funcionario(funcionario_vet[read_funcionario(funcionario_vet, MAX)]);
                break;
                //Medico
            case 3:
                limpar_tela();
                read_medico(medico_vet[read_medico(medico_vet, MAX)]);
                break;
                //Paciente
            case 4:
                limpar_tela();
                read_paciente(paciente_vet[read_paciente(paciente_vet, MAX)]);
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

void menu_adm_delete(funcionario_t funcionario_vet[],
                     especialidade_t especialidade_vet[],
                     medico_t medico_vet[],
                     paciente_t paciente_vet[])
{
    bool continuar = true;
    do
    {
        limpar_tela();
        printf("\n1-Especialidade");
        printf("\n2-Funcionario");
        printf("\n3-Medico");
        printf("\n4-Paciente");
        printf("\n0-Sair");

        bool is_valid = true;
        int op = 0;
        do
        {
            printf("\n>");
            scanf("%d", &op);

            switch (op)
            {
                //Especialidade
            case 1:
                limpar_tela();
                delete_especialidade(especialidade_vet, MAX);
                break;
                //Funcionario
            case 2:
                limpar_tela();
                delete_funcionario(funcionario_vet, MAX);
                break;
                //Medico
            case 3:
                limpar_tela();
                delete_medico(medico_vet, MAX);
                break;
                //Paciente
            case 4:
                limpar_tela();
                delete_paciente(paciente_vet, MAX);
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
void menu_adm_update(funcionario_t funcionario_vet[],
                     especialidade_t especialidade_vet[],
                     medico_t medico_vet[],
                     paciente_t paciente_vet[])
{
    bool continuar = true;
    do
    {
        limpar_tela();
        printf("\n1-Especialidade");
        printf("\n2-Funcionario");
        printf("\n3-Medico");
        printf("\n4-Paciente");
        printf("\n0-Sair");

        bool is_valid = true;
        int op = 0;
        do
        {
            printf("\n>");
            scanf("%d", &op);

            switch (op)
            {
                //Especialidade
            case 1:
                limpar_tela();
                update_especialidade(especialidade_vet, MAX);
                break;
                //Funcionario
            case 2:
                limpar_tela();
                update_funcionario(funcionario_vet, MAX);
                break;
                //Medico
            case 3:
                limpar_tela();
                update_medico(medico_vet, MAX, especialidade_vet, MAX);
                break;
                //Paciente
            case 4:
                limpar_tela();
                update_paciente(paciente_vet, MAX);
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

void menu_funcionario(paciente_t paciente_vet[], int tam)
{
    bool continuar = true;
    do
    {
        limpar_tela();
        printf("\n1- Cadastro");
        printf("\n2- Exibir");
        printf("\n0- Sair");

        bool is_valid = true;
        int op = 0;
        do
        {
            printf("\n>");
            scanf("%d", &op);

            switch (op)
            {
                //Cadastro
            case 1:
                limpar_tela();
                create_paciente(paciente_vet, tam);
                break;
                //Exibir
            case 2:
                limpar_tela();
                read_paciente(paciente_vet[read_paciente(paciente_vet, tam)]);

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
void menu_medico(paciente_t paciente_vet[], int tam)
{
    bool continuar = true;
    do
    {
        limpar_tela();
        printf("\n1- Exibir");
        printf("\n0- Sair");

        bool is_valid = true;
        int op = 0;
        do
        {
            printf("\n>");
            scanf("%d", &op);

            switch (op)
            {

                //Exibir
            case 1:
                limpar_tela();
                read_paciente(paciente_vet[read_paciente(paciente_vet, tam)]);

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

void create_funcionario(funcionario_t funcionario_vet[], int tam)
{
    for (size_t i = 0; i < tam; i++)
    {
        create_funcionario(&funcionario_vet[i]);
    }
}
void create_funcionario(funcionario_t *funcionario)
{
    printf("\n----------------------------------\n");
    printf("\nMatricula:\n");
    ler_string(funcionario->matricula, sizeof(funcionario->matricula));
    printf("\nNome:\n");
    ler_string(funcionario->nome, sizeof(funcionario->nome));
    funcionario->login = create_login();
    funcionario->exist = true;
}
int read_funcionario(funcionario_t funcionario_vet[], int tam)
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
void read_funcionario(funcionario_t funcionario)
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
    pausar_limpar_tela();
}
void delete_funcionario(funcionario_t funcionario_vet[], int tam)
{

    int op = read_funcionario(funcionario_vet, tam);

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

void update_funcionario(funcionario_t funcionario_vet[], int tam)
{
    int op = read_funcionario(funcionario_vet, tam);

    if (funcionario_vet[op].exist)
    {
        create_funcionario(&funcionario_vet[op]);
        printf("\nFuncionario %s foi atualizado\n", funcionario_vet[op].nome);
    }
    else
    {
        printf("\nFuncionario não existe\n");
    }
}

/*
crud paciente

*/

void create_paciente(paciente_t paciente_vet[], int tam)
{
    for (size_t i = 0; i < tam; i++)
    {
        create_paciente(&paciente_vet[i]);
    }
}
void create_paciente(paciente_t *paciente)
{
    printf("\n----------------------------------\n");
    printf("\nCPF:\n");
    ler_string(paciente->cpf, sizeof(paciente->cpf));
    printf("\nNome:\n");
    ler_string(paciente->nome, sizeof(paciente->nome));
    paciente->login = create_login();
    paciente->exist = true;
}
int read_paciente(paciente_t paciente_vet[], int tam)
{
    int op;
    for (int i = 0; i < tam; i++)
    {

        if (paciente_vet[i].exist)
        {
            printf("\n%d - %s", i, paciente_vet[i].nome);
        }
    }
    printf("\n----------------------------------\n");
    printf("\nSelecione um Paciente\n");
    do
    {
        printf(">");
        scanf("%d", &op);
    } while (op < 0 || op > tam);
    return op;
}
void read_paciente(paciente_t paciente)
{
    if (paciente.exist)
    {
        printf("\n----------------------------------");
        printf("\nCPF:%s", paciente.cpf);
        printf("\nNome:%s", paciente.nome);
        printf("\nTelefone:%s", paciente.telefone);
        printf("\nUsuário:%s", paciente.login.usuario);
        printf("\n----------------------------------\n");
    }
    else
    {
        printf("\nPaciente não existe\n");
    }
    pausar_limpar_tela();
}
void delete_paciente(paciente_t paciente_vet[], int tam)
{

    int op = read_paciente(paciente_vet, tam);

    if (paciente_vet[op].exist)
    {
        paciente_vet[op].exist = false;
        printf("\nPaciente %s foi deletado\n", paciente_vet[op].nome);
    }
    else
    {
        printf("\nPaciente não existe\n");
    }
}
void update_paciente(paciente_t paciente_vet[], int tam)
{
    int op = read_paciente(paciente_vet, tam);

    if (paciente_vet[op].exist)
    {
        create_paciente(&paciente_vet[op]);
        printf("\nPaciente %s foi atualizado\n", paciente_vet[op].nome);
    }
    else
    {
        printf("\nPaciente não existe\n");
    }
}

/*
crud especialidade

*/

void create_especialidade(especialidade_t especialidade_vet[], int tam)
{
    for (size_t i = 0; i < tam; i++)
    {
        create_especialidade(&especialidade_vet[i]);
    }
}
void create_especialidade(especialidade_t *especialidade)
{
    printf("\n----------------------------------\n");
    printf("\nCode:\n");
    scanf("%d", especialidade->cod);
    printf("\nNome:\n");
    ler_string(especialidade->nome, sizeof(especialidade->nome));

    especialidade->exist = true;
}
int read_especialidade(especialidade_t especialidade_vet[], int tam)
{
    int op;
    for (int i = 0; i < tam; i++)
    {
        if (especialidade_vet[i].exist)
        {
            printf("\n%d - %s", i, especialidade_vet[i].nome);
        }
    }
    printf("\n----------------------------------\n");
    printf("\nSelecione uma Especialidade\n");
    do
    {
        printf(">");
        scanf("%d", &op);
    } while (op < 0 || op > tam);
    return op;
}
void read_especialidade(especialidade_t especialidade)
{
    if (especialidade.exist)
    {
        printf("\n----------------------------------");

        printf("\nNome:%s", especialidade.nome);
        printf("\nCodigo:%d", especialidade.cod);
        printf("\n----------------------------------\n");
    }
    else
    {
        printf("\nEspecialidade não existe\n");
    }
    pausar_limpar_tela();
}
void delete_especialidade(especialidade_t especialidade_vet[], int tam)
{

    int op = read_especialidade(especialidade_vet, tam);

    if (especialidade_vet[op].exist)
    {
        especialidade_vet[op].exist = false;
        printf("\nEspecialidade %s foi deletado\n", especialidade_vet[op].nome);
    }
    else
    {
        printf("\nEspecialidade não existe\n");
    }
}
void update_especialidade(especialidade_t especialidade_vet[], int tam)
{
    int op = read_especialidade(especialidade_vet, tam);

    if (especialidade_vet[op].exist)
    {
        create_especialidade(&especialidade_vet[op]);
        printf("\nEspecialidade %s foi atualizado\n", especialidade_vet[op].nome);
    }
    else
    {
        printf("\nEspecialidade não existe\n");
    }
}

/*
crud medico 

*/

void create_medico(medico_t medico_vet[], int tam_medico_vet, especialidade_t especialidade_vet[], int tam_especialidade_vet)
{
    for (size_t i = 0; i < tam_medico_vet; i++)
    {
        create_medico(&medico_vet[i], especialidade_vet, tam_especialidade_vet);
    }
}
void create_medico(medico_t *medico, especialidade_t especialidade_vet[], int tam)
{
    printf("\n----------------------------------\n");
    printf("\nCRM:\n");
    ler_string(medico->crm, sizeof(medico->crm));
    printf("\nNome:\n");
    ler_string(medico->nome, sizeof(medico->nome));
    int op = read_especialidade(especialidade_vet, tam);
    medico->especialidade = especialidade_vet[op];
    medico->login = create_login();
    medico->exist = true;
}
int read_medico(medico_t medico_vet[], int tam)
{
    int op;
    for (int i = 0; i < tam; i++)
    {

        if (medico_vet[i].exist)
        {
            printf("\n%d - %s", i, medico_vet[i].nome);
        }
    }
    printf("\n----------------------------------\n");
    printf("\nSelecione um Medico\n");
    do
    {
        printf(">");
        scanf("%d", &op);
    } while (op < 0 || op > tam);
    return op;
}
void read_medico(medico_t medico)
{
    if (medico.exist)
    {
        printf("\n----------------------------------");
        printf("\nCPF:%s", medico.crm);
        printf("\nNome:%s", medico.nome);
        printf("\nEspecialidade:%s", medico.especialidade.nome);
        printf("\nUsuário:%s", medico.login.usuario);
        printf("\n----------------------------------\n");
    }
    else
    {
        printf("\nMedico não existe\n");
    }
    pausar_limpar_tela();
}
void delete_medico(medico_t medico_vet[], int tam)
{

    int op = read_medico(medico_vet, tam);

    if (medico_vet[op].exist)
    {
        medico_vet[op].exist = false;
        printf("\nMedico %s foi deletado\n", medico_vet[op].nome);
    }
    else
    {
        printf("\nMedico não existe\n");
    }
}
void update_medico(medico_t medico_vet[], int tam_medico_vet, especialidade_t especialidade_vet[], int tam_especialidade_vet)
{
    int op = read_medico(medico_vet, tam_medico_vet);

    if (medico_vet[op].exist)
    {
        create_medico(&medico_vet[op], especialidade_vet, tam_especialidade_vet);
        printf("\nMedico %s foi atualizado\n", medico_vet[op].nome);
    }
    else
    {
        printf("\nMedico não existe\n");
    }
}

void gerar_dados(funcionario_t funcionario_vet[],
                 especialidade_t especialidade_vet[],
                 medico_t medico_vet[],
                 paciente_t paciente_vet[])
{
    printf("\nGerando dados...\n");
    printf("\nFuncionarios...");
    //gerar dados de funcionario
    for (int i = 0; i < MAX; i++)
    {
        sprintf(funcionario_vet[i].nome, "funcionario %d", i);
        sprintf(funcionario_vet[i].matricula, "%d%d", i, i);
        sprintf(funcionario_vet[i].login.usuario, "fun%d", i);
        sprintf(funcionario_vet[i].login.senha, "%d%d%d", i, i, i);
        funcionario_vet[i].exist = true;
    }
    printf("\nPacientes...");
    //gerar dados de paciente
    for (int i = 0; i < MAX; i++)
    {
        sprintf(paciente_vet[i].nome, "paciente %d", i);
        sprintf(paciente_vet[i].cpf, "%d%d", i, i);
        sprintf(paciente_vet[i].login.usuario, "pac%d", i);
        sprintf(paciente_vet[i].login.senha, "%d%d%d", i, i, i);
        paciente_vet[i].exist = true;
    }
    printf("\nEspecialidades...");
    //gerar dados de especialidade
    for (int i = 0; i < MAX; i++)
    {
        sprintf(especialidade_vet[i].nome, "especialidade %d", i);
        especialidade_vet[i].cod = i + 10;
        especialidade_vet[i].exist = true;
    }
    printf("\nMedicos...");
    //gerar dados de medico
    for (int i = 0; i < MAX; i++)
    {
        sprintf(medico_vet[i].nome, "medico %d", i);
        sprintf(medico_vet[i].crm, "%d%d", i, i);
        sprintf(medico_vet[i].login.usuario, "med%d", i);
        sprintf(medico_vet[i].login.senha, "%d%d%d", i, i, i);
        medico_vet[i].especialidade = especialidade_vet[i];
        medico_vet[i].exist = true;
    }

    printf("\nDados gerados com sucesso\n");
    pausar_limpar_tela();
}

void inicializador(login_t *adm, funcionario_t funcionario_vet[],
                   especialidade_t especialidade_vet[],
                   medico_t medico_vet[],
                   paciente_t paciente_vet[])
{
    // inicializar adm
    sprintf(adm->usuario, "adm");
    sprintf(adm->senha, "123");

    // inicializar vetor funcionario
    for (int i = 0; i < MAX; i++)
        funcionario_vet[i].exist = false;

    //inicializar vetor paciente
    for (int i = 0; i < MAX; i++)
        paciente_vet[i].exist = false;

    //inicializar vetor especialidade
    for (int i = 0; i < MAX; i++)
        especialidade_vet[i].exist = false;

    //inicializar vetor medico
    for (int i = 0; i < MAX; i++)
        medico_vet[i].exist = false;
}