#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// char -> caractere
// char[10] -> string

//struct e procedimentos

#define MAX 2
#define VL_PASSAGEM 2

typedef struct {
	char login[20];
	char senha[20];
}login_t;

typedef struct {
	char bairro[120];
	char rua[120];
	char casa[10];
}endereco_t;

typedef struct {
	char nome[120];
	endereco_t endereco;
}instituicao_t;

typedef struct {
	char nome[120];
	instituicao_t instituicao;
	endereco_t endereco;
	char telefone[16];
	login_t login;
	int status;
	int credito;
	float saldo;
}estudante_t;

typedef struct {
	login_t login;
}adm_t;

typedef struct {
	char nome[120];
	login_t login;
}funcionario_t;


instituicao_t instituicao_vet[MAX];
estudante_t estudante_vet[MAX];
funcionario_t funcionario_vet[MAX];
adm_t adm;

void limpar_tela();
void pausar_limpar_tela();
void menu_login();
void login_adm();
void login_fun();
void login_aluno();
void menu_adm();
void menu_adm_cadastrar();
void menu_fun();
void menu_aluno();
void cadastrar_funcionario();
void cadastrar_instituicao();
void cadastrar_aluno();
void exibir_alunos();
void validar();
void vender();
void saldo();


int is_valid_instituicoes = 0;

int main(){
	menu_login();
	return 0;
} 

void limpar_tela(){
	system("cls");
}
void pausar_limpar_tela(){
	system("pause");
	limpar_tela();
}


//adm  == NULL -> cadastrar adm 
void menu_login(){
	do{
		printf("\nSistema de Login:\n");
		printf("\n1 - adm");
		printf("\n2 - funcionario");
		printf("\n3 - aluno");
		printf("\n0 - Sair");
		int is_valid;
		int op;
		do{
			printf("\nSelecione um op��o:\n");
			printf(">");
			scanf("%d",&op);
			is_valid = 1;
			switch(op){
				//1 - adm
				case 1:
					limpar_tela();
					login_adm();
					break;
				//2 - funcionario
				case 2:
					limpar_tela();
					login_fun();
					break;
				//3 - aluno
				case 3:
					limpar_tela();
					login_aluno();
					break;
				//0 - Sair
				case 0:
					limpar_tela();
					exit(1);
				default:
					is_valid =0;
					break;
			}
			
		}while(!is_valid);
	}while(1);
}
void login_adm(){
	menu_adm();
}
void login_fun(){
	menu_fun();
}

void login_aluno(){
	menu_aluno();
}

