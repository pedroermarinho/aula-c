//ENUNCIADO
//Faça um programa para gerenciar loja aluguel carros.
//O sistema irá cadastrar:
//    • Carro: modelo, cor, ano, quantidade, valor diária, placa;
//    • Cliente: nome, endereço (rua, casa, bairro), telefone, número CNH.
//O Sistema irá realizar o aluguel dos carros:
//    • O cliente cadastrado escolhe o carro disponível e aluga de acordo com o tempo desejado, valor total.
//O sistema terá devolução:
//    O funcionário pesquisa a placa, o sistema lista os dados do carro
//    e quando finalizar a devolução o carro volta a estar disponível.
//Observação: Limite de 5 (cinco) Carros e 5 (cinco) Clientes, estipulado pelo professor!.

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct Carro{
	char modelo[50];
	char cor[50];
	int ano;
	float valor;
	char placa[15];
	bool disponivel;
}Carro;

typedef struct Endereco{
	char rua[100];
	int casa;
	char bairo[100];
}Endereco;

typedef struct Cliente{
	char nome[120];
	char telefone[16];
	char cnh[50];
	Endereco endereco;
}Cliente;

Cliente cadastrarCliente();
Carro cadastrarCarro();
void limparTela();
void limparPausarTela();
void infoCarro(Carro carro);
void infoCliente(Cliente cliente);
char* textFormat(char text[120],int index);
void statusCarro(Carro carro);
void statusCarro(Carro carro,int index);
Cliente gerarCliente(int index);
Carro gerarCarro(int index);
void selectInfor(Cliente cliente);
void selectInfor(Cliente cliente, Carro carro);

