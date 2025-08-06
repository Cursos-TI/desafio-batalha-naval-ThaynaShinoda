#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int main() {
  //TABULEIRO ZERADO
  int tabuleiro[LINHAS][COLUNAS];
  // l = linha   &   c = coluna
  for(int l = 0; l < LINHAS; l++) {
    for(int c = 0; c < COLUNAS; c++) {
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

  //NAVIO C
  int navio_C[3] = {3, 3, 3};
  int linha_inicial_navio_C = 3;
  int coluna_inicial_navio_C = 0;

  for(int x = 0; x < tamanho_navio; x++){
    tabuleiro[linha_inicial_navio_C + x][coluna_inicial_navio_C + x] = navio_C[x];
    //tabuleiro[3+0][0+0] = navio_C[0] -> tabuleiro[3][0]
    //tabuleiro[3+1][0+1] = navio_C[1] -> tabuleiro[4][1]
    //tabuleiro[3+2][0+2] = navio_C[2] -> tabuleiro[5][2]
  }

  //NAVIO D
  int navio_D[3] = {3, 3, 3};
  int linha_inicial_navio_D = 1;
  int coluna_inicial_navio_D = 9;

  for(int x = 0; x < tamanho_navio; x++) {
    tabuleiro[linha_inicial_navio_D + x][coluna_inicial_navio_D - x] = navio_D[x];
    //tabuleiro[1+0][9-0] = navio_D[0] -> tabuleiro[1][9]
    //tabuleiro[1+1][9-1] = navio_D[1] -> tabuleiro[2][8]
    //tabuleiro[1+2][9-2] = navio_D[2] -> tabuleiro[3][7]
  }

  //HABILIDADE CONE
  int cone[3][5] = {
    {0,0,5,0,0},
    {0,5,5,5,0},
    {5,5,5,5,5}
  };
  int linha_inicial_cone = 7;
  int coluna_inicial_cone = 0;

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 5; j++){
      if(cone[i][j] != 0) { // Se não for 0 no cone
        if(tabuleiro[linha_inicial_cone + i][coluna_inicial_cone + j] == 3) {
          tabuleiro[linha_inicial_cone + i][coluna_inicial_cone + j] = 1; // Colisão: navio + habilidade = 1
        } else {
          tabuleiro[linha_inicial_cone + i][coluna_inicial_cone + j] = cone[i][j]; // Coloca o 5
        }
      }
      // Se for 0 no cone, não faz nada (preserva o que já estava no tabuleiro)
    }
  }

  //HABILIDADE CRUZ
  int cruz[3][5] = {
    {0,0,5,0,0},
    {5,5,5,5,5},
    {0,0,5,0,0}
  };
  int linha_inicial_cruz = 1;
  int coluna_inicial_cruz = 4;

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 5; j++){
      if(cruz[i][j] != 0) { // Se não for 0 na cruz
        if(tabuleiro[linha_inicial_cruz + i][coluna_inicial_cruz + j] == 3) {
          tabuleiro[linha_inicial_cruz + i][coluna_inicial_cruz + j] = 1; // Colisão: navio + habilidade = 1
        } else {
          tabuleiro[linha_inicial_cruz + i][coluna_inicial_cruz + j] = cruz[i][j]; // Coloca o 5
        }
      }
      // Se for 0 na cruz, não faz nada (preserva o que já estava no tabuleiro)
    }
  }

  //HABILIDADE OCTAEDRO
  int octaedro[3][3] = {
    {0,5,0},
    {5,5,5},
    {0,5,0}
  };
  int linha_inicial_octaedro = 0;
  int coluna_inicial_octaedro = 0;

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(octaedro[i][j] != 0) { // Se não for 0 no octaedro
        if(tabuleiro[linha_inicial_octaedro + i][coluna_inicial_octaedro + j] == 3) {
          tabuleiro[linha_inicial_octaedro + i][coluna_inicial_octaedro + j] = 1; // Colisão: navio + habilidade = 1
        } else {
          tabuleiro[linha_inicial_octaedro + i][coluna_inicial_octaedro + j] = octaedro[i][j]; // Coloca o 5
        }
      }
      // Se for 0 no octaedro, não faz nada (preserva o que já estava no tabuleiro)
    }
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