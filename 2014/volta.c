#include<stdio.h>
#include<stdlib.h>

double velocidadeMedia(int);
double espaco(double. int, int);

int main(int argc, char **argv) {
  int tempoA, tempoB;
  int nVoltasA;
  double espacoB;
  double vmB;
  
  // Pega os tempos do carro a e b;
  tempoA = atoi(argv[1]);
  tempoB = atoi(argv[2]);
  
  // Calcular a velocidade media por valotas de B
  vmB = velocidadeMedia(tampoB);
  
  nVoltasA = 0;
  do {
    nVoltasA++;
    
    // Calcular o espaço percorrido a cada volta de A
    espacoB = espaco(vmB, tempoA, nVoltasA);
  } while(!((nVoltasA - espacoB) > 0));
  
  printf("%d voltas\n", (nVoltasA - espacoB));
  return 0;
}

/**
 * Velocidade Media
 * @arg tempo: Integer, tempo em segundos para o número de voltas
 * @return um double contendo a velocidade média para uma volta
 */
double velocidadeMedia(int tempo) {
  return (1 / tempo);
}

/**
 * Espaco
 * @arg vm: Double, velocidade média do veículo
 * @arg tempo: Integer, tempo percorrido
 * @arg n: Integer, número que irá a multiplicar o tempo percorrido
 * @return um Double contendo o espço percorrido das voltas
 */
double espaco(double vm, int tempo, int n) {
  return (vm * tempo * n);
}


