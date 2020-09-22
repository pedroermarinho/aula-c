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

typedef struct Funcionario
{
    char nomeFuncionario[120];
    int matricula;
    char login[60];
    char senha[60];
} Funcionario;

typedef struct Curso
{
    char nomeCurso[120];
    char area[120];
} Curso;

typedef struct Livro
{
    char nomelivro[120];
    int ISBN;
    int disponivel;
    Curso curso;
} Livro;

typedef struct Aluno
{
    char nomeAluno[120];
    int matricula;
    Curso curso;
    Livro livros[MAX_LIVROS_ALUNO];
} Aluno;

Funcionario funcionarios[MAX];
Livro livros[MAX_LIVROS];
Curso cursos[MAX];
Aluno alunos[MAX];

void limparTela();       //limpar tela
void limparPausarTela(); // pausar e limpar tela

void login(); //sistema login

// menus de controle
void menuLogin();     // menu do login
void menuRelatorio(); //menu de relatorio
//menus do adm
void menuAdm();         // menu principal do adm
void menuAdmCadastro(); // menu de cadastrados do adm
void menuAdmGerar();    // menu de geração de dados automaticos do adm
//menus do funcionario
void menuFuncionario(); // menu do principal do funcionario

//cadastro de funcionarios
void cadastrarFuncionarios(); //cadastrar funcionarios
void gerarFuncionarios();     //gerar dados funcionarios
void exibirFuncionarios();    //exibir dados dos funcionarios

//cadastro e exibição de alunos
void cadastrarAlunos(); //cadastrar alunos
void gerarAlunos();     //gerar dados funcionarios
void exibirAlunos();    //exibir dados alunos

//cadastro e exibição de cursos
void cadastroCursos(); //cadastrar cursos
void gerarCursos();    //gerar dados dos cursos
void exibirCursos();   //exibir dados dos cursos

//cadastro e exibição de livros
void cadastrarLivros();     //cadastrar livros
void gerarLivros();         //gerar dados livros
void exibirLivrosDisp();    //exibir dados dos livros disponíveis
void exibirLivrosNaoDisp(); //exibir dados dos livros não disponíveis

// sistema de controle de livros
void emprestimoLivro(); //sistemas de emprestimo livros
void devolucaoLivro();  //sitema de devolução de livros

//relatorio
void relatorioAlunoLivros();
void pesquisarRelatorioAluno(); //pesquisar por relatorio do aluno

int isValidCurso = 0;
int isValidFuncionarios = 0;
int isValidLogin = 0;
int isValidAluno = 0;
int isValidLivro = 0;

main()
{
    setlocale(LC_ALL, "Portuguese");

    menuLogin();

    return 0;

} //Fim main

void limparTela()
{
#ifdef __WIN32
    system("cls");
#else
    system("clear");
#endif
} //fim procedimento limparTela

void limparPausarTela()
{
    printf("\n\n");
#ifdef __WIN32
    system("pause");
#else
    system("read -p \"Pressione enter para continuar\" saindo");
#endif
    limparTela();
} //fim procedimento limparPausarTela

void menuLogin()
{
    do
    {
        int isValid = 1;
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
                limparTela();
                menuAdm();
                break;

            case 2:
                limparTela();
                login();
                break;

            case 0:
                exit(1);
                break;

            default:
                isValid = 0;
                break;
            }

        } while (!isValid);

    } while (1);

} //fim procedimento menuLogic

void menuAdm()
{
    int continuar = 1;
    do
    {

        int isValid = 1;
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
                limparTela();
                menuAdmCadastro();
                break;
                //2 - Emprestimo
            case 2:
                limparTela();
                emprestimoLivro();

                break;
                //3 - Devolução
            case 3:
                limparTela();
                devolucaoLivro();
                break;
                //4 - Relatorio
            case 4:
                limparTela();
                menuRelatorio();
                break;
            case 5:
                limparTela();
                menuAdmGerar();
                break;

            case 0:
                limparTela();
                continuar = 0;
                break;

            default:
                isValid = 0;
                break;
            }
        } while (!isValid);
    } while (continuar);
} //fim procedimento

