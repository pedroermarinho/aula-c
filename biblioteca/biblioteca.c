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

//Alunos Pedro Marinho e Rayssa Carla

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 2 // define a quantidade de dados que serão cadastrados

typedef struct Funcionario
{
    char nomefuncionario[120];
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
    Livro livros[MAX];
} Aluno;

Funcionario funcionarios[MAX];
Livro livros[MAX];
Curso cursos[MAX];
Aluno alunos[MAX];

void limparTela();       //limpar tela
void limparPausarTela(); // pausar e limpar tela

void login(); //sistema login

// menus de controle
void menuLogin(); // menu do login
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
void exibirLivros();        //exibir dados dos livros
void exibirLivrosDisp();    //exibir dados dos livros disponíveis
void exibirLivrosNaoDisp(); //exibir dados dos livros não disponíveis

// sistema de controle de livros
void emprestimoLivro(); //sistemas de emprestimo livros
void devolucaoLivro();  //sitema de devolução de livros

//relatorio
void relatorio();

int isValidCurso = 0;
int isValidFuncionarios = 0;
int isValidLogin = 0;

main()
{
    setlocale(LC_ALL, "Portuguese");

    menuLogin();

    return 0;

} //Fim main

void limparTela()
{
    system("cls");
} //fim procedimento limparTela

void limparPausarTela()
{
    system("pause");
    limparTela();
} //fim procedimento limparPausarTela

void menuLogin()
{
    do
    {
        int isValid = 1;
        printf("\n#__________Tipo de Usuario__________#\n");
        printf("\n1 - Administrador");
        printf("\n2 - Funcionario");
        printf("\n0 - Sair");
        int op;
        do
        {
            printf("\n#__________Selecione uma opcao:__________#\n");
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
        printf("\n#_________Sistema do Adm_________#\n");
        printf("\n1 - Cadastros");
        printf("\n2 - Realizar Emprestimo");
        printf("\n3 - Realizar Devolução");
        printf("\n4 - Relatorio");
        printf("\n5 - Gerar");
        printf("\n0 - Sair");
        int op;
        do
        {
            printf("\nEscolha uma opção:");
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
                relatorio();
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
    printf("\nSistema de Cadastro do Adm\n");
    printf("\n1 - Funcionario");
    printf("\n2 - Curso");
    printf("\n3 - Livros");
    printf("\n4 - Cadastro Aluno");
    printf("\n0 - Sair");
    int op;
    do
    {
        printf("\nEscolha uma opção:");
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
    printf("\nSistema de Gerar do Adm\n");
    printf("\n1 - Funcionario");
    printf("\n2 - Curso");
    printf("\n3 - Livros");
    printf("\n4 - Aluno");
    printf("\n5 - Todos");
    printf("\n0 - Sair");
    int op;
    do
    {
        printf("\nEscolha uma opção:");
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
        //Aluno
        case 4:
            limparTela();
            gerarAlunos();
            break;
        //Aluno
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
        printf("\nSistema do Funcionario\n");
        printf("\n1 - Cadastro aluno");
        printf("\n2 - Emprestimo");
        printf("\n3 - Devolucação");
        printf("\n0 - Sair");
        int op;
        do
        {
            printf("\nEscolha uma opção:");
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

void cadastrarFuncionarios()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("\n###__________CADASTRO___________###\n");
        printf("Nome:");
        fflush(stdin);
        gets(funcionarios[i].nomefuncionario);

        printf("\nMatricula:");
        scanf("%d", &funcionarios[i].matricula);

        printf("\nLogin:");
        fflush(stdin);
        gets(funcionarios[i].login);

        printf("\nSenha:");
        fflush(stdin);
        gets(funcionarios[i].senha);
    } //fim for de cadastro de funcionario
    isValidFuncionarios =1;
    limparPausarTela();

} //fim do procedimento de cadastro de funcionario

void gerarFuncionarios()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        sprintf(funcionarios[i].nomefuncionario, "Funcionario %d", i);
        funcionarios[i].matricula = i;
        sprintf(funcionarios[i].login, "login%d", i);
        sprintf(funcionarios[i].senha, "senha%d", i);
    }
    printf("\n####________Dados do Funcionario gerados automaticamente________####\n");

    limparPausarTela();
    isValidFuncionarios =1;

} //fim do procedimento
void exibirFuncionarios()
{
    printf("\n#-------------------------------------------------------#\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("%d - %s\n", i, funcionarios[i].nomefuncionario);
    }
    printf("\n#-------------------------------------------------------#\n");
}

void cadastrarAlunos()
{

    if (isValidCurso)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            printf("Nome:");
            fflush(stdin);
            gets(alunos[i].nomeAluno);

            printf("\nMatricula:");
            scanf("%d", &alunos[i].matricula);

            // alunos[i].curso = 0; //arrumar

        } //fim for de cadastro de funcionario
    }
    else
    {
        printf("\n###_____Nenhum dos Cursos cadastrado____###\n");
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

            //alunos[i]. = 0; //arrumar
        }
        printf("\n###_____Dados do Alunos gerados automaticamente_____###\n");
    }
    else
    {
        printf("\n###_____Nenhum Curso cadastrado____###\n");
    }
    limparPausarTela();
} //fim do procedimento

