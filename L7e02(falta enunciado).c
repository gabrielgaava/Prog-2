/* Gustavo Henrique de Oliveira Villar
Turma 01
Dev-Cpp
20/09/2017
Lista 7 - Exercicío 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Código dado pelo exercício.
int boyer (char *a, char *b) {

    int ult[256];

    int ocorrs = 0, m, n, k, i, j;

    m = strlen(a);
    n = strlen(b);

    k = m-1;

    for(i=0; i<256; ++i) ult[i] = 0;
    for(i=0; i<m; ++i) ult[a[i]] = i;

    while (k<n) {
        i = m-1;
        j = k;
        while (i>=0 && a[i] == b[j]) {
            --i;
            --j;
        }
        if (i<0) ++ocorrs;
        k+= m-ult[b[k + 1]];
    }
    return ocorrs;
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
  contador = boyer(palavra,texto);
  printf("A palavra '%s' aparece %d vezes no texto.\n",palavra,contador);
  return 0;
  puts("O codigo nao funciona pois os indices estavam errados.")
}
