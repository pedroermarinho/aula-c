/*
SINETRAM
1.	Faça um sistema para gerenciar o sistema de transporte de estudantes. O administrador do sistema poderá cadastrar escola, faculdade, cursos preparatórios como:
-Nome
-Endereço(Rua, Numero, Bairro, Telefone)
	O administrador Cadastra os cursos:
		-Nome 
		-Faculdade que é uma lista exibida pelo sistema através do cadastro.
	O administrador Cadastra estudantes:
		-Nome
		-Faculdade
		-Curso
		-Telefone
		-Endereço (rua, casa, bairro)
		-Login(E-mail)
		-Senha(alfanumérica)
	O administrador Validar cadastro: Quando o aluno é cadastrado fica com status de “pendente”, de acordo com número de cadastro de alunos será formada uma lista e o administrador aceita o cadastro fazendo o status do aluno ficar “ativo”. O administrador realiza a venda de passagem: Revisando a matricula do aluno.
	O aluno deve pagar o valor desejado, o sistema contabiliza a quantidade de créditos e registra o saldo. 
O administrador Cadastra funcionário:
	 -Nome
	-Matricula
	-Login
	-Senha livre
O funcionário poderá cadastrar aluno, realizar venda de passagem.
O estudante poderá entrar no sistema para verificar saldo: O sistema exibe os dados do estudante e exibe a quantidade de créditos e saldo.

Dupla
Valor: 4,0 PONTOS
*/

//Alunos Pedro Marinho e Rayssa Carla

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

#define MAX 2              // define a quantidade de dados que serão cadastrados
#define VL_PASSAGEM 2

typedef struct Login{
	char usuario[20];
	char senha[20];
}Login;

typedef struct ADM{
	Login login;
}ADM;

typedef struct Endereco{
	char rua[60];
	char casa[20];
	char bairro[60];
}Endereco;


typedef struct Curso
{
   	char nomeCurso[120];
   	Endereco endereco;
   	char telefone[20];   		
} Curso;

typedef struct Funcionario
{
    char nomeFuncionario[120];
    int matricula;
    Login login;
} Funcionario;

typedef struct Estudante{
	char matricula[20];
	char nomeEstudante[120];
	Login login;
	char telefone[20];
    int status;
    float saldo;
    int credito;  
	Endereco endereco;
	Curso curso;
}Estudante;


Funcionario funcionarios[MAX];
Curso cursos[MAX];
Estudante estudantes[MAX];
ADM adm;

void limparTela();       //limpar tela
void limparPausarTela(); // pausar e limpar tela

void login();

// menus de controle
void menuLogin();     // menu do login
void menuRelatorio(); //menu de relatorio
//menus do adm
void menuAdm();         // menu principal do adm
void menuAdmCadastro(); // menu de cadastrados do adm
void menuAdmGerar();    // menu de geração de dados automaticos do adm
//menus do funcionario
void menuFuncionario(); // menu do principal do funcionario

//menu do Estudante
void menuEstudante(); //menu do principal do Estudante



void loginADM();
void loginFuncionario();
void loginEstudante();

//cadastro de funcionarios
void cadastrarFuncionarios(); //cadastrar funcionarios
void gerarFuncionarios();     //gerar dados funcionarios
void exibirFuncionarios();    //exibir dados dos funcionarios

//cadastro e exibição de alunos
void cadastrarEstudante(); //cadastrar alunos
void gerarEstudante();     //gerar dados funcionarios
void exibirEstudante();    //exibir dados alunos

//cadastro e exibição de cursos
void cadastroCursos(); //cadastrar cursos
void gerarCursos();    //gerar dados dos cursos
void exibirCursos();   //exibir dados dos cursos

//sistema de credito
void colocarCredito(); //adicionar credito
void saldo(); //
void validarEstudante(); //


int isValidCurso = 0;
int isValidFuncionarios = 0;
int isValidLogin = 0;
int isValidEstudante = 0;


