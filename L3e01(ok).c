#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laborat�rio de Algoritmos e t�cnicas de programa��o II - Turma 1
//Dev-C++ 5.11
//23/08/2017
//Lista 3 - Exerc�cio 1
/*Escreva um programa que simule uma calculadora de 4 opera��es. Seu programa devera:
(a) - Ler dois n�meros e o operador;
(b) - Chamar uma fun��o com passagem de par�metros para efetuar os c�lculos;
(c) - Escrever o resultado final;
/*
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void foper(float *n1x, float *n2x, int operadorx,float *resultado){

	if(operadorx==0)
	{
		 *resultado = *n1x+*n2x;
	}
	else if(operadorx==1)
	{
		*resultado = *n1x-*n2x;
	}
	else if(operadorx==2)
	{
		*resultado = *n1x**n2x;
	}
	else if(operadorx==3)
	{
		*resultado = *n1x / *n2x;
	}

}
int main(int argc, char *argv[]) {
	int operador;
	float n1,n2,resultado;
	puts("Digite os dois numeros");
	scanf("%f",&n1);
	scanf("%f",&n2);
	puts("Informe a operacap\n0-Soma\n1-Subtracao\n2-Multiplicacao\n3-Divisao");
	scanf("%d",&operador);
	foper(&n1,&n2,operador,&resultado);
	printf("O resultado da operacao escolhida entre %.3f e %.3f = %.3f",n1,n2,resultado);

	return 0;
}
