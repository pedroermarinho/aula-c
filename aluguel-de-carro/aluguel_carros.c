 
 //ENUNCIADO
//Fa�a um programa para gerenciar loja aluguel carros.
//O sistema ir� cadastrar:
//    � Carro: modelo, cor, ano, quantidade, valor di�ria, placa;
//    � Cliente: nome, endere�o (rua, casa, bairro), telefone, n�mero CNH.
//O Sistema ir� realizar o aluguel dos carros:
//    � O cliente cadastrado escolhe o carro dispon�vel e aluga de acordo com o tempo desejado, valor total.
//O sistema ter� devolu��o:
//    O funcion�rio pesquisa a placa, o sistema lista os dados do carro 
//    e quando finalizar a devolu��o o carro volta a estar dispon�vel.
//Observa��o: Limite de 5 (cinco) Carros e 5 (cinco) Clientes, estipulado pelo professor!.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Carro
{
	char modelo[50];
	char cor[50];
	int ano;
	float valor;
	char placa[15];
	int disponivel;
} Carro;


typedef struct Cliente
{
	char nome[50];
	char telefone[16];
	char cnh[50];
	char rua[50];
	int casa;
	char bairro[50];

} Cliente;

Cliente cadastrarCliente();
Carro cadastrarCarro();

void limparTela();
void limparPausarTela();

void infoCarro(Carro carro);
void infoCliente(Cliente cliente);

void statusCarro(Carro carro, int index);
void statusCarroSimples(Carro carro);

Cliente gerarCliente(int index);
Carro gerarCarro(int index);

void selectInfo(Cliente cliente, Carro carro);
void selectInfoSimples(Cliente cliente);

void salvarDadosClient(Cliente clientes[5]);
int recuperarDadosClient(Cliente clientes[5]);

void salvarDadosCarros(Carro carros[5]);
int recuperarDadosCarros(Carro carros[5]);

