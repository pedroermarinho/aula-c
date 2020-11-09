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
#define MAX_AGENDA 14

typedef enum
{
    CREATE = 0,
    READ,
    UPDATE,
    DELETE
} crud_t;

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

typedef struct
{
    medico_t medico;
    paciente_t paciente;
    int hora;
    bool exist;
} agenda_t;

typedef struct
{
    login_t adm;
    funcionario_t funcionario_vet[MAX];
    especialidade_t especialidade_vet[MAX];
    medico_t medico_vet[MAX];
    paciente_t paciente_vet[MAX];
    agenda_t agenda_vet[MAX_AGENDA];
} vets_t;

//teste
void main_teste();
char *all_tests();

void menu_login(vets_t *dados);
void menu_adm(vets_t *dados);

void menu_adm_crud(crud_t crud, vets_t *dados);

void menu_funcionario(vets_t *dados);
void menu_medico(vets_t *dados);

void limpar_tela();
void pausar_limpar_tela();
int gerar_dados(vets_t *dados);

int inicializador(vets_t *dados);

login_t auth();
bool auth(login_t login1, login_t login2);
bool auth(tipo_t tipo, vets_t *dados, int tam);

char *ler_string(char *string, int tam);

int create_tipo(tipo_t tipo, vets_t *dados, int tam);
int read_tipo(tipo_t tipo, vets_t *dados, int tam);
int update_tipo(tipo_t tipo, vets_t *dados, int tam);
int delete_tipo(tipo_t tipo, vets_t *dados, int tam);

int create_funcionario(funcionario_t *funcionario);
int read_funcionario(funcionario_t funcionario);

int create_paciente(paciente_t *paciente);
int read_paciente(paciente_t paciente);

int create_especialidade(especialidade_t *especialidade);
int read_especialidade(especialidade_t especialidade);

int create_medico(medico_t *medico, vets_t *dados, int tam_especialidade);
int read_medico(medico_t medico);

paciente_t search(paciente_t paciente_vet[], int tam);

void agendar(vets_t *dados);

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
                string[ultima_letra] = '\0';
        }

        if (strlen(string) == 0)
            valid = false;

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
        if (strcmp(login1.senha, login2.senha) == 0)
            return true;

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

paciente_t search(paciente_t paciente_vet[], int tam)
{
    char cpf[30];
    puts("CPF:");
    ler_string(cpf, sizeof(cpf));

    for (int i = 0; i < tam; i++)
        if (strcmp(paciente_vet[i].cpf, cpf) == 0)
            return paciente_vet[i];
}

void agendar_create(vets_t *dados)
{

    paciente_t paciente = search(dados->paciente_vet, MAX);

    medico_t medico = dados->medico_vet[read_tipo(MEDICO, dados, MAX)];

    puts("\nSelecione um horario entre as 8 a 17:");
    int hora;
    bool valid = true;
    do
    {
        printf(">");
        scanf("%d", &hora);
    } while (hora >= 8 && hora <= 17);

    if (paciente.exist && medico.exist)
    {
        for (int i = 0; i < MAX_AGENDA; i++)
        {
            if (dados->agenda_vet[i].exist)
            {
                if (dados->agenda_vet[i].hora = hora)
                {
                    if (dados->agenda_vet)
                    {
                        
                    }
                    
                }
            }
        }
    }
}