void menu_adm(){
	limpar_tela();
	int continuar =1;
	do{
		printf("\nSistema do ADM:\n");
		printf("\n1 - Cadastrar");
		printf("\n2 - Validar");
		printf("\n3 - Vender");
		printf("\n0 - Sair");
		int is_valid;
		int op;
		do{
			printf("\nSelecione um op��o:\n");
			printf(">");
			scanf("%d",&op);
			is_valid = 1;
			switch(op){
				//1 - Cadastrar
				case 1:
					limpar_tela();
					menu_adm_cadastrar();
					break;
				//2 - Validar
				case 2:
					limpar_tela();
					validar();
					break;
				//3 - Vender
				case 3:
					limpar_tela();
					vender();
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
void menu_adm_cadastrar(){
	limpar_tela();
	int continuar =1;
	do{
		printf("\nSistema de Cadastro do ADM:\n");
		printf("\n1 - Aluno");
		printf("\n2 - Instui�ao");
		printf("\n3 - Funcionario");
		printf("\n0 - Sair");
		int is_valid;
		int op;
		do{
			printf("\nSelecione um op��o:\n");
			printf(">");
			scanf("%d",&op);
			is_valid = 1;
			switch(op){
				//1 - Aluno
				case 1:
					limpar_tela();
					cadastrar_aluno();
					break;
				//2 - Instui�ao
				case 2:
					limpar_tela();
					cadastrar_instituicao();
					break;
				//3 - Funcionario
				case 3:
					limpar_tela();
					cadastrar_funcionario();
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

//1 -> true = verdadeiro
//0 -> false = falso

void menu_fun(){
	limpar_tela();
	int continuar =1;
	do{
		printf("\nSistema de Funcionario:\n");
		printf("\n1 - Cadastrar Aluno");
		printf("\n2 - Vender");
		printf("\n0 - Sair");
		int is_valid;
		int op;
		do{
			printf("\nSelecione um op��o:\n");
			printf(">");
			scanf("%d",&op);
			is_valid = 1;
			switch(op){
				//1 - Cadastrar Aluno
				case 1:
					limpar_tela();
					cadastrar_aluno();
					break;
				//2 - Vender
				case 2:
					limpar_tela();
					login_fun();
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

void menu_aluno(){
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
					saldo();
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


void cadastrar_funcionario(){
	int i;
	for(i = 0;i<MAX;i++){
		sprintf(funcionario_vet[i].nome,"funcionaio %d",i);//funcionario 1
		sprintf(funcionario_vet[i].login.login,"login%d",i);	//login1
		sprintf(funcionario_vet[i].login.senha,"senha%d",i);	//senha1
	}
	printf("\nCadastrado realizado -> Funcionario\n");
	is_valid_instituicoes =1;
	pausar_limpar_tela();
}

void cadastrar_instituicao(){
	int i;
	for(i = 0;i<MAX;i++){
		sprintf(instituicao_vet[i].nome,"institui��o %d",i);
		sprintf(instituicao_vet[i].endereco.bairro,"bairro %d",i);
		sprintf(instituicao_vet[i].endereco.casa,"casa %d",i);
		sprintf(instituicao_vet[i].endereco.rua,"rua %d",i);
	}
	printf("\nCadastrado realizado -> Institui��o\n");
	pausar_limpar_tela();
} 
void cadastrar_aluno(){
	if(is_valid_instituicoes){
		int i;
		for(i = 0;i<MAX;i++){
			sprintf(estudante_vet[i].nome,"aluno %d",i);
			sprintf(estudante_vet[i].endereco.bairro,"bairro %d",i);
			sprintf(estudante_vet[i].endereco.casa,"casa %d",i);
			sprintf(estudante_vet[i].endereco.rua,"rua %d",i);
			sprintf(estudante_vet[i].login.login,"login%d",i);	//login1
			sprintf(estudante_vet[i].login.senha,"senha%d",i);	//senha1
			sprintf(estudante_vet[i].telefone,"%d%d%d%d",i,i,i,i);	
			estudante_vet[i].instituicao = instituicao_vet[i];
			estudante_vet[i].status = 0;
		}
		printf("\nCadastrado realizado -> Aluno\n");
	}else{
		printf("\nNenhuma Institui��o cadastrada\n");
	}
	pausar_limpar_tela();
}

void exibir_alunos(){
	if(is_valid_instituicoes){
		int i;
		for(i = 0;i<MAX;i++){
			printf("\n%d -> %s",i,estudante_vet[i].nome);
		
		}

	}else{
		printf("\nNenhuma Institui��o cadastrada\n");
	}
}

void validar(){
	if(is_valid_instituicoes){
		int i;
		for(i = 0;i<MAX;i++){
			if(!estudante_vet[i].status){
				printf("\n%d -> %s",i,estudante_vet[i].nome);
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
void vender(){
	exibir_alunos();
	int op;
	printf("\nSelecione um estudante para colocar credito:\n");
	printf(">");
	scanf("%d",&op);
	limpar_tela();
	
	printf("\nnome: %s",estudante_vet[op].nome);
	printf("\nbairro: %s",estudante_vet[op].endereco.bairro);
	printf("\ncasa: %s",estudante_vet[op].endereco.casa);
	printf("\nrua: %s",estudante_vet[op].endereco.rua);
	printf("\nlogin: %s",estudante_vet[op].login.login);	//login1
	printf("\nsenha: %s",estudante_vet[op].login.senha);
	printf("\nInstitui��es: %s",estudante_vet[op].instituicao.nome);
	
	printf("\n\n");
	
	float valor;
	printf("\nValor em diheiro a ser colocado:(ex 20.50)\n");
	printf(">");
	scanf("%f",&valor);
	

	estudante_vet[op].saldo +=remainder(valor, VL_PASSAGEM);
	estudante_vet[op].credito += floor(valor/VL_PASSAGEM);
	
	
	printf("\nsaldo ->%.2f",estudante_vet[op].saldo);
	printf("\ncredito ->%d",estudante_vet[op].credito);
	printf("\n\n");
	pausar_limpar_tela();
	
	
}
void saldo(){
	exibir_alunos();
	int op;
	printf("\nSelecione um estudante:\n");
	printf(">");
	scanf("%d",&op);
	limpar_tela();
	
	printf("\nnome: %s",estudante_vet[op].nome);
	printf("\nbairro: %s",estudante_vet[op].endereco.bairro);
	printf("\ncasa: %s",estudante_vet[op].endereco.casa);
	printf("\nrua: %s",estudante_vet[op].endereco.rua);
	printf("\nlogin: %s",estudante_vet[op].login.login);	//login1
	printf("\nsenha: %s",estudante_vet[op].login.senha);
	printf("\nInstitui��es: %s",estudante_vet[op].instituicao.nome);
	printf("\nSaldo: %.2f",estudante_vet[op].saldo);
	printf("\nCredito: %d",estudante_vet[op].credito);
	pausar_limpar_tela();
}


