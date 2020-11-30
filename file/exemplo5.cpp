#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct 
{
    char nome[120];
    int idade;
} pessoa_t;


int main(){

         
//-----------escrever-----------

    FILE *arquivo_salvar =  fopen("exemplo5.bin","wb");

    if(arquivo_salvar == NULL){
        exit(1);
    }

    pessoa_t pessoa_vet[2];

    strcpy(pessoa_vet[0].nome,"Pedro Marinho");
    pessoa_vet[0].idade = 20;

    strcpy(pessoa_vet[1].nome,"Pedro Eduardo");
    pessoa_vet[1].idade = 21;

    fwrite(pessoa_vet,sizeof(pessoa_t),2,arquivo_salvar);
   
    
    fclose(arquivo_salvar);

//-----------ler-----------

    FILE *arquivo_recuperar = fopen("exemplo5.bin","rb");
    
    
    if(arquivo_recuperar == NULL){
        exit(1);
    }

    pessoa_t ler_pessoa_vet[2];

    for(int i = 0; i<2; i++){
        pessoa_t pessoa_local;

        int tamanho = fread(&pessoa_local,sizeof(pessoa_t),1,arquivo_recuperar);

        if(tamanho<1  || feof(arquivo_recuperar)){
            break;
        }

        ler_pessoa_vet[i] = pessoa_local;
    }

    printf("nome: %s\n",ler_pessoa_vet[0].nome);
    printf("idade: %d\n\n",ler_pessoa_vet[0].idade);

    printf("nome: %s\n",ler_pessoa_vet[1].nome);
    printf("idade: %d",ler_pessoa_vet[1].idade);

    fclose(arquivo_recuperar);
    
    return 0;
}