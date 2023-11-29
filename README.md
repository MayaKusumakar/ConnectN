CONNECT N

Write a program to implement the game connect-n. Connect-n is like Connect-4 but the size of the board the number of pieces in a row needed to win are user parameters. If you have never played Connect-4 before you can play it here: https://www.mathsisfun.com/games/connect4.html. The basic gist of the game is that each player takes a turn dropping one of their pieces into a column. Pieces land on top of pieces already played in that column. Each player is trying to get n pieces in a row either vertically, horizontally or diagonally. The game ends if either player gets n pieces in a row or the board becomes full.

Implementation Details:
Your program should accept 3 command-line arguments
The number of rows on the board
The number of columns on the board
The number of pieces in a row needed to win
It is ok if the number of pieces in a row needed to win is larger than what can fit on a board.
For example, on a 3 X 3 board it is ok for the number of pieces in a row needed to win to be 100
If the user does not enter enough arguments, too many arguments or invalid values your program should complain about the error made and then show the user how to call your program and then terminate
You may find exit helpful here
Player 1's pieces are represented by X
Player 2's pieces are represented by O
That's a capital Oh and not a zero
Player 1 always plays first
After the game is over a winner should be declared if there is one and if there is no winner a tie should be declared
Assumptions
Input will NOT always be valid.

If the user does not enter enough arguments, too many arguments or invalid values your program should complain about the error made and then show the user how to call your program and then terminate

Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win
If invalid input is entered while your program is running you should keep asking the user for input until they enter valid input.

Valid Input
Number of rows: An integer greater than 0
Number of columns: An integer greater than 0
Number of pieces in a row needed to win: An integer greater than 0
User Move: An integer specifying a column between 0 and the number of columns - 1 that is not already full
Requirements
Must be made of at least 3.c files and 2.h files
There must be a comment at the top of your program describing what it does
Each function in your program
Must have a comment describing what it does
Must describe what each parameter to your function means
Your program must have at least 8 user-defined functions
Restrictions
No global variables may be used
