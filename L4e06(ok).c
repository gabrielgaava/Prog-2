#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laboratório de Algoritmos e técnicas de programação II - Turma 1
//Dev-C++ 5.11
//30/08/2017
//Lista 4 - Exercício 6

/*Defina uma função recursiva que recebe dois números naturais m e n e retorna o produto de todos os números no invertalo [m,n]: m * (m+1)*...*(n-1)*n.
Exemplo: Dado o intervalo [5,10] a função deve calcular 5*6*7*8*9*10
*/
int multipli(int n1, int n2){
  if(n1<n2)
  {
    return n1 * multipli(n1+1,n2);
  }
  else if (n1==n2)
  {
    return n2;
  }
  else
  {
    return multipli(n2,n1);
  }
}
 int main(int argc, char const *argv[]) {
  int minimo,maximo,resultado;
  puts("Digite o menor numero do intervalo:");
  scanf("%d",&minimo);
  puts("Digite o maior numero do intervalo:");
  scanf("%d",&maximo);
  resultado = multipli(minimo,maximo);
  printf("A multiplicacao dos valores no intervalo [%d,%d] = %d",minimo,maximo,resultado);

  return 0;
}
