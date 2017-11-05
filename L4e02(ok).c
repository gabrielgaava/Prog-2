#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laboratório de Algoritmos e técnicas de programação II - Turma 1
//Dev-C++ 5.11
//30/08/2017
//Lista 4 - Exercício 2
                                                                   //n
/* Escrever uma função recursiva para calcular a seguinte soma: soma=Σ i²*/
                                                                 //i=1
int potencia(int numero){
  if(numero>0)
  {
    return numero*numero + potencia(numero-1);
  }
  return 0;
}
 int main(int argc, char const *argv[]) {
  int numero,resultado;
  puts("Digite o numero maximo da somatoria:");
  scanf("%d",&numero);
  resultado = potencia(numero);
  printf("A somatoria dos quadrados dos primeiros %d numeros = %d\n",numero,resultado);
  return 0;
}
