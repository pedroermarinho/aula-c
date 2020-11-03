//Faça um sistema para controlar biblioteca, O adm geral
//Cadastrar Funcionario:Nome, Matricula, Login e Senha
//Cadastrar Livro: Nome, ISBN, Curso
//Cadastrar Curso: Nome, Area
//Ao cadastrar o livro é exibido a lista de cursos e
//o ADM associa ao livro. O adm cadastra aluno
//Aluno:Nome, Matricula e Curso. O adm realiza
//emprestemos: SO PODERAR LIVRO PARA OS ALUNOS MATRICULADOS, O
//ALUNO PODERÁ EMPRESTAR ATÉ 3 LIVROS. O ADM REALIZA
//DEVOLUÇÕES LIVROS: PESQUISA o nome aluno, verificar
//os livros emprestados e devolver o livro deixando disponivel
//no sistema para o proximo aluguel. O adm terá relatorio de livros
//emprestados, o aluno e o curso. O funcionario realiza o cadastro dos alunos
//emprestimos livro, devolução livro.
//a)Todos Cadastro minino 2;
//b)Procedimentos;
//c)Vetor e registro;

//cadastro de aluno
//emprestimo de livro e devoluçao de livro

//Alunos Pedro Marinho e Rayssa Carla

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 2              // define a quantidade de dados que serão cadastrados
#define MAX_LIVROS 6       // define a quantidade de livros que serão cadastrados
#define MAX_LIVROS_ALUNO 3 // define a quantidade de livros que serão cadastrados

typedef struct 
{
    char nome_funcionario[120];
    int matricula;
    char login[60];
    char senha[60];
} funcionario_t;

typedef struct 
{
    char nome_curso[120];
    char area[120];
} curso_t;

typedef struct 
{
    char nome_livro[120];
    int isbn;
    int disponivel;
    curso_t curso;
} livro_t;

typedef struct 
{
    char nome_aluno[120];
    int matricula;
    curso_t curso;
    livro_t livro_vet[MAX_LIVROS_ALUNO];
} aluno_t;

funcionario_t funcionario_vet[MAX];
livro_t livro_vet[MAX_LIVROS];
curso_t curso_vet[MAX];
aluno_t aluno_vet[MAX];

void limpar_tela();       //limpar tela
void pausar_limpar_tela(); // pausar e limpar tela

void login(); //sistema login

// menus de controle
void menu_login();     // menu do login
void menu_relatorio(); //menu de relatorio
//menus do adm
void menu_adm();         // menu principal do adm
void menu_adm_cadastro(); // menu de cadastrados do adm
void menu_adm_gerar();    // menu de geração de dados automaticos do adm
//menus do funcionario
void menu_funcionario(); // menu do principal do funcionario

//cadastro de funcionarios
void cadastrar_funcionarios(); //cadastrar funcionarios
void gerar_funcionarios();     //gerar dados funcionarios
void exibir_funcionarios();    //exibir dados dos funcionarios

//cadastro e exibição de alunos
void cadastrar_alunos(); //cadastrar alunos
void gerar_alunos();     //gerar dados funcionarios
void exibir_alunos();    //exibir dados alunos

//cadastro e exibição de cursos
void cadastro_cursos(); //cadastrar cursos
void gerar_cursos();    //gerar dados dos cursos
void exibir_cursos();   //exibir dados dos cursos

//cadastro e exibição de livros
void cadastrar_livros();     //cadastrar livros
void gerar_livros();         //gerar dados livros
void exibir_livros_disp();    //exibir dados dos livros disponíveis
void exibir_livros_nao_disp(); //exibir dados dos livros não disponíveis

// sistema de controle de livros
void emprestimo_livro(); //sistemas de emprestimo livros
void devolucao_livro();  //sitema de devolução de livros

//relatorio
void relatorio_aluno_livros();
void pesquisar_relatorio_aluno(); //pesquisar por relatorio do aluno

int is_valid_curso = 0;
int is_valid_funcionarios = 0;
int is_valid_login = 0;
int is_valid_aluno = 0;
int is_valid_livro = 0;

main()
{
    setlocale(LC_ALL, "Portuguese");

    menu_login();

    return 0;

} //Fim main

void limpar_tela()
{
#ifdef __WIN32
    system("cls");
#else
    system("clear");
#endif
} //fim procedimento limpar_tela

void pausar_limpar_tela()
{
    printf("\n\n");
    system("read -p \"Pressione enter para continuar\" saindo");
    limpar_tela();
} //fim procedimento pausar_limpar_tela

