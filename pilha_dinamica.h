# ifndef PILHA_ESTATICA_H
# define PILHA_ESTATICA_H

#include <stdbool.h>
#include <stddef.h>

typedef struct node Node;
typedef struct pilhaDinamica PilhaDinamica; 

void iniciarPD(PilhaDinamica* pilha);
void inserirPD(PilhaDinamica* pilha, int data);
int removerPD(PilhaDinamica* pilha);
int vaziaPD(PilhaDinamica* pilha);
void encerrarPD(PilhaDinamica *pilha);
void exibirPD(PilhaDinamica* pilha);

void menuPilhaDinamica();

#endif
