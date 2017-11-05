#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laborat�rio de Algoritmos e t�cnicas de programa��o II - Turma 1
//Dev-C++ 5.11
//23/08/2017
//Lista 3 - Exerc�cio 2
/*Fun��o que recebe inteiro n (0<n<=100), um vetor de elementos reais e x e devolve quantas vezes x ocorre no vetor de n elementos. A fun��o retorna o c�lculo efetuado.Oprograma deve ler os
dados e mostrar as sa�das*/
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
void verificador(int vetor[], int qtd, int x, int *contador){
	int i;
	*contador=0;
	for(i=0;i<qtd;i++)
	{
		if(x==vetor[i])
		{
			*contador=*contador+1;
		}
	}

}

int main(int argc, char *argv[]) {
	int vetor[100],x,qtd,contador;
	puts("Digite a quantidade de elementos que deseja no vetor:");
	scanf("%d",&qtd);
	lervetor(vetor,qtd);
	puts("Digite o valor que deseja ver quantas vezes esta presente no vetor:");
	scanf("%d",&x);
	verificador(vetor,qtd,x,&contador);
	printf("O valor %d aparece %d vezes no vetor digitado.\n",x,contador);
	return 0;
}
