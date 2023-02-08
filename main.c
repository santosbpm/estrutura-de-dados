# include "pilha_estatica.h"
# include "fila_estatica.h"
# include "pilha_dinamica.h"
# include "outros.h"

# include <stdio.h>

int main() {
  bool dem = true;
  while(dem) {
    int opcao;
    printf("--------------Menu de Estrutura de Dados--------------\n");
    printf("1 - Pilha Estatica\n");
    printf("2 - Fila Estatica\n");
    printf("3 - Pilha Dinamica\n");
    printf("4 - Sair\n");
    printf("\n Selecione uma opção: ");
    scanf("%d", &opcao);
    printf("\n");
    
    switch (opcao){
      case 1:
        menuPilha();
        break;
      case 2:
        menuFila();
        break;
      case 3:
        menuPilhaDinamica();
        break;
      case 4:
        printf("Obrigado! Até a próxima.\n");
        dem = false;
        break;
      default:
        printf("Opção não existente!\n");
        break;
    }
    continuar();
  }

  return 0;
}
