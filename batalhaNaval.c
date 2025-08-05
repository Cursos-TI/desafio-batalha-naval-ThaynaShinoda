#include <stdio.h>

int main() {
  //TABULEIRO ZERADO
  int tabuleiro[10][10];
  // l = linha   &   c = coluna
  for(int l = 0; l < 10; l++) {
    for(int c = 0; c < 10; c++) {
      tabuleiro[l][c] = 0;
    }
  }

  //ADICIONANDO NAVIOS NO TABULEIRO
  int tamanho_navio = 3;

  //NAVIO A
  int navio_A[3] = {3, 3, 3};
  int linha_navio_A = 2;
  int coluna_inicial_navio_A = 3;
  
  for(int x = 0; x < tamanho_navio; x++) {
    tabuleiro[linha_navio_A][coluna_inicial_navio_A + x] = navio_A[x];
    //tabuleiro[2][3+0] = navio_A[0]
    //tabuleiro[2][3+1] = navio_A[1]
    //tabuleiro[2][3+2] = navio_A[2]
  }

  //NAVIO B
  int navio_B[3] = {3, 3, 3};
  int coluna_navio_B = 6;
  int linha_inicial_navio_B = 6;

  for(int x = 0; x < tamanho_navio; x++){
    tabuleiro[linha_inicial_navio_B + x][coluna_navio_B] = navio_B[x];
    //tabuleiro[6+0][6] = navio_B[0]
    //tabuleiro[6+1][6] = navio_B[1]
    //tabuleiro[6+2][6] = navio_B[2]
  }

  //EXIBIÇÃO DO TABULEIRO
  printf("===== BATALHA NAVAL =====\n\n");
  
  printf("  "); //Espaço para alinhar o cabeçalho
  char cabecalho[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  for(int letra = 0; letra < 10; letra++) {
    printf("%c ", cabecalho[letra]);
  }
  printf("\n");

  for(int l = 0; l < 10; l++) {
    printf("%d ", l); //Coloca numeração da linha
    for(int c = 0; c < 10; c++){
      printf("%d ", tabuleiro[l][c]);
    }
    printf("\n"); //Pula para próxima linha
  }

  return 0;
}