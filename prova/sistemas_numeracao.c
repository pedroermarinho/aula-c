/*
1. Sistema de numeração
Existem diferentes tipos de sistemas de numeração, sendo os mais conhecidos os sistemas binário, octal, decimal e hexadecimal. O sistema decimal é o mais utilizado no dia a dia dos seres humanos. Os sistemas binário, octal e hexadecimal são mais utilizados na área da computação. Nesse sentido, você deverá escrever um programa que leia um número inteiro N e mostre o valor desse número em binário, octal e hexadecimal.

 

Exemplo de entrada:
27

Exemplo de saída:
Binario 11011
Octal 33
Hexadecimal 1B

Exemplo de entrada:
131

Exemplo de saída: 
Binario 10000011
Octal 203
Hexadecimal 83
*/
#include <stdio.h>

void toBinario(int num);
void toOctal(int num);
void toDecimal(int num);
void toHexadecimal(int num);
int main(void){
    int num;
    int octal;
    printf("Digite um numero inteiro:");
    scanf("%i",&num);
    toBinario(num);
    toOctal(num);
    toDecimal(num);
    toHexadecimal(num);
    printf("\n");
return 0;
}

void toBinario(int num){
	int num_local = num;
	int vet_bin[8];

	int i = 0, j;

	while(num_local > 0)
	{
		vet_bin[i] = num_local % 2;
		i++;
		num_local = num_local / 2;
	}

    printf("\nBinario ");
	for(j = i - 1; j >= 0; j--)
		printf("%d", vet_bin[j]);
}
void toOctal(int num){
    int i = 1,a,n=num; //i inicializado a 1
    int octal = 0; //octal inicializado a 0

    if(n<=7) {
        octal=n;
    }
    else {
        while(n>=8) {
            a=n%8;
            n=n/8;
            octal = octal + a * i; //calculo do octal
            i *= 10; //aumento do fator de base 10
        }
        n=n%8;
        octal = octal + n * i; //mesmo calculo aqui
    }
    printf("\nOctal %d",octal);
}
void toDecimal(int num){
    printf("\nDecimal %d",num);
}
void toHexadecimal(int num){
    printf("\nHexadecimal %X",num);
}