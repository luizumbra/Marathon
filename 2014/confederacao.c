#include<stdio.h>
#include<stdlib.h>

/**
 * Plano de cada órbita
 **/
typedef struct plano {
  int a;
  int b;
  int c;
  int d;
}Plano;

/**
 * Posição de cada planeta
 **/
typedef struct ponto {
  int x;
  int y;
  int z;
}Ponto;

int verifPontoPertenceAoPlano(Ponto, Plano);
int maiorElemento(int, int*);
int qtdDePlanetas(int, int, Ponto*, Plano*);

int main(int argc, char **argv) {
  // Definindo as entradas
  int m, n, i, j;
  m = atoi(argv[1]);
  n = atoi(argv[2]);

  Plano pl[m];
  for(i = 0; i < m; i++) {
    j = ((i + 1) * 3 + i);
    pl[i].a = atoi(argv[j]);
    pl[i].b = atoi(argv[j + 1]);
    pl[i].c = atoi(argv[j + 2]);
    pl[i].d = atoi(argv[j + 3]);
  }
  Ponto po[n];
  j += 3;
  for(i = 0; i < n; i++) {
    po[i].x = atoi(argv[++j]);
    po[i].y = atoi(argv[++j]);
    po[i].z = atoi(argv[++j]);
  }

  print("%d\n", qtdDePlanetas(m, n, po, pl));

  return 0;
}

int qtdDePlanetas(int m, int n, Ponto *po, Plano *pl) {
  int max[m], i, j;
  // Tudos os max igual a zero
  for(i = 0; i < m; i++) {
    max[i] = 0;
  }

  for(i = 0; i < m; i++) {
    for(j = 0; j < n; j++) {
      if(verifPontoPertenceAoPlano(po[j], pl[i])) {
	max[i]++;
      }
    }
  }

  return maiorElemento(m, max);
}

int verifPontoPertenceAoPlano(Ponto po, Plano pl) {
  return ((pl.a * po.x + pl.b * po.y + pl.c * po.z - pl.d) == 0);
}

int maiorElemento(int n, int *v) {
  int i, aux;
  aux = v[0];
  for(i = 1; i <n; i++) {
    if(aux < v[i]) {
      aux = v[i];
    }
  }
  return aux;
}