void menu_login()
{
    do
    {
        int is_valid = 1;
        printf("\n_________Tipo de Usuario_____________\n");
        printf("\n1 - Administrador");
        printf("\n2 - Funcionario");
        printf("\n0 - Sair");
        int op;
        do
        {
            printf("\n_________Selecione uma opcao_________\n");
            printf(">");
            scanf("%d", &op);
            switch (op)
            {
                //1-Cadastro
            case 1:
                limpar_tela();
                menu_adm();
                break;

            case 2:
                limpar_tela();
                login();
                break;

            case 0:
                exit(1);
                break;

            default:
                is_valid = 0;
                break;
            }

        } while (!is_valid);

    } while (1);

} //fim procedimento menuLogic

void menu_adm()
{
    int continuar = 1;
    do
    {

        int is_valid = 1;
        printf("\n_________Sistema do Adm___________\n");
        printf("\n1 - Cadastros");
        printf("\n2 - Realizar Emprestimo");
        printf("\n3 - Realizar Devolução");
        printf("\n4 - Relatorio");
        printf("\n5 - Gerar");
        printf("\n0 - Sair");
        int op;
        do
        {
            printf("\n_________Escolha uma opção_________\n");
            printf(">");
            scanf("%d", &op);
            switch (op)
            {
                //1 - Cadastrados
            case 1:
                limpar_tela();
                menu_adm_cadastro();
                break;
                //2 - Emprestimo
            case 2:
                limpar_tela();
                emprestimo_livro();

                break;
                //3 - Devolução
            case 3:
                limpar_tela();
                devolucao_livro();
                break;
                //4 - Relatorio
            case 4:
                limpar_tela();
                menu_relatorio();
                break;
            case 5:
                limpar_tela();
                menu_adm_gerar();
                break;

            case 0:
                limpar_tela();
                continuar = 0;
                break;

            default:
                is_valid = 0;
                break;
            }
        } while (!is_valid);
    } while (continuar);
} //fim procedimento

void menu_adm_cadastro()
{
    int is_valid = 1;
    printf("\n_________Sistema de Cadastro do Adm_____________\n");
    printf("\n1 - Funcionario");
    printf("\n2 - Curso");
    printf("\n3 - Livros");
    printf("\n4 - Cadastro Aluno");
    printf("\n0 - Sair");
    int op;
    do
    {
        printf("\n_________Escolha uma opção_________\n");
        printf(">");
        scanf("%d", &op);
        switch (op)
        {
        /// 1 - Funcionario
        case 1:
            limpar_tela();
            cadastrar_funcionarios();
            break;
        //2 - Curso
        case 2:
            limpar_tela();
            cadastro_cursos();
            break;
        //3 - Livros
        case 3:
            limpar_tela();
            cadastrar_livros();
            /* code */
            break;
        case 4:
            limpar_tela();
            cadastrar_alunos();
            break;
        case 0:
            limpar_tela();
            break;

        default:
            is_valid = 0;
            break;
        }
    } while (!is_valid);
} //fim do procedimento

void menu_adm_gerar()
{
    int is_valid = 1;
    printf("\n_________Sistema de Gerar do Adm____________\n");
    printf("\n1 - Funcionario");
    printf("\n2 - Curso");
    printf("\n3 - Livros");
    printf("\n4 - Aluno");
    printf("\n5 - Todos");
    printf("\n0 - Sair");
    int op;
    do
    {
        printf("\n_________Escolha uma opção_________________\n");
        printf(">");
        scanf("%d", &op);
        switch (op)
        {
        /// 1 - Funcionario
        case 1:
            limpar_tela();
            gerar_funcionarios();
            break;
        //2 - Curso
        case 2:
            limpar_tela();
            gerar_cursos();
            break;
        //3 - Livros
        case 3:
            limpar_tela();
            gerar_livros();
            /* code */
            break;
        //4 - Aluno
        case 4:
            limpar_tela();
            gerar_alunos();
            break;
        //5 - Todos
        case 5:
            limpar_tela();
            gerar_funcionarios();
            gerar_cursos();
            gerar_livros();
            gerar_alunos();
            break;
        case 0:
            limpar_tela();
            break;

        default:
            is_valid = 0;
            break;
        }
    } while (!is_valid);
} //fim do procedimento

