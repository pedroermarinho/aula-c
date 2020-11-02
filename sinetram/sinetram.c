/*
SINETRAM
1.	Fa�a um sistema para gerenciar o sistema de transporte de estudantes. O administrador do sistema poder� cadastrar escola, faculdade, cursos preparat�rios como:
-Nome
-Endere�o(Rua, Numero, Bairro, Telefone)
	O administrador Cadastra os cursos:
		-Nome 
		-Faculdade que � uma lista exibida pelo sistema atrav�s do cadastro.
	O administrador Cadastra estudantes:
		-Nome
		-Faculdade
		-Curso
		-Telefone
		-Endere�o (rua, casa, bairro)
		-Login(E-mail)
		-Senha(alfanum�rica)
	O administrador Validar cadastro: Quando o aluno � cadastrado fica com status de �pendente�, de acordo com n�mero de cadastro de alunos ser� formada uma lista e o administrador aceita o cadastro fazendo o status do aluno ficar �ativo�. O administrador realiza a venda de passagem: Revisando a matricula do aluno.
	O aluno deve pagar o valor desejado, o sistema contabiliza a quantidade de cr�ditos e registra o saldo. 
O administrador Cadastra funcion�rio:
	 -Nome
	-Matricula
	-Login
	-Senha livre
O funcion�rio poder� cadastrar aluno, realizar venda de passagem.
O estudante poder� entrar no sistema para verificar saldo: O sistema exibe os dados do estudante e exibe a quantidade de cr�ditos e saldo.

Dupla
Valor: 4,0 PONTOS
*/

//Alunos Pedro Marinho e Rayssa Carla

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

#define MAX 2              // define a quantidade de dados que ser�o cadastrados
#define VL_PASSAGEM 2.34

typedef struct 
{
	char usuario[20];
	char senha[20];
}login_t;

typedef struct 
{
	login_t login;
}adm_t;

typedef struct 
{
	char rua[60];
	char casa[20];
	char bairro[60];
}endereco_t;

typedef struct 
{
   	char nome_curso[120];
   	endereco_t endereco;
   	char telefone[20];   		
} curso_t;

typedef struct 
{
    char nome_funcionario[120];
    int matricula;
    login_t login;
} funcionario_t;

typedef struct 
{
	char matricula[20];
	char nome_estudante[120];
	login_t login;
	char telefone[20];
    int status;
    float saldo;
    int credito;  
	endereco_t endereco;
	curso_t curso;
}estudante_t;


funcionario_t funcionario_vet[MAX];
curso_t curso_vet[MAX];
estudante_t estudante_vet[MAX];
adm_t adm;

estudante_t select_estudante;

void limpar_tela();       //limpar tela
void pausar_limpar_tela(); // pausar e limpar tela

void login();

// menus de controle
void menu_login();     // menu do login
void menu_relatorio(); //menu de relatorio
//menus do adm
void menu_adm();         // menu principal do adm
void menu_adm_cadastro(); // menu de cadastrados do adm
void menu_adm_gerar();    // menu de gera��o de dados automaticos do adm
//menus do funcionario
void menu_funcionario(); // menu do principal do funcionario

//menu do Estudante
void menu_estudante(); //menu do principal do Estudante



void login_adm();
void login_funcionario();
void login_estudante();

//cadastro de funcionarios
void cadastrar_funcionarios(); //cadastrar funcionarios
void gerar_funcionarios();     //gerar dados funcionarios
void exibir_funcionarios();    //exibir dados dos funcionarios

//cadastro e exibi��o de alunos
void cadastrar_estudante(); //cadastrar alunos
void gerar_estudante();     //gerar dados funcionarios
void exibir_estudante();    //exibir dados alunos
void exibir_estudante_disp();

//cadastro e exibi��o de cursos
void cadastro_cursos(); //cadastrar cursos
void gerar_cursos();    //gerar dados dos cursos
void exibir_cursos();   //exibir dados dos cursos

