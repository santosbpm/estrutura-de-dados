# include "pilha_dinamica.h"
# include "outros.h"

# include <stdlib.h>
# include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

// Estrutura da pilha
typedef struct pilhaDinamica {
    struct Node* topo;
} PilhaDinamica;

// Inicialização da pilha
void iniciarPD(PilhaDinamica* pilha) {
    pilha->topo = NULL;
}

// Inserção na pilha
void inserirPD(PilhaDinamica* pilha, int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = pilha->topo;
    pilha->topo = node;
}

// Remoção da pilha
int removerPD(PilhaDinamica* pilha) {
    if (vaziaPD(pilha)) {
        printf("A pilha está vazia.\n");
        return -1;
    }
    struct Node* node = pilha->topo;
    int data = node->data;
    pilha->topo = node->next;
    free(node);
    return data;
}

// Verificação de vazio
int vaziaPD(PilhaDinamica* pilha) {
    return pilha->topo == NULL;
}

// Encerramento da pilha
void encerrarPD(PilhaDinamica *pilha) {
    while (!vaziaPD(pilha)) {
        removerPD(pilha);
    }
}

// Exibição dos elementos da pilha
void exibirPD(PilhaDinamica* pilha) {
    struct Node* node = pilha->topo;
    printf("### Exibindo Pilha ###\n");
    while (node != NULL) {
        printf("%d \n", node->data);
        node = node->next;
    }
    printf("\n");
}


void menuPilhaDinamica() {
  bool dem = true;
  int capacidade;
  
  printf("Construa a sua estrutura de Pilha Dinamica\n");
  printf("\n");

  PilhaDinamica pilha;
  iniciarPD(&pilha);

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
        inserirPD(&pilha, val);
        break;
      case 2:
        removerPD(&pilha);
        break;
      case 3:
        exibirPD(&pilha);
        break;
      case 4:
        printf("Obrigado! Até a próxima.\n");
        encerrarPD(&pilha);
        dem = false;
        break;
      default:
        printf("Opção inexistente!\n");
        break;
    }
    continuar();
  }
}
