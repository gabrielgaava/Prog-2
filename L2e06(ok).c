#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Gustavo Henrique de Oliveira Villar
//Laboratório de Algoritmos e técnicas de programação II - Turma 1
//Dev-C++ 5.11
//16/08/2017
//Lista 2 - Exercício 6
/*
(a) Cosntrua uma funçao encaixa que dados dois inteiros positivos a e b verifica se b corresponde aos ultimos digitos de a.

a			b		
567890		890		=>	Encaixa
1243		1243	=>	Encaixa
2457		245		=>	Não Encaixa
457			2457	=>	Não Encaixa

(b) Usando a funçao do item anterior, faça um programa que le dois inteiros positivos a e b e verifica se o menor deles é segmento do outro. Exemplo:

a			b
567890		890		=>	b é segmento de a
1243		2212435	=>	a é segmento de b
235			236		=>	um nao é segmento do outro
0
*/
int encaixa(int ax,int bx)
{
	int digitosa,digitosb;
	digitosa=digitosb=0;
	//Contando digitos de A
	do
	{
		digitosa=digitosa+1;
		ax=ax/10;
		
	}while(a !=0);
	//Contando Digitos de B
	do
	{
		digitosb=digitosb+1;
		bx=bx/10;
		
	}while(b !=0);
	if(digitosa>digitosb)
	{
		do
		{
			ax=ax/10
		}while(digitosa>digitosb)
	}
}

int main(int argc, char *argv[]) {
	int a,b,op,resultado;
	puts("Digite o que deseja fazer:\n1-(a)\n2-(b)");
	scanf("%d",&op);
	puts("Digite o valor de a:")
	scanf("%d",&a);
	puts("Digite o valor de b:")
	scanf("%d",&b);
	if(op==1)
	{
		resultado = encaixa(a,b);	
	}
	
	return 0;
}
