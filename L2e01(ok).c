#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laborat�rio de Algoritmos e t�cnicas de programa��o II - Turma 1
//Dev-C++ 5.11
//16/08/2017
//Lista 2 - Exerc�cio 1
/* Escreva uma Fun��o que, dado n inteiro positivo, devolva a soma 1+2+...+n.Chame esta fun��o a partir do programa principal*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int fsoma(int x)
{
	int contador,somax;
	somax=0;
	for(contador=1;contador<=x;contador++)
	{
		somax=somax+contador;
	}
	return somax;
}
int main(int argc, char *argv[]) {
	int n,soma;
	puts("Digite o numero que deseja:");
	scanf("%d",&n);
	soma = fsoma(n);
	printf("A soma dos %d primeiros numeros inteiros e %d\n",n,soma);
	return 0;
}
