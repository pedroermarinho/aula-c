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
#include <malloc.h>

#define MAX 2
#define MAX_AGENDA 8

const char HORAS[8][16] = {
    "08:00 as 09:00",
    "09:00 as 10:00",
    "10:00 as 11:00",
    "11:00 as 12:00",
    "13:00 as 14:00",
    "14:00 as 15:00",
    "15:00 as 16:00",
    "16:00 as 17:00"};

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
    char nome[120];
    char cpf[20];
    char telefone[20];
    login_t login;
    bool exist;
} paciente_t;

typedef struct
{
    paciente_t paciente;
    bool exist;
} agenda_t;

typedef struct
{
    char crm[10];
    char nome[120];
    login_t login;
    especialidade_t especialidade;
    agenda_t agenda_vet[MAX_AGENDA];
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
    login_t adm;
    funcionario_t funcionario_vet[MAX];
    especialidade_t especialidade_vet[MAX];
    medico_t medico_vet[MAX];
    paciente_t paciente_vet[MAX];
} vets_t;

int salvar(vets_t *dados);
int recuperar(vets_t *dados);

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
bool read_funcionario(funcionario_t funcionario);

int create_paciente(paciente_t *paciente);
bool read_paciente(paciente_t paciente);

int create_especialidade(especialidade_t *especialidade);
bool read_especialidade(especialidade_t especialidade);

int create_medico(medico_t *medico, vets_t *dados, int tam_especialidade);
bool read_medico(medico_t medico);

paciente_t search(paciente_t paciente_vet[], int tam);

bool create_agenda(vets_t *dados);
int read_agenda(vets_t *dados);

int main()
{

    setlocale(LC_ALL, "portuguese");

    vets_t* dados = (vets_t*) malloc(sizeof(vets_t));
    inicializador(dados);
    recuperar(dados);
    menu_login(dados);

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

char *ler_string( char *string, int tam)
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

bool auth(const login_t login1, const login_t login2)
{

    if (strcmp(login1.usuario, login2.usuario) == 0)
        if (strcmp(login1.senha, login2.senha) == 0)
            return true;

    return false;
}

bool auth(const tipo_t tipo, vets_t *dados,const int tam)
{

    const login_t login1 = auth();
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

void menu_login( vets_t *dados)
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

void menu_adm( vets_t *dados)
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
        puts("6- Agendar");
        puts("7- Ver Agenda");
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
                //Agendar
            case 6:
                limpar_tela();
                system("title Agendar");
                create_agenda(dados);
                break;
                //Ver Agenda
            case 7:
                limpar_tela();
                system("title Ver Agenda");
                read_agenda(dados);
                break;
                //Salvar

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

void menu_adm_crud(const crud_t crud, vets_t *dados)
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
void menu_funcionario( vets_t *dados)
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
                create_tipo(PACIENTE, dados, MAX);
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

void menu_medico( vets_t *dados)
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

int create_tipo(const tipo_t tipo,  vets_t *dados, const int tam)
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
    salvar(dados);
    return EXIT_SUCCESS;
}

int delete_tipo(const tipo_t tipo,  vets_t *dados, const int tam)
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
    salvar(dados);
    return EXIT_SUCCESS;
}

int update_tipo(const tipo_t tipo,  vets_t *dados, const int tam)
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
    salvar(dados);
    return EXIT_SUCCESS;
}

int read_tipo(const tipo_t tipo, vets_t *dados,const int tam)
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

paciente_t search( paciente_t paciente_vet[],const int tam)
{
    char cpf[30];
    puts("CPF:");
    ler_string(cpf, sizeof(cpf));

    for (int i = 0; i < tam; i++)
        if (strcmp(paciente_vet[i].cpf, cpf) == 0)
            return paciente_vet[i];

    const paciente_t paciente_falso = {.exist = false};
    return paciente_falso;
}

bool create_agenda( vets_t *dados)
{

    const paciente_t paciente = search(dados->paciente_vet, MAX);

    if (!read_paciente(paciente))
        return false;

    const int medico_id = read_tipo(MEDICO, dados, MAX);

    if (!dados->medico_vet[medico_id].exist)
        return false;

    puts("\nSelecione um horario entre as 8 a 17:");

    for (int i = 0; i < 8; i++)
        if (!dados->medico_vet[medico_id].agenda_vet[i].exist)
            printf("%d - %s\n", i, HORAS[i]);

    int hora;
    do
    {
        printf(">");
        scanf("%d", &hora);
    } while (hora < 0 || hora > 7);

    if (dados->medico_vet[medico_id].agenda_vet[hora].exist)
    {
        puts("Horario indisponível");
        pausar_limpar_tela();
        return false;
    }

    dados->medico_vet[medico_id].agenda_vet[hora].exist = true;
    dados->medico_vet[medico_id].agenda_vet[hora].paciente = paciente;
    puts("Agendamento realizado com sucesso");
    pausar_limpar_tela();
    salvar(dados);
    return true;
}
int read_agenda( vets_t *dados)
{
    for (int i = 0; i < MAX; i++)
    {
        if (!dados->medico_vet[i].exist)
            continue;
            
        printf("\n- %s", dados->medico_vet[i].nome);
        for (int j = 0; j < MAX_AGENDA; j++)
            if (dados->medico_vet[i].agenda_vet[j].exist)
                printf("\n\t* %s - %s", HORAS[j], dados->medico_vet[i].agenda_vet[j].paciente.nome);
    }
    pausar_limpar_tela();
    return EXIT_SUCCESS;
}

/*
crud funcionario

*/

int create_funcionario( funcionario_t *funcionario)
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

