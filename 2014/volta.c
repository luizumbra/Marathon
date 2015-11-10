#include<stdio.h>
#include<stdlib.h>

typedef struct carro {
  unsigned double anguloPorSeg;
  unsigned double angulo;
  unsigned int numVolta;
  unsigned int seg;
} Carro;

void pause(Carro a, Carro b){

  fflush(stdin);
  getchar();
}



int volta(Carro, Carro);

int main(int argc, char **argv) {
  Carro x, y;
  x.angulo = y.angulo = 0.0;
  x.numVolta = y.numVolta = 0;

  x.seg = atoi(argv[1]);
  y.seg = atoi(argv[2]);

  x.anguloPorSeg = 360 / x.seg;
  y.anguloPorSeg = 360 / y.seg;

  printf("%d\n", volta(x, y));
  return 0;
}

/**
 * Volta
 * @arg x, o tempo em segundos que o piloto mais rápido faz a volta
 * @arg y, o tempo em segundo que o pilito mais lento faz a volta
 * @return a volta em que o piloto mais lento se torna um retardatário
 **/
int volta(Carro x, Carro y) {
  unsigned int seg = 0;
  while(!(x.angulo <= y.angulo && x.numVolta < y.numVolta)) {
    printf("while(!(%d <= %f))")
    // Calcula o angulo
    x.angulo = (x.anguloPorSeg + x.angulo) >= 360 ? (x.anguloPorSeg + x.angulo - 360) : (x.anguloPorSeg + x.angulo);
    y.angulo = (y.anguloPorSeg + y.angulo) >= 360 ? (y.anguloPorSeg + y.angulo - 360) : (y.anguloPorSeg + y.angulo);

    // Calcula a volta
    seg++;
    if((seg % x.seg) == 0) {
      x.numVolta++;
    }
    if((seg % y.seg) == 0) {
      y.numVolta++;
    }
  }

  return x.numVolta;
}
