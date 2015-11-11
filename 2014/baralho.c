#include<stdio.h>
#include<stdlib.h>

void dividir(int, int, int[], int*);
int verificarOrdem(int, int[]);
int embaralhar(int, int[], int);

int main(int argc, char **argv) {
  int t = atoi(argv[1]);
  int v[t], i;
  for(i = 0; i < t * 2; i++) {
    v[i] = i;
  }

  printf("%d\n", embaralhar(t, v, 0));
  return 0;
}

/**
 * Embaralhar
 * @arg n, tamanho do baralho.
 * @arg b, um vetor que representa o baralho
 * @arg q, contador para a quantidade de vezes que o baralho foi embaralhado
 * @return o número mínimo de vezes que o processo de embaralhamento deve ser repetido para que o baralho fique novamente ordenado.
 **/
int embaralhar(int n, int b[], int q) {
  int i, j, metade1[n/2], metade2[n/2];

  // Dividir o baralho em 0..n/2
  dividir(0, n / 2, b, metade1);

  // Dividir o baralho em n/2+1..n
  dividir(n / 2, n, b, &metade2[0]);

  // Intercala
  for(i = 0; i < n; i += 2) {
    b[i] = metade2[i / 2];
    b[i + 1] = metade1[i / 2];
  }

  // Verifica se está ordenado, caso sim retorne q
  if(verificarOrdem(n, b)) {
    return q + 1;
  }

  // Repita o movimento de embaralhar
  return embaralhar(n, b, q + 1);
}

/**
 * Dividir
 * @arg a, posição inicial
 * @arg b, posição final
 * @arg v, vetor a ser dividido
 * @return um subvetor de v da posição a..b
 **/
void dividir(int a, int b, int v[], int *d) {
  int i;
  for(i = 0; (i + a) < b; i++) {
    d[i] = v[i + a];
  }
}

/**
 * Verificar Ordem
 * @arg n, o tamanho do vetor v
 * @arg v, vetor de tamanho n
 * return 1, caso v estaja ordenado. 0, caso contrário
 **/
int verificarOrdem(int n, int v[]) {
  int i;
  for(i = 0; i < n - 1; i++) {
    if(v[i] > v[i + 1]) {
      return 0;
    }
  }
  return 1;
}
