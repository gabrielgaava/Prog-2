#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laborat�rio de Algoritmos e t�cnicas de programa��o II - Turma 1
//Dev-C++ 5.11
//23/08/2017
//Lista 3 - Exerc�cio 3
/*Procedimento que recebe n e m inteiros(0<n,m<=100) e dois vetores A e B de n e m elementos respectivamente j� ordenados e devolve o vetor C de n+m elementos contendo os elementos de A e B
ordenados. O procedimento n�o deve fazer ordena�ao. Deve usar a informa�ao que os vetores estao ordenados e fazer a intercala�ao apropriada de elementos de A e B, copiando-os para o vetor C.
O programa principal deve ler os dados, chamar adequadamente a fun�ao e escrever os resultados.*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void lervetor(int vetor[], int qtd)
{
	int i;
	for(i=0;i<qtd;i++)
	{
		printf("Digite o valor %d do vetor:\n",i+1);
		scanf("%d",&vetor[i]);
	}
}
void imprimirvetor(int vetor[], int qtd)
{
	int i;
	for(i=0;i<qtd;i++)
	{

		printf("%5d",vetor[i]);
	}
	puts("");
}
void ordenador(int a[100],int b[100],int c[200],int n, int m, int z)
{
	int i,j,x;
	i=0;
	j=i;
	x=j;
	for(x=0;x<z;x++)
	{
		if(a[i]>b[j])
		{
			c[x]=b[j];
			j++;
		}
		else if (b[j]>a[i])
		{
			c[x]=a[i];
			i++;
		}
	}
}
int main(int argc, char *argv[]) {
	int a[100],b[100],c[200],n,m,z;
	puts("Digite o tamanho do vetor A:");
	scanf("%d",&n);
	puts("Digite o tamanho do vetor B:");
	scanf("%d",&m);
	z=n+m;
	puts("Digite o vetor A ja ordenado:");
	lervetor(a,n);
	puts("Digite o vetor B ja ordenado:");
	lervetor(b,m);
	ordenador(a,b,c,n,m,z);
	puts("Impressao do vetor C:");
	imprimirvetor(c,z);
	return 0;
}
