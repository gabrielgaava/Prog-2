#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laboratório de Algoritmos e técnicas de programação II - Turma 1
//Dev-C++ 5.11
//23/08/2017
//Lista 3 - Exercício 4
/*Escrava a função SOMA que recebe duas matrizes A e B e 2 inteiros n e m(0<n,m<=100).As matrizes tem n linhas por m colunas. Devolve a matriz C que é a soma de A e B.*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void lermatriz(int a[10][10],int n, int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}
void escrevermatriz(int a[10][10],int n, int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%5d",a[i][j]);
		}
		puts("");
	}
}
void SOMA(int a[10][10],int b[10][10], int c[10][10],int n, int m){
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			c[i][j]=a[i][j]+b[i][j]; 
		}
	}
	
}
int main(int argc, char *argv[]) {
	int a[10][10],b[10][10],c[10][10],n,m;
	puts("Digite o numero de linhas:");
	scanf("%d",&n);
	puts("Digite o numero de colunas:");
	scanf("%d",&m);
	puts("Digite a matriz A:");
	lermatriz(a,n,m);
	puts("Digite a matriz B:");
	lermatriz(b,n,m);
	SOMA(a,b,c,n,m);
	puts("Matriz C=a+b:");
	escrevermatriz(c,n,m);
	return 0;
}
