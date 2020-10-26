#include <stdio.h>

void imprimirNumero(int a);
void imprimirNumeroQualquer();
void leitura(int *a );
int main()
{
   int a =0;
   int b;
   printf("1 -%x\n",&a);
   printf("1 -%d\n",a);
   leitura(&b);
   imprimirNumero(a);
   imprimirNumeroQualquer();
    return 0;
}
// a = 0 => a = 61fe1c
void leitura(int *numero ){
    printf("2 -%x\n",numero);
    scanf("%d",numero);
    printf("2 -%d\n",*numero);
}


void imprimirNumero(int numero){
    printf("3 -%x\n",&numero);
    printf("3 -%d\n",numero);
}

void imprimirNumeroQualquer(){
    int a;
    printf("4 -%x\n",&a);
    printf("4 -%d\n",a);
}