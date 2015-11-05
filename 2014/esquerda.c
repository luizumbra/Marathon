#include<stdio.h>

char volver(int, char[]);

int main(int argc, char **argv) {
  char v[] = {'e', 'e'};
  printf("%c\n", volver(2, v));
  return 0;
}

/**
 * @arg n, número de comandos emitidos
 * @arg v, a série de comandos
 * @return direção para o qual o recruta deve ter a face voltada - 'n' (norte), 'l' (leste), 's' (sul), 'o' (oeste)
 **/
char volver(int n, char v[]) {
  char rosaDosVentos[4] = {'n', 'l', 's', 'o'};
  int i, vol = 0;
  for(i = 0; i < n; i++) {
    // Virar para a esquerda é o equivalente a andar 3 posições no sentido horário
    if(v[i] == 'e') {
      vol = (vol + 3) % 4;
    }

    // Virar para a direita é o equivalente a andar uma posição no sentido horário
    else if(v[i] == 'd') {
      vol = (vol + 1) % 4;
    }
  }

  return rosaDosVentos[vol];
}
