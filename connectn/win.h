#ifndef WIN_H
#define WIN_H
#include <stdbool.h>
bool checkWinHorizontally(char **board, char piece, int numRows, int numCols, int numToWin);
bool checkWinVertically(char **board, char piece, int numRows, int numCols, int numToWin);
bool checkWinDiagonallyOnLeft(char **board, char piece, int numRows, int numCols, int numToWin);
bool checkWinDiagonallyOnRight(char **board, char piece, int numRows,
int numCols, int numToWin);
bool isWin(char **board, char piece, int numRows, int numCols,
int numToWin);
bool isTie(char **board, int numRows, int numCols, int numToWin);
bool isGameOver(char **board, char piece, int numRows, int numCols, int numToWin);
bool isBoardFull(char **board, int numRows, int numCols);
#endif