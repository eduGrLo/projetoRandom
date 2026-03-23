#include <stdio.h>

int main(){
  char tabuleiro[3][3];

  int i, j;

  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      tabuleiro[i][j] = ' ';
    }
  }


  for(i = 0; i < 3; i++){

    if(i > 0) {
      printf("|");
    }
    printf("\n ___ ___ ___ \n");

    for(j = 0; j < 3; j++){
      printf("| %c ", tabuleiro[i][j]);
    }
  }

  printf("|\n ___ ___ ___ \n");


  return 0;
}
