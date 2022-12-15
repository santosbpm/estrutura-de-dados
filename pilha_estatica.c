# include "pilha_estatica.h"
# include "outros.h"

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
    printf("A pilha está cheia!\n");
  } else {
    P->topo++;
    P->dado[P->topo] = val;
    printf("Valor %d inserido na posição %d.\n", val, P->topo);
  }
}


void remover(PilhaEstatica *P) {
  if (vaziaPilha(P)) {
    printf("A pilha está vazia!\n");
  } else {
    int val = P->dado[P->topo];
    P->topo--;
    printf("Valor %d removido com sucesso!\n", val);
  }
}


void exibirPilha(const PilhaEstatica *P) {
  printf("Capacidade: %d\n", P->capacidade);
  printf("Topo: %d\n", P->topo);

  for (int i = 0; i <= P->topo; i++) {
    printf("Índice[%d] = Elemento[%d]\n", i, P->dado[i]);
  }
  puts("");
  
}


void menuPilha() {
  bool dem = true;
  int capacidade;
  
  printf("Construa a sua estrutura de Pilha\n");
  printf("Digite o tamanho da sua pilha: ");
  scanf("%d", &capacidade);
  printf("\n");
  PilhaEstatica *P = iniciarPilha(capacidade);

  while(dem) {
    int opcao;
    printf("### Menu de Opções ###\n");
    printf("1 - Inserir\n");
    printf("2 - Remover\n");
    printf("3 - Exibir pilha\n");
    printf("4 - Sair da Pilha\n");
    printf("\nSelecione uma opção: ");
    scanf("%d", &opcao);
    printf("\n");

    switch (opcao){
      case 1:
        printf("Digite o valor a ser inserido: ");
        int val;
        scanf("%d", &val);
        inserir(P, val);
        break;
      case 2:
        remover(P);
        break;
      case 3:
        exibirPilha(P);
        break;
      case 4:
        printf("Obrigado! Até a próxima.\n");
        encerrarPilha(&P);
        dem = false;
        break;
      default:
        printf("Opção inexistente!\n");
        break;
    }
    continuar();
  }
}
