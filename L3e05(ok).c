#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laborat�rio de Algoritmos e t�cnicas de programa��o II - Turma 1
//Dev-C++ 5.11
//23/08/2017
//Lista 3 - Exerc�cio 5
/*Escreva uma função que recebe inteiro n (0<n<=100) e um vetor de m elementos e imprime todas as subsequencias crescentes neste vetor. Exemplo 3 5 8 2 6 4 8
tem as seguintes subsequencias crescentes:
3 5 8
2 6
4 8
*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void lervetor(int * vetor, int qtd){
	int i;
	for(i = 0; i < qtd; i++)
  {
		printf("\nDigite o elemento de numero %d do Vetor =  ",i+1);
		scanf("%d",(vetor+i));
	}
}
void funcao(int *vetor, int qtd){
	int i;
	for(i = 0; i < qtd; i++){
    if(*(vetor+i) <= *(vetor+1+i))
    {
		    printf("%d",*(vetor+i));
    }
    else{
        printf("%d",*(vetor+i));
        puts("");
    }
	}
}
int main(){

  int vetor[100], qtd;

  printf("Qual o tamanho do vetor : ");
  scanf("%d",&qtd);
  lervetor(vetor, qtd);
  funcao(vetor,qtd);

  return 0;

}
