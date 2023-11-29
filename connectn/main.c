/*
Sets up and allows the user to play the game, connectN using arguments given in terminal to decide what the board size of rows and columns will be as well as the number needed of pieces in a row to win the game. This program also checks and makes sure all inputs are valid and will not allow a valid input.
*/
#include "setup.h"
#include "play.h"
#include "inputvalidation.h"
#include "win.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int GetRow(int argc, char** argv)
{
    /*
    GetRow gets the row argument from the arguments given in the terminal
    @argc: the number of arguments
    @argv: the actual argument given
    @returns the row given in the argument
        */
    char blank;
    int row;
    int read = sscanf(argv[1], "%d %c", &row, &blank);
    if (read != 1)
    {
        exit(0);
    }
    return row;
}

int GetCol(int argc, char** argv)
{
        /*
    GetCol gets the column argument from the arguments given in the terminal
    @argc: the number of arguments
    @argv: the actual argument given
    @returns the column given in the argument
        */
    int col;
    char blank;
    int read = sscanf(argv[2], "%d %c", &col, &blank);
    if (read != 1)
    {
        exit(0);
    }
    return col;
}

int GetNumToWin(int argc, char** argv)
{
            /*
    GetNumToWin gets the number to win argument from the arguments given in the terminal
    @argc: the number of arguments
    @argv: the actual argument given
    @returns the number to win given in the argument
        */
    char blank;
    int numToWin;
    int read = sscanf(argv[3], "%d %c", &numToWin, &blank);
    if (read != 1)
    {
        exit(0);
    }
    
    return numToWin;
}

int main(int argc, char** argv){
            /*
    main puts together the game, calling the functions necessary to play connectn
    @argc: the number of arguments
    @argv: the actual argument given
    @returns 0 if the program runs sucessfully.
        */
    if(argc < 4){
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        exit(0);
    } 
    else if (argc > 4)
    {
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }
    const char blank = '*';
    int cur_player_turn = 0;
    char* player_pieces = (char*)malloc(2*sizeof(char));
    

    player_pieces[0] = 'X';
    player_pieces[1] = 'O';
    int row = GetRow(argc, argv);
    int col = GetCol(argc, argv);
    int numToWin = GetNumToWin(argc, argv);

    char** board = Init_Board(row, col);
    PlayGame(board, row, col, numToWin, cur_player_turn, player_pieces, blank);
    cleanup(&board, row);

    return 0;
}
