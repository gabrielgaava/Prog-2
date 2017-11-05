/* Gustavo Henrique de Oliveira Villar
Turma 01
Dev-Cpp
13/09/2017
Lista 6 - Todos exercícios
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // Alguns comandos uteis para se trabalhar com strings

int ler_nomes(char nomes[100][100], int cont){
  int i;
  for(i=0;i<cont;i++)
  {
    printf("Digite o nome de numero %d:\t",i+1);
    getchar();
    scanf("%[^\n]",nomes[i]);
    puts("");
  }
}

int copiar_nomes(char nomes[100][100], char copia[100][100], int cont){
  int tamanho,i,j;
  for(i=0;i<cont;i++)
  {
    tamanho= strlen(nomes[i]);
    for(j=0;j<tamanho;j++)
    {
      copia[i][j]=nomes[i][j];
    }
  }
  puts("Nomes Copiados com Sucesso!");
  puts("");
}

int minusculas(char nomes[100][100], int cont){
  int tamanho,i,j;
  for(i=0;i<cont;i++)
  {
    tamanho= strlen(nomes[i]);
    for(j=0;j<tamanho;j++)
    {
      nomes[i][j]=tolower(nomes[i][j]);
    }
  }
  puts("Letras convertidas para minusculas com Sucesso!");
  puts("");
}

int buscar_palavra(char *texto, char *palavra, int *posicoes){
  int tamanho_texto, tamanho_palavra, i,j,k, ocorrencia, cont;
  ocorrencia = cont = 0;
  tamanho_texto = strlen(texto);
  tamanho_palavra = strlen(palavra);
  for(k=tamanho_palavra-1;k<tamanho_texto;k++)
  {
    j=k;
    cont=0;
    for(i=tamanho_palavra-1;i>=0;i--)
    {
      if(palavra[i]==texto[j])
      {
        cont++;
        j--;
      }
    }
  }
}

int remover_caracter(char *texto, int quant, int inicio)
{
  int i,tamanho;
  tamanho = strlen(texto);
  if(inicio>tamanho || quant + inicio > tamanho)
  {
    return 0;
  }
  for(i=quant+inicio; i<=tamanho;i++)
  {
    texto[i-quant] = texto[i];
  }
  return 1;
}

int remover_ligacao(char *texto, int cont)
{
  //Definindo o que sao palavras de ligacao.
  char palavras[13][8] = { {"das"}, {"da"}, {"di"}, {"dos"}, {"do"}, {"del"}, {"de"}, {"la"}, {"junior"}, {"filho"}, {"neto"}};
  int i,j, pos[100], contador;
  for(i=0;i<11;i++)
  {
    contador = 0;
    contador = buscar_palavra(texto,palavras[i],pos);
    for(j=0;j<contador;j++)
    {
      remover_caracter(texto,strlen(palavras[i]), pos[j]-strlen(palavras[j])+1);
    }
  }
}

int remover_brancos(char *texto){
  int i,j,tamanho;
  tamanho = strlen(texto);
  for(i=0;i<tamanho;i++)
  {
    if (texto[i]==' ')
    {
      j=i;
      while(texto[j]==' ')
      {
        j++;
      }
      remover_caracter(texto, (j-i-1), i+1);
    }
  }
  if(texto[0]==' ')
  {
    remover_caracter(texto,1,0);
  }
  tamanho = strlen(texto);
  if(texto[tamanho-1]==' ')
  {
    remover_caracter(texto,1,(tamanho-1));
  }
  return 1;
}

void imprimir_nomes(char nomes[100][100], char copia[100][100], int cont){
  int i,j,tamanho1,tamanho2;
  for(i=0;i<cont;i++)
  {
    tamanho1 = strlen(nomes[i]);
    tamanho2 = strlen(copia[i]);
    printf("Nome formatado: ");
    for(j=0;j<tamanho2;j++)
    {
      printf("%c",copia[i][j]);
    }
    puts("");
    printf("Nome nao formatado: ");
    for(j=0;j<tamanho1;j++)
    {
      printf("%c", nomes[i][j]);
    }
    puts("");
    puts("");
  }
}

void ref_biblio(char *texto){
  int i,j,k,tamanho,espaco;
  espaco=0;
  tamanho=strlen(texto);
  for(i=0;i<tamanho;i++)
  {
    if(texto[i]==' ')
    {
      espaco++;
    }
  }
  for(i=0;i<espaco;i++)
  {
    for(k=0;k<tamanho;k=k+3)
    {
      j=k;
    }
    while(texto[j]!=' ')
    {
      j++;
    }
    remover_caracter(texto,j-k-2,k+3);
  }
  k=0;
  for(i=0;i<espaco;i++)
  {
    texto[k]=toupper(texto[k]);
    texto[k+1]='.';
    texto[k+2]=' ';
    k=k+3;
  }
  texto[k]=toupper(texto[k]);
}

int main(int argc, char const *argv[]) {
  char nomes[100][100],copia[100][100];
  int i,cont;
  puts("Formatador de nomes:\t");
  printf("Digite a quantidade de nomes:\t");
  scanf("%d",&cont);
  puts("");
  ler_nomes(nomes,cont);
  //Copia para nao perder os nomes
  copiar_nomes(nomes,copia,cont);
  //Converter para letras minusculas
  minusculas(nomes,cont);
  //Fazendo de fato a formatacao do texto:
  for(i=0;i<cont;i++)
  {
    remover_ligacao(nomes[i],cont);
    remover_brancos(nomes[i]);
    ref_biblio(nomes[i]);
  }
  puts("Imprimindo nomes formatados:");
  imprimir_nomes(copia,nomes,cont);
  return 0;
}
