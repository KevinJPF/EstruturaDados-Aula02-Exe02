#include "pilha.h"
#include <stdio.h>

int main(void) {
  int qtdNumeros, numero;

  printf("Quantidade de numeros: ");
  scanf("%d", &qtdNumeros);

  Pilha Pa = pilha(qtdNumeros);
  Pilha Pb = pilha(qtdNumeros);

  for (int i = 0; i < qtdNumeros; i++) {
    printf("Numero %d: ", i + 1);
    scanf("%d", &numero);
    empilha(numero, Pa);
  }

  do {
    if (!vaziap(Pb) && topo(Pa) > topo(Pb)) {
      numero = desempilha(Pa);
      empilha(desempilha(Pb), Pa);
      empilha(numero, Pa);
    } else if (vaziap(Pb) || topo(Pa) < topo(Pb)) {
      empilha(desempilha(Pa), Pb);
    } else {
      desempilha(Pa);
    }
  } while (!vaziap(Pa));

  while (!vaziap(Pb))
    empilha(desempilha(Pb), Pa);

  printf("Numeros ordenados(Pa): ");

  while (!vaziap(Pa))
    printf("%d - ", desempilha(Pa));
  printf("Fim.\n");

  destroip(&Pa);

  return 0;
}