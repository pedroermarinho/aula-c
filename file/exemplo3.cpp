#include<stdio.h>
#include<string.h>

typedef struct
{
    char nome[120];
    int idade;

}pessoa_t;


int main(){

    
//-----------escrever-----------

    FILE *arquivo_salvar =  fopen("exemplo3.bin","wb");

    pessoa_t pessoa;

    strcpy(pessoa.nome,"Pedro Marinho");
    pessoa.idade = 20;

    fwrite(&pessoa,sizeof(pessoa_t),1,arquivo_salvar);

    fclose(arquivo_salvar);

//-----------ler-----------

    FILE *arquivo_recuperar = fopen("exemplo3.bin","rb");

    pessoa_t ler_pessoa;

    fread(&ler_pessoa,sizeof(pessoa_t),1,arquivo_recuperar);

    printf("nome: %s\n",ler_pessoa.nome);
    printf("idade: %d",ler_pessoa.idade);


    fclose(arquivo_recuperar);



    return 0;
}