main()
{
    setlocale(LC_ALL, "Portuguese");
    
    sprintf(adm.login.usuario,"adm");
    sprintf(adm.login.senha,"adm");

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
        printf("\n3 - Estudante");
        printf("\n0 - Sair");
        int op;
        do
        {
            printf("\n_________Selecione uma opcao_________\n");
            printf(">");
            scanf("%d", &op);
            switch (op)
            {
        	//1 - Administrador
            case 1:
                limparTela();
                loginADM();
                break;
			//2 - Funcionario
            case 2:
                limparTela();
                loginFuncionario();
                break;
			//3 - Estudante
			case 3:
				limparTela();
				loginEstudante();
				break;
			//0 - sair
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
        printf("\n1 - Cadastrar");
        printf("\n2 - Validar");
        printf("\n3 - Vender");
        printf("\n0 - Sair");
        int op;
        do
        {
            printf("\n_________Escolha uma opção_________\n");
            printf(">");
            scanf("%d", &op);
            switch (op)
            {
            //1 - Cadastrar
            case 1:
                limparTela();
                menuAdmCadastro();
                break;
            //2 - Validar
            case 2:
                limparTela();
                validarEstudante();
                break;
            //3 - Vender
            case 3:
                limparTela();
                colocarCredito();
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
	int continuar =1;
	do{
			
	    int isValid = 1;
	    printf("\n_________Sistema de Cadastro do Adm_____________\n");
	    printf("\n1 - Funcionario");
	    printf("\n2 - Curso");
	    printf("\n3 - Estudante");
	    printf("\n4 - Gerar Cadastrados");
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
	        //3 - Estudante
	        case 3:
	            limparTela();
	            cadastrarEstudante();
	            break;
	        //4 - Gerar Cadastrados
	        case 4:
	            limparTela();
	            menuAdmGerar();
	            break;
	        case 0:
	        	continuar = 0;
	            limparTela();
	            break;
	
	        default:
	            isValid = 0;
	            break;
	        }
	    } while (!isValid);
    }while(continuar);
} //fim do procedimento

void menuAdmGerar()
{
	int continuar =1;
	do{
	    int isValid = 1;
	    printf("\n_________Sistema de Gerar do Adm____________\n");
	    printf("\n1 - Funcionario");
	    printf("\n2 - Curso");
	    printf("\n3 - Estudante");
	    printf("\n4 - Todos");
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
	        //3 - Aluno
	        case 3:
	            limparTela();
	            gerarEstudante();
	            break;
	        //4 - Todos
	        case 4:
	            limparTela();
	            gerarFuncionarios();
	            gerarCursos();
	            gerarEstudante();
	            break;
	        case 0:
	        	continuar = 0;
	            limparTela();
	            break;
	
	        default:
	            isValid = 0;
	            break;
	        }
	    } while (!isValid);
    }while(continuar);
} //fim do procedimento

