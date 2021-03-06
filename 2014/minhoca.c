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

void mostrarTunel(Tunel*, int);
void mostrarConsulta(Consulta*, int);

int main(int argc, char **argv) {
  int i, j;

  // Preparando a entrada
  int s, t, q;

  // Número de salões
  s = atoi(argv[1]);
  printf("%d ", s);

  // Número de túneis
  t = atoi(argv[2]);
  printf("%d\n", t);

  // Descrição do Túnel
  Tunel descT[t];
  for(i = 0; i < t; i++) {
    descT[i].a = atoi(argv[i * 3 + 3]);
    descT[i].b = atoi(argv[i * 3 + 4]);
    descT[i].c = atoi(argv[i * 3 + 5]);
  }
  mostrarTunel(descT, t);

  // Número de consultas
  i = (i - 1) * 3 + 5 + 1;
  q = atoi(argv[i]);
  printf("%d\n", q);
  
  // Descrição da Consulta
  Consulta descC[q];
  for(j = 0; j < q; j++) {
    descC[j].x = atoi(argv[j * 2 + i + 1]);
    descC[j].m = atoi(argv[j * 2 + i + 2]);
  }
  mostrarConsulta(descC, q);

  // Re-montar a descrição de túneis
  Tunel descTT[t * 2];
  for(i = 0; i < t * 2; i += 2) {
    descTT[i].a = descT[i / 2].a;
    descTT[i].b = descT[i / 2].b;
    descTT[i].c = descT[i / 2].c;
    
    descTT[i + 1].a = descT[i / 2].b;
    descTT[i + 1].b = descT[i / 2].a;
    descTT[i + 1].c = descT[i / 2].c;
  }
  mostrarTunel(descTT, t * 2);
  // A partir daqui somente usar o discTT
  
  return 0;
}

void mostrarTunel(Tunel *t, int m) {
  int i;
  for(i = 0; i < m; i++) {
    printf("%d %d %d\n", t[i].a, t[i].b, t[i].c);
  }
}

void mostrarConsulta(Consulta *c, int t) {
  int i;
  for(i = 0; i < t; i++) {
    printf("%d %d\n", c[i].x, c[i].m);
  }
}