void menuAdmCadastro()
{
    int isValid = 1;
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
            limparTela();
            cadastrarFuncionarios();
            break;
        //2 - Curso
        case 2:
            limparTela();
            cadastroCursos();
            break;
        //3 - Livros
        case 3:
            limparTela();
            cadastrarLivros();
            /* code */
            break;
        case 4:
            limparTela();
            cadastrarAlunos();
            break;
        case 0:
            limparTela();
            break;

        default:
            isValid = 0;
            break;
        }
    } while (!isValid);
} //fim do procedimento

void menuAdmGerar()
{
    int isValid = 1;
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
            limparTela();
            gerarFuncionarios();
            break;
        //2 - Curso
        case 2:
            limparTela();
            gerarCursos();
            break;
        //3 - Livros
        case 3:
            limparTela();
            gerarLivros();
            /* code */
            break;
        //4 - Aluno
        case 4:
            limparTela();
            gerarAlunos();
            break;
        //5 - Todos
        case 5:
            limparTela();
            gerarFuncionarios();
            gerarCursos();
            gerarLivros();
            gerarAlunos();
            break;
        case 0:
            limparTela();
            break;

        default:
            isValid = 0;
            break;
        }
    } while (!isValid);
} //fim do procedimento

void menuFuncionario()
{
    int continuar = 1;
    do
    {
        int isValid = 1;
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
                limparTela();
                cadastrarAlunos();
                break;

            //2 - Emprestimo
            case 2:
                limparTela();
                emprestimoLivro();
                break;
            //3 - Devolucação
            case 3:
                limparTela();
                devolucaoLivro();
                break;
            case 0:
                limparTela();
                continuar = 0;
                break;

            default:
                isValid = 0;
                break;
            }
        } while (!isValid);
    } while (continuar);
} //fim do procedimento

void menuRelatorio()
{
    int isValid = 1;
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
            limparTela();
            pesquisarRelatorioAluno();
            break;

        //2 - Todos os alunos com livros
        case 2:
            limparTela();
            relatorioAlunoLivros();
            break;
        //3 - Todos os livros disponiveis
        case 3:
            limparTela();
            exibirLivrosDisp();
            limparPausarTela();
            break;
        //4 - Todos os livros não disponiveis
        case 4:
            limparTela();
            exibirLivrosNaoDisp();
            limparPausarTela();
            break;
        //0 - Sair
        case 0:
            limparTela();
            break;
        default:
            isValid = 0;
            break;
        }
    } while (!isValid);
}

void cadastrarFuncionarios()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("\n__________CADASTRO___________\n");
        printf("Nome:");
        fflush(stdin);
        gets(funcionarios[i].nomeFuncionario);

        printf("\nMatricula:");
        scanf("%d", &funcionarios[i].matricula);

        printf("\nLogin:");
        fflush(stdin);
        gets(funcionarios[i].login);

        printf("\nSenha:");
        fflush(stdin);
        gets(funcionarios[i].senha);
    } //fim for de cadastro de funcionario
    isValidFuncionarios = 1;
    limparPausarTela();

} //fim do procedimento de cadastro de funcionario

void gerarFuncionarios()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        sprintf(funcionarios[i].nomeFuncionario, "Funcionario %d", i);
        funcionarios[i].matricula = i;
        sprintf(funcionarios[i].login, "login%d", i);
        sprintf(funcionarios[i].senha, "senha%d", i);
    }
    printf("\n_________Dados do Funcionario gerados automaticamente_________\n");

    limparPausarTela();
    isValidFuncionarios = 1;

} //fim do procedimento
void exibirFuncionarios()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("%d - %s\n", i, funcionarios[i].nomeFuncionario);
    }
    printf("\n______________________________________________________\n");
}

void cadastrarAlunos()
{

    if (isValidCurso)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            printf("\n______________________________________________________\n");
            printf("Nome:");
            fflush(stdin);
            gets(alunos[i].nomeAluno);

            printf("\nMatricula:");
            scanf("%d", &alunos[i].matricula);

            int op;
            printf("Selecione um curso");
            exibirCurso();
            printf("\n>");
            scanf("%d", &op);

            alunos[i].curso = cursos[op];

        } //fim for de cadastro de funcionario
        isValidAluno = 1;
    }
    else
    {
        printf("\n_________Nenhum dos Cursos cadastrado_________\n");
    }
    limparPausarTela();
} //fim do procedimento de cadastro de alunos

