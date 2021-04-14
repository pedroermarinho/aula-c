 
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

typedef struct 
{
	char modelo[50];
	char cor[50];
	int ano;
	float valor;
	char placa[15];
	int disponível;
} carro_t;


typedef struct
{
	char nome[50];
	char telefone[16];
	char cnh[50];
	char rua[50];
	int casa;
	char bairro[50];

} cliente_t;

cliente_t cadastrar_cliente();
carro_t cadastrar_carro();

void limpar_tela();
void pausar_limpar_tela();

void info_carro(carro_t carro);
void info_cliente(cliente_t cliente);

void status_carro(carro_t carro, int index);
void status_carro_simples(carro_t carro);

cliente_t gerar_cliente(int index);
carro_t gerar_carro(int index);

void select_info(cliente_t cliente, carro_t carro);
void select_info_simples(cliente_t cliente);

void salvar_dados_client(cliente_t cliente_vet[5]);
int recuperar_dados_client(cliente_t cliente_vet[5]);

void salvar_dados_carros(carro_t carro_vet[5]);
int recuperar_dados_carros(carro_t carro_vet[5]);

int main()
{

	setlocale(LC_ALL, "Portuguese");

	int is_valid_client = 0;
	int is_valid_car = 0;

	cliente_t cliente_vet[5];
	carro_t carro_vet[5];

	if (recuperar_dados_carros(carro_vet))
	{
		is_valid_car = 1;
	}
	if (recuperar_dados_client(cliente_vet))
	{
		is_valid_client = 1;
	}

	int clienteAtual;
	int carroAtual;

	int continuar = 1;

	int op_menu;
	
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

		int is_valid;
		do
		{
			printf("\nEscolha uma opcao:");
			scanf("%d", &op_menu);
			is_valid = 1;
			switch (op_menu)
			{
			// 1 - Gerar clientes e carros
			case 1:
				limpar_tela();
				printf("1 - Gerar cadastros de carros\n");
				printf("2 - Gerar cadastros de clientes\n");
				printf("0 - Sair\n");
				do
				{
					printf("\nEscolha uma opcao:");
					scanf("%d", &op_menu);
					is_valid = 1;
					switch (op_menu)
					{
					//1 - Gerar cadastros de carros
					case 1:
						limpar_tela();
						
						for ( i = 0; i < 5; i++)
						{
							carro_vet[i] = gerar_carro(i);
						}
						is_valid_car = 1;
						printf("\nCarros gerados Automaticamente\n");
						pausar_limpar_tela();
						break;
					//2 - Gerar cadastros de clientes
					case 2:
						limpar_tela();
					
						for (i = 0; i < 5; i++)
						{
							cliente_vet[i] = gerar_cliente(i);
						}
						is_valid_client = 1;
						printf("\nClientes gerados Automaticamente\n");
						pausar_limpar_tela();
						break;
					//0 - Sair
					case 0:
						limpar_tela();
						break;
					default:
						is_valid = 0;
						printf("Opcao invalida, escolha outra:");
						break;
					}
				} while (!is_valid);
				break;

			//2 - Cadastrar clientes e carros
			case 2:
				limpar_tela();

				printf("1 - Cadastrar carros\n");
				printf("2 - Cadastrar clientes\n");
				printf("0 - Sair\n");
				do
				{
					printf("\nEscolha uma opcao:");
					scanf("%d", &op_menu);
					is_valid = 1;
					switch (op_menu)
					{
					//1 - Cadastrar carros
					case 1:
						limpar_tela();
					
						for (i = 0; i < 5; i++)
						{
							printf("\n------------------------------\n");
							carro_vet[i] = cadastrar_carro();
						}
						is_valid_car = 1;
						pausar_limpar_tela();
						break;
					//2 - Cadastrar clientes
					case 2:
						limpar_tela();
						for ( i = 0; i < 5; i++)
						{
							printf("\n------------------------------\n");
							cliente_vet[i] = cadastrar_cliente();
						}
						is_valid_client = 1;
						pausar_limpar_tela();
						break;
					//0 - Sair
					case 0:
						limpar_tela();
						break;
					default:
						is_valid = 0;
						printf("Opcao invalida, escolha outra:");
						break;
					}
				} while (!is_valid);
				break;

			//3 - informacoes sobre os clientes e carros
			case 3:
				limpar_tela();
				if (is_valid_client || is_valid_car)
				{
					printf("1 - Clientes\n");
					printf("2 - Carros\n");
					printf("0 - Sair\n");
					do
					{
						printf("\nEscolha uma opcao:");
						scanf("%d", &op_menu);
						is_valid = 1;
						switch (op_menu)
						{
						//1 - Clientes
						case 1:
							limpar_tela();
							if (is_valid_client)
							{
							
								for (i = 0; i < 5; i++)
								{
									info_cliente(cliente_vet[i]);
									printf("\n------------------------------\n");
								}
							}
							else
							{
								printf("\nNenhum cliente cadastrado\n");
							}
							pausar_limpar_tela();
							break;
						//2 - Carros
						case 2:
							limpar_tela();
							if (is_valid_car)
							{
								printf("1 - Todos os carros\n");
								printf("2 - Pesquisar por placa\n");
								printf("3 - Status dos carros\n");
								printf("0 - Sair\n");
								do
								{
									printf("\nEscolha uma opcao:");
									scanf("%d", &op_menu);
									is_valid = 1;
									switch (op_menu)
									{
									//1 - Todos os carros
									case 1:
										limpar_tela();
									
										for (i = 0; i < 5; i++)
										{
											printf("\n------------------------------\n");
											info_carro(carro_vet[i]);
										}
										pausar_limpar_tela();
										break;
									//2 - Pesquisar por placa
									case 2:
										limpar_tela();
										char placa[60];
										printf("Pesquisar placa:");
										scanf("%s", &placa);
										
										for (i = 0; i < 5; i++)
										{
											if (strcmp(carro_vet[i].placa, placa) == 0)
											{
												printf("\n------------------------------\n");
												info_carro(carro_vet[i]);
											}
										}
										pausar_limpar_tela();
										break;
									//3 - Status dos carros
									case 3:
										limpar_tela();
										for ( i = 0; i < 5; i++)
										{
											printf("\n------------------------------\n");
											status_carro_simples(carro_vet[i]);
										}
										pausar_limpar_tela();
										break;
									//0 - Sair
									case 0:
										limpar_tela();
										break;
									default:
										is_valid = 0;
										printf("Opcao invalida, escolha outra:");
										break;
									}
								} while (!is_valid);
							}
							else
							{
								printf("\nNenhum carro cadastrado\n");
								pausar_limpar_tela();
							}
							break;
						///0 - Sair
						case 0:
							limpar_tela();
							break;
						default:
							is_valid = 0;
							printf("Opcao invalida, escolha outra:");
							break;
						}
					} while (!is_valid);
				}
				else
				{
					printf("\nNenhum carro ou client cadastrado\n");
					pausar_limpar_tela();
				}
				break;

			//4 - Sistema aluguel
			case 4:
				limpar_tela();
				if (is_valid_client && is_valid_car)
				{
					printf("\nLista de Clientes\n");
					for ( i = 0; i < 5; i++)
					{
						printf("%d -> %s\n", i, cliente_vet[i].nome);
					}

					do
					{
						printf("\nEscolhar um cliente para gerenciar:");
						scanf("%d", &clienteAtual);
					} while (clienteAtual > 4 || clienteAtual < 0);

					limpar_tela();

					select_info_simples(cliente_vet[clienteAtual]);

					info_cliente(cliente_vet[clienteAtual]);

					pausar_limpar_tela();
					printf("\n\nLista de Carros\n");
					for (i = 0; i < 5; i++)
					{
						status_carro(carro_vet[i], i);
					}

					do
					{
						printf("\nEscolhar um carro disponível para o clente:");
						scanf("%d", &carroAtual);
					} while (carro_vet[carroAtual].disponível == 0 || (carroAtual > 4 || carroAtual < 0));

					carro_vet[carroAtual].disponível = 0;

					limpar_tela();
					select_info(cliente_vet[clienteAtual], carro_vet[carroAtual]);

					info_carro(carro_vet[carroAtual]);

					pausar_limpar_tela();
					select_info(cliente_vet[clienteAtual], carro_vet[carroAtual]);

					int dias;
					printf("\nPor quantos dias deseja alugar? :");
					scanf("%d", &dias);

					limpar_tela();
					select_info(cliente_vet[clienteAtual], carro_vet[carroAtual]);

					printf("\nValor total do aluguel: %.2f\n", (carro_vet[carroAtual].valor * dias));
					printf("\nO carro deverar ser entregue em %d dias!!!", dias);

					pausar_limpar_tela();
				}
				else
				{
					printf("\nNenhum carro ou cliente cadastrado\n");
					pausar_limpar_tela();
				}
				break;
			//5 - Devolu��o do carro
			case 5:
				limpar_tela();
				int isDevolucao;
				if (is_valid_car)
				{
					isDevolucao = 0;
					for ( i = 0; i < 5; i++)
					{
						if (!carro_vet[i].disponível)
						{
							printf("\n------------------------------\n");
							status_carro(carro_vet[i], i);
							isDevolucao = 1;
						}
					}
				}
				if (isDevolucao)
				{
					do
					{
						printf("\nSelecione um carro para fazer a devolucao:");
						scanf("%d", &op_menu);
					} while (op_menu > 4 || op_menu < 0);

					carro_vet[op_menu].disponível = 1;
				}
				else
				{
					printf("Todos os carros estao disponiveis");
				}

				pausar_limpar_tela();
				break;

			//6 - Salvar dados
			case 6:
				limpar_tela();
				if (is_valid_car)
				{
					salvar_dados_carros(carro_vet);
				}
				else
				{
					printf("\nDados do carros não encontrado\n");
				}

				if (is_valid_client)
				{
					salvar_dados_client(cliente_vet);
				}
				else
				{
					printf("\nDados dos clientes não encontrado\n");
				}

				pausar_limpar_tela();
				break;
			//0 - Sair
			case 0:
				limpar_tela();
				exit(0);
				break;

			default:
				is_valid = 0;
				printf("Opcao invalida, escolha outra:");

				break;
			}
		} while (!is_valid);

	} while (1);
	return 0;
}

