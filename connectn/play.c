#include "play.h"
#include "inputvalidation.h"
#include "setup.h"
#include "win.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*Function returns true if the col is within the board limits
@col: total colum
@colChoice: the column given by the user
@returns: true if col is in limits
*/
bool isOnBoardCol(int col, int colChoice)
{
    return isBetween(colChoice, 0, col - 1);
}
/*Function returns true if the the chosen col is emtpy
@board: the board
@col: total colum
@row: the row
@colChoice: the column given by the user
@blank: blank character of the board
@returns: true if col is in limits

*/
bool isColEmpty(char** board, int row, int col, int colChoice, char blank)
{
  for (int i=0; i <= row; i++)
  {
    if (i >= row)
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
/*Function returns true if the play is valid
@board: the board
@col: total colum
@row: the row
@colChoice: the column given by the user
@num_args_read: numberof args returned from the isValidFormat function
@blank: blank character of the board
@returns: true if the play is valid
*/
bool isValidPlay(char** board, int row, int col, int colChoice, int num_args_read, char blank)
{
    return isValidFormat(num_args_read, 1) && isOnBoardCol(col, colChoice) && isColEmpty(board, row, col, colChoice, blank);
}

/*Function asks the user to pick a column to play their piece in
@board: the board
@col: total colum
@row: the row
@outCol: the column given by the user
@blank: blank character of the board
@returns: nothing
*/

void PickValidCol(char **board, int row, int col, int *outCol, char blank) {
  int num_args_read;
  int maxCalls = 20;
  int numCalls = 0;
  do {
    printf("Enter a column between 0 and %d to play in: ", col-1);
    num_args_read = scanf("%d", outCol);
    numCalls++;
    if (numCalls > maxCalls)
    {
      exit(0);
    }
  } while (!isValidPlay(board, row, col, *outCol, num_args_read, blank));
}

/*Function has the player take a turn
@board: the board
@col: total colum
@row: the row
@curPlayerPiece: the piece "x" or "o" of the player
@outCol: the column given by the user
@blank: blank character of the board
@returns: nothing
*/

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

/*Function asks the user to pick a column to play their piece in
@board: the board
@col: total colum
@row: the row
@outCol: the column given by the user
@blank: blank character of the board
@returns: nothing
*/

void PrintResults(char **board, int row, int col, int curPlayerTurn, int winNum, char blank) {
  displayBoard(board, row, col);
  if ((isGameOver(board, 'X', row, col, winNum)) || (isGameOver(board, 'O', row, col, winNum))) {
    if (isTie(board, row, col, winNum))
    {
      printf("Tie game!\n");
    }
    else
    {
      printf("Player %d Won!\n", curPlayerTurn + 1);
    }

  } else {
    
  }
}

/*Function switches turns 
@curPlayerTurn: the current player
@return: nothing
*/

void SwitchPlayers(int *curPlayerTurn) {
  if (*curPlayerTurn == 0) {
    *curPlayerTurn = 1;
  } else {
    *curPlayerTurn = 0;
  }
}

/*Function plays the game: takes turn, switches players, prints the results when over
@board: the board
@col: total colum
@row: the row
@winNum: the number of pieces needed in a row to win
@curPlayerTurn: the current player
@playerPieces: the pieces of the two players, "x" and "o"
@blank: blank character of the board
@returns: nothing
*/
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
