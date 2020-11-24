/*
(2)faça programa que cadastre 3 números e exiba maior dentre eles
*/
//Pedro Marinhos
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void cadastrar();
void maior_numero(int num1, int num2,int num3);
void result_msg(int result);

int main(void)
{
    setlocale(LC_ALL,"Portuguese");
    cadastrar();
    getchar();
    return 0;
}
void cadastrar()
{
    int num1;
    int num2;
    int num3;
    printf("\nDigite um número:\n");
    printf(">");
    scanf("%d", &num1);
    printf("\nDigite outro número:\n");
    printf(">");
    scanf("%d", &num2);
    printf("\nDigite mais um número:\n");
    printf(">");
    scanf("%d", &num3);
    maior_numero(num1, num2, num3);
}
void maior_numero(int num1, int num2,int num3){
    int result =num1;

    if(result<num2)
        result =num2;
    
    if (result<num3)
        result =num3;

   result_msg(result); 
    
}
void result_msg(int result)
{
    printf("\n%d é o maior número encontrado\n",result);
}