#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

#define MAX 3

typedef struct {
	char name_estado[120];
	char uf[3];	
}estado_t;

typedef struct {
	char nome_municipio[120];
	int quantidade;
	char uf[3];
}municipio_t;


void limpar_tela();
void pausar_limpar_tela();
void menu_principal();
void cadastrar_estado();
void gerar_cadastros_estados();
void menu_cadastrar();
void menu_cadastrar_estado();
void menu_cadastrar_municipios();
void cadastrar_municipios();
void gerar_cadastros_municipios();
void menu_pesquisar();
void pesquisar_estados();
void pesquisar_municios();
void salvar_estados();
int recuperar_estados();
void salvar_municipios();
int recuperar_municipios();


estado_t estado_vet[MAX];
municipio_t municipio_vet[MAX][MAX];

int is_valid = 0;
int op_menu;
int index =0;
int index2 =0;

int is_estados= 0;
int is_municipios= 0;

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	if(recuperar_estados()){
		is_estados =1;
	}
	if(recuperar_municipios()){
		is_municipios=1;
	}
	menu_principal();
	
	return 0;
}

void menu_principal(){
	do{
		printf("\nSistema Censo\n");
	
		printf("\n1 - Cadastrar");
		printf("\n2 - Pesquisar");
		printf("\n3 - Salvar");
		printf("\n0 - Sair");
		
		do{
			is_valid =1;
			printf("\nEscolha uma opção:");
			scanf("%d",&op_menu);
			
			switch(op_menu){
				//1 - Cadastrar
				case 1:
					limpar_tela();
					menu_cadastrar();
					break;
				//2 - Pesquisar
				case 2:
					limpar_tela();
					menu_pesquisar();
					break;
				//3 - Salvar
				case 3:
					limpar_tela();
					salvar_estados();
					salvar_municipios();
					break;
				//0 - Sair
				case 0:
					limpar_tela();
					exit(1);
					break;
				default:
					is_valid=0;
					break;
			}
			
		}while(!is_valid);
	}while(1);
}

void menu_cadastrar(){
	printf("\nSistema de Cadastro\n");
	printf("\n1 - Estados");
	printf("\n2 - Municipios");
	printf("\n0 - Sair");
	do{
		is_valid =1;
		printf("\nEscolha uma opção:");
		scanf("%d",&op_menu);
		
		switch(op_menu){
			//1 - Estados
			case 1:
				limpar_tela();
				menu_cadastrar_estado();
				break;
			//2 - Municipios
			case 2:
				limpar_tela();
				menu_cadastrar_municipios();
				break;
			//0 - Sair
			case 0:
				limpar_tela();
				break;
			default:
				is_valid = 0;
				break;
		}
	}while(!is_valid);

}

