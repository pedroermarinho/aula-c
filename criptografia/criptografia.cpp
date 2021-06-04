



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


const int TAMANHO_MENSAGEM=250;
const int TAMANHO_CHAVE=4;
int MENSAGEM_CRIPTOGRAFADA[TAMANHO_MENSAGEM];


void criptografar(int *tamanho){

    char mensagem[TAMANHO_MENSAGEM];


    printf("\nDigite uma mensagem:");
    scanf("%s",&mensagem);


    *tamanho = strlen(mensagem) ;

    int chave[TAMANHO_CHAVE];
    printf("\nDigite as chaves de criptografia:\n");
    for (int indicador_chave = 0; indicador_chave < TAMANHO_CHAVE; indicador_chave++)
    {
        printf(" %dº chave: ",indicador_chave+1 );
        scanf("%d",&chave[indicador_chave]);
    }
    

    printf("\nmensagem: %s\n",mensagem);

    for(int indicador_caractere = 0 ; indicador_caractere < *tamanho; indicador_caractere ++){
        MENSAGEM_CRIPTOGRAFADA[indicador_caractere] = mensagem[indicador_caractere];
    }

    for (int indicador_caractere = 0; indicador_caractere < *tamanho;)
    {
        for (int indicador_chave = 0; indicador_chave < TAMANHO_CHAVE; indicador_chave++)
        {
            MENSAGEM_CRIPTOGRAFADA[indicador_caractere] *= chave[indicador_chave];
            indicador_caractere++;
        }
    }
    printf("\nmensagem criptografada: ");
    
    for(int indicador_caractere = 0 ; indicador_caractere < *tamanho; indicador_caractere ++){
        printf("%d ",MENSAGEM_CRIPTOGRAFADA[indicador_caractere]);
    }
    printf("\n");
}

 void descriptografar( int tamanho){


    int chave[TAMANHO_CHAVE];
    printf("\nDigite as chaves de criptografia:\n");
    for (int indicador_chave = 0; indicador_chave < TAMANHO_CHAVE; indicador_chave++)
    {
        printf(" %dº chave: ",indicador_chave+1);
        scanf("%d",&chave[indicador_chave]);
    }
    
    

    char mensagem_descriptografada[TAMANHO_MENSAGEM];

     for (int indicador_caractere = 0; indicador_caractere < tamanho;)
    {
        for (int indicador_chave = 0; indicador_chave < TAMANHO_CHAVE; indicador_chave++)
        {
            MENSAGEM_CRIPTOGRAFADA[indicador_caractere] /= chave[indicador_chave];
            indicador_caractere++;
        }
    }

    
    for(int indicador_caractere = 0 ; indicador_caractere < tamanho; indicador_caractere ++){
        mensagem_descriptografada[indicador_caractere] = (char) MENSAGEM_CRIPTOGRAFADA[indicador_caractere];
    }
     
    printf("\nmensagem descriptografada: %s",mensagem_descriptografada);
 }

 int main(int argc, char const *argv[])
 {

     int tamanho;

     



     criptografar( &tamanho);

     descriptografar(tamanho);


     printf("\n\n");

     return 0;
 }
 