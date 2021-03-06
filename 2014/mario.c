#include<stdio.h>
#include<stdlib.h>

int qtdMaiorSeq(int, int*);
int alocacaoArmario(int, int, int*);

int main(int argc, char **argv) {
  int v[5] = {1, 3, 5, 6, 8};
  printf("%d\n", alocacaoArmario(5, 5, v));

  return 0;
}

/**
 * Alocação de Armários
 * @arg n, quantidade de armarios oslicitados pelo cliente
 * @arg l, quantidade de armários disponíveis
 * @arg x, vetor ordenado com os indices dos armários disponíveis
 * @return número mínimo de trocas que Mario precisa fazer para acomodar o pedido do novo cliente.
 **/
int alocacaoArmario(int n, int l, int *x) {
  int qtdSeqDisp;
  // Verifica se a quantidade solicitda não é mair do que a quantidade de armários disponíveis
  if(n > l) {
    return -1;
  }

  // Pega a quantidade da maior sequencia de armários livre consecutivos
  qtdSeqDisp = qtdMaiorSeq(l, x);

  // Subtrai a quantidade solicitada da quantidade em sequencia disponível
  return n - qtdSeqDisp;
}

/**
 * Quantidade da Maior Sequencia
 * @arg n, tamanho do vetor v
 * @arg v, vetor de inteiros ordenados
 * @return a quantidade da maior sequencia de números consecutivos em v
 **/
int qtdMaiorSeq(int n, int *v) {
  int c1, c2, i, j;
  c1 = c2 = 0;
  for(i = 0; i < n; i++) {
    c1 = 1;
    for(j = 0; i + j + 1 < n; j++) {
      if((v[i + j] + 1) == v[i + j + 1]) {
	c1++;
      }
      else {
	break;
      }
    }

    if(c1 > c2) {
      c2 = c1;
    }
  }
  return c2;
}
