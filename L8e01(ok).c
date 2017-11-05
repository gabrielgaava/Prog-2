/* Gustavo Henrique de Oliveira Villar
Turma 01
Dev-Cpp
18/10/2017
Lista 8 - Todos exercícios
*/
/*
1) Implementar a função de busca sequencial visto em aula que, dado um vetor, e um elemento x, a função retorna a posição do vetor onde o elemento foi encontrado. Caso o elemento não esteja no
no vetor, a função retorna -1.

2) Implementar a função de busca binária visto em aula. A busca binária requer que o seu vetor esteja ordenado. Dado um vetor ordenado e um elemento x, a função retorna a posição do vetor onde x
foi encontrado. Caso o elemento não esteja no vetor, a função devolve -1.

3) Implementar uma função chamada GerarVetorAleatoriamente(int V[], int n) que gera números aleatórios e os atribui a um vetor usando a função rand() da seguinte forma:
						numero = INT_MAX*rand() / (RAND_MAX + 1.0);

4) Implementar uma função chamada verifica ordem, a qual verifica se os elementos de um vetor estão de fato ordenados, devolvendo 1 se os elementos estão em ordem crescente, caso contrário devolve
0. Essa função será utilizada para testar as implementações dos métodos de ordenação.
		int verificaOrdem (int *v, int n);

5) Implementar os métodos de ordenação que foram dados em sala de aula: Bolha, Inserção, Seleção e ShellSort. Compare a execução dos algoritmos com diferentes vetores. Veja, para cada um deles, o
número de trocas necessárias para obter o vetor ordenado. Inclua comandos para contar o número de trocas em todos os códigos.

6) Melhorar o método da Bolha de forma a utilizar uma variável troca que marca quando trocas foram necessárias. Assim, o laço mais externo somente deve continuar se trocas foram necessárias no laço
mais interno. Veja se a sua solução está ordenando o vetor ( usar a função para verificar isso). Para difernetes tipos de vetores, compare o total de trocas com sua modificação, com o algoritmo sem
a modificação. Insira um comando nos algoritmos para contar o número de trocas feitas.

7) Modificar o Método da Bolha de forma que, em vez de a cada iteração levar o menor elemento para o início do vetor, ele leva o maior elemento para o final do vetor.

8) Modifique o algoritmo de Ordenação por Inserção de forma que a ordenação seja realizada em ordem decrescente.

9) Conforme visto em aula, o método de Ordenação ShellSort usa um vetor de k elementos (total de ciclos), que contém os k incrmentos a serem utiliados. Knuth sugere a que a escolha do número de ciclos
e os incrementos a serem utilizados sejam formulados da seguinte forma:
Defina a função recursiva f tal que
f(1) = 1 e f(i+1) = 3 * f(i) + 1
Seja x o menor inteiro tal que f(x) >= n (total de elementos do vetor)
k será x-2
I[i] será f(k-(i+1)+1) para i de 1 até k.
Implemente a formulação de Knutt para escolher a quantidade de passos k, o vetor I, com k dados. Faça com que seu programa execute várias vezes com difernetes tamanhos de vetores a serem
ordenados, calcule os valores dos passos k e os valores de incremento e escreva-os na tela.
Discuta como esses valores se alteram conforme o tamanho do vetor cresce.

*/
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//Item 1
    int buscaSequencial (float v[], int n, float x) {
        int m;
        for(m=0; m<n && v[m]<x; m++);
        if(m==n) return -1;
        else if(v[m]==x) return m;
        else return -1;
    }

// Exercicio 02
    int buscaBinaria (float *v, int n, float x) { // Vetor deve ser ordenado
        int m, e, d;
        e = 0;
        d = n-1;
        while(e<=d) {
            m = (e+d)/2;
            if(v[m]==x) return m;
            else
                if(v[m]<x) e = m+1;
                else d = m-1;
        }
        return -1;
    }

//Item 3
void vetor_aleatorio(float vetor[1000], int tamanho){
  int i;
  for(i=0;i<tamanho;i++)
  {
    vetor[i] = (double) INT_MAX*rand() / (RAND_MAX + 1.0);
  }
}

//Item 4
    int verificaOrdem (float *v, int n) {
        int i, x=1;
        n--;
        for(i=0; i<n; i++)
            if(v[i]>v[i+1]) x = 0;
        return x;
    }

//Item 5
      int bubbleSort(float v[], int n) {
            int i, j, troca=0;
            float aux;
            for(i=0; i<n-1; i++)
                for(j=n-1; j>i; j--)
                    if(v[j-1]>v[j]) {
                        aux = v[j-1];
                        v[j-1] = v[j];
                        v[j] = aux;
                        troca++;
                    }
            return troca;
        }

        int selectionSort(float v[], int n) {
            int ind, i, j, trocas=0;
            float menor, troca;
            for(i=0; i<n-1; i++) {
                menor = v[i];
                ind = i;
                troca = 0;
                for(j=i+1; j<n; j++)
                    if(v[j]<menor) {
                        menor = v[j];
                        ind = j;
                        troca = 1;
                    }
                if(troca) {
                    v[ind] = v[i];
                    v[i] = menor;
                    trocas++;
                }
            }
            return trocas;
        }

        int inserctionSort(float v[], int n) {
            int i, j, trocas=0;
            float x;
            for(i=1; i<n; i++) {
                x = v[i];
                j = i-1;
                while(j>=0 && v[j]>x) {
                    v[j+1] = v[j];
                    j--;
                    trocas++;
                }
                v[j+1] = x;
            }
            return trocas;
        }

        int shellSort(float v[], int n) {
            int ciclo, incr[20], i, j, k, h, trocas=0;
            float x;
            printf("De a quantidade de ciclos: ");
            scanf("%d", &ciclo);

            printf("De o tamanho dos blocos: ");
            for(i=0; i<ciclo; i++){
                printf("Bloco %d: ", i+1);
                scanf("%d", &incr[i]);
            }

            for(k=1; k<=ciclo; k++) {
                h = incr[k-1];
                for(i=h; i<n; i++) {
                    x = v[i];
                    for(j=i-h; j>=0 && v[j]>x; j=j-h){
                        v[j+h] = v[j];
                        trocas++;
                    }
                    v[j+h] = x;
                }
            }
            return trocas;
        }