void menu_funcionario()
{
    int continuar = 1;
    do
    {
        int is_valid = 1;
        printf("\n_________Sistema do Funcionario_________\n");
        printf("\n1 - Cadastro aluno");
        printf("\n2 - Emprestimo");
        printf("\n3 - Devolucação");
        printf("\n0 - Sair");
        int op;
        do
        {
            printf("\n_________Escolha uma opção_____________\n");
            printf(">");
            scanf("%d", &op);
            switch (op)
            {
            ///1 - Cadastro aluno
            case 1:
                limpar_tela();
                cadastrar_alunos();
                break;

            //2 - Emprestimo
            case 2:
                limpar_tela();
                emprestimo_livro();
                break;
            //3 - Devolucação
            case 3:
                limpar_tela();
                devolucao_livro();
                break;
            case 0:
                limpar_tela();
                continuar = 0;
                break;

            default:
                is_valid = 0;
                break;
            }
        } while (!is_valid);
    } while (continuar);
} //fim do procedimento

void menu_relatorio()
{
    int is_valid = 1;
    printf("\n_________Sistema do Relatorios_________\n");
    printf("\n1 - Pesquisar por aluno");
    printf("\n2 - Todos os alunos com livros");
    printf("\n3 - Todos os livros disponiveis");
    printf("\n4 - Todos os livros não disponiveis");
    printf("\n0 - Sair");
    int op;
    do
    {
        printf("\n_________Escolha uma opção____________\n");
        printf(">");
        scanf("%d", &op);
        switch (op)
        {
        ///1 - Pesquisar por aluno
        case 1:
            limpar_tela();
            pesquisar_relatorio_aluno();
            break;

        //2 - Todos os alunos com livros
        case 2:
            limpar_tela();
            relatorio_aluno_livros();
            break;
        //3 - Todos os livros disponiveis
        case 3:
            limpar_tela();
            exibir_livros_disp();
            pausar_limpar_tela();
            break;
        //4 - Todos os livros não disponiveis
        case 4:
            limpar_tela();
            exibir_livros_nao_disp();
            pausar_limpar_tela();
            break;
        //0 - Sair
        case 0:
            limpar_tela();
            break;
        default:
            is_valid = 0;
            break;
        }
    } while (!is_valid);
}

void cadastrar_funcionarios()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("\n__________CADASTRO___________\n");
        printf("Nome:");
        fflush(stdin);
        gets(funcionario_vet[i].nome_funcionario);

        printf("\nMatricula:");
        scanf("%d", &funcionario_vet[i].matricula);

        printf("\nLogin:");
        fflush(stdin);
        gets(funcionario_vet[i].login);

        printf("\nSenha:");
        fflush(stdin);
        gets(funcionario_vet[i].senha);
    } //fim for de cadastro de funcionario
    is_valid_funcionarios = 1;
    pausar_limpar_tela();

} //fim do procedimento de cadastro de funcionario

void gerar_funcionarios()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        sprintf(funcionario_vet[i].nome_funcionario, "Funcionario %d", i);
        funcionario_vet[i].matricula = i;
        sprintf(funcionario_vet[i].login, "login%d", i);
        sprintf(funcionario_vet[i].senha, "senha%d", i);
    }
    printf("\n_________Dados do Funcionario gerados automaticamente_________\n");

    pausar_limpar_tela();
    is_valid_funcionarios = 1;

} //fim do procedimento
void exibir_funcionarios()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("%d - %s\n", i, funcionario_vet[i].nome_funcionario);
    }
    printf("\n______________________________________________________\n");
}

void cadastrar_alunos()
{

    if (is_valid_curso)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            printf("\n______________________________________________________\n");
            printf("Nome:");
            fflush(stdin);
            gets(aluno_vet[i].nome_aluno);

            printf("\nMatricula:");
            scanf("%d", &aluno_vet[i].matricula);

            int op;
            printf("Selecione um curso");
            exibirCurso();
            printf("\n>");
            scanf("%d", &op);

            aluno_vet[i].curso = curso_vet[op];

        } //fim for de cadastro de funcionario
        is_valid_aluno = 1;
    }
    else
    {
        printf("\n_________Nenhum dos Cursos cadastrado_________\n");
    }
    pausar_limpar_tela();
} //fim do procedimento de cadastro de alunos

void gerar_alunos()
{
    if (is_valid_curso)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            sprintf(aluno_vet[i].nome_aluno, "Aluno %d", i);
            sprintf(aluno_vet[i].matricula, "matricula%d", i);
            aluno_vet[i].curso = curso_vet[i];
            //alunos[i]. = 0; //arrumar
        }
        is_valid_aluno = 1;
        printf("\n_________Dados do Alunos gerados automaticamente_________\n");
    }
    else
    {
        printf("\n_________Nenhum Curso cadastrado_________\n");
    }
    pausar_limpar_tela();
} //fim do procedimento

