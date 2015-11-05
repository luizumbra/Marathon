/**
 * Description of the exercise
 **/
/*M ́ario  ́e dono de uma empresa de guarda-volumes, a Arm ́arios a Custos Moderados (ACM). M ́ario conquistou sua clientela gra ̧cas `a rapidez no processo de armazenar os volumes. Para isso, ele tem duas t ́ecnicas:
• Todos os arm ́arios est ̃ao dispostos numa fila e s ̃ao numerados com inteiros positivos a partir de 1. Isso permite a M ́ario economizar tempo na hora de procurar um arm ́ario;
• Todos os arm ́arios tˆem rodinhas, o que lhe d ́a grande flexibilidade na hora de rearranjar seus arm ́arios (naturalmente, quando M ́ario troca dois arm ́arios de posi ̧c ̃ao, ele tamb ́em troca suas numera ̧c ̃oes, para que eles continuem numerados sequ ̈encialmente a partir de 1).
Para alugar arm ́arios para um novo cliente, M ́ario gosta de utilizar arm ́arios cont ́ıguos, pois no in ́ıcio da loca ̧c ̃ao um novo cliente em geral faz muitas requisi ̧c ̃oes para acessar o conteu ́do armazenado, e o fato de os arm ́arios estarem cont ́ıguos facilita o acesso para o cliente e para M ́ario.
Desde que M ́ario tenha arm ́arios livres em quantidade suficiente, ele sempre pode conseguir isso. Por exemplo, se a requisic ̧ ̃ao de um novo cliente necessita de quatro arm ́arios, mas apenas os arm ́arios de nu ́mero 1, 3, 5, 6, 8 estiverem dispon ́ıveis, M ́ario pode trocar os arm ́arios 5 e 2 e os arm ́arios 6 e 4 de posi ̧c ̃ao: assim, ele pode alugar o intervalo de arm ́arios de 1 at ́e 4.
No entanto, para minimizar o tempo de atendimento a um novo cliente, M ́ario quer fazer o menor nu ́mero de trocas poss ́ıvel para armazenar cada volume. No exemplo acima, ele poderia simplesmente trocar os arm ́arios 1 e 4 de posi ̧c ̃ao, e alugar o intervalo de 3 at ́e 6.
M ́ario est ́a muito ocupado com seus clientes e pediu que vocˆe fizesse um programa para determinar o nu ́mero m ́ınimo de trocas necess ́ario para satisfazer o pedido de loca ̧c ̃ao de um novo cliente*/

#include<stdio.h>
#include<math.h>

int maiorSeq(int, int[]);
int minimoDeAlocacao(int, int, int[]);

int main(int argc, char **argv) {
  int armario[6] = {1, 3, 5, 6, 8};
  printf("%d\n", minimoDeAlocacao(5, 5, armario));
  return 0;
}

/**
 * @arg n, número de armários desejados pelo cliente.
 * @arg l, quantidade de armários disponíveis.
 * @arg x, vetor com o indice dos armários disponíveis
 * @return, um valor inteiro com o número de alocações,
 *          caso não seja possível efetuar a quantidade
 *          de alocações completas retorna -1.
 **/
int minimoDeAlocacao(int n, int l, int x[]) {
  // Verifica se há armários o suficiente
  if(n > l) {
    return -1;
  }

  // Procura pela maior sequência da fila
  int maior = maiorSeq(l, x);

  // Verifica a diferença entre a maior sequencia e a quantidade desejada
  return (n - maior);
}

/**
 * @arg l tamanho do vetor x
 * @arg x, vetor de inteiros (circular)
 * @arg c, conta a maior quantidade de sequencia de x
 **/
int maiorSeq(int l, int x[]) {
  int i, c1, c2, valorDaSeq, indice;

  // Procura por todas as seq.
  c1 = c2 = 0;
  for(i = 0; i < l; i++) {
    // efetua a contagem
    valorDaSeq = x[i] + 1;
    indice = (i + 1) % l;

    c1 = 0;
    while(valorDaSeq == x[indice] && c1 < l) {
      c1 += 1;
      indice = (indice + 1) % l;
      valorDaSeq += 1;
    }

    if(c1 > c2) {
      c2 = c1;
    }
  }

  return c2;
}
