#ifndef PLAY_H
#define PLAY_H
#include <stdbool.h>
bool isOnBoardCol(int col, int colChoice);
bool isColEmpty(char** board, int row, int col, int colChoice, char blank);
bool isValidPlay(char** board, int row, int col, int colChoice, int num_args_read, char blank);
void PickValidCol(char **board, int row, int col, int *outCol, char blank);
void PlayerTakesTurn(char **board, int row, int col, char curPlayerPiece, char blank);
void PrintResults(char **board, int row, int col, int curPlayerTurn, int winNum, char blank);
void SwitchPlayers(int *curPlayerTurn);
void PlayGame(char **board, int row, int col, int winNum, int curPlayerTurn, char *playerPieces, char blank);
#endif
