#include <stdio.h>
#include <stdlib.h>

#define LINHAS 10
#define COLUNAS 10
#define AGUA 0
#define NAVIO 3
#define NAVIO_ATINGIDO 1
#define HABILIDADE_MARCA 5

int main() {
  //TABULEIRO ZERADO
  int tabuleiro[LINHAS][COLUNAS];
  // l = linha   &   c = coluna
  for(int l = 0; l < LINHAS; l++) {
    for(int c = 0; c < COLUNAS; c++) {
      tabuleiro[l][c] = AGUA;
    }
  }

  //ADICIONANDO NAVIOS NO TABULEIRO
  int tamanho_navio = 3;

  //NAVIO A
  int navio_A[3] = {NAVIO, NAVIO, NAVIO};
  int linha_navio_A = 2;
  int coluna_inicial_navio_A = 3;
  
  for(int x = 0; x < tamanho_navio; x++) {
    tabuleiro[linha_navio_A][coluna_inicial_navio_A + x] = navio_A[x];
    //tabuleiro[2][3+0] = navio_A[0]
    //tabuleiro[2][3+1] = navio_A[1]
    //tabuleiro[2][3+2] = navio_A[2]
  }

  //NAVIO B
  int navio_B[3] = {NAVIO, NAVIO, NAVIO};
  int coluna_navio_B = 6;
  int linha_inicial_navio_B = 6;

  for(int x = 0; x < tamanho_navio; x++){
    tabuleiro[linha_inicial_navio_B + x][coluna_navio_B] = navio_B[x];
    //tabuleiro[6+0][6] = navio_B[0]
    //tabuleiro[6+1][6] = navio_B[1]
    //tabuleiro[6+2][6] = navio_B[2]
  }

  //NAVIO C
  int navio_C[3] = {NAVIO, NAVIO, NAVIO};
  int linha_inicial_navio_C = 3;
  int coluna_inicial_navio_C = 0;

  for(int x = 0; x < tamanho_navio; x++){
    tabuleiro[linha_inicial_navio_C + x][coluna_inicial_navio_C + x] = navio_C[x];
    //tabuleiro[3+0][0+0] = navio_C[0] -> tabuleiro[3][0]
    //tabuleiro[3+1][0+1] = navio_C[1] -> tabuleiro[4][1]
    //tabuleiro[3+2][0+2] = navio_C[2] -> tabuleiro[5][2]
  }

  //NAVIO D
  int navio_D[3] = {NAVIO, NAVIO, NAVIO};
  int linha_inicial_navio_D = 1;
  int coluna_inicial_navio_D = 9;

  for(int x = 0; x < tamanho_navio; x++) {
    tabuleiro[linha_inicial_navio_D + x][coluna_inicial_navio_D - x] = navio_D[x];
    //tabuleiro[1+0][9-0] = navio_D[0] -> tabuleiro[1][9]
    //tabuleiro[1+1][9-1] = navio_D[1] -> tabuleiro[2][8]
    //tabuleiro[1+2][9-2] = navio_D[2] -> tabuleiro[3][7]
  }

  //HABILIDADE CONE - Geração programática
  int cone[3][5];
  // Inicializar matriz com zeros
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 5; j++) {
      cone[i][j] = 0;
    }
  }
  // Criar padrão cone usando loops e condicionais
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 5; j++) {
      // Padrão cone: cresce de cima para baixo
      if(i == 0 && j == 2) { // Primeira linha: só o centro
        cone[i][j] = HABILIDADE_MARCA;
      } else if(i == 1 && (j >= 1 && j <= 3)) { // Segunda linha: centro ± 1
        cone[i][j] = HABILIDADE_MARCA;
      } else if(i == 2) { // Terceira linha: toda a linha
        cone[i][j] = HABILIDADE_MARCA;
      }
    }
  }
  
  int linha_inicial_cone = 7;
  int coluna_inicial_cone = 0;

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 5; j++){
      if(cone[i][j] != 0) { // Se não for 0 no cone
        int linha_tab = linha_inicial_cone + i;
        int coluna_tab = coluna_inicial_cone + j;
        // Verificação de limites do tabuleiro
        if(linha_tab >= 0 && linha_tab < LINHAS && coluna_tab >= 0 && coluna_tab < COLUNAS) {
          if(tabuleiro[linha_tab][coluna_tab] == NAVIO) {
            tabuleiro[linha_tab][coluna_tab] = NAVIO_ATINGIDO; // Colisão: navio + habilidade = 1
          } else if(tabuleiro[linha_tab][coluna_tab] == AGUA) {
            tabuleiro[linha_tab][coluna_tab] = cone[i][j]; // Aplica habilidade na água
          }
        }
      }
      // Se for 0 no cone, não faz nada (preserva o que já estava no tabuleiro)
    }
  }

  //HABILIDADE CRUZ - Geração programática
  int cruz[3][5];
  // Inicializar matriz com zeros
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 5; j++) {
      cruz[i][j] = 0;
    }
  }
  // Criar padrão cruz usando loops e condicionais
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 5; j++) {
      // Padrão cruz: linha do meio toda preenchida + coluna do meio toda preenchida
      if(i == 1) { // Linha do meio: toda preenchida
        cruz[i][j] = HABILIDADE_MARCA;
      } else if(j == 2) { // Coluna do meio: toda preenchida
        cruz[i][j] = HABILIDADE_MARCA;
      }
    }
  }
  
  int linha_inicial_cruz = 1;
  int coluna_inicial_cruz = 4;

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 5; j++){
      if(cruz[i][j] != 0) { // Se não for 0 na cruz
        int linha_tab = linha_inicial_cruz + i;
        int coluna_tab = coluna_inicial_cruz + j;
        // Verificação de limites do tabuleiro
        if(linha_tab >= 0 && linha_tab < LINHAS && coluna_tab >= 0 && coluna_tab < COLUNAS) {
          if(tabuleiro[linha_tab][coluna_tab] == NAVIO) {
            tabuleiro[linha_tab][coluna_tab] = NAVIO_ATINGIDO; // Colisão: navio + habilidade = 1
          } else if(tabuleiro[linha_tab][coluna_tab] == AGUA) {
            tabuleiro[linha_tab][coluna_tab] = cruz[i][j]; // Aplica habilidade na água
          }
        }
      }
      // Se for 0 na cruz, não faz nada (preserva o que já estava no tabuleiro)
    }
  }

  //HABILIDADE OCTAEDRO - Geração programática usando distância de Manhattan
  int octaedro[3][3];
  // Inicializar matriz com zeros
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      octaedro[i][j] = 0;
    }
  }
  // Criar padrão octaedro (losango) usando distância de Manhattan
  int centro = 1; // Centro da matriz 3x3 está na posição [1][1]
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      // Distância de Manhattan: |i - centro| + |j - centro|
      int distancia = abs(i - centro) + abs(j - centro);
      if(distancia <= centro) { // Se a distância for <= raio do losango
        octaedro[i][j] = HABILIDADE_MARCA;
      }
    }
  }
  
  int linha_inicial_octaedro = 0;
  int coluna_inicial_octaedro = 0;

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(octaedro[i][j] != 0) { // Se não for 0 no octaedro
        int linha_tab = linha_inicial_octaedro + i;
        int coluna_tab = coluna_inicial_octaedro + j;
        // Verificação de limites do tabuleiro
        if(linha_tab >= 0 && linha_tab < LINHAS && coluna_tab >= 0 && coluna_tab < COLUNAS) {
          if(tabuleiro[linha_tab][coluna_tab] == NAVIO) {
            tabuleiro[linha_tab][coluna_tab] = NAVIO_ATINGIDO; // Colisão: navio + habilidade = 1
          } else if(tabuleiro[linha_tab][coluna_tab] == AGUA) {
            tabuleiro[linha_tab][coluna_tab] = octaedro[i][j]; // Aplica habilidade na água
          }
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