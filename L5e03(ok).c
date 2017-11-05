#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Gustavo Henrique de Oliveira Villar
//Laboratório de Algoritmos e técnicas de programação II - Turma 1
//Dev-C++ 5.11
//06/09/2017
//Lista 5 - Exercício 3
/* Para evitar erros na digitação de sequências de números de importância fundamental (ex: CPF,RG,número de conta bancária),geralmente
adiciona-se ao número um dígito verificador. Escreva um programa para ler um número com n digitos e seu dígito verificador. Escreva uma função
para verificar se o número fornecido está correto ou não. No programa principal escrever valor digitado e as mensagens informando o usuário
se está correto ou não.
Exemplo : 811057-3 (número 811507, dígito verificador 3)

O método para calcular o digito verigicador é dado a seguir:

    -Cada algorismo do número é multiplicado por um peso começando por 2 e crescendo da direita para esquerda: 7x2,5x3,0x4,1x5,1x6,8x7;
    -Somam-se as parcelas obtidas: 14+15+0+5+6+56 = 96;
    -Calcula-se o resto da divisao desta soma por 11 (96/11, resto 8);
    -Subtraia-se de 11 o resto obtido: 11-8 = 3;
    -Se o valor encontrado for 10 ou 11, o dígito verificador será zero, nos outros casos, o dígito verificador é o próprio número encontrado.

  Tratar o número como uma string:
  811057-3\0
*/
  int verificador(numerox,digitox,tamanhox){
    int soma,d,resto,i;
    soma=0;
    for(i=tamanhox;i>0;i=i-1)
    {
      d = numerox%10;
      soma = (soma + d) * (tamanhox-i+2);
      numerox/=10;
    }
    resto = soma % 11;
    soma = 11-resto;
    if(soma==10 || soma==11)
    {
      soma =0;
    }
    if (soma==digitox)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
 int main(int argc, char const *argv[]) {
   char numerochar[50],digschar[50];
   int numero,digito,tamanho;
   puts("Digite a sequencia:");
   getchar();
   scanf("%[^\n]",&numerochar);
   tamanho = strlen(numerochar) - 2;
   numero = atoi(seq);
   strcpy(digschar,numerochar);
   digschar[tamanho] = '0';
   digito = atoi(digschar) % 10;
   if(verificador(numero,digito,tamanho)==1)
   {
     printf("O numero %s eh valida!\n\n",numero);
   }
   else
   {
     puts("O numero nao e valido");
   }

  return 0;
}