bool read_funcionario(const funcionario_t funcionario)
{
    if (!funcionario.exist)
    {
        puts("\nFuncionario não existe\n");
        pausar_limpar_tela();
        return false;
    }

    puts("\n----------------------------------");
    printf("\nMatricula:%s", funcionario.matricula);
    printf("\nNome:%s", funcionario.nome);
    printf("\nUsuário:%s", funcionario.login.usuario);
    puts("\n----------------------------------\n");
    pausar_limpar_tela();
    return true;
}

/*
crud paciente

*/

int create_paciente(  paciente_t *paciente)
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

bool read_paciente(const paciente_t paciente)
{
    if (!paciente.exist)
    {
        puts("\nPaciente não existe\n");
        pausar_limpar_tela();
        return false;
    }

    puts("\n----------------------------------");
    printf("\nCPF:%s", paciente.cpf);
    printf("\nNome:%s", paciente.nome);
    printf("\nTelefone:%s", paciente.telefone);
    printf("\nUsuário:%s", paciente.login.usuario);
    puts("\n----------------------------------\n");
    pausar_limpar_tela();
    return true;
}

/*
crud especialidade

*/

int create_especialidade( especialidade_t *especialidade)
{
    puts("\n----------------------------------\n");
    puts("\nCode:");
    ler_string(especialidade->cod, sizeof(especialidade->cod));
    puts("\nNome:");
    ler_string(especialidade->nome, sizeof(especialidade->nome));

    especialidade->exist = true;
    return EXIT_SUCCESS;
}

bool read_especialidade( const especialidade_t especialidade)
{
    if (!especialidade.exist)
    {
        printf("\nEspecialidade não existe\n");
        pausar_limpar_tela();
        return false;
    }

    puts("\n----------------------------------");

    printf("\nNome:%s", especialidade.nome);
    printf("\nCódigo:%s", especialidade.cod);
    puts("\n----------------------------------");
    pausar_limpar_tela();
    return true;
}

/*
crud medico 

*/

int create_medico( medico_t *medico,  vets_t *dados, const int tam_especialidade)
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

bool read_medico(const medico_t medico)
{
    if (!medico.exist)
    {
        puts("\nMedico não existe\n");
        pausar_limpar_tela();
        return false;
    }

    puts("\n----------------------------------");
    printf("\nCPF:%s", medico.crm);
    printf("\nNome:%s", medico.nome);
    printf("\nEspecialidade:%s", medico.especialidade.nome);
    printf("\nUsuário:%s", medico.login.usuario);
    puts("\n----------------------------------");
    pausar_limpar_tela();
    return true;
}

int gerar_dados( vets_t *dados)
{
    puts("\nGerando dados...");

    //gerar dados de especialidade
    for (int i = 0; i < MAX; i++)
    {
        printf("\nEspecialidades...%d", i);

        sprintf(dados->especialidade_vet[i].nome, "especialidade %d", i);
        sprintf(dados->especialidade_vet[i].cod, "%d%d%d", i, i, i);
        dados->especialidade_vet[i].exist = true;

        printf("\nFuncionarios...%d", i);

        sprintf(dados->funcionario_vet[i].nome, "funcionario %d", i);
        sprintf(dados->funcionario_vet[i].matricula, "%d%d", i, i);
        sprintf(dados->funcionario_vet[i].login.usuario, "fun%d", i);
        sprintf(dados->funcionario_vet[i].login.senha, "%d%d%d", i, i, i);
        dados->funcionario_vet[i].exist = true;

        printf("\nPacientes...%d", i);

        sprintf(dados->paciente_vet[i].nome, "paciente %d", i);
        sprintf(dados->paciente_vet[i].cpf, "%d%d%d", i, i, i);
        sprintf(dados->paciente_vet[i].login.usuario, "pac%d", i);
        sprintf(dados->paciente_vet[i].login.senha, "%d%d%d", i, i, i);
        sprintf(dados->paciente_vet[i].telefone, "%d%d%d", i, i, i);
        dados->paciente_vet[i].exist = true;

        printf("\nMedicos...%d", i);

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

int inicializador( vets_t *dados)
{
    const  login_t adm = {{usuario : "adm"}, {senha : "123"}};
    dados->adm = adm;

    for (int i = 0; i < MAX; i++)
    {
        // inicializar vetor funcionario
        dados->funcionario_vet[i].exist = false;

        //inicializar vetor paciente
        dados->paciente_vet[i].exist = false;

        //inicializar vetor especialidade
        dados->especialidade_vet[i].exist = false;

        //inicializar vetor medico
        dados->medico_vet[i].exist = false;

        //inicializar vetor agenda
        for (int j = 0; j < MAX_AGENDA; j++)
            dados->medico_vet[i].agenda_vet[j].exist = false;
        
    }
    return EXIT_SUCCESS;
}
int salvar( vets_t *dados)
{

    FILE *arquivo = fopen("dados.bin", "wb");

    if (arquivo == NULL)
        return EXIT_FAILURE;

    fwrite(dados, sizeof(vets_t), 1, arquivo);

    fclose(arquivo);

    return EXIT_SUCCESS;
}

int recuperar( vets_t *dados)
{

    FILE *arquivo = fopen("dados.bin", "rb");

    if (arquivo == NULL)
        return EXIT_FAILURE;

    vets_t dados_local;

    int tam_file = fread(&dados_local, sizeof(vets_t), 1, arquivo);

    if (tam_file < 1)
        return EXIT_FAILURE;

    *dados = dados_local;

    fclose(arquivo);

    return EXIT_SUCCESS;
}
