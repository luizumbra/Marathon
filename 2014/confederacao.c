#include<stdio.h>
#include<stdlib.h>

void pause() {
  fflush(stdin);
  getchar();
}

typedef struct plano {
  int a;
  int b;
  int c;
  int d;
}Plano;

typedef struct posicao {
  int x;
  int y;
  int z;
}Posicao;

int main(int argc, char **argv) {
  // Definindo as entradas
  int m, n, i, j;
  m = atoi(argv[1]);
  n = atoi(argv[2]);
  //  pause();
  Plano pl[m];
  for(i = 0; i < m; i++) {
    j = ((i + 1) * 3 + i);
    pl[i].a = atoi(argv[j]);
    pl[i].b = atoi(argv[j + 1]);
    pl[i].c = atoi(argv[j + 2]);
    pl[i].d = atoi(argv[j + 3]);
  }
  Posicao po[n];
  j += 3;
  for(i = 0; i < n; i++) {
    po[i].x = atoi(argv[++j]);
    po[i].y = atoi(argv[++j]);
    po[i].z = atoi(argv[++j]);
  }

  // Teste
  //  printf("m: %d\n", m);
  //  for(i = 0; i < m; i++) {
  //    printf("A: %d -- B: %d -- C: %d -- D: %d\n", pl[i].a, pl[i].b, pl[i].c, pl[i].d);
  //  }
  //  printf("n: %d\n", n);
  //  for(i = 0; i < n; i++) {
  //    printf("X: %d -- Y: %d -- Z: %d\n", po[i].x, po[i].y, po[i].z);
  //  }
  return 0;
}
