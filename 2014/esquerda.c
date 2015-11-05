#include<stdio.h>

int executarComandos(char*);
char volver(int, char*);

int main(int argc, char **argv) {
  printf("%c\n", volver(argc, argv[1]));
  return 0;
}

/**
 * Volver
 * @arg n, quantidade de comandos dito pelo sargento.
 * @arg l, vetor com os comandos dito pelo sargento.
 * @return a direção para o qual o recruta deve ter sua face voltada após executar a série de comandos. Nessa etapa deve conter os caracteres 'N', 'L', 'S' e 'S' para representar os quatro pontos cardeais.
 **/
char volver(int n, char *l) {
  char rosaDosVentos[4] = {'N', 'L', 'S', 'O'};

  // Executa os comando do sargento
  unsigned int direcaoDaFace = executarComandos(l) % 4;

  // Descobre a direção da face, a partir da Rosa dos Ventos
  return rosaDosVentos[direcaoDaFace];
}

/**
 * Executar Comandos
 * @arg l, ponteiro para a lista de comandos do sergento
 * @return, um inteiro representando os giros no sentido horário do soldado
 **/
int executarComandos(char *l) {
  // 'D', representa girar um passo no sentido horário
  if(*l == 'D') {
    return executarComandos((l + 1)) + 1;
  }
  // 'E', representa girar três passos no sentido horário
  else if(*l == 'E') {
    return executarComandos((l + 1)) + 3;
  }
  // '\0', não há giro
  else {
    return 0;
  }
}