void exibir_alunos()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("\n%d - %s", i, aluno_vet[i].nome_aluno);
    } //fim do for de exibição de aluno
    printf("\n______________________________________________________\n");
}

//cadastro e exibição de cursos
void cadastro_cursos()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("\n______________________________________________________\n");
        printf("Nome do Curso: ");
        fflush(stdin);
        gets(curso_vet[i].nome_curso);

        printf("\nÁrea: ");
        fflush(stdin);
        gets(curso_vet[i].area);
    } //fim for do cadastro de cursos

    is_valid_curso = 1;
    pausar_limpar_tela();
} //fim do procedimento de cadastro de cursos

void exibirCurso()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("%d - %s - %s\n", i, curso_vet[i].nome_curso, curso_vet[i].area);
    } //fim do for para exibir a lista de livros
    printf("\n______________________________________________________\n");
} //fim do procedimento para exibição dos livros

void gerar_cursos()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        sprintf(curso_vet[i].nome_curso, "curso %d", i);
        sprintf(curso_vet[i].area, "area%d", i);
    }
    printf("\n_________Dados do Cursos gerados automaticamente_________\n");
    is_valid_curso = 1;
    pausar_limpar_tela();
} //fim do procedimento

void cadastrar_livros()
{
    if (is_valid_curso)
    {
        int i;
        for (i = 0; i < MAX_LIVROS; i++)
        {
            printf("\n______________________________________________________\n");
            printf("Nome do Livro:");
            fflush(stdin);
            gets(livro_vet[i].nome_livro);

            printf("\nIsbn:");
            scanf("%d", &livro_vet[i].isbn);

            int op;
            exibirCurso();
            printf("\nSelecione um curso:");
            scanf("%d", &op);

            livro_vet[i].curso = curso_vet[op];

            livro_vet[i].disponivel = 1;
        }
        is_valid_livro = 1;
    }
    else
    {
        printf("\n_________Nenhum Curso cadastrado_________\n");
    }
    pausar_limpar_tela();
}

void gerar_livros()
{
    if (is_valid_curso)
    {
        int i;
        for (i = 0; i < MAX_LIVROS; i++)
        {
            sprintf(livro_vet[i].nome_livro, "Livro %d", i);
            livro_vet[i].isbn = i;
            livro_vet[i].curso = curso_vet[1];
            livro_vet[i].disponivel = 1;
        }
        is_valid_livro = 1;
        printf("\n_________Dados do livros gerados automaticamente_________\n");
    }
    else
    {
        printf("\n_________Nenhum Curso cadastrado_________\n");
    }
    pausar_limpar_tela();
} //fim do procedimento

void login()
{
    if (is_valid_funcionarios)
    {
        do
        {
            char login[120];
            char senha[120];
            printf("\nLogin:");
            fflush(stdin);
            gets(login);
            printf("\nSenha:");
            fflush(stdin);
            gets(senha);
            int i;
            for (i = 0; i < MAX; i++)
            {
                if (strcmp(funcionario_vet[i].login, login) == 0)
                {
                    if (strcmp(funcionario_vet[i].senha, senha) == 0)
                    {
                        is_valid_login = 1;
                    }
                }
            }
            if (!is_valid_login)
            {
                printf("\nSenha incorreta\n");
                pausar_limpar_tela();
            }
            else if (is_valid_login)
            {
                limpar_tela();
                menu_funcionario();
            }

            int op;
            limpar_tela();
            printf("\n1 - Nova tentativa");
            printf("\n0 - Sair");
            printf("\n>");
            scanf("%d", &op);
            if (op == 0)
            {
                break;
            }

        } while (is_valid_login == 0);
    }
    else
    {
        printf("\n_________Nenhum funcionario Cadastrado_________\n");
        pausar_limpar_tela();
    }
}

void exibir_livros_disp()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX_LIVROS; i++)
    {
        if (livro_vet[i].disponivel)
        {
            printf("\n%d - %s - %s", i, livro_vet[i].nome_livro, livro_vet[i].curso.area);
        }
    } //for de exibição de livros
    printf("\n______________________________________________________\n");
}
void exibir_livros_nao_disp()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX_LIVROS; i++)
    {
        if (!livro_vet[i].disponivel)
        {
            printf("\n%d - %s - %s", i, livro_vet[i].nome_livro, livro_vet[i].curso.area);
        }
    } //for de exibição de livros
    printf("\n______________________________________________________\n");
}

