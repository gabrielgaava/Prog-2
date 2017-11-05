#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laboratório de Algoritmos e técnicas de programação II - Turma 1
//Dev-C++ 5.11
//16/08/2017
//Lista 2 - Exercício 4
/*
(a) Escreva uma função que recebe como parametros dois numeros a e b e devolve o mdc(máximo divisior comum) de a e b, calculado por meio do algoritmo de Euclides.
(b) Escreva um programa que leia um inteiro positivo n e uma sequencia de n inteiros nao negativos e imprime o mds de todos os numeros da sequencia.
*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int mdc(int x,int y){
	int aux;
	aux=x%y;
	while(aux!=0)
	{
		x=y;
		y=aux;
		aux=x%y;
	}
	return y;
}

int mdcn(int qtd){
	int contador,mdc,x,y,aux;
	puts("Digite o primeiro numero da sequencia:");
	scanf("%d",&mdc);
	contador=1;
	while(contador < qtd)
	{
		printf("Digite o numero %d da sequencia:\n",contador+1);
		scanf("%d",x);
		contador=contador +1;
		aux=1;
		while (aux <= mdc && aux <= x)
		{
			if(mdc%aux==0 && x%aux==0)
			{
				y=aux;
			}
			aux=aux+1;	
		}
		mdc=y;
	}
	return mdc;
}
int main(int argc, char *argv[]) {
	int n1,n2,op,resposta;
	puts("Digite a opcao:\n1-MDC entre 2 numeros\n2-MDC entre n numeros");
	scanf("%d",&op);
	//(a)
	if(op==1)
	{
		puts("Digite os dois valores:");
		scanf("%d",&n1);
		scanf("%d",&n2);
		resposta=mdc(n1,n2);
		printf("O MDC entre %d e %d = %d",n1,n2,resposta);	
	}
	else if (op==2)
	{
		puts("Digite o valor de n");
		scanf("%d",&n1);
		resposta=mdcn(n1);
		printf("O MDC entre os %d numeros digitados e igual a %d",n1,resposta);
	}
	return 0;
}
