#include "play.h"
#include "inputvalidation.h"
#include "setup.h"
#include "win.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isOnBoardCol(int col, int colChoice)
{
    return isBetween(colChoice, 0, col - 1);
}

bool isColEmpty(char** board, int row, int col, int colChoice, char blank)
{
  for (int i=0; i <= row; i++)
  {
    if (i >= col)
    {
      return false;
    }
    else if (board[i][colChoice] == blank)
    {
      return true;
    } 
  }
  return false;
}

bool isValidPlay(char** board, int row, int col, int colChoice, int num_args_read, char blank)
{
    return isValidFormat(num_args_read, 1) && isOnBoardCol(col, colChoice) && isColEmpty(board, row, col, colChoice, blank);
}

void PickValidCol(char **board, int row, int col, int *outCol, char blank) {
  int num_args_read;
  do {
    printf("Enter a column between 0 and %d to play in: ", col-1);
    num_args_read = scanf("%d", outCol);
  } while (!isValidPlay(board, row, col, *outCol, num_args_read, blank));
}

void PlayerTakesTurn(char **board, int row, int col, char curPlayerPiece, char blank) {
  int colChoice = col;
  displayBoard(board, row, col);
  PickValidCol(board, row, col, &colChoice, blank);

  for (int i = 0; i < row; i++) {
    if (board[i][colChoice] == blank) 
    {
      board[i][colChoice] = curPlayerPiece;
      break;
    } 
  } 
}

void PrintResults(char **board, int row, int col, int curPlayerTurn, int winNum, char blank) {
  displayBoard(board, row, col);
  if ((isGameOver(board, 'X', row, col, winNum)) || (isGameOver(board, 'O', row, col, winNum))) {
    if (isTie(board, row, col, winNum))
    {
      printf("\n");
      printf("Tie game.\n");
    }
    else
    {
      printf("\n");
      printf("Player %d Won!\n", curPlayerTurn + 1);
    }

  } else {
    
  }
}

void SwitchPlayers(int *curPlayerTurn) {
  if (*curPlayerTurn == 0) {
    *curPlayerTurn = 1;
  } else {
    *curPlayerTurn = 0;
  }
}

void PlayGame(char **board, int row, int col, int winNum, int curPlayerTurn, char *playerPieces, char blank) {
  do {
    PlayerTakesTurn(board, row, col, playerPieces[curPlayerTurn], blank);
    if ((isGameOver(board, 'X', row, col, winNum)) || (isGameOver(board, 'O', row, col, winNum))) 
    {
      break;
    }
    SwitchPlayers(&curPlayerTurn);
  } while (true);

  PrintResults(board, row, col, curPlayerTurn, winNum, blank);
}