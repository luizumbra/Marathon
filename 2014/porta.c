#include<stdio.h>
#include<stdlib.h>

int mudarEstadoPorta(int);
int contaEstado(int, int*, int);

int main(int argc, char **argv) {
  mudarEstadoPorta(atoi(argv[1]));
  return 0;
}

/**
 * Mudar Estado Porta
 * @arg n, quantidade de portas e descendentes
 * @return um vetor com as portas fechadas e abertas
 **/
int mudarEstadoPorta(int n) {
  // porta aberta e fechada é representada pelo valo 0 e 1, respectivamente
  int i, j, portas[n];

  // Inicia as portas com 0, porta fechada
  for(i = 0; i < n; i++) {
    portas[i] = 0;
  }

  // Muda o estado a cada entrada dos descendentes
  for(i = 1; i <= n; i++) {
    for(j = 0; j < n; j++) {
      if(!((j + 1) % i)) {
	portas[j] = !portas[j];
      }
    }
  }

  return contaEstado(n, portas, 1);
}
/**
 * Conta Estados
 * @arg n, tamanho do vetor p
 * @arg p, vetor de estados
 * @arg x, estado desejado
 * @return a quantidade de x dentro de p
 **/
int contaEstado(int n, int *p, int x) {
  int i;
  for(i = 0; i < n; i++) {
    if(p[i] == x) {
      printf("%d ", i + 1);
    }
  }
  printf("\n");
  return 0;
}