void gerarAlunos()
{
    if (isValidCurso)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            sprintf(alunos[i].nomeAluno, "Aluno %d", i);
            sprintf(alunos[i].matricula, "matricula%d", i);
            alunos[i].curso = cursos[i];
            //alunos[i]. = 0; //arrumar
        }
        isValidAluno = 1;
        printf("\n_________Dados do Alunos gerados automaticamente_________\n");
    }
    else
    {
        printf("\n_________Nenhum Curso cadastrado_________\n");
    }
    limparPausarTela();
} //fim do procedimento

void exibirAlunos()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("\n%d - %s", i, alunos[i].nomeAluno);
    } //fim do for de exibição de aluno
    printf("\n______________________________________________________\n");
}

//cadastro e exibição de cursos
void cadastroCursos()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("\n______________________________________________________\n");
        printf("Nome do Curso: ");
        fflush(stdin);
        gets(cursos[i].nomeCurso);

        printf("\nÁrea: ");
        fflush(stdin);
        gets(cursos[i].area);
    } //fim for do cadastro de cursos

    isValidCurso = 1;
    limparPausarTela();
} //fim do procedimento de cadastro de cursos

void exibirCurso()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("%d - %s - %s\n", i, cursos[i].nomeCurso, cursos[i].area);
    } //fim do for para exibir a lista de livros
    printf("\n______________________________________________________\n");
} //fim do procedimento para exibição dos livros

void gerarCursos()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        sprintf(cursos[i].nomeCurso, "curso %d", i);
        sprintf(cursos[i].area, "area%d", i);
    }
    printf("\n_________Dados do Cursos gerados automaticamente_________\n");
    isValidCurso = 1;
    limparPausarTela();
} //fim do procedimento

void cadastrarLivros()
{
    if (isValidCurso)
    {
        int i;
        for (i = 0; i < MAX_LIVROS; i++)
        {
            printf("\n______________________________________________________\n");
            printf("Nome do Livro:");
            fflush(stdin);
            gets(livros[i].nomelivro);

            printf("\nIsbn:");
            scanf("%d", &livros[i].ISBN);

            int op;
            exibirCurso();
            printf("\nSelecione um curso:");
            scanf("%d", &op);

            livros[i].curso = cursos[op];

            livros[i].disponivel = 1;
        }
        isValidLivro = 1;
    }
    else
    {
        printf("\n_________Nenhum Curso cadastrado_________\n");
    }
    limparPausarTela();
}

void gerarLivros()
{
    if (isValidCurso)
    {
        int i;
        for (i = 0; i < MAX_LIVROS; i++)
        {
            sprintf(livros[i].nomelivro, "Livro %d", i);
            livros[i].ISBN = i;
            livros[i].curso = cursos[1];
            livros[i].disponivel = 1;
        }
        isValidLivro = 1;
        printf("\n_________Dados do livros gerados automaticamente_________\n");
    }
    else
    {
        printf("\n_________Nenhum Curso cadastrado_________\n");
    }
    limparPausarTela();
} //fim do procedimento

void login()
{
    if (isValidFuncionarios)
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
                if (strcmp(funcionarios[i].login, login) == 0)
                {
                    if (strcmp(funcionarios[i].senha, senha) == 0)
                    {
                        isValidLogin = 1;
                    }
                }
            }
            if (!isValidLogin)
            {
                printf("\nSenha incorreta\n");
                limparPausarTela();
            }
            else if (isValidLogin)
            {
                limparTela();
                menuFuncionario();
            }

            int op;
            limparTela();
            printf("\n1 - Nova tentativa");
            printf("\n0 - Sair");
            printf("\n>");
            scanf("%d", &op);
            if (op == 0)
            {
                break;
            }

        } while (isValidLogin == 0);
    }
    else
    {
        printf("\n_________Nenhum funcionario Cadastrado_________\n");
        limparPausarTela();
    }
}

void exibirLivrosDisp()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX_LIVROS; i++)
    {
        if (livros[i].disponivel)
        {
            printf("\n%d - %s - %s", i, livros[i].nomelivro, livros[i].curso.area);
        }
    } //for de exibição de livros
    printf("\n______________________________________________________\n");
}
void exibirLivrosNaoDisp()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX_LIVROS; i++)
    {
        if (!livros[i].disponivel)
        {
            printf("\n%d - %s - %s", i, livros[i].nomelivro, livros[i].curso.area);
        }
    } //for de exibição de livros
    printf("\n______________________________________________________\n");
}

