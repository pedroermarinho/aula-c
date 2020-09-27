#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// char -> caractere
// char[10] -> string

//struct e procedimentos

#define MAX 2
#define VL_PASSAGEM 2

typedef struct Login{
	char login[20];
	char senha[20];
}Login;

typedef struct Endereco{
	char bairro[120];
	char rua[120];
	char casa[10];
};

typedef struct Instituicao{
	char nome[120];
	Endereco endereco;
};

typedef struct Estudante{
	char nome[120];
	Instituicao instituicao;
	Endereco endereco;
	char telefone[16];
	Login login;
	int status;
	int credito;
	float saldo;
}Estudante;

typedef struct ADM{
	Login login;
};

typedef struct Funcionario{
	char nome[120];
	Login login;
};


Instituicao Instituicoes[MAX];
Estudante estudantes[MAX];
Funcionario funcionarios[MAX];
ADM adm;

void limparTela();
void pausarLimparTela();
void menuLogin();
void loginADM();
void loginFun();
void loginAluno();
void menuADM();
void menuADMCadastar();
void menuFun();
void menuAluno();
void cadastrarFuncionario();
void cadastrarInstituicao();
void cadastrarAluno();
void exibirAlunos();
void validar();
void vender();
void saldo();


int isValidInstituicoes = 0;

int main(){
	menuLogin();
	return 0;
} 

void limparTela(){
	system("cls");
}
void pausarLimparTela(){
	system("pause");
	limparTela();
}


//adm  == NULL -> cadastrar adm 
void menuLogin(){
	do{
		printf("\nSistema de Login:\n");
		printf("\n1 - adm");
		printf("\n2 - funcionario");
		printf("\n3 - aluno");
		printf("\n0 - Sair");
		int isValid;
		int op;
		do{
			printf("\nSelecione um opção:\n");
			printf(">");
			scanf("%d",&op);
			isValid = 1;
			switch(op){
				//1 - adm
				case 1:
					limparTela();
					loginADM();
					break;
				//2 - funcionario
				case 2:
					limparTela();
					loginFun();
					break;
				//3 - aluno
				case 3:
					limparTela();
					loginAluno();
					break;
				//0 - Sair
				case 0:
					limparTela();
					exit(1);
				default:
					isValid =0;
					break;
			}
			
		}while(!isValid);
	}while(1);
}
void loginADM(){
	menuADM();
}
void loginFun(){
	menuFun();
}

void loginAluno(){
	menuAluno();
}

