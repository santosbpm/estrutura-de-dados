# include "pilha_estatica.h"

# include <stdlib.h>
# include <stdio.h>

typedef struct pilha {
  int *dado;
  int capacidade;
  int topo;
} PilhaEstatica;


PilhaEstatica *iniciarPilha(int capacidade) {
  PilhaEstatica *P = (PilhaEstatica*) calloc(1, sizeof(PilhaEstatica));

  P->capacidade = capacidade;
  P->topo = -1;
  P->dado = (int*) calloc(P->capacidade, sizeof(int));

  return P;
}

void encerrarPilha(PilhaEstatica **P_ref) {
  PilhaEstatica *P = *P_ref;

  free(P->dado);
  free(P);

  *P_ref = NULL;
}


bool vaziaPilha(const PilhaEstatica *P) {
  return P->topo == -1;
}


bool cheiaPilha(const PilhaEstatica *P) {
  return P->topo == (P->capacidade - 1);
}

void inserir(PilhaEstatica *P, int val) {
  if (cheiaPilha(P)) {
    fprintf(stderr, "A pilha está cheia\n");
  } else {
    P->topo++;
    P->dado[P->topo] = val;
  }
}

void remover(PilhaEstatica *P) {
  if (vaziaPilha(P)) {
    fprintf(stderr, "A pilha está vazia\n");
  } else {
    int val = P->dado[P->topo];
    P->topo--;
  }
}

void exibir(const PilhaEstatica *P) {
  printf("capacidade: %d\n", P->capacidade);
  printf("topo: %d\n", P->topo);

  for (long i = 0; i <= P->topo; i++) {
    printf("%d, ", P->dado[i]);
  }
  puts("");
  
}

