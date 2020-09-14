#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

#define MAX 3

typedef struct Estado{
	char nameEstado[120];
	char uf[3];	
}Estado;

typedef struct Municipio{
	char nomeMunicipio[120];
	int quantidade;
	char uf[3];
}Municipio;


void limparTela();
void limparPausarTela();
void menuPrincipal();
void cadastrarEstado();
void gerarCadastrosEstados();
void menuCadastrar();
void menuCadastrarEstado();
void menuCadastrarMunicipios();
void cadastrarMunicipios();
void gerarCadastrosMunicipios();
void menuPesquisar();
void pesquiarEstados();
void pesquiarMunicios();
void salvarEstados();
int recuperarEstados();
void salvarMunicipios();
int recuperarMunicipios();


Estado estados[MAX];
Municipio municipios[MAX][MAX];

int isValid = 0;
int opMenu;
int index =0;
int index2 =0;

int isEstados= 0;
int isMunicipios= 0;

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	if(recuperarEstados()){
		isEstados =1;
	}
	if(recuperarMunicipios()){
		isMunicipios=1;
	}
	menuPrincipal();
	
	return 0;
}

void menuPrincipal(){
	do{
		printf("\nSistema Censo\n");
	
		printf("\n1 - Cadastrar");
		printf("\n2 - Pesquisar");
		printf("\n3 - Salvar");
		printf("\n0 - Sair");
		
		do{
			isValid =1;
			printf("\nEscolha uma opção:");
			scanf("%d",&opMenu);
			
			switch(opMenu){
				//1 - Cadastrar
				case 1:
					limparTela();
					menuCadastrar();
					break;
				//2 - Pesquisar
				case 2:
					limparTela();
					menuPesquisar();
					break;
				//3 - Salvar
				case 3:
					limparTela();
					salvarEstados();
					salvarMunicipios();
					break;
				//0 - Sair
				case 0:
					limparTela();
					exit(1);
					break;
				default:
					isValid=0;
					break;
			}
			
		}while(!isValid);
	}while(1);
}

void menuCadastrar(){
	printf("\nSistema de Cadastro\n");
	printf("\n1 - Estados");
	printf("\n2 - Municipios");
	printf("\n0 - Sair");
	do{
		isValid =1;
		printf("\nEscolha uma opção:");
		scanf("%d",&opMenu);
		
		switch(opMenu){
			//1 - Estados
			case 1:
				limparTela();
				menuCadastrarEstado();
				break;
			//2 - Municipios
			case 2:
				limparTela();
				menuCadastrarMunicipios();
				break;
			//0 - Sair
			case 0:
				limparTela();
				break;
			default:
				isValid = 0;
				break;
		}
	}while(!isValid);

}