//sistema de credito
void colocar_credito(); //adicionar credito
void saldo(); //
void saldo_estudante();
void validar_estudante(); //


int is_valid_curso = 0;
int is_valid_funcionarios = 0;

int is_valid_estudante = 0;


main()
{
    setlocale(LC_ALL, "Portuguese");
    
    sprintf(adm.login.usuario,"adm");
    sprintf(adm.login.senha,"adm");

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
#ifdef __WIN32
    system("pause");
#else
    system("read -p \"Pressione enter para continuar\" saindo");
#endif
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
                limpar_tela();
                login_adm();
                break;
			//2 - Funcionario
            case 2:
                limpar_tela();
                login_funcionario();
                break;
			//3 - Estudante
			case 3:
				limpar_tela();
				login_estudante();
				break;
			//0 - sair
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
        printf("\n1 - Cadastrar");
        printf("\n2 - Validar");
        printf("\n3 - Vender");
        printf("\n0 - Sair");
        int op;
        do
        {
            printf("\n_________Escolha uma op��o_________\n");
            printf(">");
            scanf("%d", &op);
            switch (op)
            {
            //1 - Cadastrar
            case 1:
                limpar_tela();
                menu_adm_cadastro();
                break;
            //2 - Validar
            case 2:
                limpar_tela();
                validar_estudante();
                break;
            //3 - Vender
            case 3:
                limpar_tela();
                colocar_credito();
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
	int continuar =1;
	do{
			
	    int is_valid = 1;
	    printf("\n_________Sistema de Cadastro do Adm_____________\n");
	    printf("\n1 - Funcionario");
	    printf("\n2 - Curso");
	    printf("\n3 - Estudante");
	    printf("\n4 - Gerar Cadastrados");
	    printf("\n0 - Sair");
	    int op;
	    do
	    {
	        printf("\n_________Escolha uma op��o_________\n");
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
	        //3 - Estudante
	        case 3:
	            limpar_tela();
	            cadastrar_estudante();
	            break;
	        //4 - Gerar Cadastrados
	        case 4:
	            limpar_tela();
	            menu_adm_gerar();
	            break;
	        case 0:
	        	continuar = 0;
	            limpar_tela();
	            break;
	
	        default:
	            is_valid = 0;
	            break;
	        }
	    } while (!is_valid);
    }while(continuar);
} //fim do procedimento

void menu_adm_gerar()
{
	int continuar =1;
	do{
	    int is_valid = 1;
	    printf("\n_________Sistema de Gerar do Adm____________\n");
	    printf("\n1 - Funcionario");
	    printf("\n2 - Curso");
	    printf("\n3 - Estudante");
	    printf("\n4 - Todos");
	    printf("\n0 - Sair");
	    int op;
	    do
	    {
	        printf("\n_________Escolha uma op��o_________________\n");
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
	        //3 - Aluno
	        case 3:
	            limpar_tela();
	            gerar_estudante();
	            break;
	        //4 - Todos
	        case 4:
	            limpar_tela();
	            gerar_funcionarios();
	            gerar_cursos();
	            gerar_estudante();
	            break;
	        case 0:
	        	continuar = 0;
	            limpar_tela();
	            break;
	
	        default:
	            is_valid = 0;
	            break;
	        }
	    } while (!is_valid);
    }while(continuar);
} //fim do procedimento

