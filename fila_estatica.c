# include "fila_estatica.h"
# include "outros.h"

# include <stdio.h>
# include <stdlib.h>

typedef struct fila {
  int *dado;
  int capacidade;
  int tamanho;
  int inicio;
  int final;
} FilaEstatica;


FilaEstatica *iniciarFila(int capacidade) {
  FilaEstatica *F = (FilaEstatica*) calloc(1, sizeof(FilaEstatica));

  F->dado = (int*) calloc(capacidade, sizeof(int));
  F->capacidade = capacidade;
  F->tamanho = 0;
  F->inicio = 0;
  F->final = 0;

  return F;
}


void encerrarFila(FilaEstatica **F_ref) {
  FilaEstatica *F = *F_ref;

  free(F->dado);
  free(F);

  *F_ref = NULL;
}


bool vaziaFila(const FilaEstatica *F) {
  return F->tamanho == 0;
}


bool cheiaFila(const FilaEstatica *F) {
  return F->tamanho == F->capacidade;
}


void enfileirar(FilaEstatica *F, int val) {
  if (cheiaFila(F)) {
    printf("A fila está cheia\n");
  } else {
    F->dado[F->final] = val;
    F->final = (F->final + 1) % F->capacidade;
    F->tamanho++;
    printf("Valor %d inserido com sucesso!", val);
  }
}


void desenfileirar(FilaEstatica *F) {
  if (vaziaFila(F)) {
    printf("A fila está vazia\n");
  } else {
    int val = F->dado[F->inicio];
    F->inicio = (F->inicio + 1) % F->capacidade;
    F->tamanho--;
    printf("Valor %d removido da fila.\n", val);
  }
}


void exibirFila(const FilaEstatica *F) {
    printf("capacidade: %d\n", F->capacidade);
    printf("tamanho: %d\n", F->tamanho);
    printf("Inicio: %d\n", F->inicio);
    printf("Final: %d\n\n", F->final);

    int s, i;

    for (s = 0, i = F->inicio; s < F->tamanho; s++, i = (i + 1) % F->capacidade) {
        printf("Índice[%d] = Elemento[%d] \n", i, F->dado[i]);
    }
    puts("");
}


void menuFila() {
  bool dem = true;
  int capacidade;
  
  printf("Construa a sua estrutura de Fila\n");
  printf("Digite o tamanho da sua fila: ");
  scanf("%d", &capacidade);
  printf("\n");
  FilaEstatica *F = iniciarFila(capacidade);

  while(dem) {
    int opcao;
    printf("-------------Menu de opções para filas-------------\n");
    printf("1 - Enfileirar\n");
    printf("2 - Desenfileirar\n");
    printf("3 - Exibir fila\n");
    printf("4 - Sair da fila\n");
    printf("\nSelecione uma opção: ");
    scanf("%d", &opcao);
    printf("\n");

    switch (opcao){
      case 1:
        printf("Digite o valor a ser inserido: ");
        int val;
        scanf("%d", &val);
        enfileirar(F, val);

        break;
      case 2:
        desenfileirar(F);
        break;
      case 3:
        exibirFila(F);
        break;
      case 4:
        printf("Obrigado! Até a próxima.\n");
        encerrarFila(&F);
        dem = false;
        break;
      default:
        printf("Opção inexistente!\n");
        break;
    }
    continuar();
  }
}


