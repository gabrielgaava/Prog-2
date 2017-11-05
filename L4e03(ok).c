#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laboratório de Algoritmos e técnicas de programação II - Turma 1
//Dev-C++ 5.11
//30/08/2017
//Lista 4 - Exercício 3

/*Faça uma função recursiva que recebe um número inteiro positivo e retorna a soma de todos os números de 1 até o número recebido, ou seja 1+2+3+...+n*/
int soma(int numero){
  if(numero>0)
  {
    return(numero+(numero-1))+soma(numero-2);
  }
  return 0;
}
 int main(int argc, char const *argv[]) {
  int numero,resultado;
  puts("Digite o numero limite da somatoria:");
  scanf("%d",numero);
  resultado = soma(numero);
  printf("A soma dos %d primeiros numeros = %d\n",numero,resultado);
  return 0;
}
