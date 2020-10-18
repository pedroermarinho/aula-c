/*
(2)faça programa que cadastre 3 números e exiba maior dentre eles
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

void cadastrar(int *x,int *y,int *w);
void maior(int x,int y,int w, int *maior);
void imprimir(int maior);

main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	int x=0,y=0,w=0;
	int maiorNum=0;
	
	cadastrar(&x,&y,&w);
	maior(x,y,w,&maiorNum);
	
	printf("\nx %d",x);
	printf("\ny %d",y);
	printf("\nw %d",w);
	imprimir(maiorNum);
	
	printf("\n");
	system("pause");
}


void cadastrar(int *x,int *y,int *w){
	int i,j,k;
	printf("\nsistema de cadastro\n");
	printf("\nprimeiro numero:");	
	scanf("%d",&i);
	printf("\nsegundo numero:");
	scanf("%d",&j);
	printf("\nterceiro numero:");
	scanf("%d",&k);
	
	*x = i;
	*y = j;
	*w = k;
}
void maior(int x,int y,int w, int *maior){
	int result = x;
	
	if(result<y){
		result = y;
	}
	if(result<w){
		result = w;
	}
	
	*maior = result;
	
}
void imprimir(int maior){
	printf("\nMaior numero é %d\n", maior);
}
