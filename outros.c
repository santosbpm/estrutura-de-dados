# include "outros.h"

# include <stdio.h>

/*
Essa função cria uma pausa no terminal
e também limpa o buffer com __fpurge()
*/
void continuar() {
  printf("Pressione enter para continuar...\n\n");
  __fpurge(stdin);
  /* Windows
  fflush(stdin);
  */
  getchar(); 
  /* Para Windows:
   getch(); */
}

