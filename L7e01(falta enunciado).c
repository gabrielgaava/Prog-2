/* Gustavo Henrique de Oliveira Villar
Turma 01
Dev-Cpp
20/09/2017
Lista 7 - Exercicío 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BoyerMoore (char *word, char *text) {
    int wordSize, textSize, i, j, k, alphabet[256], occur = 0;

    wordSize = strlen(word);
    textSize = strlen(text);

    for(i=0; i<256; i++) alphabet[i] = -1;
    for(i=0; i<wordSize; i++) alphabet[word[i]] = i;

    k = wordSize-1;

    while(k<textSize) {
        i = wordSize - 1;
        j = k;
        while(i>=0 && word[i]==text[j]) {
            i--;
            j--;
        }
        if (i<0) occur++;
        k = k + wordSize - alphabet[text[k+1]];
    }

    return occur;
}

int main(int argc, char const *argv[]) {
  char texto[1000],palavra[100];
  int contador;
  printf("Digite o texto que deseja:\t");
  scanf("%[^\n]", texto);
  getchar();
  puts("");
  printf("Digite a palavra que deseja procurar no texto:\t");
  scanf("%[^\n]", palavra);
  getchar();
  puts("");
  contador = BoyerMoore(palavra,texto);
  printf("A palavra '%s' aparece %d vezes no texto.\n",palavra,contador);
  return 0;
}