void menuFuncionario()
{
    int continuar = 1;
    do
    {
        int isValid = 1;
        printf("\n_________Sistema do Funcionario_________\n");
        printf("\n1 - Cadastro aluno");
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
                cadastrarEstudante();
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

void menuEstudante()
{
	limparTela();
	int continuar =1;
	do{
		printf("\nSistema de Aluno:\n");
		printf("\n1 - Saldo");
		printf("\n0 - Sair");
		int isValid;
		int op;
		do{
			printf("\nSelecione um opção:\n");
			printf(">");
			scanf("%d",&op);
			isValid = 1;
			switch(op){
				//1 - Saldo
				case 1:
					saldo();
					break;
				//0 - Sair
				case 0:
					continuar = 0;
					limparTela();
					break;
				default:
					isValid =0;
					break;
			}
			
		}while(!isValid);
	}while(continuar);	
}

void loginADM()
{
	printf("\nSistema de Login do ADM\n");
	printf("\nUsuario padrão: adm");
	printf("\nSenha padrão: adm\n");
    do
    {
        char usuario[120];
        char senha[120];
        printf("\nLogin:\n");
        printf(">");
        fflush(stdin);
        gets(usuario);
        printf("\nSenha:\n");
        printf(">");
        fflush(stdin);
        gets(senha);
        int i;
            if (strcmp(adm.login.usuario, usuario) == 0)
            {
                if (strcmp(adm.login.senha, senha) == 0)
                {
                    isValidLogin = 1;
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
            menuAdm();
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
	limparTela();
}

void loginFuncionario()
{
	printf("\nSistema de Login do Funcionario\n");
    if (isValidFuncionarios)
    {
        do
        {
            char usuario[120];
            char senha[120];
            printf("\nLogin:");
            fflush(stdin);
            gets(usuario);
            printf("\nSenha:");
            fflush(stdin);
            gets(senha);
            int i;
            for (i = 0; i < MAX; i++)
            {
                if (strcmp(funcionarios[i].login.usuario, usuario) == 0)
                {
                    if (strcmp(funcionarios[i].login.senha, senha) == 0)
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
        limparTela();
    }
    else
    {
        printf("\n_________Nenhum funcionario Cadastrado_________\n");
        limparPausarTela();
    }
}

void loginEstudante()
{
	printf("\nSistema de Login do Estudante\n");
    if (isValidEstudante)
    {
        do
        {
            char usuario[120];
            char senha[120];
            printf("\nLogin:");
            fflush(stdin);
            gets(usuario);
            printf("\nSenha:");
            fflush(stdin);
            gets(senha);
            int i;
            for (i = 0; i < MAX; i++)
            {
                if (strcmp(estudantes[i].login.usuario, usuario) == 0)
                {
                    if (strcmp(estudantes[i].login.senha, senha) == 0)
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
                menuEstudante();
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
        limparTela();
    }
    else
    {
        printf("\n_________Nenhum estudante Cadastrado_________\n");
        limparPausarTela();
    }
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
        gets(funcionarios[i].login.usuario);

        printf("\nSenha:");
        fflush(stdin);
        gets(funcionarios[i].login.senha);
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
        sprintf(funcionarios[i].login.usuario, "login%d", i);
        sprintf(funcionarios[i].login.senha, "senha%d", i);
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

void cadastrarEstudante()
{

    if (isValidCurso)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            printf("\n______________________________________________________\n");
            printf("Nome:");
            fflush(stdin);
            gets(estudantes[i].nomeEstudante);

            printf("\nMatricula:");
            scanf("%d", &estudantes[i].matricula);

            int op;
            printf("Selecione um curso");
            exibirCursos();
            printf("\n>");
            scanf("%d", &op);

            estudantes[i].curso = cursos[op];

        } //fim for de cadastro de funcionario
        isValidEstudante = 1;
    }
    else
    {
        printf("\n_________Nenhum dos Cursos cadastrado_________\n");
    }
    limparPausarTela();
} //fim do procedimento de cadastro de alunos

void gerarEstudante()
{
    if (isValidCurso)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            sprintf(estudantes[i].nomeEstudante, "Aluno %d", i);
            sprintf(estudantes[i].matricula, "matricula%d", i);
            estudantes[i].curso = cursos[i];
            //alunos[i]. = 0; //arrumar
        }
        isValidEstudante = 1;
        printf("\n_________Dados do Alunos gerados automaticamente_________\n");
    }
    else
    {
        printf("\n_________Nenhum Curso cadastrado_________\n");
    }
    limparPausarTela();
} //fim do procedimento

void exibirEstudante()
{
    printf("\n______________________________________________________\n");
    if(isValidEstudante){
	    int i;
	    for (i = 0; i < MAX; i++)
	    {
	        printf("\n%d -> %s",i,estudantes[i].nome);
	    } //fim do for de exibição de aluno
    }else{
		printf("\nNenhuma Instituição cadastrada\n");
	}
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

        printf("\nTelefone: ");
        fflush(stdin);
        gets(cursos[i].telefone);
    } //fim for do cadastro de cursos

    isValidCurso = 1;
    limparPausarTela();
} //fim do procedimento de cadastro de cursos

void exibirCursos()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
		 printf("\n%d -> %s",i,cursos[i].nomeCurso);
    } //fim do for para exibir a lista de livros
    printf("\n______________________________________________________\n");
} //fim do procedimento para exibição dos livros

void gerarCursos()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        sprintf(cursos[i].nomeCurso,"instituição %d",i);
		sprintf(cursos[i].endereco.bairro,"bairro %d",i);
		sprintf(cursos[i].endereco.casa,"casa %d",i);
		sprintf(cursos[i].endereco.rua,"rua %d",i);
    }
    printf("\n_________Dados do Cursos gerados automaticamente_________\n");
    isValidCurso = 1;
    limparPausarTela();
} //fim do procedimento

void colocarCredito()
{
	
	exibirEstudante();
	int op;
	printf("\nSelecione um estudante para colocar credito:\n");
	printf(">");
	scanf("%d",&op);
	limparTela();
	
	printf("\nnome: %s",estudantes[op].nomeEstudante);
	printf("\nbairro: %s",estudantes[op].endereco.bairro);
	printf("\ncasa: %s",estudantes[op].endereco.casa);
	printf("\nrua: %s",estudantes[op].endereco.rua);
	printf("\nlogin: %s",estudantes[op].login.usuario);	//login1
	printf("\nsenha: %s",estudantes[op].login.senha);
	printf("\nInstituições: %s",estudantes[op].curso.nomeCurso);
	
	printf("\n\n");
	
	float valor;
	printf("\nValor em diheiro a ser colocado:(ex 20.50)\n");
	printf(">");
	scanf("%f",&valor);
	

	estudantes[op].saldo +=remainder(valor, VL_PASSAGEM);
	estudantes[op].credito += floor(valor/VL_PASSAGEM);
	
	
	printf("\nsaldo ->%.2f",estudantes[op].saldo);
	printf("\ncredito ->%d",estudantes[op].credito);
	printf("\n\n");
	limparPausarTela();
}

void saldo()
{
	exibirEstudante();
	int op;
	printf("\nSelecione um estudante:\n");
	printf(">");
	scanf("%d",&op);
	limparTela();
	
	printf("\nnome: %s",estudantes[op].nomeEstudante);
	printf("\nbairro: %s",estudantes[op].endereco.bairro);
	printf("\ncasa: %s",estudantes[op].endereco.casa);
	printf("\nrua: %s",estudantes[op].endereco.rua);
	printf("\nlogin: %s",estudantes[op].login.usuario);	//login1
	printf("\nsenha: %s",estudantes[op].login.senha);
	printf("\nInstituições: %s",estudantes[op].curso.nomeCurso);
	printf("\nSaldo: %.2f",estudantes[op].saldo);
	printf("\nCredito: %d",estudantes[op].credito);
	limparPausarTela();
}

void validarEstudante()
{
	if(isValidCurso){
		int i;
		for(i = 0;i<MAX;i++){
			if(!estudantes[i].status){
				printf("\n%d -> %s",i,estudantes[i].nomeEstudante);
			}	
		}
		int op;
		printf("\nSelecione um estudante para ser ativado:\n");
		printf(">");
		scanf("%d",&op);
		estudantes[op].status = 1;
		printf("\nAtivação realizada\n");
	
	}else{
		printf("\nNenhuma Instituição cadastrada\n");
	}
	limparPausarTela();
}

