#include <stdio.h>
#include <malloc.h>
#define MAX 255

typedef struct 
{
    int peso;
    int altura;
}peso_altura_t;

int main(){
    
    peso_altura_t* pessoa1 = (peso_altura_t*) malloc(sizeof(peso_altura_t));
    pessoa1 -> altura = 160;
    pessoa1 -> peso = 70;

    printf("Peso: %i, Altura: %i", pessoa1->peso,pessoa1->altura);

    return 0;
}