// sistema de controle de livros
void emprestimo_livro()
{

    if (is_valid_aluno && is_valid_livro)
    {

        int selectAluno;
        printf("\nAlunos:\n");
        exibir_alunos();
        printf("\nSelecione um aluno:");
        scanf("%d", &selectAluno);

        limpar_tela();

        int continuarSelecao = 1;

        int i;
        for (i = 0; i < MAX_LIVROS_ALUNO; i++)
        {
            int selectLivro;
            printf("Livros:");
            exibir_livros_disp();
            printf("\nSelecione um livro:");
            scanf("%d", &selectLivro);
            aluno_vet[selectAluno].livro_vet[i] = livro_vet[selectLivro];

            livro_vet[selectLivro].disponivel = 0;

            printf("\nDeseja emprestar outro livro? 1 -sim, 0- nao:\n");
            scanf("%d", &continuarSelecao);
            limpar_tela();

            if (!continuarSelecao)
            {
                break;
            }
        }
    }
    else
    {
        printf("\nDados insuficientes\n");
    }
}
void devolucao_livro()
{
    if (is_valid_aluno && is_valid_livro)
    {

        int selectAluno;
        int op;
        //exibir livros emprestados
        printf("Livros empretados:\n");

        exibir_livros_nao_disp();

        printf("_________Selecione o livro que deseja devolver:_________\n");
        scanf("%d", &op);

        livro_vet[op].disponivel = 1;

        int i;
        //for para copmpararação do aluno ao livro
        for (i = 0; i < MAX; i++)
        {
            int j;
            for (j = 0; j < MAX_LIVROS_ALUNO; j++)
            {
                if (strcmp(aluno_vet[i].livro_vet[j].nome_livro, livro_vet[op].nome_livro) == 0)
                {
                    aluno_vet[i].livro_vet[j].nome_livro[0] = '\0';
                    aluno_vet[i].livro_vet[j].isbn = 0;
                    aluno_vet[i].livro_vet[j].disponivel = 0;
                    aluno_vet[i].livro_vet[j].curso.nome_curso[0] = '\0';
                    aluno_vet[i].livro_vet[j].curso.area[0] = '\0';
                }
            }
        }
        printf("Devolução realizada!");
    }
    else
    {
        printf("\nDados insuficientes\n");
    }
    pausar_limpar_tela();
}

void relatorio_aluno_livros()
{
    if (is_valid_aluno)
    {

        printf("\n_________Sistema de Relatorio_________\n");

        int i;
        for (i = 0; i < MAX; i++)
        {

            printf("\n______________________________________________________\n");
            printf("\nNome: %s", aluno_vet[i].nome_aluno);
            printf("\nMatricula: %d", aluno_vet[i].matricula);
            printf("\nCurso: %s", aluno_vet[i].curso.nome_curso);
            printf("\nLivros:");
            int j;
            for (j = 0; j < MAX_LIVROS_ALUNO; j++)
            {
                if (aluno_vet[i].livro_vet[j].nome_livro[0] != NULL && aluno_vet[i].livro_vet[j].nome_livro[0] != '\0')
                {
                    printf("\n%s", aluno_vet[i].livro_vet[j].nome_livro);
                }
            }
        }
    }
    else
    {
        printf("\n_________Nenhum aluno cadastrado_________\n");
    }

    pausar_limpar_tela();
}

void pesquisar_relatorio_aluno()
{
    char pesquisar[120];

    printf("\n_________Sistema de Pesquisa_________\n");
    printf("\nDigite um nome:\n");
    printf(">");
    scanf("%s", &pesquisar);

    if (is_valid_aluno)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            if (strcmp(aluno_vet[i].nome_aluno, pesquisar) == 0)
            {
                printf("\n______________________________________________________\n");
                printf("\nNome: %s", aluno_vet[i].nome_aluno);
                printf("\nMatricula: %d", aluno_vet[i].matricula);
                printf("\nCurso: %s", aluno_vet[i].curso.nome_curso);
                printf("\nLivros:");
                int j;
                for (j = 0; j < MAX_LIVROS_ALUNO; j++)
                {
                    if (aluno_vet[i].livro_vet[i].nome_livro[0] != NULL && aluno_vet[i].livro_vet[i].nome_livro[0] != '\0')
                    {
                        printf("\n%s", aluno_vet[i].livro_vet[j].nome_livro);
                    }
                }
            }
        }
    }
    else
    {
        printf("\n_________Nenhum aluno cadastrado_________\n");
    }
    pausar_limpar_tela();
}