void menu_login(vets_t *dados)
{
    do
    {
        limpar_tela();
        system("title Menu Login");
        puts("Usuario padrão para adm:adm");
        puts("Senha padrão para adm:123\n\n");

        puts("1-ADM");
        puts("2-Funcionario");
        puts("3-Medico");
        //printf("\n4-Paciente");
        puts("0-Sair");

        bool is_valid = true;
        int op = 0;
        do
        {

            printf(">");
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

                //     //paciente
                // case 4:
                //     limpar_tela();
                //     if (auth(PACIENTE, dados, MAX))
                //     {
                //     }
                //     break;

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
        system("title Menu ADM");
        puts("1- Cadastro");
        puts("2- Exibir");
        puts("3- Deletar");
        puts("4- Alterar");
        puts("5- Gerar Dados");
        puts("0- Sair");

        bool is_valid = true;
        int op = 0;
        do
        {
            printf(">");
            scanf("%d", &op);

            switch (op)
            {
                //Cadastro
            case 1:
                limpar_tela();
                system("title Menu Cadastro");
                menu_adm_crud(CREATE, dados);
                break;
                //Exibir
            case 2:
                limpar_tela();
                system("title Menu Leitura");
                menu_adm_crud(READ, dados);
                break;
                //Deletar
            case 3:
                limpar_tela();
                system("title Menu Deletar");
                menu_adm_crud(DELETE, dados);
                break;
                //Alterar
            case 4:
                limpar_tela();
                system("title Menu Alterar");
                menu_adm_crud(UPDATE, dados);
                break;
                //Gerar Dados
            case 5:
                limpar_tela();
                system("title Gerar Dados");
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

void menu_adm_crud(crud_t crud, vets_t *dados)
{
    bool continuar = true, is_valid = true;

    int (*crud_func[])(tipo_t, vets_t *, int) = {
        create_tipo,
        read_tipo,
        update_tipo,
        delete_tipo};

    do
    {
        limpar_tela();
        puts("1-Especialidade");
        puts("2-Funcionario");
        puts("3-Medico");
        puts("4-Paciente");
        puts("0-Sair");

        is_valid = true;
        int op = 0;
        do
        {
            printf(">");
            scanf("%d", &op);

            switch (op)
            {
                //Especialidade
            case 1:
                limpar_tela();
                if (crud == READ)
                    read_especialidade(dados->especialidade_vet[crud_func[crud](ESPECIALIDADE, dados, MAX)]);
                else
                    crud_func[crud](ESPECIALIDADE, dados, MAX);
                break;
                //Funcionario
            case 2:
                limpar_tela();
                if (crud == READ)
                    read_funcionario(dados->funcionario_vet[crud_func[crud](FUNCIONARIO, dados, MAX)]);
                else
                    crud_func[crud](FUNCIONARIO, dados, MAX);
                break;

                //Medico
            case 3:
                limpar_tela();
                if (crud == READ)
                    read_medico(dados->medico_vet[crud_func[crud](MEDICO, dados, MAX)]);
                else
                    crud_func[crud](MEDICO, dados, MAX);
                break;

                //Paciente
            case 4:
                limpar_tela();
                if (crud == READ)
                    read_paciente(dados->paciente_vet[crud_func[crud](PACIENTE, dados, MAX)]);
                else
                    crud_func[crud](PACIENTE, dados, MAX);
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
        puts("1- Cadastro");
        puts("2- Exibir");
        puts("0- Sair");

        bool is_valid = true;
        int op = 0;
        do
        {
            printf(">");
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
                read_paciente(dados->paciente_vet[read_tipo(PACIENTE, dados, MAX)]);
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
        puts("1- Exibir");
        puts("0- Sair");

        bool is_valid = true;
        int op = 0;
        do
        {
            printf(">");
            scanf("%d", &op);

            switch (op)
            {

                //Exibir
            case 1:
                limpar_tela();
                read_paciente(dados->paciente_vet[read_tipo(PACIENTE, dados, MAX)]);
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

int create_tipo(tipo_t tipo, vets_t *dados, int tam)
{

    switch (tipo)
    {
    case ESPECIALIDADE:
        for (int i = 0; i < tam; i++)
            create_especialidade(&dados->especialidade_vet[i]);
        break;

    case MEDICO:
        for (int i = 0; i < tam; i++)
            create_medico(&dados->medico_vet[i], dados, tam);
        break;

    case FUNCIONARIO:
        for (int i = 0; i < tam; i++)
            create_funcionario(&dados->funcionario_vet[i]);
        break;

    case PACIENTE:
        for (int i = 0; i < tam; i++)
            create_paciente(&dados->paciente_vet[i]);
        break;

    default:
        printf("\n(create_tipo) tipo_t invalido\n");
        exit(EXIT_FAILURE);
        break;
    }
    return EXIT_SUCCESS;
}

int delete_tipo(tipo_t tipo, vets_t *dados, int tam)
{
    int op = 0;

    switch (tipo)
    {
    case ESPECIALIDADE:
    {
        op = read_tipo(ESPECIALIDADE, dados, tam);
        if (dados->especialidade_vet[op].exist)
            dados->especialidade_vet[op].exist = false;
        break;
    }

    case MEDICO:
    {
        op = read_tipo(MEDICO, dados, tam);
        if (dados->medico_vet[op].exist)
            dados->medico_vet[op].exist = false;
        break;
    }

    case FUNCIONARIO:
    {
        op = read_tipo(FUNCIONARIO, dados, tam);
        if (dados->funcionario_vet[op].exist)
            dados->funcionario_vet[op].exist = false;
        break;
    }

    case PACIENTE:
    {
        op = read_tipo(PACIENTE, dados, tam);
        if (dados->paciente_vet[op].exist)
            dados->paciente_vet[op].exist = false;
        break;
    }
    default:
        puts("\n(delete_tipo) tipo_t invalido\n");
        exit(EXIT_FAILURE);
        break;
    }
    return EXIT_SUCCESS;
}

int update_tipo(tipo_t tipo, vets_t *dados, int tam)
{
    int op = 0;

    switch (tipo)
    {
    case ESPECIALIDADE:
    {
        op = read_tipo(ESPECIALIDADE, dados, MAX);
        if (dados->especialidade_vet[op].exist)
            create_especialidade(&dados->especialidade_vet[op]);
        break;
    }

    case MEDICO:
    {
        op = read_tipo(MEDICO, dados, MAX);
        if (dados->medico_vet[op].exist)
            create_medico(&dados->medico_vet[op], dados, tam);
        break;
    }

    case FUNCIONARIO:
    {
        op = read_tipo(FUNCIONARIO, dados, MAX);
        if (dados->funcionario_vet[op].exist)
            create_funcionario(&dados->funcionario_vet[op]);
        break;
    }

    case PACIENTE:
    {
        op = read_tipo(PACIENTE, dados, MAX);
        if (dados->paciente_vet[op].exist)
            create_paciente(&dados->paciente_vet[op]);
        break;
    }
    default:
        puts("\n(delete_tipo) tipo_t invalido\n");
        exit(EXIT_FAILURE);
        break;
    }
    return EXIT_SUCCESS;
}

int read_tipo(tipo_t tipo, vets_t *dados, int tam)
{
    int op = 0;

    switch (tipo)
    {
    case ESPECIALIDADE:
        for (int i = 0; i < tam; i++)
            if (dados->especialidade_vet[i].exist)
                printf("\n%d - %s", i, dados->especialidade_vet[i].nome);
        break;

    case MEDICO:
        for (int i = 0; i < tam; i++)
            if (dados->medico_vet[i].exist)
                printf("\n%d - %s", i, dados->medico_vet[i].nome);
        break;

    case FUNCIONARIO:
        for (int i = 0; i < tam; i++)
            if (dados->funcionario_vet[i].exist)
                printf("\n%d - %s", i, dados->funcionario_vet[i].nome);
        break;

    case PACIENTE:
        for (int i = 0; i < tam; i++)
            if (dados->paciente_vet[i].exist)
                printf("\n%d - %s", i, dados->paciente_vet[i].nome);
        break;

    default:
        puts("\n(read_tipo) tipo_t invalido\n");
        exit(EXIT_FAILURE);
        break;
    }

    puts("\n----------------------------------\n");
    puts("Selecione uma opção");
    do
    {
        printf(">");
        scanf("%d", &op);
    } while (op < 0 || op > tam);
    return op;
}

/*
crud funcionario

*/

int create_funcionario(funcionario_t *funcionario)
{
    puts("----------------------------------");
    puts("\nMatricula:");
    ler_string(funcionario->matricula, sizeof(funcionario->matricula));
    puts("\nNome:");
    ler_string(funcionario->nome, sizeof(funcionario->nome));
    funcionario->login = auth();
    funcionario->exist = true;
    return EXIT_SUCCESS;
}

int read_funcionario(funcionario_t funcionario)
{
    if (funcionario.exist)
    {
        puts("\n----------------------------------");
        printf("\nMatricula:%s", funcionario.matricula);
        printf("\nNome:%s", funcionario.nome);
        printf("\nUsuário:%s", funcionario.login.usuario);
        puts("\n----------------------------------\n");
    }
    else
        puts("\nFuncionario não existe\n");

    pausar_limpar_tela();
    return EXIT_SUCCESS;
}

/*
crud paciente

*/

int create_paciente(paciente_t *paciente)
{
    puts("\n----------------------------------\n");
    puts("\nCPF:");
    ler_string(paciente->cpf, sizeof(paciente->cpf));
    puts("\nNome:");
    ler_string(paciente->nome, sizeof(paciente->nome));
    paciente->login = auth();
    paciente->exist = true;
    return EXIT_SUCCESS;
}

int read_paciente(paciente_t paciente)
{
    if (paciente.exist)
    {
        puts("\n----------------------------------");
        printf("\nCPF:%s", paciente.cpf);
        printf("\nNome:%s", paciente.nome);
        printf("\nTelefone:%s", paciente.telefone);
        printf("\nUsuário:%s", paciente.login.usuario);
        puts("\n----------------------------------\n");
    }
    else
        puts("\nPaciente não existe\n");

    pausar_limpar_tela();
    return EXIT_SUCCESS;
}

/*
crud especialidade

*/

int create_especialidade(especialidade_t *especialidade)
{
    puts("\n----------------------------------\n");
    puts("\nCode:");
    ler_string(especialidade->cod, sizeof(especialidade->cod));
    puts("\nNome:");
    ler_string(especialidade->nome, sizeof(especialidade->nome));

    especialidade->exist = true;
    return EXIT_SUCCESS;
}

int read_especialidade(especialidade_t especialidade)
{
    if (especialidade.exist)
    {
        puts("\n----------------------------------");

        printf("\nNome:%s", especialidade.nome);
        printf("\nCódigo:%s", especialidade.cod);
        puts("\n----------------------------------");
    }
    else
        printf("\nEspecialidade não existe\n");

    pausar_limpar_tela();
    return EXIT_SUCCESS;
}

/*
crud medico 

*/

int create_medico(medico_t *medico, vets_t *dados, int tam_especialidade)
{
    puts("\n----------------------------------");
    puts("\nCRM:");
    ler_string(medico->crm, sizeof(medico->crm));
    puts("\nNome:");
    ler_string(medico->nome, sizeof(medico->nome));
    int op = read_tipo(ESPECIALIDADE, dados, tam_especialidade);
    medico->especialidade = dados->especialidade_vet[op];
    medico->login = auth();
    medico->exist = true;
    return EXIT_SUCCESS;
}

int read_medico(medico_t medico)
{
    if (medico.exist)
    {
        puts("\n----------------------------------");
        printf("\nCPF:%s", medico.crm);
        printf("\nNome:%s", medico.nome);
        printf("\nEspecialidade:%s", medico.especialidade.nome);
        printf("\nUsuário:%s", medico.login.usuario);
        puts("\n----------------------------------");
    }
    else
        puts("\nMedico não existe\n");

    pausar_limpar_tela();
    return EXIT_SUCCESS;
}
int gerar_dados(vets_t *dados)
{
    puts("\nGerando dados...");
    puts("Especialidades...");
    //gerar dados de especialidade
    for (int i = 0; i < MAX; i++)
    {
        sprintf(dados->especialidade_vet[i].nome, "especialidade %d", i);
        sprintf(dados->especialidade_vet[i].cod, "%d%d%d", i, i, i);
        dados->especialidade_vet[i].exist = true;
    }
    puts("Funcionarios...");
    //gerar dados de funcionario
    for (int i = 0; i < MAX; i++)
    {
        sprintf(dados->funcionario_vet[i].nome, "funcionario %d", i);
        sprintf(dados->funcionario_vet[i].matricula, "%d%d", i, i);
        sprintf(dados->funcionario_vet[i].login.usuario, "fun%d", i);
        sprintf(dados->funcionario_vet[i].login.senha, "%d%d%d", i, i, i);
        dados->funcionario_vet[i].exist = true;
    }
    puts("Pacientes...");
    //gerar dados de paciente
    for (int i = 0; i < MAX; i++)
    {
        sprintf(dados->paciente_vet[i].nome, "paciente %d", i);
        sprintf(dados->paciente_vet[i].cpf, "%d%d", i, i);
        sprintf(dados->paciente_vet[i].login.usuario, "pac%d", i);
        sprintf(dados->paciente_vet[i].login.senha, "%d%d%d", i, i, i);
        sprintf(dados->paciente_vet[i].telefone, "%d%d%d", i, i, i);
        dados->paciente_vet[i].exist = true;
    }

    puts("Medicos...");
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

    puts("\nDados gerados com sucesso");
    pausar_limpar_tela();
    return EXIT_SUCCESS;
}

int inicializador(vets_t *dados)
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

    for (int i = 0; i < MAX; i++)
        dados->especialidade_vet[i].exist = false;

    //inicializar vetor agenda
    for (int i = 0; i < MAX_AGENDA; i++)
        dados->agenda_vet[i].exist = false;

    return EXIT_SUCCESS;
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