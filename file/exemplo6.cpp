#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct 
{
    char nome[120];
    int idade;
} pessoa_t;

typedef struct 
{
    char cpf[20];
    char rg[15];
} identidade_t;


int main(){

         
//-----------escrever-----------

    FILE *arquivo_salvar_pessoa =  fopen("exemplo6_pessoa.bin","wb");

    if(arquivo_salvar_pessoa == NULL){
        exit(1);
    }

    pessoa_t pessoa_vet[2];

    strcpy(pessoa_vet[0].nome,"Pedro Marinho");
    pessoa_vet[0].idade = 20;

    strcpy(pessoa_vet[1].nome,"Pedro Eduardo");
    pessoa_vet[1].idade = 21;

    fwrite(pessoa_vet,sizeof(pessoa_t),2,arquivo_salvar_pessoa);

    fclose(arquivo_salvar_pessoa);

//-----------ler-----------

    FILE *arquivo_recuperar_pessoa = fopen("exemplo6_pessoa.bin","rb");
    
    if(arquivo_recuperar_pessoa == NULL){
        exit(1);
    }

    pessoa_t ler_pessoa_vet[2];

    fread(ler_pessoa_vet,sizeof(pessoa_t),2,arquivo_recuperar_pessoa);

    printf("nome: %s\n",ler_pessoa_vet[0].nome);
    printf("idade: %d\n\n",ler_pessoa_vet[0].idade);

    printf("nome: %s\n",ler_pessoa_vet[1].nome);
    printf("idade: %d\n\n",ler_pessoa_vet[1].idade);

    fclose(arquivo_recuperar_pessoa);
    
            
//-----------escrever-----------

    FILE *arquivo_salvar_identidade =  fopen("exemplo6_identidade.bin","wb");

    if(arquivo_salvar_identidade == NULL){
        exit(1);
    }

    identidade_t identidade_vet[2];

    strcpy(identidade_vet[0].cpf,"111111111111");
    strcpy(identidade_vet[0].rg,"1111111");

    strcpy(identidade_vet[1].cpf,"22222222222");
    strcpy(identidade_vet[1].rg,"222222");

    fwrite(identidade_vet,sizeof(identidade_t),2,arquivo_salvar_identidade);

    fclose(arquivo_salvar_identidade);

//-----------ler-----------

    FILE *arquivo_recuperar_identidade = fopen("exemplo6_identidade.bin","rb");
    
    if(arquivo_recuperar_identidade == NULL){
        exit(1);
    }

    identidade_t ler_identidade_vet[2];

    fread(ler_identidade_vet,sizeof(identidade_t),2,arquivo_recuperar_identidade);

    for (int i = 0; i < 2; i++)
    {
        printf("cpf: %s\n",ler_identidade_vet[i].cpf);
        printf("rg: %s\n\n",ler_identidade_vet[i].rg);
    }
    


    fclose(arquivo_recuperar_identidade);


    return 0;
}