int main()
{

	setlocale(LC_ALL, "Portuguese");

	int isValidClient = 0;
	int isValidCar = 0;

	Cliente clientes[5];
	Carro carros[5];

	if (recuperarDadosCarros(carros))
	{
		isValidCar = 1;
	}
	if (recuperarDadosClient(clientes))
	{
		isValidClient = 1;
	}

	int clienteAtual;
	int carroAtual;

	int continuar = 1;

	int opMenu;
	
	int i=0;

	printf("\n\n");
	do
	{
		continuar = 0;

		printf("1 - Gerar clientes e carros\n");
		printf("2 - Cadastrar clientes e carros\n");
		printf("3 - informacoes sobre os clientes e carros\n");
		printf("4 - Sistema aluguel\n");
		printf("5 - Devolucao do carro\n");
		printf("6 - Salvar dados\n");
		printf("0 - Sair\n");

		int isValid;
		do
		{
			printf("\nEscolha uma opcao:");
			scanf("%d", &opMenu);
			isValid = 1;
			switch (opMenu)
			{
			// 1 - Gerar clientes e carros
			case 1:
				limparTela();
				printf("1 - Gerar cadastros de carros\n");
				printf("2 - Gerar cadastros de clientes\n");
				printf("0 - Sair\n");
				do
				{
					printf("\nEscolha uma opcao:");
					scanf("%d", &opMenu);
					isValid = 1;
					switch (opMenu)
					{
					//1 - Gerar cadastros de carros
					case 1:
						limparTela();
						
						for ( i = 0; i < 5; i++)
						{
							carros[i] = gerarCarro(i);
						}
						isValidCar = 1;
						printf("\nCarros gerados Automaticamente\n");
						limparPausarTela();
						break;
					//2 - Gerar cadastros de clientes
					case 2:
						limparTela();
					
						for (i = 0; i < 5; i++)
						{
							clientes[i] = gerarCliente(i);
						}
						isValidClient = 1;
						printf("\nClientes gerados Automaticamente\n");
						limparPausarTela();
						break;
					//0 - Sair
					case 0:
						limparTela();
						break;
					default:
						isValid = 0;
						printf("Opcao invalida, escolha outra:");
						break;
					}
				} while (!isValid);
				break;

			//2 - Cadastrar clientes e carros
			case 2:
				limparTela();

				printf("1 - Cadastrar carros\n");
				printf("2 - Cadastrar clientes\n");
				printf("0 - Sair\n");
				do
				{
					printf("\nEscolha uma opcao:");
					scanf("%d", &opMenu);
					isValid = 1;
					switch (opMenu)
					{
					//1 - Cadastrar carros
					case 1:
						limparTela();
					
						for (i = 0; i < 5; i++)
						{
							printf("\n------------------------------\n");
							carros[i] = cadastrarCarro();
						}
						isValidCar = 1;
						limparPausarTela();
						break;
					//2 - Cadastrar clientes
					case 2:
						limparTela();
						for ( i = 0; i < 5; i++)
						{
							printf("\n------------------------------\n");
							clientes[i] = cadastrarCliente();
						}
						isValidClient = 1;
						limparPausarTela();
						break;
					//0 - Sair
					case 0:
						limparTela();
						break;
					default:
						isValid = 0;
						printf("Opcao invalida, escolha outra:");
						break;
					}
				} while (!isValid);
				break;

			//3 - informacoes sobre os clientes e carros
			case 3:
				limparTela();
				if (isValidClient || isValidCar)
				{
					printf("1 - Clientes\n");
					printf("2 - Carros\n");
					printf("0 - Sair\n");
					do
					{
						printf("\nEscolha uma opcao:");
						scanf("%d", &opMenu);
						isValid = 1;
						switch (opMenu)
						{
						//1 - Clientes
						case 1:
							limparTela();
							if (isValidClient)
							{
							
								for (i = 0; i < 5; i++)
								{
									infoCliente(clientes[i]);
									printf("\n------------------------------\n");
								}
							}
							else
							{
								printf("\nNenhum cliente cadastrado\n");
							}
							limparPausarTela();
							break;
						//2 - Carros
						case 2:
							limparTela();
							if (isValidCar)
							{
								printf("1 - Todos os carros\n");
								printf("2 - Pesquisar por placa\n");
								printf("3 - Status dos carros\n");
								printf("0 - Sair\n");
								do
								{
									printf("\nEscolha uma opcao:");
									scanf("%d", &opMenu);
									isValid = 1;
									switch (opMenu)
									{
									//1 - Todos os carros
									case 1:
										limparTela();
									
										for (i = 0; i < 5; i++)
										{
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
										scanf("%s", &placa);
										
										for (i = 0; i < 5; i++)
										{
											if (strcmp(carros[i].placa, placa) == 0)
											{
												printf("\n------------------------------\n");
												infoCarro(carros[i]);
											}
										}
										limparPausarTela();
										break;
									//3 - Status dos carros
									case 3:
										limparTela();
										for ( i = 0; i < 5; i++)
										{
											printf("\n------------------------------\n");
											statusCarroSimples(carros[i]);
										}
										limparPausarTela();
										break;
									//0 - Sair
									case 0:
										limparTela();
										break;
									default:
										isValid = 0;
										printf("Opcao invalida, escolha outra:");
										break;
									}
								} while (!isValid);
							}
							else
							{
								printf("\nNenhum carro cadastrado\n");
								limparPausarTela();
							}
							break;
						///0 - Sair
						case 0:
							limparTela();
							break;
						default:
							isValid = 0;
							printf("Opcao invalida, escolha outra:");
							break;
						}
					} while (!isValid);
				}
				else
				{
					printf("\nNenhum carro ou client cadastrado\n");
					limparPausarTela();
				}
				break;

			//4 - Sistema aluguel
			case 4:
				limparTela();
				if (isValidClient && isValidCar)
				{
					printf("\nLista de Clientes\n");
					for ( i = 0; i < 5; i++)
					{
						printf("%d -> %s\n", i, clientes[i].nome);
					}

					do
					{
						printf("\nEscolhar um cliente para gerenciar:");
						scanf("%d", &clienteAtual);
					} while (clienteAtual > 4 || clienteAtual < 0);

					limparTela();

					selectInfoSimples(clientes[clienteAtual]);

					infoCliente(clientes[clienteAtual]);

					limparPausarTela();
					printf("\n\nLista de Carros\n");
					for (i = 0; i < 5; i++)
					{
						statusCarro(carros[i], i);
					}

					do
					{
						printf("\nEscolhar um carro disponivel para o clente:");
						scanf("%d", &carroAtual);
					} while (carros[carroAtual].disponivel == 0 || (carroAtual > 4 || carroAtual < 0));

					carros[carroAtual].disponivel = 0;

					limparTela();
					selectInfo(clientes[clienteAtual], carros[carroAtual]);

					infoCarro(carros[carroAtual]);

					limparPausarTela();
					selectInfo(clientes[clienteAtual], carros[carroAtual]);

					int dias;
					printf("\nPor quantos dias deseja alugar? :");
					scanf("%d", &dias);

					limparTela();
					selectInfo(clientes[clienteAtual], carros[carroAtual]);

					printf("\nValor total do aluguel: %.2f\n", (carros[carroAtual].valor * dias));
					printf("\nO carro deverar ser entregue em %d dias!!!", dias);

					limparPausarTela();
				}
				else
				{
					printf("\nNenhum carro ou cliente cadastrado\n");
					limparPausarTela();
				}
				break;
			//5 - Devolu��o do carro
			case 5:
				limparTela();
				int isDevolucao;
				if (isValidCar)
				{
					isDevolucao = 0;
					for ( i = 0; i < 5; i++)
					{
						if (!carros[i].disponivel)
						{
							printf("\n------------------------------\n");
							statusCarro(carros[i], i);
							isDevolucao = 1;
						}
					}
				}
				if (isDevolucao)
				{
					do
					{
						printf("\nSelecione um carro para fazer a devolucao:");
						scanf("%d", &opMenu);
					} while (opMenu > 4 || opMenu < 0);

					carros[opMenu].disponivel = 1;
				}
				else
				{
					printf("Todos os carros estao disponiveis");
				}

				limparPausarTela();
				break;

			//6 - Salvar dados
			case 6:
				limparTela();
				if (isValidCar)
				{
					salvarDadosCarros(carros);
				}
				else
				{
					printf("\nDados do carros não encontrado\n");
				}

				if (isValidClient)
				{
					salvarDadosClient(clientes);
				}
				else
				{
					printf("\nDados dos clientes não encontrado\n");
				}

				limparPausarTela();
				break;
			//0 - Sair
			case 0:
				limparTela();
				exit(0);
				break;

			default:
				isValid = 0;
				printf("Opcao invalida, escolha outra:");

				break;
			}
		} while (!isValid);

	} while (1);
	return 0;
}

///--------------------------------------------------------------------------------------------------------------------------------------

Cliente cadastrarCliente()
{
	Cliente cliente;
	printf("Nome (char)\t\t:");
	scanf("%s", &cliente.nome);
	printf("Telefone (char)\t\t:");
	scanf("%s", &cliente.telefone);
	printf("Cnh (char)\t\t:");
	scanf("%s", &cliente.cnh);
	printf("Endereco\n");
	printf("Rua (char)\t\t:");
	scanf("%s", &cliente.rua);
	printf("Nº Casa (int)\t\t:");
	scanf("%d", &cliente.casa);
	printf("Bairro (char)\t\t:");
	scanf("%s", &cliente.bairro);
	return cliente;
}

Carro cadastrarCarro()
{

	Carro carro;
	printf("Modelo (char)\t\t:");
	scanf("%s", &carro.modelo);
	printf("Cor (char)\t\t:");
	scanf("%s", &carro.cor);
	printf("Ano (int)\t\t:");
	scanf("%d", &carro.ano);
	printf("Valor (float)\t\t:");
	scanf("%f", &carro.valor);
	printf("Placa (char)\t\t:");
	scanf("%s", &carro.placa);
	carro.disponivel = 1;
	return carro;
}

void limparTela()
{
	#ifdef WINDOWS
    	system("cls");
	#else
    	system ("clear");
	#endif
}
void limparPausarTela()
{
	printf("\n\n");
	#ifdef WINDOWS
    	system("pause");
	#else
    	system("read -p \"Pressione enter para continuar\" saindo");
	#endif
	
	limparTela();
}

void infoCarro(Carro carro)
{
	printf("\nDados do carro:\n");
	printf("\nmodelo\t\t:%s", carro.modelo);
	printf("\ncor\t\t:%s", carro.cor);
	printf("\nano\t\t:%d", carro.ano);
	printf("\nvalor\t\t:%.2f", carro.valor);
	printf("\nplaca\t\t:%s", carro.placa);
}

void infoCliente(Cliente cliente)
{
	printf("\nDados do Cliente:\n");
	printf("\nnome\t\t:%s", cliente.nome);
	printf("\nrua\t\t:%s", cliente.rua);
	printf("\ncasa\t\t:%d", cliente.casa);
	printf("\nbairro\t\t:%s", cliente.bairro);
	printf("\ntelefone\t:%s", cliente.telefone);
	printf("\ncnh\t\t:%s", cliente.cnh);
}

void statusCarro(Carro carro, int index)
{
	printf("%d -> %s => %s\n", index, carro.modelo, (carro.disponivel ? "disponivel" : "nao disponivel"));
}

void statusCarroSimples(Carro carro)
{
	printf("%s => %s\n", carro.modelo, (carro.disponivel ? "disponivel" : "nao disponivel"));
}

Cliente gerarCliente(int index)
{
	Cliente cliente;

	sprintf(cliente.nome, "%s %d", "nome", index);
	sprintf(cliente.rua, "%s %d", "rua", index);
	cliente.casa = index;
	sprintf(cliente.bairro, "%s %d", "bairro", index);
	sprintf(cliente.telefone, "%s %d", "telefone", index);
	sprintf(cliente.cnh, "%s %d", "cnh", index);

	return cliente;
}

Carro gerarCarro(int index)
{
	Carro carro;
	sprintf(carro.modelo, "%s %d", "modelo", index);
	sprintf(carro.cor, "%s %d", "cor", index);
	carro.ano = 2000 + index;
	carro.valor = 10 + 10 * index;
	sprintf(carro.placa, "%s %d", "placa", index);
	carro.disponivel = 1;

	return carro;
}

void selectInfo(Cliente cliente, Carro carro)
{
	printf("\nNome do cliente Selecionado -> %s\n", cliente.nome);
	printf("Modelo do carro selecionado -> %s\n", carro.modelo);
}

void selectInfoSimples(Cliente cliente)
{
	printf("\nNome do cliente Selecionado -> %s\n", cliente.nome);
}

void salvarDadosClient(Cliente clientes[5])
{
	FILE *arquivoClient;
	arquivoClient = fopen("client.bin", "wb");

	if (arquivoClient != NULL)
	{
		int i;
		for ( i = 0; i < 5; i++)
		{
			fwrite(&clientes[i], sizeof(Cliente), sizeof(clientes[i]), arquivoClient);
		}
		fclose(arquivoClient);
		printf("\nDados dos Clientes salvos\n");
	}
	else
	{
		printf("\nErro ao salvar os dados dos clientes\n");
	}
}

int recuperarDadosClient(Cliente clientes[5])
{

	FILE *arquivoClient = fopen("client.bin", "rb");

	if (arquivoClient != NULL)
	{
		int i;
		for ( i = 0; i < 5; i++)
		{
			Cliente cliente;

			size_t tamanhoArquivo = fread(&cliente, sizeof(Cliente), 1, arquivoClient);

			if (tamanhoArquivo < 1)
				break;
			else
				clientes[i] = cliente;
		}
		fclose(arquivoClient); // fecha o arquivo
		printf("\nDados dos Clientes recuperados\n");
		return 1;
	}
	else
	{
		printf("\nErro ao ler os dados dos clientes\n");
		return 0;
	}
}

void salvarDadosCarros(Carro carros[5])
{
	FILE *arquivoCarro;
	arquivoCarro = fopen("carro.bin", "wb");
	if (arquivoCarro != NULL)
	{
		int i;
		for ( i = 0; i < 5; i++)
		{
			fwrite(&carros[i], sizeof(Carro), sizeof(carros[i]), arquivoCarro);
		}
		fclose(arquivoCarro);
		printf("\nDados dos Carros salvos\n");
	}
	else
	{
		printf("\nErro ao salvar os dados dos Carros\n");
	}
}
int recuperarDadosCarros(Carro carros[5])
{

	FILE *arquivoCarro = fopen("carro.bin", "rb");

	if (arquivoCarro != NULL)
	{
		int i;
		for ( i = 0; i < 5; i++)
		{
			Carro carro;

			size_t tamanhoArquivo = fread(&carro, sizeof(Carro), 1, arquivoCarro);

			if (tamanhoArquivo < 1)
				break;
			else
				carros[i] = carro;
		}
		fclose(arquivoCarro); // fecha o arquivo
		printf("\nDados dos Carros recuperados\n");
		return 1;
	}
	else
	{
		printf("\nErro ao ler os dados dos carros\n");
		return 0;
	}
}
