/*
Mesa redonda
Ana, Beatriz e Carolina sempre saem juntas para tomar café numa padaria onde as mesas são circulares e têm três cadeiras numeradas 0, 1 e 2, no sentido anti-horário, como ilustrado na figura ao lado.

Elas gostam de decidir quem vai sentar em qual cadeira com uma brincadeira gerando números aleatórios nos seus celulares. Primeiro Ana sorteia um número inteiro A e, começando da cadeira 1, seguindo no sentido anti-horário, conta A cadeiras e senta na cadeira em que a contagem terminar. Depois Beatriz sorteia um número B e faz a mesma coisa: começando da cadeira 1, no sentido anti-horário, conta B cadeiras. Se a cadeira final estiver livre, Beatriz senta nela. Caso seja a cadeira onde Ana está sentada, então Beatriz senta na próxima cadeira no sentido anti-horário. Claro, ao final, Carolina senta na cadeira que estiver livre.


Por exemplo, se Ana sortear 8, ela vai contar [1,2,0,1,2,0,1,2] e sentar na cadeira 2. Depois, se Beatriz sortear 6, ela vai contar [1,2,0,1,2,0] e sentar na cadeira 0. Assim, Carolina senta na cadeira 1. Num outro exemplo, se Ana sortear 3, ela vai contar [1,2,0] e sentar na cadeira 0. Depois, se Beatriz sortear 9, ela vai contar [1,2,0,1,2,0,1,2,0] e, como Ana já está sentada na cadeira 0, Beatriz senta na cadeira 1. Dessa forma, Carolina senta na cadeira 2.

Neste problema, dados os números sorteados por Ana e Beatriz, seu programa deve imprimir o número da cadeira onde Carolina vai sentar.

Entrada
A primeira linha da entrada contém um inteiro A representando o número sorteado por Ana. A segunda linha da entrada contém um inteiro B representando o número sorteado por Beatriz.

Saída
Seu programa deve imprimir uma linha contendo um número inteiro indicando a cadeira onde Carolina vai sentar.

Restrições
1 ≤ A ≤ 1000
1 ≤ B ≤ 1000
Exemplos
Entrada
8
6
Saída
1
	
 

Entrada
3
9
Saída
2
	
 
*/

#include <stdio.h>

int cadeiraOcupada(int x){
    int result;
     int i,cont=0,cont2= 0;
        for ( i = 0; i < x; i++)
        {
            cont ++;
            if (cont<=2)
            {
                cont2 = cont;
                
            }else
            {
                cont=0;
                cont2= cont;
                
            }
            
        }
        result = cont2;
    return result;
}

int main(int argc, char const *argv[])
{
    int a, b;

    int C0=0, C1=0, C2=0;
    scanf("%d",&a);
    scanf("%d",&b);
   
    if (1 <= a && a <=1000 && 1 <= b && b <=1000)
    {
       int resultA = cadeiraOcupada(a);
       switch (resultA)
        {
        case 0:
            C0 =1;
            break;
        case 1:
            C1 =1;
            break;
        case 2:
            C2 =1;
            break;
        
        default:
            break;
        }
       int resultB = cadeiraOcupada(b);
        switch (resultB)
        {
        case 0:
            if (C0)
            {
                C1 =1;
            }else
            {
               C0 =1; 
            }
            break;
        case 1:
            if (C1)
            {
                C2 =1;
            }else
            {
               C1 =1; 
            }
            break;
        case 2:
            C2 =1;
            if (C2)
            {
                C0 =1;
            }else
            {
               C2 =1; 
            }
            break;
        
        default:
            break;
        }

        if (!C0)
        {
            printf("0\n");
        }
        if (!C1)
        {
            printf("1\n");
        }
        if (!C2)
        {
            printf("2\n");
        }
        
    }
    


    return 0;
}