#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
  system("clear");

  char tabuleiro[3][3];
  int i, j;
  int choi, choj;               //choice i, linha   |   choice j, coluna
  char pecJog, pecOpon;                  //peca do jogador;
  bool running = true;

  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      tabuleiro[i][j] = ' ';
    }
  }

  while((pecJog != 'X') && (pecJog != 'O')){
    printf("\nX | O\n");
    scanf("%c", &pecJog);
    system("clear");
  }

  pecOpon = (pecJog == 'X' ? 'O' : 'X');

  while(running){
    system("clear");
    showTab(tabuleiro);

    do{
      while((choi < 1) || (choi > 3)){
        printf("\n[linha]: ");
        scanf("%d", &choi);
      }

      while((choj < 1) || (choj > 3)){
        printf("\n[coluna]: ");
        scanf("%d", &choj);
      }

      if(tabuleiro[choi - 1][choj - 1] != ' '){
        printf("Campo ja preenchido!");
	choi = 0;
	choj = 0;
      }
    }while(tabuleiro[choi - 1][choj - 1] != ' ');

    tabuleiro[choi - 1][choj - 1] = pecJog;   //jogadaJogador

    if(verify(tabuleiro, pecJog)){
      running = false;
      system("clear");

      printf("\n ----------");
      printf("\n| You win! |");
      printf("\n ----------\n");
    }

    jogadaOponente(tabuleiro, pecOpon);

    if(verify(tabuleiro, pecOpon)){
      running = false;
      system("clear");

      printf("\n -------");
      printf("\n| lose! |");
      printf("\n -------\n");
    }

    choi = 0;
    choj = 0;
  }

  printf("\n");
  showTab(tabuleiro);

  return 0;
}