void menuADM(){
	limparTela();
	int continuar =1;
	do{
		printf("\nSistema do ADM:\n");
		printf("\n1 - Cadastrar");
		printf("\n2 - Validar");
		printf("\n3 - Vender");
		printf("\n0 - Sair");
		int isValid;
		int op;
		do{
			printf("\nSelecione um opção:\n");
			printf(">");
			scanf("%d",&op);
			isValid = 1;
			switch(op){
				//1 - Cadastrar
				case 1:
					limparTela();
					menuADMCadastar();
					break;
				//2 - Validar
				case 2:
					limparTela();
					validar();
					break;
				//3 - Vender
				case 3:
					limparTela();
					vender();
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
void menuADMCadastar(){
	limparTela();
	int continuar =1;
	do{
		printf("\nSistema de Cadastro do ADM:\n");
		printf("\n1 - Aluno");
		printf("\n2 - Instuiçao");
		printf("\n3 - Funcionario");
		printf("\n0 - Sair");
		int isValid;
		int op;
		do{
			printf("\nSelecione um opção:\n");
			printf(">");
			scanf("%d",&op);
			isValid = 1;
			switch(op){
				//1 - Aluno
				case 1:
					limparTela();
					cadastrarAluno();
					break;
				//2 - Instuiçao
				case 2:
					limparTela();
					cadastrarInstituicao();
					break;
				//3 - Funcionario
				case 3:
					limparTela();
					cadastrarFuncionario();
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

//1 -> true = verdadeiro
//0 -> false = falso

void menuFun(){
	limparTela();
	int continuar =1;
	do{
		printf("\nSistema de Funcionario:\n");
		printf("\n1 - Cadastrar Aluno");
		printf("\n2 - Vender");
		printf("\n0 - Sair");
		int isValid;
		int op;
		do{
			printf("\nSelecione um opção:\n");
			printf(">");
			scanf("%d",&op);
			isValid = 1;
			switch(op){
				//1 - Cadastrar Aluno
				case 1:
					limparTela();
					cadastrarAluno();
					break;
				//2 - Vender
				case 2:
					limparTela();
					loginFun();
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

void menuAluno(){
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


void cadastrarFuncionario(){
	int i;
	for(i = 0;i<MAX;i++){
		sprintf(funcionarios[i].nome,"funcionaio %d",i);//funcionario 1
		sprintf(funcionarios[i].login.login,"login%d",i);	//login1
		sprintf(funcionarios[i].login.senha,"senha%d",i);	//senha1
	}
	printf("\nCadastrado realizado -> Funcionario\n");
	isValidInstituicoes =1;
	pausarLimparTela();
}

void cadastrarInstituicao(){
	int i;
	for(i = 0;i<MAX;i++){
		sprintf(Instituicoes[i].nome,"instituição %d",i);
		sprintf(Instituicoes[i].endereco.bairro,"bairro %d",i);
		sprintf(Instituicoes[i].endereco.casa,"casa %d",i);
		sprintf(Instituicoes[i].endereco.rua,"rua %d",i);
	}
	printf("\nCadastrado realizado -> Instituição\n");
	pausarLimparTela();
} 
void cadastrarAluno(){
	if(isValidInstituicoes){
		int i;
		for(i = 0;i<MAX;i++){
			sprintf(estudantes[i].nome,"aluno %d",i);
			sprintf(estudantes[i].endereco.bairro,"bairro %d",i);
			sprintf(estudantes[i].endereco.casa,"casa %d",i);
			sprintf(estudantes[i].endereco.rua,"rua %d",i);
			sprintf(estudantes[i].login.login,"login%d",i);	//login1
			sprintf(estudantes[i].login.senha,"senha%d",i);	//senha1
			sprintf(estudantes[i].telefone,"%d%d%d%d",i,i,i,i);	
			estudantes[i].instituicao = Instituicoes[i];
			estudantes[i].status = 0;
		}
		printf("\nCadastrado realizado -> Aluno\n");
	}else{
		printf("\nNenhuma Instituição cadastrada\n");
	}
	pausarLimparTela();
}

void exibirAlunos(){
	if(isValidInstituicoes){
		int i;
		for(i = 0;i<MAX;i++){
			printf("\n%d -> %s",i,estudantes[i].nome);
		
		}

	}else{
		printf("\nNenhuma Instituição cadastrada\n");
	}
}

void validar(){
	if(isValidInstituicoes){
		int i;
		for(i = 0;i<MAX;i++){
			if(!estudantes[i].status){
				printf("\n%d -> %s",i,estudantes[i].nome);
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
	pausarLimparTela();
}
void vender(){
	exibirAlunos();
	int op;
	printf("\nSelecione um estudante para colocar credito:\n");
	printf(">");
	scanf("%d",&op);
	limparTela();
	
	printf("\nnome: %s",estudantes[op].nome);
	printf("\nbairro: %s",estudantes[op].endereco.bairro);
	printf("\ncasa: %s",estudantes[op].endereco.casa);
	printf("\nrua: %s",estudantes[op].endereco.rua);
	printf("\nlogin: %s",estudantes[op].login.login);	//login1
	printf("\nsenha: %s",estudantes[op].login.senha);
	printf("\nInstituições: %s",estudantes[op].instituicao.nome);
	
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
	pausarLimparTela();
	
	
}
void saldo(){
	exibirAlunos();
	int op;
	printf("\nSelecione um estudante:\n");
	printf(">");
	scanf("%d",&op);
	limparTela();
	
	printf("\nnome: %s",estudantes[op].nome);
	printf("\nbairro: %s",estudantes[op].endereco.bairro);
	printf("\ncasa: %s",estudantes[op].endereco.casa);
	printf("\nrua: %s",estudantes[op].endereco.rua);
	printf("\nlogin: %s",estudantes[op].login.login);	//login1
	printf("\nsenha: %s",estudantes[op].login.senha);
	printf("\nInstituições: %s",estudantes[op].instituicao.nome);
	printf("\nSaldo: %.2f",estudantes[op].saldo);
	printf("\nCredito: %d",estudantes[op].credito);
	pausarLimparTela();
}


