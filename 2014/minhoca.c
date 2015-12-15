#include<stdio.h>
#include<stdlib.h>

typedef struct tunel {
  // A e B representam os salões ligados pelo túnel
  int a;
  int b;
  // C representa o comprimento do túnel
  int c;
}Tunel;

typedef struct consulta {
  // Salão de entrada
  int x;
  // Comprimento da minhoca
  int m;
}Consulta;

int main(int argc, char **argv) {
  int i;

  // Preparando a entrada
  int s, t;
  // Número de salões
  s = atoi(argv[1]);
  // Número de túneis
  t = atoi(argv[2]);
  // Descrição do Túnel
  Tunel desc[t];
  for(i = 0; i < t; i++) {
    desc[i].a = atoi(argv[i * 3 + 3]);
    desc[i].b = atoi(argv[i * 3 + 4]);
    desc[i].c = atoi(argv[i * 3 + 5]);
  }
  // Número de consultas
  int q;

  return 0;
}
