#include "win.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool checkWinHorizontally(char **board, char piece, int numRows, int numCols,
                          int numToWin) {
  /*
  function to see if one of the players has won by having the user defined
number to win in a row horizontally
@board: the board of the game that holds the pieces
@piece: which piece we are checking to see if it has enough in a row
@numRows: the number of rows on the board
@numCols: the number of cols on the board
@num to win: the number of pieces in a row that must be in a row to win
@returns: true if the player has won horizontally, false if they have not
*/
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j <= numCols - numToWin; ++j) {
      bool found = true;
      for (int k = 0; k < numToWin; ++k) {
        if (board[i][j + k] != piece) {
          found = false;
          break;
        }
      }
      if (found) {
        return true;
      }
    }
  }
  return false;
}

bool checkWinVertically(char **board, char piece, int numRows, int numCols,
                        int numToWin) {
  /*
  function to see if one of the players has won by having the user defined
number to win in a row vertically
@board: the board of the game that holds the pieces
@piece: which piece we are checking to see if it has enough in a row
@numRows: the number of rows on the board
@numCols: the number of cols on the board
@num to win: the number of pieces in a row that must be in a row to win
@returns: true if the player has won vertically, false if they have not
*/
  for (int j = 0; j < numCols; ++j) {
    for (int i = 0; i <= numRows - numToWin; ++i) {
      bool found = true;
      for (int k = 0; k < numToWin; ++k) {
        if (board[i + k][j] != piece) {
          found = false;
          break;
        }
      }
      if (found) {
        return true;
      }
    }
  }
  return false;
}

bool checkWinDiagonallyOnLeft(char **board, char piece, int numRows,
                              int numCols, int numToWin) {
  /*
  function to see if one of the players has won by having the user defined
  number to win in a row diagonally on the left side
  @board: the board of the game that holds the pieces
  @piece: which piece we are checking to see if it has enough in a row
  @numRows: the number of rows on the board
  @numCols: the number of cols on the board
  @num to win: the number of pieces in a row that must be in a row to win
  @returns: true if the player has won diagonally (left side), false if they
  have not
  */
  for (int i = numToWin - 1; i < numRows; ++i) {
    for (int j = 0; j <= numCols - numToWin; ++j) {
      bool found = true;
      for (int k = 0; k < numToWin; ++k) {
        if (board[i - k][j + k] != piece) {
          found = false;
          break;
        }
      }
      if (found)
        return true;
    }
  }

  return false;
}

bool checkWinDiagonallyOnRight(char **board, char piece, int numRows,
                               int numCols, int numToWin) {
  /*
  function to see if one of the players has won by having the user defined
  number to win in a diagonally on right side
  @board: the board of the game that holds the pieces
  @piece: which piece we are checking to see if it has enough in a row
  @numRows: the number of rows on the board
  @numCols: the number of cols on the board
  @num to win: the number of pieces in a row that must be in a row to win
  @returns: true if the player has won diagonally (right side), false if they
  have not
  */
  for (int i = 0; i <= numRows - numToWin; ++i) {
    for (int j = 0; j <= numCols - numToWin; ++j) {
      bool found = true;
      for (int k = 0; k < numToWin; ++k) {
        if (board[i + k][j + k] != piece) {
          found = false;
          break;
        }
      }
      if (found)
        return true;
    }
  }
  return false;
}

bool isBoardFull(char **board, int numRows, int numCols) {
  /*
  function to see if the board is currently full
  @board: the board of the game that holds the pieces
  @numRows: the number of rows on the board
  @numCols: the number of cols on the board
  @returns: true if the board is full, false if it is not
  */
  for (int col = 0; col < numCols; col++) {
    if (board[numRows - 1][col] == '*') {
      return false;
    }
  }
  return true;
}

bool isWin(char **board, char piece, int numRows, int numCols,
              int numToWin) {
  /*
  function to see if one of the players has in any direction
  @board: the board of the game that holds the pieces
  @piece: which piece we are checking to see if it has enough in a row
  @numRows: the number of rows on the board
  @numCols: the number of cols on the board
  @num to win: the number of pieces in a row that must be in a row to win
  @returns: true if any player has won, false if they have not
  */

  if (checkWinHorizontally(board, piece, numRows, numCols, numToWin)) {
    return true;
  }
  if (checkWinVertically(board, piece, numRows, numCols, numToWin)) {
    return true;
  }
  if (checkWinDiagonallyOnLeft(board, piece, numRows, numCols, numToWin)) {
    return true;
  }
  if (checkWinDiagonallyOnRight(board, piece, numRows, numCols, numToWin)) {
    return true;
  }
  return false;
}
bool isTie(char **board, int numRows, int numCols, int numToWin) {
  /*
  function to see if the game is tied
  @board: the board of the game that holds the pieces
  @numRows: the number of rows on the board
  @numCols: the number of cols on the board
  @num to win: the number of pieces in a row that must be in a row to win
  @returns: true if the board is full and no one has won the game, false
  otherwise
  */
  if (isBoardFull(board, numRows, numCols)) {
    if (isWin(board, 'X', numRows, numCols, numToWin) == false) {
      if (isWin(board, 'O', numRows, numCols, numToWin) == false) {
        return true;
      }
    }
  }

  return false;
}

bool isGameOver(char **board, char piece, int numRows, int numCols, int numToWin)
{
  return isWin(board, piece, numRows, numCols, numToWin) || isTie(board, numRows, numCols, numToWin);
}

