#include <stdio.h>
#include <stdlib.h>
//Gustavo Henrique de Oliveira Villar
//Laboratório de Algoritmos e técnicas de programação II - Turma 1
//Dev-C++ 5.11
//30/08/2017
//Lista 4 - Exercício 5

/*Desenvolva algortimos recursivos para os seguintes problemas:
a. Conversão de um número natural em base binária.
b.Cálculo de: 2 + 5 + 10 + 17 + 26 + (n²+1)
              -   -   -    -    -    -----
              4   5   6    7    8    (n+3)
*/
long int binario(int n)
{
  if (n!=0)
  {
    return n%2 + binario(n/2)*10;
  }
  else {
    return 0;
  }
}
float soma(int n){
  if(n!=0)
  {
    return (n*n+1)/(n+3) + soma(n-1);
  }
  else
  {
    return 0;
  }
}

 int main(int argc, char const *argv[]) {
    int op,n;
    long int numero;
    puts("Digite a opcao desejada:\n1-Converter decimal em binário.\n2-Fazer a sequencia desejada.");
    if (op==1)
    {
      puts("Digite o valor de n:");
      scanf("%d",&n);
      numero = binario(n);
      printf("O numero %d em binario e %d.\n",n,numero);
    }
    else if(op==2)
    {
      puts("Digite o valor de n:");
      scanf("%d",&n);
      numero = soma(n);
      printf("Resposta = %.3f\n",soma);
    }
  return 0;
}
