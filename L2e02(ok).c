#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laboratório de Algoritmos e técnicas de programação II - Turma 1
//Dev-C++ 5.11
//16/08/2017
//Lista 2 - Exercício 2
/*Escreva um programa que pede dois inteiros ao usúario e permite que o usuário 
escolha qual operaçao a executar com esses dois numeros: (1)soma,(2)subtraçao,
(3)multiplicaçao e (4) divisao. Cada uma das operaçoes deve ser implementada como uma funçao separada que retorna o valor calculado.
Toda a comunicaçao com o usuario (leitura e escrita) deve ser feita no programa principal.
*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float fsoma(float x,float y)
{
	float resposta;
	resposta = x+y;
	return resposta;
}
float fsub(float x,float y)
{
	float resposta;
	resposta = x-y;
	return resposta;
}
float fmulti(float x,float y)
{
	float resposta;
	resposta = x*y;
	return resposta;
}
float fdiv(float x,float y)
{
	float resposta;
	resposta = x/y;
	return resposta;
}
int main(int argc, char *argv[]) {
	float a,b,resultado;
	int op;
	puts("Digite dois numeros");
	scanf("%f",&a);
	scanf("%f",&b);
	puts("Digite a operacao desejada:\n1-Soma\n2-Subtracao\n3-Multiplicacao\n4-Divisao");
	scanf("%d",&op);
	if(op==1)
	{
		resultado = fsoma(a,b);
		printf("A soma de %.3f com %.3f e %.3f",a,b,resultado);
	}
	if(op==2)
	{
		resultado = fsub(a,b);
		printf("A sub de %.3f com %.3f e %.3f",a,b,resultado);
	}
	if(op==3)
	{
		resultado = fmulti(a,b);
		printf("A multiplicacao de %.3f com %.3f e %.3f",a,b,resultado);
	}
	if(op==4)
	{
		resultado = fdiv(a,b);
		printf("A divisao de %.3f com %.3f e %.3f",a,b,resultado);
	}
	
	return 0;
}
