/*Gustavo Henrique de Oliveira Villar
Turma 01
Dev-Cpp
25/10/17
Lista 9 - Todos exercícios

Parte 1 - Algoritmos de Ordenação e busca
Nesta primeira parte você deve ter implementado as seguintes funções, todas elas referentes a vetores com valores inteiros.
1. uma função que implemente o algoritmo da bolha;
2. uma função que implemente o algoritmo da seleção;
3. uma função que implemente o algoritmo de inserção;
4. uma função que implemente o algoritmo de Shell Sort;
5. uma função que implemente o algoritmo mergesort;//a ser implementado hoje
6. uma funçao que implemente o algoritmo quicksort;//a ser implementada hoje
7. uma função que implemente busca sequencial;
8. uma função que implemente busca binária;
9. as funções GerarVetorAleatorio, tempo e verifica_ordem;

Parte 2 - Programa principal e uma função para medir o tempo de processamento 
Você deve implementar um programa principal, que para vários tamanhos de vetores, faça um teste do funcionamento de suas funções. O usuário fornecerá o tempo máximo que seu programa deverá
executar. Nos testes você deve usar a função verifica_ordem para verificar se os algoritmos estão ordenando corretamente e também comparar os resultados das buscas binárias e sequencial.

Lembre-se que, embora a busca binária seja muito mais rápida do que a sequencial, ela requer que os elementos do vetor estejam ordenados. A ordenação requer um esforço computacional
adicional. Quando será que vale a pena pagar esse preço adicional? Uma possível forma para dar uma resposta a essa questão é considerar o número de buscas que serão feitas.
Neste exercício vamos determinar, na prática, para vários valores de n, quando começa a valer a pena a ordenação de um vetor com n inteiros para permitir a busca binária.
O programa main, e a função tempo, pode ter o seguinte esqueleto:

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
				
				
O seu programa deve permitir as opções de escolha dos altoritmos descritos acima, deverá testar valores de n bem grandes (por exemplo: a partir de 2000, com acrescimento de 2000 a cada passo).
Para cada valor de n, o seu programa deverá informar, para cada método especificado, qual o valor mínimo do numero de buscar a partir do qual vale a pena fazer a ordenação e busca binária em vez
de busca sequencial sem ordenação.
O processo para quando for detectado que seu programa já usou um tempo maior do que a duração especificada peo usuário.
Escreva o programa principal de forma que o usuário possa escolher um determinado método de ordenação ou poderá decidir executar o programa utilizando todos os métodos de ordenação de uma única vez.
Para tamanhos de vetores não muito grandes, é comum que os tempos de execução sejam zero, pois como os processos são muito rápidos, a medida de tempo não consegue capturar essa passagem rápida do tempo.
Assim, outras formas de mostrar a eficiência de um método em relação a outros é a comparação do número de trocas efetudas e, também a quantidade de iterações efetuadas pelos métodos para ordenar os vetores.
Implemente contadores para essas formas, de maneira que o sue programa consiga dar ao usuário um panorama de eficácia dos métodos de ordenação.
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
        
//Metodo de inserção 
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
	void intercala (int V[], int p, int q, int r){
		int i,j,k,*w;
		w=(int*)malloc((r-p)*sizeof(int));
		i=p;
		k=0;
		j=q;
		while(i<q && j<r)
		if(V[i]<=V[j])
		w[k++]=V[i++];
		else w[k++]=V[j++];
		while(i<q) w[k++]=V[i++];
		while(j<r) w[k++]=V[j++];
		for(i=0;i<k;i++) V[p+i]=w[i];
		free(w); 
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
    
//Gerar vetor aleatório
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



int main(int argc, char *argv[]) {
	return 0;
}
