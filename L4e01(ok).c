#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laboratório de Algoritmos e técnicas de programação II - Turma 1
//Dev-C++ 5.11
//30/08/2017
//Lista 4 - Exercício 1
/* Escreva um programa que para ler um número inteiro n com vários digitos e que chama uma função recursiva ContaDigitos, passando o inteiro n, que conta e retorna quantos digitos o número tem.
Exemplo: o número 5429 possui 4 digitos
*/
int ContDigito(int numerox){
  if(numerox!=0)
  {
    return 1 + ContDigito(numerox/10);
    numerox=numerox/10;
  }
  return 0;
}
 int main(int argc, char const *argv[]) {
  int numero,chamada;
  puts("Digite o numero que deseja saber a quantidade de digitos:");
  scanf("%d",&numero);
  chamada = ContDigito(numero);
  printf("O numero %d possui %d digitos.\n",numero,chamada);
  return 0;
}
