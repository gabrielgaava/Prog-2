#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laboratório de Algoritmos e técnicas de programação II - Turma 1
//Dev-C++ 5.11
//30/08/2017
//Lista 4 - Exercício 7

/* O fatorial duplo de um número natural n é o produto de todos os números de 1 (ou 2) até n, contados de 2 em 2.
Exemplo: O fatorial duplo de 8 é 8*6*4*2 = 384. E o fatorial duplo de 7 é 7*5*3*2*1 = 105.
Defina uma função recursiva para calcular o fatorial duplo de um número natural usando recursividade.
*/

int fat(int n)
{
 if (n>0)
     return n*fat(n-2);
 else return 1;
}
int main()
{
 int n;
 puts("Digite o numero que deseja calcular o fatorial duplo: ");
 scanf("%d", &n);
 printf("\nO fatorial duplo de %d e' %d", n, fat(n));
 return 0;
}
