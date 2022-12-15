# include "outros.h"

# include <stdio.h>

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

