/* Gustavo Henrique de Oliveira Villar
Turma 01
Dev-Cpp
20/09/2017
Lista 7 - Exercicío 3
*/

int boyerMoore (char *word, char *text) {
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
