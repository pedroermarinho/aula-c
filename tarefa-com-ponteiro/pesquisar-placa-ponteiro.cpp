/*
faça programa que cadastre carro: marca,modelo,cor,placa, valor.Pesquise por placa se existir exiba: marca,modelo,cor,placa,valor IPVA (é 3% do valor do carro)

Com ponteiro
*/
//Pedro Marinho
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct Carro
{
    char marca[120];
    char modelo[60];
    char placa[20];
    char cor[20];
    float valor;
} Carro;

void cadastrar(Carro *carro1,Carro *carro2);
void pesquisar(Carro carro1,Carro carro2);
void imprimirMsg(Carro carro);

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    Carro carro1;
    Carro carro2;
    cadastrar(&carro1,&carro2);
    pesquisar(carro1, carro2);
    getchar();
    return 0;
}
void cadastrar(Carro *carro1,Carro *carro2)
{
    
    printf("\n-------------------------\n");
    printf("\nMarca:\n");
    printf(">");
    fflush(stdin);
    gets(carro1->marca);
    printf("\nModelo:\n");
    printf(">");
    fflush(stdin);
    gets(carro1->modelo);
    printf("\nCor:\n");
    printf(">");
    fflush(stdin);
    fflush(stdin);
    gets(carro1->cor);
    printf("\nPlaca:\n");
    printf(">");
    fflush(stdin);
    gets(carro1->placa);
    printf("\nValor:\n");
    printf(">");
    scanf("%f",&carro1->valor);
    
    printf("\n-------------------------\n");
    printf("\nMarca:\n");
    printf(">");
    fflush(stdin);
    gets(carro2->marca);
    printf("\nModelo:\n");
    printf(">");
    fflush(stdin);
    gets(carro2->modelo);
    printf("\nCor:\n");
    printf(">");
    fflush(stdin);
    fflush(stdin);
    gets(carro2->cor);
    printf("\nPlaca:\n");
    printf(">");
    fflush(stdin);
    gets(carro2->placa);
    printf("\nValor:\n");
    printf(">");
    scanf("%f",&carro2->valor);    
}
void pesquisar(Carro carro1,Carro carro2)
{
    char placa[20];
    printf("\nSistema de pesquisa\n");
    printf("\nPlaca:\n");
    printf(">");
    fflush(stdin);
    gets(placa);
    if (strcmp(placa,carro1.placa)==0)
    {
        imprimirMsg(carro1);
    }
    if (strcmp(placa,carro2.placa)==0)
    {
        imprimirMsg(carro2);
    }
    
}
void imprimirMsg(Carro carro)
{
    printf("\nInformações\n");
    printf("\nMarca:%s",carro.marca);
    printf("\nModelo:%s",carro.modelo);
    printf("\nCor:%s",carro.cor);
    printf("\nPlaca:%s",carro.placa);
    printf("\nValor:%.2f",carro.valor);
    printf("\nIPVA:%.2f",(carro.valor * 0.03));
}