///--------------------------------------------------------------------------------------------------------------------------------------

cliente_t cadastrar_cliente()
{
	cliente_t cliente;
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

carro_t cadastrar_carro()
{

	carro_t carro;
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
	carro.disponível = 1;
	return carro;
}

void limpar_tela()
{
	#ifdef WINDOWS
    	system("cls");
	#else
    	system ("clear");
	#endif
}
void pausar_limpar_tela()
{
	printf("\n\n");
	#ifdef WINDOWS
    	system("pause");
	#else
    	system("read -p \"Pressione enter para continuar\" saindo");
	#endif
	
	limpar_tela();
}

void info_carro(carro_t carro)
{
	printf("\nDados do carro:\n");
	printf("\nmodelo\t\t:%s", carro.modelo);
	printf("\ncor\t\t:%s", carro.cor);
	printf("\nano\t\t:%d", carro.ano);
	printf("\nvalor\t\t:%.2f", carro.valor);
	printf("\nplaca\t\t:%s", carro.placa);
}

void info_cliente(cliente_t cliente)
{
	printf("\nDados do Cliente:\n");
	printf("\nnome\t\t:%s", cliente.nome);
	printf("\nrua\t\t:%s", cliente.rua);
	printf("\ncasa\t\t:%d", cliente.casa);
	printf("\nbairro\t\t:%s", cliente.bairro);
	printf("\ntelefone\t:%s", cliente.telefone);
	printf("\ncnh\t\t:%s", cliente.cnh);
}

void status_carro(carro_t carro, int index)
{
	printf("%d -> %s => %s\n", index, carro.modelo, (carro.disponível ? "disponível" : "nao disponível"));
}

void status_carro_simples(carro_t carro)
{
	printf("%s => %s\n", carro.modelo, (carro.disponível ? "disponível" : "nao disponível"));
}

cliente_t gerar_cliente(int index)
{
	cliente_t cliente;

	sprintf(cliente.nome, "%s %d", "nome", index);
	sprintf(cliente.rua, "%s %d", "rua", index);
	cliente.casa = index;
	sprintf(cliente.bairro, "%s %d", "bairro", index);
	sprintf(cliente.telefone, "%s %d", "telefone", index);
	sprintf(cliente.cnh, "%s %d", "cnh", index);

	return cliente;
}

carro_t gerar_carro(int index)
{
	carro_t carro;
	sprintf(carro.modelo, "%s %d", "modelo", index);
	sprintf(carro.cor, "%s %d", "cor", index);
	carro.ano = 2000 + index;
	carro.valor = 10 + 10 * index;
	sprintf(carro.placa, "%s %d", "placa", index);
	carro.disponível = 1;

	return carro;
}

void select_info(cliente_t cliente, carro_t carro)
{
	printf("\nNome do cliente Selecionado -> %s\n", cliente.nome);
	printf("Modelo do carro selecionado -> %s\n", carro.modelo);
}

void select_info_simples(cliente_t cliente)
{
	printf("\nNome do cliente Selecionado -> %s\n", cliente.nome);
}

void salvar_dados_client(cliente_t cliente_vet[5])
{
	FILE *arquivoClient;
	arquivoClient = fopen("client.bin", "wb");

	if (arquivoClient != NULL)
	{
		int i;
		for ( i = 0; i < 5; i++)
		{
			fwrite(&cliente_vet[i], sizeof(cliente_t), sizeof(cliente_vet[i]), arquivoClient);
		}
		fclose(arquivoClient);
		printf("\nDados dos Clientes salvos\n");
	}
	else
	{
		printf("\nErro ao salvar os dados dos clientes\n");
	}
}

int recuperar_dados_client(cliente_t cliente_vet[5])
{

	FILE *arquivoClient = fopen("client.bin", "rb");

	if (arquivoClient != NULL)
	{
		int i;
		for ( i = 0; i < 5; i++)
		{
			cliente_t cliente;

			size_t tamanhoArquivo = fread(&cliente, sizeof(cliente_t), 1, arquivoClient);

			if (tamanhoArquivo < 1)
				break;
			else
				cliente_vet[i] = cliente;
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

void salvar_dados_carros(carro_t carro_vet[5])
{
	FILE *arquivo_carro;
	arquivo_carro = fopen("carro.bin", "wb");
	if (arquivo_carro != NULL)
	{
		int i;
		for ( i = 0; i < 5; i++)
		{
			fwrite(&carro_vet[i], sizeof(carro_t), sizeof(carro_vet[i]), arquivo_carro);
		}
		fclose(arquivo_carro);
		printf("\nDados dos Carros salvos\n");
	}
	else
	{
		printf("\nErro ao salvar os dados dos Carros\n");
	}
}
int recuperar_dados_carros(carro_t carro_vet[5])
{

	FILE *arquivo_carro = fopen("carro.bin", "rb");

	if (arquivo_carro != NULL)
	{
		int i;
		for ( i = 0; i < 5; i++)
		{
			carro_t carro;

			size_t tamanhoArquivo = fread(&carro, sizeof(carro_t), 1, arquivo_carro);

			if (tamanhoArquivo < 1)
				break;
			else
				carro_vet[i] = carro;
		}
		fclose(arquivo_carro); // fecha o arquivo
		printf("\nDados dos Carros recuperados\n");
		return 1;
	}
	else
	{
		printf("\nErro ao ler os dados dos carros\n");
		return 0;
	}
}
