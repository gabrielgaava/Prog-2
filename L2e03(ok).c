#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laboratório de Algoritmos e técnicas de programação II - Turma 1
//Dev-C++ 5.11
//16/08/2017
//Lista 2 - Exercício 3
/*Resolva o problema abaixo:
(a) Escreva uma função que recebe um inteiro positivo m e devolve 1 se m é primo, 0 em caso contrário;
(b) Escreva um programa que leia um inteiro naão negativo n e imprima a soma dos n primeiros numeros primos;
*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int fprimo(int x){
	int contador,divisor;
	contador = 0;
	for (divisor =1;divisor<=x;divisor++)
	{
		if(x%divisor==0)
		{
			contador = contador +1;
		}
	}
	if(contador==2)
	{
		return 1;
	}
	else if (contador != 2)
	{
		return 0;
	}

int fsoma(int x){
	int contador1,divisor,contador2,soma,numero;
	contador2=0;
	soma=0;
	numero=1;
	while (contador2 <= x)
	{
		contador1=0;
		for(divisor =1;divisor<=numero;divisor++)
		{
			if(numero%divisor==0)
			{
				contador1=contador1 + 1;
			}
			
		}
		if (contador1==2)
		{
			contador2=contador2+1;
			soma=soma+numero;
		}
	}
	return soma;
}
	

int main(int argc, char *argv[]) {
	int m,op,resposta;
	puts("Digite a opcao desejada:\n1-Verificar se um numero e primo\n2-Somar os n primeiros primos");
	scanf("%d",&op);
	//(a)
	if(op==1)
	{
		puts("Digite o numero:");
		scanf("%d",&m);
		resposta = fprimo(m);
		if(resposta == 1 )
		{
			printf("O numero %d eh primo",m);
		}
		else if (resposta == 0 )
		{
			printf("o numero %d nao eh primo",m);
		}
	}
	//(b)
	if(op==2)
	{
		puts("Digite a quantidade de numeros");
		scanf("%d",m);
		resposta = fsoma(m);
		printf("A soma dos primeiros %d numeros primos eh %d\n",m,resposta);
	}

	return 0;
}
