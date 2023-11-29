#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char **Init_Board(int numRows, int numCols) {
  char **board = (char **)calloc(numRows * sizeof(char *), '*');

  for (int row = 0; row < numRows; ++row) {
    board[row] = (char *)calloc(numCols, sizeof(char));
    for (int col = 0; col < numCols; ++col) {
      board[row][col] = '*';
    }
  }
  return board;
}

void displayBoard(char **board, int numRows, int numCols) {
  for (int i = numRows - 1; i >= 0; i--) {
    printf("%d", i);
    for (int j = 0; j < numCols; j++) {
      printf(" %c", board[i][j]);
    }
    printf("\n");
  }
  printf(" ");
  for (int i = 0; i < numCols; i++) {
    printf(" %d", i);
  }
}

bool isValidMove(char **board, int colChoice, int numRows, int numCols) {
  if (colChoice < 0) {
    return false;
  }
  if (colChoice > numCols) {
    return false;
  }
  if (board[numRows - 1][colChoice] != '*') {
    return false;
  }
  return true;
}

void cleanup(char ***board, int numRows) {
  for (int i = 0; i < numRows; ++i) {
    free((*board)[i]);
  }
  free(*board);
  *board = NULL;
}

/*
int main(void) {
  char **board;
  board = Init_Board(5, 5);
  displayBoard(board, 5, 5);
        board[4][4] = 'X';
  return 0;
}
*/