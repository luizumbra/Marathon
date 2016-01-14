#include<stdio.h>
#include<stdlib.h>

double velocidadeMedia(int);
double espaco(double. int, int);

int main(int argc, char **argv) {
  int tempoA, tempoB;
  int nVoltasA = 0;
  double espacoB;
  double vmB;
  
  // Pega os tempos do carro a e b;
  tempoA = atoi(argv[1]);
  tempoB = atoi(argv[2]);
  
  // Calcular a velocidade media por valotas de B
  vmB = velocidadeMedia(tampoB);
  
  do {
    nVoltasA++;
    
    // Calcular o espaço percorrido a cada volta de A
    espacoB = espaco(vmB, tempoA, nVoltasA);
  } while(!((nVoltasA - espacoB) > 0));
  
  return 0;
}