//Item 6
  int bubbleSortTroca(float v[], int n) {
      int i=0, j, aux, troca = 1, trocas=0;
      while(troca) {
          troca = 0;
          for(j=n-1; j>i; j--)
              if(v[j-1]>v[j]) {
                  aux = v[j-1];
                  v[j-1] = v[j];
                  v[j] = aux;
                  troca = 1;
                  trocas++;
              }
          i++;
      }
      return trocas;
  }

//Item 7
int bubbleSortAlterado(float v[], int n) {
    int i=n-1, j, aux, troca = 1, trocas=0;
    while(troca) {
        troca = 0;
        for(j=0; j<i; j++)
            if(v[j]>v[j+1]) {
                aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
                troca = 1;
                trocas++;
            }
        i--;
    }
    return trocas;
}

//Item 8
  void inserctionSortMenor(float v[], int n) {
      int x, i, j;
      for(i=1; i<n; i++) {
          j = i;
          while(j>0 && v[j-1]<v[j]) {
              x = v[j];
              v[j] = v[j - 1];
              v[j - 1] = x;
              j--;
          }
      }
  }

//Item 9
  int knutt(int i){
    if(i==1)
    {
      return 1;
    }
    return 3 * knutt(i-1) + 1;
  }

  int ShellSortKnutt(float v[], int n)
  {
    int i,j,k,h,trocas,ciclo;
    ciclo=h=1;
    trocas=h-1;
    float x;

    do {
      h = 3*h + 1;
      ciclo++;
    }while (h<n);
    int incr[ciclo];
    for(i=0;i<ciclo;i++)
    {
      incr[i]=knutt(ciclo-i);
    }
    for(k=1; k<=ciclo; k++) {
        h = incr[k-1];
        for(i=h; i<n; i++) {
            x = v[i];
            for(j=i-h; j>=0 && v[j]>x; j=j-h){
                v[j+h] = v[j];
                trocas++;
            }
            v[j+h] = x;
        }
    }
    return trocas;
  }

//Imprimir vetor
void imprimir_vetor(float vetor[1000], int tamanho){
  int i;
  for(i=0;i<tamanho;i++)
  {
    printf("%.3f\t",vetor[i]);
  }
  puts("");
}

int main(int argc, char const *argv[]) {
  float vetor1[1000],vetor2[1000],vetor3[1000],vetor4[1000],vetor5[1000];
  int i,tamanho;
  printf("Digite a quantidade de elementos no vetor:\t");
  scanf("%d",&tamanho);
  puts("");
  //Para facilitar os testes e garantir dados nao viciados, os vetores serão gerados aleatoriamente.
  vetor_aleatorio(vetor1,tamanho);
  imprimir_vetor(vetor1,tamanho);
  puts("");
  //Como é preciso testar varios modos de ordenaçao é preciso copiar o vetor para outros
  for(i=0;i<tamanho;i++)
  {
    vetor2[i]=vetor1[i];//inserction
    vetor3[i]=vetor1[i];//Selection
    vetor4[i]=vetor1[i];//Shell
    vetor5[i]=vetor1[i];//BubbleTroca
  }

  //Contando os numeros de trocas
  puts("Contando o numero de trocas:");
  puts("");
  printf("Contagem Bubble Sort: %d",bubbleSort(vetor1,tamanho));
  puts("");
  if(verificaOrdem(vetor1,tamanho))
  {
    puts("Sucesso!");
  }
  else
  {
    puts("Falha!");
  }
  puts("");
  printf("Contagem Inserction Sort: %d",inserctionSort(vetor2,tamanho));
  puts("");
  if(verificaOrdem(vetor2,tamanho))
  {
    puts("Sucesso!");
  }
  else
  {
    puts("Falha!");
  }
  puts("");
  printf("Contagem Selection Sort: %d",selectionSort(vetor3,tamanho));
  puts("");
  if(verificaOrdem(vetor3,tamanho))
  {
    puts("Sucesso!");
  }
  else
  {
    puts("Falha!");
  }
  puts("");
  printf("Contagem Shell Sort: %d", ShellSortKnutt(vetor4,tamanho));
  puts("");
  if(verificaOrdem(vetor4,tamanho))
  {
    puts("Sucesso!");
  }
  else
  {
    puts("Falha!");
  }
  puts("");
  printf("Contagem Bubble Sort Troca: %d",bubbleSortTroca(vetor5,tamanho));
  puts("");
  if(verificaOrdem(vetor5,tamanho))
  {
    puts("Sucesso!");
  }
  else
  {
    puts("Falha!");
  }
  puts("");


  return 0;
}
