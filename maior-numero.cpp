#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void setNum();
void maiorNumero(int a, int b,int c);
void imprimirMsg(int x);

int main(void)
{
    setlocale(LC_ALL,"UTF-8");
    setNum();
    return 0;
}
void setNum()
{
    int a;
    int b;
    int c;
    printf("\nDigite um número:\n");
    printf(">");
    scanf("%d", &a);
    printf("\nDigite outro número:\n");
    printf(">");
    scanf("%d", &b);
    printf("\nDigite mais um número:\n");
    printf(">");
    scanf("%d", &c);
    maiorNumero(a, b, c);
}
void maiorNumero(int a, int b,int c){
    int maior =a;

    if(maior<b){
        maior =b;
    }
    if (maior<c)
    {
        maior =c;
    }

   imprimirMsg(maior); 
    
}
void imprimirMsg(int x)
{
    printf("\n%d é o maior número encontrado\n",x);
}