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

/* testes: minunit */
#define mu_assert(message, test) \
    do                           \
    {                            \
        if (!(test))             \
            return message;      \
    } while (0)
#define mu_run_test(test)       \
    do                          \
    {                           \
        char *message = test(); \
        if (message)            \
            return message;     \
    } while (0)

#define MAX 2

typedef struct
{
    char cod[3];
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

typedef enum
{
    ADM,
    PACIENTE,
    MEDICO,
    FUNCIONARIO,
    ESPECIALIDADE
} tipo_t;

typedef struct
{
    login_t adm;
    funcionario_t funcionario_vet[MAX];
    especialidade_t especialidade_vet[MAX];
    medico_t medico_vet[MAX];
    paciente_t paciente_vet[MAX];
} vets_t;

//teste
void main_teste();
char *all_tests();

void menu_login(vets_t *dados);
void menu_adm(vets_t *dados);

void menu_adm_create(vets_t *dados);
void menu_adm_read(vets_t *dados);
void menu_adm_delete(vets_t *dados);
void menu_adm_update(vets_t *dados);

void menu_funcionario(vets_t *dados);
void menu_medico(vets_t *dados);

void limpar_tela();
void pausar_limpar_tela();
void gerar_dados(vets_t *dados);

void inicializador(vets_t *dados);

login_t auth();
bool auth(login_t login1, login_t login2);
bool auth(tipo_t tipo, vets_t *dados, int tam);

char *ler_string(char *string, int tam);

void create_tipo(tipo_t tipo, vets_t *dados, int tam);
void delete_tipo(tipo_t tipo, vets_t *dados, int tam);
void update_tipo(tipo_t tipo, vets_t *dados, int tam);

void create_funcionario(funcionario_t *funcionario);
int read_funcionario(funcionario_t funcionario_vet[], int tam);
void read_funcionario(funcionario_t funcionario);
void update_funcionario(funcionario_t funcionario_vet[], int tam);

void create_paciente(paciente_t *paciente);
int read_paciente(paciente_t paciente_vet[], int tam);
void read_paciente(paciente_t paciente);
void update_paciente(paciente_t paciente_vet[], int tam);

void create_especialidade(especialidade_t *especialidade);
int read_especialidade(especialidade_t especialidade_vet[], int tam);
void read_especialidade(especialidade_t especialidade);
void update_especialidade(especialidade_t especialidade_vet[], int tam);

void create_medico(medico_t *medico, especialidade_t especialidade_vet[], int tam);
int read_medico(medico_t medico_vet[], int tam);
void read_medico(medico_t medico);
void update_medico(medico_t medico_vet[], int tam_medico_vet, especialidade_t especialidade_vet[], int tam_especialidade_vet);

int main()
{

    setlocale(LC_ALL, "Portuguese_Brazil");

    // // main_teste();

    vets_t dados;
    inicializador(&dados);
    menu_login(&dados);

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
    __WIN32 ? system("pause") : system("read -p \"Pressione enter para continuar\" saindo");
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

    login_t login;

    printf("\nUsuario:\n");
    ler_string(login.usuario, sizeof(login.usuario));
    printf("\nSenha:\n");
    ler_string(login.senha, sizeof(login.senha));

    return login;
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

bool auth(tipo_t tipo, vets_t *dados, int tam)
{

    login_t login1 = auth();
    login_t login2 = {{usuario : ""}, {senha : ""}};

    switch (tipo)
    {
    case ADM:
        login2 = dados->adm;
        break;

    case MEDICO:
        for (int i = 0; i < tam; i++)
            if (dados->medico_vet[i].exist)
                login2 = dados->medico_vet[i].login;
        break;

    case FUNCIONARIO:
        for (int i = 0; i < tam; i++)
            if (dados->funcionario_vet[i].exist)
                login2 = dados->funcionario_vet[i].login;
        break;

    case PACIENTE:
        for (int i = 0; i < tam; i++)
            if (dados->paciente_vet[i].exist)
                login2 = dados->paciente_vet[i].login;
        break;

    default:
        printf("\n(auth) tipo_t invalido\n");
        exit(EXIT_FAILURE);
        break;
    }
    return auth(login1, login2);
}

void menu_login(vets_t *dados)
{
    do
    {
        limpar_tela();
        printf("\nUsuario padrão para adm:adm");
        printf("\nSenha padrão para adm:123\n\n");

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
                if (auth(ADM, dados, 0))
                    menu_adm(dados);
                break;

                //Funcionario
            case 2:
                limpar_tela();
                if (auth(FUNCIONARIO, dados, MAX))
                    menu_funcionario(dados);
                break;

                //Medico
            case 3:
                limpar_tela();
                if (auth(MEDICO, dados, MAX))
                    menu_medico(dados);
                break;

                //paciente
            case 4:
                limpar_tela();
                if (auth(PACIENTE, dados, MAX)){
                    }
                break;

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

void menu_adm(vets_t *dados)
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
                menu_adm_create(dados);
                break;
                //Exibir
            case 2:
                limpar_tela();
                menu_adm_read(dados);
                break;
                //Deletar
            case 3:
                limpar_tela();
                menu_adm_delete(dados);
                break;
                //Alterar
            case 4:
                limpar_tela();
                menu_adm_update(dados);
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

void menu_adm_create(vets_t *dados)
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
                create_tipo(ESPECIALIDADE, dados, MAX);
                break;
                //Funcionario
            case 2:
                limpar_tela();
                create_tipo(FUNCIONARIO, dados, MAX);
                break;
                //Medico
            case 3:
                limpar_tela();
                create_tipo(MEDICO, dados, MAX);
                break;
                //Paciente
            case 4:
                limpar_tela();
                create_tipo(PACIENTE, dados, MAX);
                break;
                //Gerar Dados
            case 5:
                limpar_tela();
                gerar_dados(dados);
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

void menu_adm_read(vets_t *dados)
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
                read_especialidade(dados->especialidade_vet[read_especialidade(dados->especialidade_vet, MAX)]);
                break;
                //Funcionario
            case 2:
                limpar_tela();
                read_funcionario(dados->funcionario_vet[read_funcionario(dados->funcionario_vet, MAX)]);
                break;
                //Medico
            case 3:
                limpar_tela();
                read_medico(dados->medico_vet[read_medico(dados->medico_vet, MAX)]);
                break;
                //Paciente
            case 4:
                limpar_tela();
                read_paciente(dados->paciente_vet[read_paciente(dados->paciente_vet, MAX)]);
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

void menu_adm_delete(vets_t *dados)
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
                delete_tipo(ESPECIALIDADE, dados, MAX);
                break;
                //Funcionario
            case 2:
                limpar_tela();
                delete_tipo(FUNCIONARIO, dados, MAX);
                break;
                //Medico
            case 3:
                limpar_tela();
                delete_tipo(MEDICO, dados, MAX);
                break;
                //Paciente
            case 4:
                limpar_tela();
                delete_tipo(PACIENTE, dados, MAX);
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

void menu_adm_update(vets_t *dados)
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
                update_tipo(ESPECIALIDADE, dados, MAX);
                break;
                //Funcionario
            case 2:
                limpar_tela();
                update_tipo(FUNCIONARIO, dados, MAX);
                break;
                //Medico
            case 3:
                limpar_tela();
                update_tipo(MEDICO, dados, MAX);
                break;
                //Paciente
            case 4:
                limpar_tela();
                update_tipo(PACIENTE, dados, MAX);
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

void menu_funcionario(vets_t *dados)
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
                create_tipo(FUNCIONARIO, dados, MAX);
                break;
                //Exibir
            case 2:
                limpar_tela();
                read_paciente(dados->paciente_vet[read_paciente(dados->paciente_vet, MAX)]);

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

void menu_medico(vets_t *dados)
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
                read_paciente(dados->paciente_vet[read_paciente(dados->paciente_vet, MAX)]);

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

//CRUD

void create_tipo(tipo_t tipo, vets_t *dados, int tam)
{

    switch (tipo)
    {
    case ESPECIALIDADE:
    {
        for (int i = 0; i < tam; i++)
            create_especialidade(&dados->especialidade_vet[i]);
        break;
    }

    case MEDICO:
    {
        for (int i = 0; i < tam; i++)
            create_medico(&dados->medico_vet[i], dados->especialidade_vet, tam);
        break;
    }

    case FUNCIONARIO:
    {
        for (int i = 0; i < tam; i++)
            create_funcionario(&dados->funcionario_vet[i]);
        break;
    }

    case PACIENTE:
    {
        for (int i = 0; i < tam; i++)
            create_paciente(&dados->paciente_vet[i]);
        break;
    }
    default:
        printf("\n(create_tipo) tipo_t invalido\n");
        exit(EXIT_FAILURE);
        break;
    }
}

void delete_tipo(tipo_t tipo, vets_t *dados, int tam)
{
    int op = 0;

    switch (tipo)
    {
    case ESPECIALIDADE:
    {
        op = read_especialidade(dados->especialidade_vet, tam);
        if (dados->especialidade_vet[op].exist)
            dados->especialidade_vet[op].exist = false;
        break;
    }

    case MEDICO:
    {
        op = read_medico(dados->medico_vet, tam);
        if (dados->medico_vet[op].exist)
            dados->medico_vet[op].exist = false;
        break;
    }

    case FUNCIONARIO:
    {
        op = read_funcionario(dados->funcionario_vet, tam);
        if (dados->funcionario_vet[op].exist)
            dados->funcionario_vet[op].exist = false;
        break;
    }

    case PACIENTE:
    {
        op = read_paciente(dados->paciente_vet, tam);
        if (dados->paciente_vet[op].exist)
            dados->paciente_vet[op].exist = false;
        break;
    }
    default:
        printf("\n(delete_tipo) tipo_t invalido\n");
        exit(EXIT_FAILURE);
        break;
    }
}

void update_tipo(tipo_t tipo, vets_t *dados, int tam)
{
    int op = 0;

    switch (tipo)
    {
    case ESPECIALIDADE:
    {
        op = read_especialidade(dados->especialidade_vet, tam);
        if (dados->especialidade_vet[op].exist)
            create_especialidade(&dados->especialidade_vet[op]);
        break;
    }

    case MEDICO:
    {
        op = read_medico(dados->medico_vet, tam);
        if (dados->medico_vet[op].exist)
            create_medico(&dados->medico_vet[op], dados->especialidade_vet, tam);
        break;
    }

    case FUNCIONARIO:
    {
        op = read_funcionario(dados->funcionario_vet, tam);
        if (dados->funcionario_vet[op].exist)
            create_funcionario(&dados->funcionario_vet[op]);
        break;
    }

    case PACIENTE:
    {
        op = read_paciente(dados->paciente_vet, tam);
        if (dados->paciente_vet[op].exist)
            create_paciente(&dados->paciente_vet[op]);
        break;
    }
    default:
        printf("\n(delete_tipo) tipo_t invalido\n");
        exit(EXIT_FAILURE);
        break;
    }
}

/*
crud funcionario

*/

void create_funcionario(funcionario_t *funcionario)
{
    printf("\n----------------------------------\n");
    printf("\nMatricula:\n");
    ler_string(funcionario->matricula, sizeof(funcionario->matricula));
    printf("\nNome:\n");
    ler_string(funcionario->nome, sizeof(funcionario->nome));
    funcionario->login = auth();
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

/*
crud paciente

*/

void create_paciente(paciente_t *paciente)
{
    printf("\n----------------------------------\n");
    printf("\nCPF:\n");
    ler_string(paciente->cpf, sizeof(paciente->cpf));
    printf("\nNome:\n");
    ler_string(paciente->nome, sizeof(paciente->nome));
    paciente->login = auth();
    paciente->exist = true;
}
int read_paciente(paciente_t paciente_vet[], int tam)
{
    int op;
    for (int i = 0; i < tam; i++)
        if (paciente_vet[i].exist)
            printf("\n%d - %s", i, paciente_vet[i].nome);

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

/*
crud especialidade

*/

void create_especialidade(especialidade_t *especialidade)
{
    printf("\n----------------------------------\n");
    printf("\nCode:\n");
    ler_string(especialidade->cod, sizeof(especialidade->cod));
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
        printf("\nCódigo:%s", especialidade.cod);
        printf("\n----------------------------------\n");
    }
    else
    {
        printf("\nEspecialidade não existe\n");
    }
    pausar_limpar_tela();
}

/*
crud medico 

*/

void create_medico(medico_t *medico, especialidade_t especialidade_vet[], int tam)
{
    printf("\n----------------------------------\n");
    printf("\nCRM:\n");
    ler_string(medico->crm, sizeof(medico->crm));
    printf("\nNome:\n");
    ler_string(medico->nome, sizeof(medico->nome));
    int op = read_especialidade(especialidade_vet, tam);
    medico->especialidade = especialidade_vet[op];
    medico->login = auth();
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

void gerar_dados(vets_t *dados)
{
    printf("\nGerando dados...\n");
    printf("\nEspecialidades...");
    //gerar dados de especialidade
    for (int i = 0; i < MAX; i++)
    {
        sprintf(dados->especialidade_vet[i].nome, "especialidade %d", i);
        sprintf(dados->especialidade_vet[i].cod, "%d%d%d", i, i, i);
        dados->especialidade_vet[i].exist = true;
    }
    printf("\nFuncionarios...");
    //gerar dados de funcionario
    for (int i = 0; i < MAX; i++)
    {
        sprintf(dados->funcionario_vet[i].nome, "funcionario %d", i);
        sprintf(dados->funcionario_vet[i].matricula, "%d%d", i, i);
        sprintf(dados->funcionario_vet[i].login.usuario, "fun%d", i);
        sprintf(dados->funcionario_vet[i].login.senha, "%d%d%d", i, i, i);
        dados->funcionario_vet[i].exist = true;
    }
    printf("\nPacientes...");
    //gerar dados de paciente
    for (int i = 0; i < MAX; i++)
    {
        sprintf(dados->paciente_vet[i].nome, "paciente %d", i);
        sprintf(dados->paciente_vet[i].cpf, "%d%d", i, i);
        sprintf(dados->paciente_vet[i].login.usuario, "pac%d", i);
        sprintf(dados->paciente_vet[i].login.senha, "%d%d%d", i, i, i);
        dados->paciente_vet[i].exist = true;
    }
    
    printf("\nMedicos...");
    //gerar dados de medico
    for (int i = 0; i < MAX; i++)
    {
        sprintf(dados->medico_vet[i].nome, "medico %d", i);
        sprintf(dados->medico_vet[i].crm, "%d%d", i, i);
        sprintf(dados->medico_vet[i].login.usuario, "med%d", i);
        sprintf(dados->medico_vet[i].login.senha, "%d%d%d", i, i, i);
        dados->medico_vet[i].especialidade = dados->especialidade_vet[i];
        dados->medico_vet[i].exist = true;
    }

    printf("\nDados gerados com sucesso\n");
    pausar_limpar_tela();
}

void inicializador(vets_t *dados)
{
    login_t adm = {{usuario : "adm"}, {senha : "123"}};
    dados->adm = adm;

    // inicializar vetor funcionario
    for (int i = 0; i < MAX; i++)
        dados->funcionario_vet[i].exist = false;

    //inicializar vetor paciente
    for (int i = 0; i < MAX; i++)
        dados->paciente_vet[i].exist = false;

    //inicializar vetor especialidade
    for (int i = 0; i < MAX; i++)
        dados->especialidade_vet[i].exist = false;

    //inicializar vetor medico
    for (int i = 0; i < MAX; i++)
        dados->medico_vet[i].exist = false;
}

/*
area destinada a teste
*/

static char *test_auth(void)
{

    login_t login1 = {{usuario : "adm"}, {senha : "123"}};
    login_t login2 = {{usuario : "adm"}, {senha : "123"}};

    mu_assert("certo, login1 == login2", auth(login1, login2) == true);

    sprintf(login2.senha, "234");
    mu_assert("erro, login1 != login2", auth(login1, login2) != true);

    return 0;
}

char *all_tests()
{
    mu_run_test(test_auth);
    return 0;
}

void main_teste()
{

    char *saida;

    saida = all_tests();

    if (0 != saida)
    {
        puts(saida);
        exit(EXIT_FAILURE);
    }

    puts("TESTES EXECUTADOS COM SUCESSO");

    exit(EXIT_SUCCESS);
}