#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Gustavo Henrique de Oliveira Villar
//Laboratório de Algoritmos e técnicas de programação II - Turma 1
//Dev-C++ 5.11
//06/09/2017
//Lista 5 - Exercício 2
/* Escrever uma função que recebe uma matriz Nomes, com N linhas, onde cada linha contém um nome de alunos de uma sala. A função deve colocar os nomes em ordem
crescente (usar a função ctrcmp que compara dois valores strings e a função strcpy que faz atribuição de valores do tipo string).
Utilizar o algoritmo de ordenação Bubble Sort visto em programação I para fazer a ordenação dos nomes.
*/
 void ordenar(char nomex[50][50],int tamanhox){
   int i j;
   char aux[50];
   for (i=1;i<tamanhox;i++)
   {
     for(j=0;j<tamanhox;j++)
     {
       if (strcmp(vet[j], vet[j+1]) >0)
       {
           strcpy(aux, vet[j]);
           strcpy(vet[j], vet[j+1]);
           strcpy(vet[j + 1], aux);
        }
     }
   }
 }
 int main(int argc, char const *argv[]) {
   char nomes[50][50];
   int tamanho,i,quantidade;
   puts("Digite a quantidade de nomes:");
   scanf("%d",&quantidade);
   puts("Digite os nomes:");
   for(i=0;i<quantidade;i=i+1)
   {
     getchar();
     scanf("%[^\n]",nomes[i]);
   }
   ordenar(nomes,quantidade);
   puts("Nomes ordenados");
   for(i=0;i<quantidade;i++)
   {
     printf("%s\n",nomes[i]);
   }
  return 0;
}
