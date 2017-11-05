#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laboratório de Algoritmos e técnicas de programação II - Turma 1
//Dev-C++ 5.11
//16/08/2017
//Lista 2 - Exercício 5
/*
Faça uma função que recebe a média final de um aluno como parametro e retorna o seu conseito, conforme a tabela abaixo:
Nota		Conceito
0.0-4.9  -		D 
5.0-6.9  -		C
7.0-8.9  -		B
9.0-10.0 -		A
*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int conceito(float media)
{
	if(media > 0.0 && media < 5.0)
	{
		return 0;
	}
	else if(media >= 5.0 && media < 7.0)
	{
		return 1;	
	}
	else if(media >= 7.0 && media < 9.0)
	{
		return 2;
	}
	else if(media >= 9.0)
	{
		return 3;
	}
}
int main(int argc, char *argv[]) {
	float media,conc;
	puts("Digite a media final do aluno");
	scanf("%f",&media);
	conc=conceito(media);
	if (conc==0)
	{
		printf("A media do aluno e %.2f portanto seu conceito e D\n",media);
	}
	if (conc==1)
	{
		printf("A media do aluno e %.2f portanto seu conceito e C\n",media);
	}
	if (conc==2)
	{
		printf("A media do aluno e %.2f portanto seu conceito e B\n",media);
	}
	if (conc==3)
	{
		printf("A media do aluno e %.2f portanto seu conceito e A\n",media);
	}
	return 0;
}