void menuCadastrarEstado(){
	printf("\nSistema de Cadastro de Estados\n");
	printf("\n1 - Gerar Cadastros");
	printf("\n2 - Cadastrar Manualmente");
	printf("\n0 - Sair");
	do{
		isValid =1;
		printf("\nEscolha uma opção:");
		scanf("%d",&opMenu);
		
		switch(opMenu){
			//1 - Gerar Cadastros
			case 1:
				limparTela();
				gerarCadastrosEstados();
				limparPausarTela();
				break;
			//2 - Cadastrar Manualmente
			case 2:
				limparTela();
				cadastrarEstado();
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
	}while(!isValid);
}

void menuCadastrarMunicipios(){
	printf("\nSistema de Cadastro de Municipios\n");
	printf("\n1 - Gerar Cadastros");
	printf("\n2 - Cadastrar Manualmente");
	printf("\n0 - Sair");
	do{
		isValid =1;
		printf("\nEscolha uma opção:");
		scanf("%d",&opMenu);
		
		switch(opMenu){
			//1 - Gerar Cadastros
			case 1:
				limparTela();
				gerarCadastrosMunicipios();
				limparPausarTela();
				break;
			//2 - Cadastrar Manualmente
			case 2:
				limparTela();
				cadastrarMunicipios();
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
	}while(!isValid);
}

void menuPesquisar(){
	printf("\nSistema de Pesquisa\n");
	printf("\n1 - Estados");
	printf("\n2 - Municipios");
	printf("\n0 - Sair");
	do{
		isValid =1;
		printf("\nEscolha uma opção:");
		scanf("%d",&opMenu);
		
		switch(opMenu){
			//1 - Estados
			case 1:
				limparTela();
				pesquiarEstados();
				limparPausarTela();
				break;
			//2 - Municipios
			case 2:
				limparTela();
				pesquiarMunicios();
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
	}while(!isValid);
}


void limparTela(){
	system("cls");
}

void limparPausarTela(){
	system("pause");
	limparTela();
}

void cadastrarEstado(){
	for(index =0; index<MAX;index++){
		printf("\nCadastro de Estado[%d]\n",index+1);
		printf("Nome:");
		scanf("%s",&estados[index].nameEstado);
		printf("UF:");
		scanf("%s",&estados[index].uf);
		printf("\nEstado Cadastrado\n");
		limparPausarTela();
	}
	isEstados=1;	
}

void gerarCadastrosEstados(){
	for(index =0; index<MAX;index++){
		sprintf(estados[index].nameEstado,"Estado %d",index);
		sprintf(estados[index].uf,"%d%d",index,index);
	}
	printf("\nEstado gerados automaticamente\n");
	isEstados=1;
}

void cadastrarMunicipios(){
	
	if(isEstados){
		for(index =0;index<MAX;index++){
			for(index2 =0;index2<MAX;index2++){
				// [][]
				limparTela();
				printf("\nCadastro do Munucipio [%d] no Estado %s [%d] \n",index2+1,estados[index].nameEstado,index+1);
				printf("\nNome:");
				scanf("%s",&municipios[index][index2].nomeMunicipio);
				printf("\nQuantidade de pessoas:");
				scanf("%d",&municipios[index][index2].quantidade);
				strcpy(municipios[index][index2].uf,estados[index].uf);
				limparPausarTela();
			}		
		}
		isMunicipios =1;
	}else{
		printf("\nNenhum estado encontrado\n");
	}
	
}

void gerarCadastrosMunicipios(){
	for(index =0; index<MAX;index++){
		for(index2 =0; index2<MAX;index2++){
			sprintf(municipios[index][index2].nomeMunicipio,"municipio%d%d",index,index2);
			municipios[index][index2].quantidade=10000*(index2+1);
			sprintf(municipios[index][index2].uf,estados[index].uf);
		}	
	}
	printf("\nMunicipios gerados automaticamente\n");
	isMunicipios=1;
}

void pesquiarEstados(){
	
	if(isEstados){
		char pesquisa[120];
		printf("\nSistema de Pesquisa de Estados por Nome ou UF\n");
		printf("\nDigite o nome ou uf do estado a ser pesquisado:");
		scanf("%s",&pesquisa);
		
		for(index = 0;index<MAX;index++){
			if(strcmp(pesquisa,estados[index].nameEstado) == 0 || strcmp(pesquisa,estados[index].uf) == 0){
				int soma =0;
				printf("\nNome do Estado:%s",estados[index].nameEstado);
				printf("\nUF:%s",estados[index].uf);	
				for(index2 =0;index2<MAX;index2++){
					if(strcmp(municipios[index][index2].uf,estados[index].uf) == 0){
						printf("\n_______________________\n");
						printf("\nNome do Municipio:%s",municipios[index][index2].nomeMunicipio);
						printf("\nHabitantes:%d",municipios[index][index2].quantidade);
						soma += municipios[index][index2].quantidade;
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

void pesquiarMunicios(){
	
	if(isEstados){
		if(isMunicipios){
		char pesquisa[120];
		printf("\nSistema de Pesquisa de Municipios por Nome\n");
		printf("\nDigite o nome do municipio a ser pesquisado:");
		scanf("%s",&pesquisa);
		
		for(index = 0;index<MAX;index++){
			for(index2 =0;index2<MAX;index2++){
				if(strcmp(municipios[index][index2].nomeMunicipio,pesquisa) == 0){
					printf("\n_______________________\n");
					printf("\nNome do Municipio:%s",municipios[index][index2].nomeMunicipio);
					printf("\nHabitantes:%d",municipios[index][index2].quantidade);
					printf("\n_______________________\n");	
					if(strcmp(municipios[index][index2].uf,estados[index].uf) == 0){
						printf("\nNome do Estado:%s",estados[index].nameEstado);
						printf("\nUF:%s",estados[index].uf);	
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

void salvarEstados(){
	
	FILE *arquivo = fopen("estados.bin", "wb");
	
	if(arquivo!=NULL){
		for(index =0;index<MAX;index++){
			fwrite(&estados[index],sizeof(Estado),sizeof(estados[index]),arquivo);
		}
		fclose(arquivo);
		printf("Dados dos estados foram salvos");
	}else{
		printf("Arquivos dos Estados não encontrado");
	}
	
}

int recuperarEstados(){
	
	FILE *arquivo = fopen("estados.bin", "rb");
	
	if(arquivo!=NULL){
		for(index =0;index<MAX;index++){
			
			Estado estado;
			
			int tamanho = fread(&estado,sizeof(Estado),1,arquivo);
			
			if(tamanho<1){
				break;
			}else{
				estados[index]=estado;
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

void salvarMunicipios(){
	
	FILE *arquivo = fopen("municipios.bin", "wb");
	
	if(arquivo!=NULL){
		for(index =0;index<MAX;index++){
			for(index2 =0;index2<MAX;index2++){
				fwrite(&municipios[index][index2],sizeof(Municipio),sizeof(municipios[index][index2]),arquivo);
			}
		}
		fclose(arquivo);
		printf("\nDados dos municipios foram salvos\n");
	}else{
		printf("\nArquivos dos Municipios não encontrado\n");
	}
	
}

int recuperarMunicipios(){
	
	FILE *arquivo = fopen("municipios.bin", "rb");
	
	if(arquivo!=NULL){
		for(index =0;index<MAX;index++){
			for(index2 =0;index2<MAX;index2++){
				Municipio municipio;
				
				int tamanho = fread(&municipio,sizeof(Municipio),1,arquivo);
				
				if(tamanho<1){
					break;
				}else{
					municipios[index][index2]=municipio;
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

