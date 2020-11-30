#include<stdio.h>

int main(){


// ponteiro ou vetor(matriz)
//-----------escrever-----------

    FILE *arquivo_salvar =  fopen("exemplo2.bin","wb");

    char nome[20]= "Pedro Marinho";

    fwrite(nome,sizeof(char),20, arquivo_salvar);

    fclose(arquivo_salvar);

//-----------ler-----------

    FILE *arquivo_recuperar = fopen("exemplo2.bin","rb");

    char ler_nome[20];

    fread(ler_nome,sizeof(char),20,arquivo_recuperar);

    printf("%s",ler_nome);

    fclose(arquivo_recuperar);


    return 0;
}