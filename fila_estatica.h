#ifndef FILA_ESTATICA_H
#define FILA_ESTATICA_H

#include <stdbool.h>

typedef struct fila FilaEstatica;

FilaEstatica *iniciarFila(int capacidade);
void encerrarFila(FilaEstatica **F_ref);
bool vaziaFila(const FilaEstatica *F);
bool cheiaFila(const FilaEstatica *F);

void enfileirar(FilaEstatica *F, int val);
void desenfileirar(FilaEstatica *F);
void exibirFila(const FilaEstatica *F);

void menuFila();

#endif