int main(){
	
	bool isValidClient = false;
	bool isValidCar = false;
	
	Cliente clientes[5];
	Carro carros[5];
	
	int clienteAtual;
	int carroAtual;
	
	bool continuar = true;
	
	int opMenu;

	do{	
		continuar = false;
		
		printf("1 - Gerar clientes e carros\n");
		printf("2 - Cadastrar clientes e carros\n");
		printf("3 - informacoes sobre os clientes e carros\n");
		printf("4 - Sistema aluguel\n");
		printf("5 - Devolucao do carro\n");
		printf("0 - Sair\n");
		
		
		
		bool isValid;
		do{
			printf("\nEscolha uma opcao:");
			scanf("%d",&opMenu);
			isValid = true;
			switch(opMenu){
				// 1 - Gerar clientes e carros
				case 1:
					limparTela();
					printf("1 - Gerar cadastros de carros\n");
					printf("2 - Gerar cadastros de clientes\n");
					printf("0 - Sair\n");
					do{
						printf("\nEscolha uma opcao:");
						scanf("%d",&opMenu);
						isValid = true;
						switch(opMenu){
							//1 - Gerar cadastros de carros
							case 1:
								limparTela();
								for(int index=0;index<5;index++){
									carros[index]=gerarCarro(index);
								}
								isValidCar = true;
								printf("\nCarros gerados Automaticamente\n");
								limparPausarTela();
								break;
							//2 - Gerar cadastros de clientes
							case 2:
								limparTela();
								for(int index=0;index<5;index++){
									clientes[index]=gerarCliente(index);
								}
								isValidClient = true;
								printf("\nClientes gerados Automaticamente\n");
								limparPausarTela();
								break;
							//0 - Sair
							case 0:
								limparTela();
								break;
							default:
								isValid = false;
								printf("Opcao invalida, escolha outra:");
								break;
						}
					}while(!isValid);
					break;
		
				//2 - Cadastrar clientes e carros
				case 2:
					limparTela();
					
					printf("1 - Cadastrar carros\n");
					printf("2 - Cadastrar clientes\n");
					printf("0 - Sair\n");
					do{
						printf("\nEscolha uma opcao:");
						scanf("%d",&opMenu);
						isValid = true;
						switch(opMenu){
							//1 - Cadastrar carros
							case 1:
								limparTela();
								for(int i=0;i<5;i++){
									printf("\n------------------------------\n");
									carros[i]=cadastrarCarro();
								}
								isValidCar = true;
								limparPausarTela();
								break;
							//2 - Cadastrar clientes
							case 2:
								limparTela();
								for(int i=0;i<5;i++){
									printf("\n------------------------------\n");
									clientes[i]=cadastrarCliente();
								}
								isValidClient = true;
								limparPausarTela();
								break;
							//0 - Sair
							case 0:
								limparTela();
								break;
							default:
								isValid = false;
								printf("Opcao invalida, escolha outra:");
								break;
						}
					}while(!isValid);
					break;
		
				//3 - informacoes sobre os clientes e carros
				case 3:
					limparTela();
					if(isValidClient || isValidCar){
						printf("1 - Clientes\n");
						printf("2 - Carros\n");
						printf("0 - Sair\n");
						do{
							printf("\nEscolha uma opcao:");
							scanf("%d",&opMenu);
							isValid = true;
							switch(opMenu){
								//1 - Clientes
								case 1:
									limparTela();
									if(isValidClient){
										for(int i = 0; i<5; i++){
											infoCliente(clientes[i]);
											printf("\n------------------------------\n");
										}
									}else{
										printf("\nNenhum cliente cadastrado\n");
									}
									limparPausarTela();
									break;
								//2 - Carros
								case 2:
									limparTela();
									if( isValidCar){
										printf("1 - Todos os carros\n");
										printf("2 - Pesquisar por placa\n");
										printf("3 - Status dos carros\n");
										printf("0 - Sair\n");
										do{
											printf("\nEscolha uma opcao:");
											scanf("%d",&opMenu);
											isValid = true;
											switch(opMenu){
												//1 - Todos os carros
												case 1:
													limparTela();
													for(int i = 0; i<5; i++){
														printf("\n------------------------------\n");
														infoCarro(carros[i]);		
													}
													limparPausarTela();
													break;
												//2 - Pesquisar por placa
												case 2:
													limparTela();
													char placa[60];
													printf("Pesquisar placa:");
													scanf("%s",&placa);
													for(int i = 0; i<5; i++){
														if (strcmp (carros[i].placa, placa) == 0){
															printf("\n------------------------------\n");
															infoCarro(carros[i]);
														}
													}
													limparPausarTela();
													break;
												//3 - Status dos carros
												case 3:
													limparTela();
													for(int i = 0; i<5; i++){
														printf("\n------------------------------\n");
														statusCarro(carros[i]);
													}
													limparPausarTela();
													break;
												//0 - Sair
												case 0:
													limparTela();
													break;
												default:
													isValid = false;
													printf("Opcao invalida, escolha outra:");
													break;
											}
										}while(!isValid);
									}else{
										printf("\nNenhum carro cadastrado\n");
										limparPausarTela();
									}	
									break;
								///0 - Sair
								case 0:
									limparTela();
									break;
								default:
									isValid = false;
									printf("Opcao invalida, escolha outra:");
									break;
							}
						}while(!isValid);
					}else{
						printf("\nNenhum carro ou client cadastrado\n");
						limparPausarTela();
					}
				break;
				
				//4 - Sistema aluguel
				case 4:
					limparTela();
					if(isValidClient && isValidCar){
						printf("\nLista de Clientes\n");
						for(int i=0; i<5; i++){
							printf("%d -> %s\n",i,clientes[i].nome);		
						}
						
						do{
							printf("\nEscolhar um cliente para gerenciar:");
							scanf("%d",&clienteAtual);
						}while(clienteAtual>4 || clienteAtual<0);
						
						limparTela();
						selectInfor(clientes[clienteAtual]);
					
						infoCliente(clientes[clienteAtual]);
						
						limparPausarTela();
						printf("\n\nLista de Carros\n");
						for(int i=0; i<5; i++){
							statusCarro(carros[i],i);
						}
						
						do{
							printf("\nEscolhar um carro disponivel para o clente:");
							scanf("%d",&carroAtual);
						}while(carros[carroAtual].disponivel==false || (carroAtual>4 || carroAtual<0) );
						
						carros[carroAtual].disponivel= false;
						
						limparTela();
						selectInfor(clientes[clienteAtual],carros[carroAtual]);
						
						infoCarro(carros[carroAtual]);
						
						limparPausarTela();
						selectInfor(clientes[clienteAtual],carros[carroAtual]);
						
						int dias;
						printf("\nPor quantos dias deseja alugar? :");
						scanf("%d",&dias);
						
						limparTela();
						selectInfor(clientes[clienteAtual],carros[carroAtual]);
						
						printf("\nValor total do aluguel: %.2f\n",(carros[carroAtual].valor*dias));
						printf("\nO carro deverar ser entregue em %d dias!!!",dias);
						
						limparPausarTela();
					}else{
						printf("\nNenhum carro ou cliente cadastrado\n");
						limparPausarTela();
					}
				break;
				//5 - Devolução do carro
				case 5:
					limparTela();
					bool isDevolucao ;
					if(isValidCar){
						isDevolucao=false;
						for(int i =0; i<5;i++){
							if(!carros[i].disponivel){
								printf("\n------------------------------\n");
								statusCarro(carros[i],i);	
								isDevolucao = true;
							}
						}
						
					}
					if(isDevolucao){
						do{
							printf("\nSelecione um carro para fazer a devolucao:");
							scanf("%d",&opMenu);
						}while(opMenu>4 || opMenu<0);
						
						carros[opMenu].disponivel =true;
					}else{
						printf("Todos os carros estao disponiveis");
					}
					
					limparPausarTela();
				break;
		
				//0 - Sair
				case 0:
					limparTela();
					exit(0);
				break;
				
				default:
					isValid = false;
					printf("Opcao invalida, escolha outra:");
					
				break;		
			}
		}while(!isValid);
		
	}while(true);
	return 0;
}


