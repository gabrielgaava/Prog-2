/*Gustavo Henrique de Oliveira Villar
Turma 01
Dev-Cpp
25/10/17
Lista 9 - Todos exerc�cios

Parte 1 - Algoritmos de Ordena��o e busca
Nesta primeira parte voc� deve ter implementado as seguintes fun��es, todas elas referentes a vetores com valores inteiros.
1. uma fun��o que implemente o algoritmo da bolha;
2. uma fun��o que implemente o algoritmo da sele��o;
3. uma fun��o que implemente o algoritmo de inser��o;
4. uma fun��o que implemente o algoritmo de Shell Sort;
5. uma fun��o que implemente o algoritmo mergesort;//a ser implementado hoje
6. uma fun�ao que implemente o algoritmo quicksort;//a ser implementada hoje
7. uma fun��o que implemente busca sequencial;
8. uma fun��o que implemente busca bin�ria;
9. as fun��es GerarVetorAleatorio, tempo e verifica_ordem;

Parte 2 - Programa principal e uma fun��o para medir o tempo de processamento
Voc� deve implementar um programa principal, que para v�rios tamanhos de vetores, fa�a um teste do funcionamento de suas fun��es. O usu�rio fornecer� o tempo m�ximo que seu programa dever�
executar. Nos testes voc� deve usar a fun��o verifica_ordem para verificar se os algoritmos est�o ordenando corretamente e tamb�m comparar os resultados das buscas bin�rias e sequencial.

Lembre-se que, embora a busca bin�ria seja muito mais r�pida do que a sequencial, ela requer que os elementos do vetor estejam ordenados. A ordena��o requer um esfor�o computacional
adicional. Quando ser� que vale a pena pagar esse pre�o adicional? Uma poss�vel forma para dar uma resposta a essa quest�o � considerar o n�mero de buscas que ser�o feitas.
Neste exerc�cio vamos determinar, na pr�tica, para v�rios valores de n, quando come�a a valer a pena a ordena��o de um vetor com n inteiros para permitir a busca bin�ria.
O programa main, e a fun��o tempo, pode ter o seguinte esqueleto:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double tempo(){
	return (double) clock()/CLOCKS_PER_SEC;
}
int main(){
	int n,i,opcao;
	double duracao, tempoinicial, tempofinal,tempototal, ...
	printf("\nForneca o tempo maximo que o programa devera executar:");
	scanf("%1f",&duracao);
	prinf("\n Duracao dos testes = %.2f segundos\n", duracao);
	printf("\n Escolha o algoritmo a ser utilizado:\n");
	printf("\n Bolha<1>");
	printf("\n Selecao<2>");
	printf("\n Insercao<3>");
	printf("\n Shell Sort<4>");
	printf("\n Mergesort<5>");
	printf("\n Quicksort<6>");
	printf("\n Todos os metodos<7>");
	printf("\n");
	scanf("%d",&opcao);
	//gera um numero aleatorio para ser procurado no vetor
	numero = (double) INT_MAX*rand() / (RAND_MAX + 1.0);
	printf("\n Numero a ser procurado: %.2f\n", numero);
	switch (opcao){
		case 1:
				printf("\n Bolha:\n");
				.
				.
				.


O seu programa deve permitir as op��es de escolha dos altoritmos descritos acima, dever� testar valores de n bem grandes (por exemplo: a partir de 2000, com acrescimento de 2000 a cada passo).
Para cada valor de n, o seu programa dever� informar, para cada m�todo especificado, qual o valor m�nimo do numero de buscar a partir do qual vale a pena fazer a ordena��o e busca bin�ria em vez
de busca sequencial sem ordena��o.
O processo para quando for detectado que seu programa j� usou um tempo maior do que a dura��o especificada peo usu�rio.
Escreva o programa principal de forma que o usu�rio possa escolher um determinado m�todo de ordena��o ou poder� decidir executar o programa utilizando todos os m�todos de ordena��o de uma �nica vez.
Para tamanhos de vetores n�o muito grandes, � comum que os tempos de execu��o sejam zero, pois como os processos s�o muito r�pidos, a medida de tempo n�o consegue capturar essa passagem r�pida do tempo.
Assim, outras formas de mostrar a efici�ncia de um m�todo em rela��o a outros � a compara��o do n�mero de trocas efetudas e, tamb�m a quantidade de itera��es efetuadas pelos m�todos para ordenar os vetores.
Implemente contadores para essas formas, de maneira que o sue programa consiga dar ao usu�rio um panorama de efic�cia dos m�todos de ordena��o.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
//Metodo da Bolha
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

//Metodo de selecao
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

//Metodo de inserçao
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

//Metodo de Shell Sort (Knut)
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

//Algoritmo mergesort
void intercala (int v[], int p, int q, int r) {
    int i, j, k, *w;
    w = (int*) malloc ((r-p)*sizeof(int));
    i=p;
    k=0;
    j=q;
    while(i<q && j<r)
        if(v[i]<=v[j])
            w[k++]=v[i++];
        else
            w[k++] = v[j++];
    while(i<q) w[k++] = v[i++];
    while(j<r) w[k++] = v[j++];
    for(i=0; i<k; i++) v[p+i] = w[i];
    free(w);
}

void mergeSort (int v[], int p, int r) {
    if(p<r-1) {
        int q = (r+p) / 2;
        mergeSort(v,p,q);
        mergeSort(v,q,r);
        intercala(v,p,q,r);
    }
}



//Algoritmo Quicksort
	void Quicksort(int V[],int e, int d){
		int i=e, j=d, aux, x;
		x=V[(i+j)/2];
		do{
			while(V[i]<x) i++;
			while(V[j]>x) j--;
			if(i<j){
				aux=V[i];
				V[i]=V[j];
				V[j]=aux;
			}
			i++;
			j--;
		}while(i<=j);
		if(e<j) Quicksort(V,e,j);
		if(i<d) Quicksort(V,i,d);
	}

//Busca Sequencial
    int buscaSequencial (float v[], int n, float x) {
        int m;
        for(m=0; m<n && v[m]<x; m++);
        if(m==n) return -1;
        else if(v[m]==x) return m;
        else return -1;
    }

//Busca Binaria
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

//Gerar vetor aleat�rio
void vetor_aleatorio(float vetor[1000], int tamanho){
  int i;
  for(i=0;i<tamanho;i++)
  {
    vetor[i] = (double) INT_MAX*rand() / (RAND_MAX + 1.0);
  }
}

//Verificar Ordem
    int verificaOrdem (float *v, int n) {
        int i, x=1;
        n--;
        for(i=0; i<n; i++)
            if(v[i]>v[i+1]) x = 0;
        return x;
    }

//Tempo
double tempo(){
	return (double) clock()/CLOCKS_PER_SEC;
}

//Copiar vetor
void copiarVetor(int v1[], int v2[], int n){
  int i;
  for (i=0;i<n;i++)
      v2[i] = v1[i];
}


//Programa principal
int main(int argc, char *argv[]) {
  int i, op, v[100], copia[100];
  double duracao, ti, tf, total, tbusca, numero;
  puts("Escolha o algortimo que deseja:\n1-Bolha\n2-Selection\n3-Insertion\n4-Shell Sort\n5-Merge Sort\n6-Quick Sort\n7-Todos anteriores.");
  scanf("%d",&op);
  puts("Digite o tempo maximo, em segundos, que o programa deve executar:");
  scanf("%f",&duracao);
  total = 0;
  i=2000;
  if(op==1)
  {
    puts("Bubble Sort");
    while(total<duracao)
    {
      vetor_aleatorio(v,i);
      ti = tempo();
      buscaSequencial(v,i,numero);
      tf = tempo();
      tbusca = tf-ti;
      ti = tempo();
      bubbleSort(v,i);
      tf = tempo();
      total += (tf-ti) + tbusca;
      printf("%d numeros\n",i);
      printf("Ordenar %lfms [%d]\n",tf-ti,verificaOrdem(v,i));
      printf("Busca Sequencial %lfms\n",tbusca);
      ti=tempo();
      buscaBinaria(v,i,numero);
      tf=tempo();
      tbusca=tf-ti;
      total = total + tbusca;
      printf("Busca Binaria %lfms\n",tbusca);
      i=i+2000;
    }
  }
  else if(op==2)
  {
    puts("Selection Sort");
    while(total<duracao)
    {
      vetor_aleatorio(v,i);
      ti = tempo();
      buscaSequencial(v,i,numero);
      tf = tempo();
      tbusca = tf-ti;
      ti = tempo();
      selectionSort(v,i);
      tf = tempo();
      total += (tf-ti) + tbusca;
      printf("%d numeros\n",i);
      printf("Ordenar %lfms [%d]\n",tf-ti,verificaOrdem(v,i));
      printf("Busca Sequencial %lfms\n",tbusca);
      ti=tempo();
      buscaBinaria(v,i,numero);
      tf=tempo();
      tbusca=tf-ti;
      total = total + tbusca;
      printf("Busca Binaria %lfms\n",tbusca);
      i=i+2000;
    }
  }
  else if(op==3)
  {
    puts("Inserction Sort");
    while(total<duracao)
    {
      vetor_aleatorio(v,i);
      ti = tempo();
      buscaSequencial(v,i,numero);
      tf = tempo();
      tbusca = tf-ti;
      ti = tempo();
      inserctionSort(v,i);
      tf = tempo();
      total += (tf-ti) + tbusca;
      printf("%d numeros\n",i);
      printf("Ordenar %lfms [%d]\n",tf-ti,verificaOrdem(v,i));
      printf("Busca Sequencial %lfms\n",tbusca);
      ti=tempo();
      buscaBinaria(v,i,numero);
      tf=tempo();
      tbusca=tf-ti;
      total = total + tbusca;
      printf("Busca Binaria %lfms\n",tbusca);
      i=i+2000;
    }
  }
  else if(op==4)
  {
    puts("Shell Sort");
    while(total<duracao)
    {
      vetor_aleatorio(v,i);
      ti = tempo();
      buscaSequencial(v,i,numero);
      tf = tempo();
      tbusca = tf-ti;
      ti = tempo();
      ShellSortKnutt(v,i);
      tf = tempo();
      total += (tf-ti) + tbusca;
      printf("%d numeros\n",i);
      printf("Ordenar %lfms [%d]\n",tf-ti,verificaOrdem(v,i));
      printf("Busca Sequencial %lfms\n",tbusca);
      ti=tempo();
      buscaBinaria(v,i,numero);
      tf=tempo();
      tbusca=tf-ti;
      total = total + tbusca;
      printf("Busca Binaria %lfms\n",tbusca);
      i=i+2000;
    }
  }
  else if(op==5)
  {
    puts("Merge Sort");
    while(total<duracao)
    {
      vetor_aleatorio(v,i);
      ti = tempo();
      buscaSequencial(v,i,numero);
      tf = tempo();
      tbusca = tf-ti;
      ti = tempo();
      mergeSort(v,0,i);
      tf = tempo();
      total += (tf-ti) + tbusca;
      printf("%d numeros\n",i);
      printf("Ordenar %lfms [%d]\n",tf-ti,verificaOrdem(v,i));
      printf("Busca Sequencial %lfms\n",tbusca);
      ti=tempo();
      buscaBinaria(v,i,numero);
      tf=tempo();
      tbusca=tf-ti;
      total = total + tbusca;
      printf("Busca Binaria %lfms\n",tbusca);
      i=i+2000;
    }
  }
  else if(op==6)
  {
    puts("Quick Sort");
    while(total<duracao)
    {
      vetor_aleatorio(v,i);
      ti = tempo();
      buscaSequencial(v,i,numero);
      tf = tempo();
      tbusca = tf-ti;
      ti = tempo();
      quickSort(v,0,i);
      tf = tempo();
      total += (tf-ti) + tbusca;
      printf("%d numeros\n",i);
      printf("Ordenar %lfms [%d]\n",tf-ti,verificaOrdem(v,i));
      printf("Busca Sequencial %lfms\n",tbusca);
      ti=tempo();
      buscaBinaria(v,i,numero);
      tf=tempo();
      tbusca=tf-ti;
      total = total + tbusca;
      printf("Busca Binaria %lfms\n",tbusca);
      i=i+2000;
    }
  }
/*  else if(op==7)
  {

  }*/
  else
  {
    puts("Invalid option.");
  }
	return 0;
}
