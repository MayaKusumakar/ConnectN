#ifndef SETUP_H
#define SETUP_H
#include <stdbool.h>
char **Init_Board(int numRows, int numCols);
void displayBoard(char **board, int numRows, int numCols);
bool isBoardFull(char **board, int numRows, int numCols);
void cleanup(char ***board, int numRows);
#endif