void exibirAlunos(){
    printf("\n#-------------------------------------------------------#\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("\n%d - %s", i, alunos[i].nomeAluno);
    } //fim do for de exibição de aluno
    printf("\n#-------------------------------------------------------#\n");
}

//cadastro e exibição de cursos
void cadastroCursos()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("\n#-------------------------------------------------------#\n");
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
    printf("\n#-------------------------------------------------------#\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("%d - %s - %s\n", i, cursos[i].nomeCurso, cursos[i].area);
    } //fim do for para exibir a lista de livros
    printf("\n#-------------------------------------------------------#\n");
} //fim do procedimento para exibição dos livros

void gerarCursos()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        sprintf(cursos[i].nomeCurso, "curso %d", i);
        sprintf(cursos[i].area, "area%d", i);
    }
    printf("\nDados do Alunos gerados automaticamente\n");
    isValidCurso = 1;
    limparPausarTela();
} //fim do procedimento

void cadastrarLivros()
{
    if (isValidCurso)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            printf("\n#-------------------------------------------------------#\n");
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
    }
    else
    {
        printf("\n###_____Nenhum Curso cadastrado____###\n");
    }
    limparPausarTela();
}

void gerarLivros()
{
    if (isValidCurso)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            sprintf(livros[i].nomelivro, "Livro %d", i);
            livros[i].ISBN = i;
            ///livros[i].cursos = cursos[i]; // corrigir
            livros[i].disponivel = 1;
        }
        printf("\n##____________Dados do livros gerados automaticamente____________##\n");
    }
    else
    {
        printf("\nNenhum Curso cadastrado\n");
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
            printf("\nSenhar:");
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
            if(!isValidLogin){
                printf("\nSenha incorreta\n");
            }else
            {
                limparTela();
                menuFuncionario();
            }
            
            int op;
            limparTela();
            printf("1 - Nova tentativa");
            printf("0 - Sair");
            if(0==0){
                break;
            }
            
        } while(!isValidLogin);
    }
    else
    {
        printf("\nNenhum funcionario Cadastrado\n");
    }
}


void exibirLivrosDisp()
{
    printf("\n#-------------------------------------------------------#\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (livros[i].disponivel)
        {
            printf("\n%d - %s - %s", i, livros[i].nomelivro, livros[i].curso.area);
        }
    } //for de exibição de livros
    printf("\n#-------------------------------------------------------#\n");
}
void exibirLivrosNaoDisp()
{
    printf("\n#-------------------------------------------------------#\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (!livros[i].disponivel)
        {
            printf("\n%d - %s - %s", i, livros[i].nomelivro, livros[i].curso.area);
        }
    } //for de exibição de livros
    printf("\n#-------------------------------------------------------#\n");
}

// sistema de controle de livros
void emprestimoLivro()
{

    int selectAluno;
    printf("\nAlunos:\n");
    exibirAlunos();
    printf("\nSelecione um aluno:");
    scanf("%d", &selectAluno);

    limparTela();

    int continuarSelecao = 1;

    int i;
    for (i = 0; i < MAX; i++)
    {
        int selectLivro;
        printf("Livros:");
        exibirLivrosDisp();
        printf("\nSelecione um livro:");
        scanf("%d", &selectLivro);
       // alunos[selectAluno].livros[i] = livros[selectLivro];

        //alunos[selectAluno].livrosEmprestados = i;

        livros[selectLivro].disponivel = 0;

        printf("\nDeseja emprestar outro livro? 1 -sim, 0- nao:");
        scanf("%d", &continuarSelecao);
        limparTela();
        if (!continuarSelecao)
        {
            break;
        }
    }
}
void devolucaoLivro()
{
    int selectAluno;
    int i, op, a, l;
    //exibir livros emprestados
    printf("Livros empretados:\n");

    for (i = 0; i < MAX; i++)
    {
        if (!livros[i].disponivel)
        {
            printf("\n______________________________________________________\n");
            printf("%d - %s", i, livros[i].nomelivro);
        }
    }

    printf("Selecione o livro que deseja devolver:\n");
    scanf("%d", &op);

    //for para copmpararação do aluno ao livro
    for (a = 0; a < MAX; a++)
    {
        for (l = 0; l < MAX; l++)
        {
            if (alunos[a].livros[l].nomelivro == livros[op].nomelivro)
            {
                strcpy(alunos[a].livros[l].nomelivro, " ");
                alunos[a].livros[l].ISBN = 0;
                alunos[a].livros[l].disponivel = 1;
                strcpy(alunos[a].livros[l].curso.nomeCurso, " ");
                strcpy(alunos[a].livros[l].curso.area, " ");
            }
        }
    }
    printf("Devolução realizada!");
    limparPausarTela();
}

void relatorio()
{
    int i, l;
    printf("Sistema de Relatorio");

    for(i=0;i<MAX;i++){
       for(l=0;l<3;l++){
           //if(alunos[i].livrosEmprestados>0){
               //printf("%d - %s - ");
          // }
       }
   }
}