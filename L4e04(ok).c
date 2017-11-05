#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laboratório de Algoritmos e técnicas de programação II - Turma 1
//Dev-C++ 5.11
//30/08/2017
//Lista 4 - Exercício 4

/*Dado um número inteiro n, escreva uma funçao recursica chamada somaDigitos, que recebe n e calcula a soma dos dígitos de n.
Exemplo: para o número 5321, a função deverá retornar 5+3+2+1=11.
*/
int SomaDigitos(int numero)
{
  if(numero != 0)
  {
    return numero%10 + SomaDigitos(numero/10);
    numero=numero/10;
  }
  return 0;
}
 int main(int argc, char const *argv[]) {
  int numero, resultado;
  puts("Digite o numero que deseja somar os digitos:");
  scanf("%d",&numero);
  resultado=SomaDigitos(numero);
  printf("A soma dos digitos de %d e %d",numero,resultado);
  return 0;
}
