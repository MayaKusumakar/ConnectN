#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "setup.h"


char **Init_Board(int numRows, int numCols) {
  /*
  Init_Board initalizes the board with the given number of rows and cols
  @numRows: the number of rows for the board
  @numCols: the number of columns for the board
  @returns the double pointer char matrix for the board
*/
  char **board = (char **)malloc(numRows * sizeof(char *));

  for (int row = 0; row < numRows; ++row) {
    board[row] = (char *)malloc(numCols * sizeof(char));
    for (int col = 0; col < numCols; ++col) {
      board[row][col] = '*';
    }
  }
  return board;
}

void displayBoard(char **board, int numRows, int numCols) {
  /*
  DisplayBoard displays the board to the console, labeling the columns/rows
  @board: the board to display
  @numRows: the number of rows in the board
  @numCols: the number of columns on the board
  @returns: nothing
*/
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
  printf("\n");
}

void cleanup(char** *board, int numRows) {
  /*
  cleanup frees the memory allocated with the board
  @board: the board to free
  @numRows: the number of rows on the board
  @returns: nothing
*/
  for (int i = 0; i < numRows; ++i) {
    free((*board)[i]);
  }
  free(*board);
  *board = NULL;
}