void menu_cadastrar_estado(){
	printf("\nSistema de Cadastro de Estados\n");
	printf("\n1 - Gerar Cadastros");
	printf("\n2 - Cadastrar Manualmente");
	printf("\n0 - Sair");
	do{
		is_valid =1;
		printf("\nEscolha uma opção:");
		scanf("%d",&op_menu);
		
		switch(op_menu){
			//1 - Gerar Cadastros
			case 1:
				limpar_tela();
				gerar_cadastros_estados();
				pausar_limpar_tela();
				break;
			//2 - Cadastrar Manualmente
			case 2:
				limpar_tela();
				cadastrar_estado();
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
	}while(!is_valid);
}

void menu_cadastrar_municipios(){
	printf("\nSistema de Cadastro de Municipios\n");
	printf("\n1 - Gerar Cadastros");
	printf("\n2 - Cadastrar Manualmente");
	printf("\n0 - Sair");
	do{
		is_valid =1;
		printf("\nEscolha uma opção:");
		scanf("%d",&op_menu);
		
		switch(op_menu){
			//1 - Gerar Cadastros
			case 1:
				limpar_tela();
				gerar_cadastros_municipios();
				pausar_limpar_tela();
				break;
			//2 - Cadastrar Manualmente
			case 2:
				limpar_tela();
				cadastrar_municipios();
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
	}while(!is_valid);
}

void menu_pesquisar(){
	printf("\nSistema de Pesquisa\n");
	printf("\n1 - Estados");
	printf("\n2 - Municipios");
	printf("\n0 - Sair");
	do{
		is_valid =1;
		printf("\nEscolha uma opção:");
		scanf("%d",&op_menu);
		
		switch(op_menu){
			//1 - Estados
			case 1:
				limpar_tela();
				pesquisar_estados();
				pausar_limpar_tela();
				break;
			//2 - Municipios
			case 2:
				limpar_tela();
				pesquisar_municios();
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
	}while(!is_valid);
}


void limpar_tela(){
	system("cls");
}

void pausar_limpar_tela(){
	system("pause");
	limpar_tela();
}

void cadastrar_estado(){
	for(index =0; index<MAX;index++){
		printf("\nCadastro de Estado[%d]\n",index+1);
		printf("Nome:");
		scanf("%s",&estado_vet[index].name_estado);
		printf("UF:");
		scanf("%s",&estado_vet[index].uf);
		printf("\nEstado Cadastrado\n");
		pausar_limpar_tela();
	}
	is_estados=1;	
}

void gerar_cadastros_estados(){
	for(index =0; index<MAX;index++){
		sprintf(estado_vet[index].name_estado,"Estado %d",index);
		sprintf(estado_vet[index].uf,"%d%d",index,index);
	}
	printf("\nEstado gerados automaticamente\n");
	is_estados=1;
}

void cadastrar_municipios(){
	
	if(is_estados){
		for(index =0;index<MAX;index++){
			for(index2 =0;index2<MAX;index2++){
				// [][]
				limpar_tela();
				printf("\nCadastro do Munucipio [%d] no Estado %s [%d] \n",index2+1,estado_vet[index].name_estado,index+1);
				printf("\nNome:");
				scanf("%s",&municipio_vet[index][index2].nome_municipio);
				printf("\nQuantidade de pessoas:");
				scanf("%d",&municipio_vet[index][index2].quantidade);
				strcpy(municipio_vet[index][index2].uf,estado_vet[index].uf);
				pausar_limpar_tela();
			}		
		}
		is_municipios =1;
	}else{
		printf("\nNenhum estado encontrado\n");
	}
	
}

void gerar_cadastros_municipios(){
	for(index =0; index<MAX;index++){
		for(index2 =0; index2<MAX;index2++){
			sprintf(municipio_vet[index][index2].nome_municipio,"municipio%d%d",index,index2);
			municipio_vet[index][index2].quantidade=10000*(index2+1);
			sprintf(municipio_vet[index][index2].uf,estado_vet[index].uf);
		}	
	}
	printf("\nMunicipios gerados automaticamente\n");
	is_municipios=1;
}

void pesquisar_estados(){
	
	if(is_estados){
		char pesquisa[120];
		printf("\nSistema de Pesquisa de Estados por Nome ou UF\n");
		printf("\nDigite o nome ou uf do estado a ser pesquisado:");
		scanf("%s",&pesquisa);
		
		for(index = 0;index<MAX;index++){
			if(strcmp(pesquisa,estado_vet[index].name_estado) == 0 || strcmp(pesquisa,estado_vet[index].uf) == 0){
				int soma =0;
				printf("\nNome do Estado:%s",estado_vet[index].name_estado);
				printf("\nUF:%s",estado_vet[index].uf);	
				for(index2 =0;index2<MAX;index2++){
					if(strcmp(municipio_vet[index][index2].uf,estado_vet[index].uf) == 0){
						printf("\n_______________________\n");
						printf("\nNome do Municipio:%s",municipio_vet[index][index2].nome_municipio);
						printf("\nHabitantes:%d",municipio_vet[index][index2].quantidade);
						soma += municipio_vet[index][index2].quantidade;
					}
				}
				printf("\n_______________________\n");
				printf("\nTotal de Habitantes:%d\n",soma);		
			}
		}
	}else{
		printf("\nNenhum Estado Encontrado\n");
	}
}

void pesquisar_municios(){
	
	if(is_estados){
		if(is_municipios){
		char pesquisa[120];
		printf("\nSistema de Pesquisa de Municipios por Nome\n");
		printf("\nDigite o nome do municipio a ser pesquisado:");
		scanf("%s",&pesquisa);
		
		for(index = 0;index<MAX;index++){
			for(index2 =0;index2<MAX;index2++){
				if(strcmp(municipio_vet[index][index2].nome_municipio,pesquisa) == 0){
					printf("\n_______________________\n");
					printf("\nNome do Municipio:%s",municipio_vet[index][index2].nome_municipio);
					printf("\nHabitantes:%d",municipio_vet[index][index2].quantidade);
					printf("\n_______________________\n");	
					if(strcmp(municipio_vet[index][index2].uf,estado_vet[index].uf) == 0){
						printf("\nNome do Estado:%s",estado_vet[index].name_estado);
						printf("\nUF:%s",estado_vet[index].uf);	
						printf("\n_______________________\n");	
					}
					
				}
			}
		}
		}else{
		printf("\nNenhum Municipio Encontrado\n");
	}
	}else{
		printf("\nNenhum Estado Encontrado\n");
	}
}

void salvar_estados(){
	
	FILE *arquivo = fopen("estados.bin", "wb");
	
	if(arquivo!=NULL){
		for(index =0;index<MAX;index++){
			fwrite(&estado_vet[index],sizeof(estado_t),sizeof(estado_vet[index]),arquivo);
		}
		fclose(arquivo);
		printf("Dados dos estados foram salvos");
	}else{
		printf("Arquivos dos Estados não encontrado");
	}
	
}

int recuperar_estados(){
	
	FILE *arquivo = fopen("estados.bin", "rb");
	
	if(arquivo!=NULL){
		for(index =0;index<MAX;index++){
			
			estado_t estado;
			
			int tamanho = fread(&estado,sizeof(estado_t),1,arquivo);
			
			if(tamanho<1){
				break;
			}else{
				estado_vet[index]=estado;
			}
		}
		fclose(arquivo);
		printf("\nDados dos estados foram recuperados\n");
		return 1;
	}else{
		printf("\nArquivos dos Estados não encontrado\n");
		return 0;
	}
	
}

void salvar_municipios(){
	
	FILE *arquivo = fopen("municipios.bin", "wb");
	
	if(arquivo!=NULL){
		for(index =0;index<MAX;index++){
			for(index2 =0;index2<MAX;index2++){
				fwrite(&municipio_vet[index][index2],sizeof(municipio_t),sizeof(municipio_vet[index][index2]),arquivo);
			}
		}
		fclose(arquivo);
		printf("\nDados dos municipios foram salvos\n");
	}else{
		printf("\nArquivos dos Municipios não encontrado\n");
	}
	
}

int recuperar_municipios(){
	
	FILE *arquivo = fopen("municipios.bin", "rb");
	
	if(arquivo!=NULL){
		for(index =0;index<MAX;index++){
			for(index2 =0;index2<MAX;index2++){
				municipio_t municipio;
				
				int tamanho = fread(&municipio,sizeof(municipio_t),1,arquivo);
				
				if(tamanho<1){
					break;
				}else{
					municipio_vet[index][index2]=municipio;
				}
			}
		}
		fclose(arquivo);
		printf("\nDados dos municipios foram recuperados\n");
		return 1;
	}else{
		printf("\nArquivos dos Municipios não encontrado\n");
		return 0;
	}
	
}

