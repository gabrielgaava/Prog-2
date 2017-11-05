#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Gustavo Henrique de Oliveira Villar
//Laboratório de Algoritmos e técnicas de programação II - Turma 1
//Dev-C++ 5.11
//06/09/2017
//Lista 5 - Exercício 1
/* Escrever uma função que recebe uma string str representando uma palavra e imprime todas as permutações circulares da palavra. A função não
deve utilizar string auxiliar.
Exemplo: Permutações circulares de AROMA ->
AAROM
MAARO
OMAAR                 5 Dígitos --> 5 permutações circulares
ROMAA
AROMA
*/
void permutador(char *palavra){
  int tamanho,i,j;
  char aux;
  tamanho = strlen(palavra);
  for(i=0;i<tamanho;i=i+1)
  {
    printf("%s\n",palavra);
    aux = palavra[0];
    for(j=1;j<tamanho;j=j+1)
    {
      palavra[j-1]=palavra[j];
    }
    palavra[tamanho-1]=aux;
  }
}
 int main(int argc, char const *argv[]) {
   char str[50];
   puts("Digite a palavra:");
   getchar();
   scanf("%[^\n]", &str);
   permutador(str);
  return 0;
}