void menu_funcionario()
{
    int continuar = 1;
    do
    {
        int is_valid = 1;
        printf("\n_________Sistema do Funcionario_________\n");
        printf("\n1 - Cadastrar aluno");
        printf("\n2 - Venda");
        printf("\n0 - Sair");
        int op;
        do
        {
            printf("\n_________Escolha uma op��o_____________\n");
            printf(">");
            scanf("%d", &op);
            switch (op)
            {
            ///1 - Cadastro aluno
            case 1:
                limpar_tela();
                cadastrar_estudante();
                break;
            ///2 - Venda
            case 2:
                limpar_tela();
                colocar_credito();
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
    printf("\n0 - Sair");
    int op;
    do
    {
        printf("\n_________Escolha uma op��o____________\n");
        printf(">");
        scanf("%d", &op);
        switch (op)
        {
        ///1 - Pesquisar por aluno
        case 1:
            limpar_tela();
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

void menu_estudante()
{
	limpar_tela();
	int continuar =1;
	do{
		printf("\nSistema de Aluno:\n");
		printf("\n1 - Saldo");
		printf("\n0 - Sair");
		int is_valid;
		int op;
		do{
			printf("\nSelecione um op��o:\n");
			printf(">");
			scanf("%d",&op);
			is_valid = 1;
			switch(op){
				//1 - Saldo
				case 1:
					saldo_estudante();
					break;
				//0 - Sair
				case 0:
					continuar = 0;
					limpar_tela();
					break;
				default:
					is_valid =0;
					break;
			}
			
		}while(!is_valid);
	}while(continuar);	
}

void login_adm()
{
	int is_valid_login = 0;
	printf("\nSistema de Login do ADM\n");
	printf("\nUsuario padr�o: adm");
	printf("\nSenha padr�o: adm\n");
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
                    is_valid_login = 1;
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
            menu_adm();
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
	limpar_tela();
}

void login_funcionario()
{
	int is_valid_login = 0;
	printf("\nSistema de Login do Funcionario\n");
    if (is_valid_funcionarios)
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
                if (strcmp(funcionario_vet[i].login.usuario, usuario) == 0)
                {
                    if (strcmp(funcionario_vet[i].login.senha, senha) == 0)
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
        limpar_tela();
    }
    else
    {
        printf("\n_________Nenhum funcionario Cadastrado_________\n");
        pausar_limpar_tela();
    }
}

void login_estudante()
{
	int is_valid_login = 0;
	printf("\nSistema de Login do Estudante\n");
    if (is_valid_estudante)
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
                if (strcmp(estudante_vet[i].login.usuario, usuario) == 0)
                {
                    if (strcmp(estudante_vet[i].login.senha, senha) == 0)
                    {
                        is_valid_login = 1;
                        select_estudante = estudante_vet[i];
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
                menu_estudante();
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
        limpar_tela();
    }
    else
    {
        printf("\n_________Nenhum estudante Cadastrado_________\n");
        pausar_limpar_tela();
    }
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
        gets(funcionario_vet[i].login.usuario);

        printf("\nSenha:");
        fflush(stdin);
        gets(funcionario_vet[i].login.senha);
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
        sprintf(funcionario_vet[i].login.usuario, "login%d", i);
        sprintf(funcionario_vet[i].login.senha, "senha%d", i);
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

void cadastrar_estudante()
{

    if (is_valid_curso)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            printf("\n______________________________________________________\n");
            printf("\nNome:\n");
            printf(">");
            fflush(stdin);
            gets(estudante_vet[i].nome_estudante);

            printf("\nMatricula:");
            printf(">");
            fflush(stdin);
            gets(estudante_vet[i].matricula);
            
            printf("\nTelefone:\n");
            printf(">");
            fflush(stdin);
            gets(estudante_vet[i].telefone);
            
            printf("\nUsuario:\n");
            printf(">");
            fflush(stdin);
            gets(estudante_vet[i].login.usuario);
            
            printf("\nSenha:\n");
            printf(">");
            fflush(stdin);
            gets(estudante_vet[i].login.senha);
            
            printf("\nBairro:\n");
	        printf(">");
	        fflush(stdin);
	        gets(estudante_vet[i].endereco.bairro);
	        
	        printf("\nRua:\n");
	        printf(">");
	        fflush(stdin);
	        gets(estudante_vet[i].endereco.rua);
	        
	        printf("\nCasa:\n");
	        printf(">");
	        fflush(stdin);
	        gets(estudante_vet[i].endereco.rua);
            
            
            estudante_vet[i].credito = 0;
            estudante_vet[i].saldo = 0;
            estudante_vet[i].status = 0;
            

            int op;
            printf("Selecione um curso");
            exibir_cursos();
            printf("\n>");
            scanf("%d", &op);

            estudante_vet[i].curso = curso_vet[op];

        } //fim for de cadastro de funcionario
        is_valid_estudante = 1;
    }
    else
    {
        printf("\n_________Nenhum dos Cursos cadastrado_________\n");
    }
    pausar_limpar_tela();
} //fim do procedimento de cadastro de alunos

void gerar_estudante()
{
    if (is_valid_curso)
    {
        int i;
        for (i = 0; i < MAX; i++)
        {
            sprintf(estudante_vet[i].nome_estudante,"aluno %d",i);
            sprintf(estudante_vet[i].matricula,"%d%d%d",i,i,i);
			sprintf(estudante_vet[i].endereco.bairro,"bairro %d",i);
			sprintf(estudante_vet[i].endereco.casa,"%d",i);
			sprintf(estudante_vet[i].endereco.rua,"rua %d",i);
			sprintf(estudante_vet[i].login.usuario,"login%d",i);	//login1
			sprintf(estudante_vet[i].login.senha,"senha%d",i);	//senha1
			sprintf(estudante_vet[i].telefone,"%d%d%d%d",i,i,i,i);	
			estudante_vet[i].curso = curso_vet[i];
			estudante_vet[i].credito = 0;
            estudante_vet[i].saldo = 0;
            estudante_vet[i].status = 0;
        }
        is_valid_estudante = 1;
        printf("\n_________Dados do Alunos gerados automaticamente_________\n");
    }
    else
    {
        printf("\n_________Nenhum Curso cadastrado_________\n");
    }
    pausar_limpar_tela();
} //fim do procedimento

void exibir_estudante()
{
    printf("\n______________________________________________________\n");
    if(is_valid_estudante){
	    int i;
	    for (i = 0; i < MAX; i++)
	    {
	        printf("\n%d -> %s",i,estudante_vet[i].nome_estudante);
	    } //fim do for de exibi��o de aluno
    }else{
		printf("\nNenhuma Institui��o cadastrada\n");
	}
    printf("\n______________________________________________________\n");
}
void exibir_estudante_disp()
{
    printf("\n______________________________________________________\n");
    if(is_valid_estudante){
	    int i;
	    for (i = 0; i < MAX; i++)
	    {
	    	if(estudante_vet[i].status){
	     	   printf("\n%d -> %s",i,estudante_vet[i].nome_estudante);
	    	}
	    } //fim do for de exibi��o de aluno
    }else{
		printf("\nNenhuma Institui��o cadastrada\n");
	}
    printf("\n______________________________________________________\n");
}
//cadastro e exibi��o de cursos
void cadastro_cursos()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        printf("\n______________________________________________________\n");
        printf("\nNome do Curso:\n");
        printf(">");
        fflush(stdin);
        gets(curso_vet[i].nome_curso);
        
        printf("\nTelefone:\n");
        printf(">");
        fflush(stdin);
        gets(curso_vet[i].telefone);
        
        printf("\nBairro:\n");
        printf(">");
        fflush(stdin);
        gets(curso_vet[i].endereco.bairro);
        
        printf("\nRua:\n");
        printf(">");
        fflush(stdin);
        gets(curso_vet[i].endereco.rua);
        
        printf("\nCasa:\n");
        printf(">");
        fflush(stdin);
        gets(curso_vet[i].endereco.rua);
    } //fim for do cadastro de cursos

    is_valid_curso = 1;
    pausar_limpar_tela();
} //fim do procedimento de cadastro de cursos

void exibir_cursos()
{
    printf("\n______________________________________________________\n");
    int i;
    for (i = 0; i < MAX; i++)
    {
		 printf("\n%d -> %s",i,curso_vet[i].nome_curso);
    } //fim do for para exibir a lista de livros
    printf("\n______________________________________________________\n");
} //fim do procedimento para exibi��o dos livros

void gerar_cursos()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        sprintf(curso_vet[i].nome_curso,"institui��o %d",i);
		sprintf(curso_vet[i].endereco.bairro,"bairro %d",i);
		sprintf(curso_vet[i].endereco.casa,"casa %d",i);
		sprintf(curso_vet[i].endereco.rua,"rua %d",i);
    }
    printf("\n_________Dados do Cursos gerados automaticamente_________\n");
    is_valid_curso = 1;
    pausar_limpar_tela();
} //fim do procedimento

void colocar_credito()
{
	
	exibir_estudante_disp();
	int op;
	printf("\nSelecione um estudante para colocar credito:\n");
	printf(">");
	scanf("%d",&op);
	limpar_tela();
	
	printf("\nnome: %s",estudante_vet[op].nome_estudante);
	printf("\nbairro: %s",estudante_vet[op].endereco.bairro);
	printf("\ncasa: %s",estudante_vet[op].endereco.casa);
	printf("\nrua: %s",estudante_vet[op].endereco.rua);
	printf("\nlogin: %s",estudante_vet[op].login.usuario);	//login1
	printf("\nsenha: %s",estudante_vet[op].login.senha);
	printf("\nInstitui��es: %s",estudante_vet[op].curso.nome_curso);
	
	printf("\n\n");
	
	float valor;
	printf("\nValor em diheiro a ser colocado:(ex 20.50)\n");
	printf(">");
	scanf("%f",&valor);
	

	estudante_vet[op].saldo += fabs(remainder(valor, VL_PASSAGEM));
	estudante_vet[op].credito += floor(valor/VL_PASSAGEM);
	
	
	printf("\nsaldo ->%.2f",estudante_vet[op].saldo);
	printf("\ncredito ->%d",estudante_vet[op].credito);
	printf("\n\n");
	pausar_limpar_tela();
}

void saldo()
{
	limpar_tela();
	exibir_estudante();
	int op;
	printf("\nSelecione um estudante:\n");
	do{
		printf(">");
		scanf("%d",&op);
	}while(op>=0 && op <MAX);
	
	limpar_tela();
	
	printf("\nnome: %s",estudante_vet[op].nome_estudante);
	printf("\nbairro: %s",estudante_vet[op].endereco.bairro);
	printf("\ncasa: %s",estudante_vet[op].endereco.casa);
	printf("\nrua: %s",estudante_vet[op].endereco.rua);
	printf("\nlogin: %s",estudante_vet[op].login.usuario);	//login1
	printf("\nsenha: %s",estudante_vet[op].login.senha);
	printf("\nInstitui��es: %s",estudante_vet[op].curso.nome_curso);
	printf("\nSaldo: %.2f",estudante_vet[op].saldo);
	printf("\nCredito: %d",estudante_vet[op].credito);
	pausar_limpar_tela();
}

void saldo_estudante()
{
	limpar_tela();
	
	printf("\nnome: %s",select_estudante.nome_estudante);
	printf("\nbairro: %s",select_estudante.endereco.bairro);
	printf("\ncasa: %s",select_estudante.endereco.casa);
	printf("\nrua: %s",select_estudante.endereco.rua);
	printf("\nlogin: %s",select_estudante.login.usuario);	//login1
	printf("\nsenha: %s",select_estudante.login.senha);
	printf("\nInstitui��es: %s",select_estudante.curso.nome_curso);
	printf("\nSaldo: %.2f",select_estudante.saldo);
	printf("\nCredito: %d",select_estudante.credito);
}

void validar_estudante()
{
	if(is_valid_curso){
		int i;
		for(i = 0;i<MAX;i++){
			if(!estudante_vet[i].status){
				printf("\n%d -> %s",i,estudante_vet[i].nome_estudante);
			}	
		}
		int op;
		printf("\nSelecione um estudante para ser ativado:\n");
		printf(">");
		scanf("%d",&op);
		estudante_vet[op].status = 1;
		printf("\nAtiva��o realizada\n");
	
	}else{
		printf("\nNenhuma Institui��o cadastrada\n");
	}
	pausar_limpar_tela();
}

