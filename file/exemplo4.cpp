#include<stdio.h>
#include<string.h>

typedef struct 
{
    char nome[120];
    int idade;
} pessoa_t;


int main(){

         
//-----------escrever-----------

    FILE *arquivo_salvar =  fopen("exemplo4.bin","wb");

    pessoa_t pessoa_vet[2];

    strcpy(pessoa_vet[0].nome,"Pedro Marinho");
    pessoa_vet[0].idade = 20;

    strcpy(pessoa_vet[1].nome,"Pedro Eduardo");
    pessoa_vet[1].idade = 21;

    fwrite(pessoa_vet,sizeof(pessoa_t),2,arquivo_salvar);

    fclose(arquivo_salvar);

//-----------ler-----------

    FILE *arquivo_recuperar = fopen("exemplo4.bin","rb");

    pessoa_t ler_pessoa_vet[2];

    fread(ler_pessoa_vet,sizeof(pessoa_t),2,arquivo_recuperar);

    printf("nome: %s\n",ler_pessoa_vet[0].nome);
    printf("idade: %d\n\n",ler_pessoa_vet[0].idade);

    printf("nome: %s\n",ler_pessoa_vet[1].nome);
    printf("idade: %d",ler_pessoa_vet[1].idade);

    fclose(arquivo_recuperar);
    
    return 0;
}