///--------------------------------------------------------------------------------------------------------------------------------------

Cliente cadastrarCliente(){
	Cliente cliente;
	printf("Nome\t\t:");
	scanf("%s",&cliente.nome);
	printf("Telefone\t:");
	scanf("%s",&cliente.telefone);
	printf("Cnh\t\t:");
	scanf("%s",&cliente.cnh);
	printf("Endereco\n");
	printf("Rua\t\t:");
	scanf("%s",&cliente.endereco.rua);
	printf("Nº Casa\t\t:");
	scanf("%d",&cliente.endereco.casa);
	printf("Bairro\t\t:");
	scanf("%s",&cliente.endereco.bairo);
	return cliente;
}

Carro cadastrarCarro(){
	Carro carro;
	printf("Modelo\t\t:");
	scanf("%s",&carro.modelo);
	printf("Cor\t\t:");
	scanf("%s",&carro.cor);
	printf("Ano\t\t:");
	scanf("%d",&carro.ano);
	printf("Valor\t\t:");
	scanf("%f",&carro.valor);
	printf("Placa\t\t:");
	scanf("%s",&carro.placa);
	carro.disponivel =true;
	return carro;
}


void limparPausarTela(){
	printf("\n\n");
	system("pause");
	system("CLS");
}
void limparTela(){
	system("CLS");
}
void infoCarro(Carro carro){
	printf("\nDados do carro:\n");
	printf("\nmodelo\t\t:%s",carro.modelo);
	printf("\ncor\t\t:%s",carro.cor);
	printf("\nano\t\t:%d",carro.ano);
	printf("\nvalor\t\t:%.2f",carro.valor);
	printf("\nplaca\t\t:%s",carro.placa);
}

void infoCliente(Cliente cliente){
	printf("\nDados do Cliente:\n");
	printf("\nnome\t\t:%s",cliente.nome);
	printf("\nrua\t\t:%s",cliente.endereco.rua);
	printf("\ncasa\t\t:%d",cliente.endereco.casa);
	printf("\nbairro\t\t:%s",cliente.endereco.bairo);
	printf("\ntelefone\t:%s",cliente.telefone);
	printf("\ncnh\t\t:%s",cliente.cnh);
}

char* textFormat(char text[120],int index){
   char str[120];
   sprintf(str, "%s %d",text,index);
   return str;
}

void statusCarro(Carro carro){
   printf("%s => %s\n",carro.modelo,(carro.disponivel?"disponivel":"nao disponivel"));
}
void statusCarro(Carro carro,int index){
   printf("%d -> %s => %s\n",index,carro.modelo,(carro.disponivel?"disponivel":"nao disponivel"));
}


Cliente gerarCliente(int index){
	Cliente cliente;
	
	strcpy(cliente.nome,textFormat("nome",index));
	strcpy(cliente.endereco.rua,textFormat("rua",index));
	cliente.endereco.casa=index;
	strcpy(cliente.endereco.bairo,textFormat("bairo",index));
	strcpy(cliente.telefone,textFormat("telefone",index));
	strcpy(	cliente.cnh,textFormat("cnh",index));
	
	return cliente;
}

Carro gerarCarro(int index){
	Carro carro;
	strcpy(carro.modelo,textFormat("modelo",index));
	strcpy(carro.cor,textFormat("cor",index));
	carro.ano=2000+index;
	carro.valor=10+10*index;
	strcpy(carro.placa,textFormat("placa",index));
	carro.disponivel =true;
	
	return carro;
}

void selectInfor(Cliente cliente){
	printf("\nNome do cliente Selecionado -> %s\n",cliente.nome);
}

void selectInfor(Cliente cliente, Carro carro){
	printf("\nNome do cliente Selecionado -> %s\n",cliente.nome);
	printf("Modelo do carro selecionado -> %s\n",carro.modelo);
}


