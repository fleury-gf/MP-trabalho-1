/**
 * \file  velha.cpp
 */

#include "velha.hpp"
#include <math.h>

/** 
 * @brief verifies the situation of a tic tac toe board 
 * @author Guilherme Fleury Franco
 * @param  velha 3x3 matrix, 1 represents X, 2 represents O and zero represents a blank space
 * 
 *  recieves a matrix representing a tic tac toe board and returns the winner, if there is one, if the game is a draw, if the game is unfinished or if the board is impossible
 */

int VerificaVelha(int velha[3][3])
{
	int winner, xwin;
	int impossible = VerifyImpossible(velha); //verifies if difference beetween number of turns is more than 1
	if (impossible == -2)
		return -2; //impossible game (uneven number of turns breaks the rules)

	int sum_winner = 0;
	for (int i = 1; i < 3; i++)
	{

		winner = Verifywin(velha, i);
		if (winner == 1)
			xwin = 1;
		sum_winner += winner;
		if (sum_winner > 2)
			return -2; // impossible game (both players win)
	}
	if (xwin == 1)
		return 1;
	if (winner == 2)
		return winner;
	int result = VerifyCompletion(velha);
	return result; //returns -1 if the game is unfinished,0 if it is a draw
}
/** 
 * @brief verifies the winner, if there is one
 * @author Guilherme Fleury Franco
 * @param  win 3x3 matrix, 1 represents X, 2 represents O and zero represents a blank space player
 * @param  player indicates if the function is checking player 1 or player 2 win
 * 
 *  recieves a matrix representing a tic tac toe board and checks the rows, columns and diagonals for a winner.
 */
int Verifywin(int win[3][3], int player)
{

	int winner;
	for (int i = 0; i < 2; i++)
	{
		winner = VerifySet(win, player, i);
		if (winner > 0)
			return winner;
	}

	for (int i = 0; i < 2; i++)
	{
		winner = VerifyDiagonal(win, player, i);
		if (0 < winner)
			return winner;
	}

	return -1;
}
/** 
 * @brief verifies the winner on rows and columns
 * @author Guilherme Fleury Franco
 * @param  win 3x3 matrix, 1 represents X, 2 represents O and zero represents a blank space player
 * @param  player indicates if the function is checking player 1 or player 2 win
 * @param  r_or_c indicates if the function is checking row or column
 *  
 * recieves a matrix representing a tic tac toe board and checks the rows and columns for a winner
 */
int VerifySet(int win[3][3], int player, int r_or_c)
{
	int c, j;
	for (int i = 0; i < 3; i++)
	{ /*line verifying loop*/
		for (c = 0, j = 0; j < 3; j++)
		{
			int row = r_or_c ? i : j;
			int col = r_or_c ? j : i;
			if (win[row][col] != player)
			{
				j = 3;
			}
			if (win[row][col] == player)
			{
				c++;
			}
		}

		if (c == 3)
		{
			return player;
		}
	}

	return -1;
}
/** 
 * @brief verifies the winner on diagonals
 * @author Guilherme Fleury Franco
 * @param  win 3x3 matrix, 1 represents X, 2 represents O and zero represents a blank space player
 * @param  player indicates if the function is checking player 1 or player 2 win
 * @param  diagonal indicates if the function is checking main or secondary diagonal
 *  
 * recieves a matrix representing a tic tac toe board and checks the diagonals for a winner
 */
int VerifyDiagonal(int win[3][3], int player, int diagonal)
{

	if (win[1][1] == player)
	{ //middle space condition
		for (int c = 0, i = 0; i < 3; i += 2)
		{

			int column = diagonal ? i : 2 - i;
			if (win[i][column] == player)
			{
				c++;
			}
			if (c == 2)
			{
				return player;
			}
		}
	}

	return -1;
}
/** 
 * @brief verifies if there is any zero on the board
 * @author Guilherme Fleury Franco
 * @param  comp 3x3 matrix, 1 represents X, 2 represents O and zero represents a blank space
 * 
 *  recieves a matrix representing a tic tac toe board and checks if there is any zero
 */
int VerifyCompletion(int comp[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (comp[i][j] == 0)
				return -1;
		}
	}
	return 0;
}
/** 
 * @brief verifies impossibility by uneven number of turns
 * @author Guilherme Fleury Franco
 * @param  comp 3x3 matrix, 1 represents X, 2 represents O and zero represents a blank space
 * 
 *  recieves a matrix representing a tic tac toe board and checks if the difference beetween the number of turns of each player is more than 1
 */
int VerifyImpossible(int imp[3][3])
{
	int xcount = 0, ocount = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (imp[i][j] == 1)
				xcount++;
			if (imp[i][j] == 2)
				ocount++;
		}
	}
	if (abs(xcount - ocount) > 1)
		return -2;

	return -1;
}