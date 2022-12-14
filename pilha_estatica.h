# ifndef PILHA_ESTATICA_H
# define PILHA_ESTATICA_H

#include <stdbool.h>
#include <stddef.h>

typedef struct pilha PilhaEstatica;

PilhaEstatica *iniciarPilha(int capacidade);
void encerrarPilha(PilhaEstatica **P_ref);
bool vaziaPilha(const PilhaEstatica *P);
bool cheiaPilha(const PilhaEstatica *P);

void inserir(PilhaEstatica *P, int val);
void exibir(const PilhaEstatica *P);
int remover(PilhaEstatica *P);

#endif
