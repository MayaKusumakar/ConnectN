#include "inputvalidation.h"
#include "play.h"
#include "setup.h"
#include "win.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int GetRow(int argc, char **argv) {

  if (argc != 4) {
    printf("Not enough arguments\n");
    printf("Usage: ./tic-tac-toe.out board_dimensions");
    exit(23);
  }
  int row;
  char should_be_blank;
  int num_args_read = sscanf(argv[1], "%d %c", &row, &should_be_blank);
  if (num_args_read != 1) {
    printf("Dimensions needs to be an integer. Found %s\n", argv[1]);
    exit(23);
  }

  if (row < 1) {
    printf("Dimensions needs to be at least 1 but was specified as %d\n", row);
    exit(23);
  }

  return row;
}

int GetCol(int argc, char **argv) {

  if (argc != 4) {
    printf("Not enough arguments\n");
    printf("Usage: ./tic-tac-toe.out board_dimensions");
    exit(23);
  }
  int col;
  char should_be_blank;
  int num_args_read = sscanf(argv[1], "%d %c", &col, &should_be_blank);
  if (num_args_read != 1) {
    printf("Dimensions needs to be an integer. Found %s\n", argv[1]);
    exit(23);
  }

  if (col < 1) {
    printf("Dimensions needs to be at least 1 but was specified as %d\n", col);
    exit(23);
  }

  return col;
}

int GetNumToWin(int argc, char **argv) {
  if (argc != 4) {
    printf("Not enough arguments\n");
    printf("Usage: ./tic-tac-toe.out board_dimensions");
    exit(23);
  }
  int numToWin;
  char should_be_blank;
  int num_args_read = sscanf(argv[1], "%d %c", &numToWin, &should_be_blank);
  if (num_args_read != 1) {
    printf("Dimensions needs to be an integer. Found %s\n", argv[1]);
    exit(23);
  }

  if (numToWin < 1) {
    printf("Dimensions needs to be at least 1 but was specified as %d\n",
           numToWin);
    exit(23);
  }

  return numToWin;
}

int main(int argc, char **argv) {

  const char blank = '*';
  int cur_player_turn = 0;
  char *player_pieces = (char *)malloc(2 * sizeof(char));

  player_pieces[0] = 'X';
  player_pieces[1] = 'O';
  int row = GetRow(argc, argv);
  int col = GetCol(argc, argv);
  int numToWin = GetNumToWin(argc, argv);

  char **board = Init_Board(row, col);
  PlayGame(board, row, col, numToWin, cur_player_turn, player_pieces, blank);
  cleanup(&board, row);

  return 0;
}