// sistema de controle de livros
void emprestimoLivro()
{

    if (isValidAluno && isValidLivro)
    {

        int selectAluno;
        printf("\nAlunos:\n");
        exibirAlunos();
        printf("\nSelecione um aluno:");
        scanf("%d", &selectAluno);

        limparTela();

        int continuarSelecao = 1;

        int i;
        for (i = 0; i < MAX_LIVROS_ALUNO; i++)
        {
            int selectLivro;
            printf("Livros:");
            exibirLivrosDisp();
            printf("\nSelecione um livro:");
            scanf("%d", &selectLivro);
            alunos[selectAluno].livros[i] = livros[selectLivro];

            livros[selectLivro].disponivel = 0;

            printf("\nDeseja emprestar outro livro? 1 -sim, 0- nao:\n");
            scanf("%d", &continuarSelecao);
            limparTela();

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
void devolucaoLivro()
{
    if (isValidAluno && isValidLivro)
    {

        int selectAluno;
        int op;
        //exibir livros emprestados
        printf("Livros empretados:\n");

        exibirLivrosNaoDisp();

        printf("_________Selecione o livro que deseja devolver:_________\n");
        scanf("%d", &op);

        livros[op].disponivel = 1;

        int i;
        //for para copmpararação do aluno ao livro
        for (i = 0; i < MAX; i++)
        {
            int j;
            for (j = 0; j < MAX; j++)
            {
                if (alunos[i].livros[j].nomelivro == livros[op].nomelivro)
                {
                    strcpy(alunos[i].livros[j].nomelivro[0], NULL);
                    alunos[i].livros[j].ISBN = 0;
                    alunos[i].livros[j].disponivel = 1;
                    strcpy(alunos[i].livros[j].curso.nomeCurso, NULL);
                    strcpy(alunos[i].livros[j].curso.area, NULL);
                }
            }
        }
        printf("Devolução realizada!");
    }
    else
    {
        printf("\nDados insuficientes\n");
    }
    limparPausarTela();
}

void relatorioAlunoLivros()
{
    if (isValidAluno)
    {

        printf("\n_________Sistema de Relatorio_________\n");

        int i;
        for (i = 0; i < MAX; i++)
        {
            if (alunos[i].livros[0].nomelivro[0] != NULL)
            {
                printf("\n______________________________________________________\n");
                printf("\nNome: %s", alunos[i].nomeAluno);
                printf("\nMatricula: %d", alunos[i].matricula);
                printf("\nCurso: %s", alunos[i].curso.nomeCurso);
                printf("\nLivros:");
                int j;
                for (j = 0; j < MAX_LIVROS_ALUNO; j++)
                {
                    if (alunos[i].livros[i].nomelivro[0] != NULL)
                    {
                        printf("\n%s", alunos[i].livros[j].nomelivro);
                    }
                }
            }
        }
    }
    else
    {
        printf("\n_________Nenhum aluno cadastrado_________\n");
    }

    limparPausarTela();
}

void pesquisarRelatorioAluno()
{
    char pesquisar[120];
    
    printf("\n_________Sistema de Pesquisa_________\n");
    printf("\nDigite um nome:\n");
    printf(">");
    scanf("%s",&pesquisar);

    if (isValidAluno)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            if (strcmp(alunos[i].nomeAluno,pesquisar)==0)
            {
                printf("\n______________________________________________________\n");
                printf("\nNome: %s", alunos[i].nomeAluno);
                printf("\nMatricula: %d", alunos[i].matricula);
                printf("\nCurso: %s", alunos[i].curso.nomeCurso);
                printf("\nLivros:");
                int j;
                for (j = 0; j < MAX_LIVROS_ALUNO; j++)
                {
                    if (alunos[i].livros[i].nomelivro[0] != NULL)
                    {
                        printf("\n%s", alunos[i].livros[j].nomelivro);
                    }
                }
            }
        }
    }
    else
    {
        printf("\n_________Nenhum aluno cadastrado_________\n");
    }
    limparPausarTela();
}
