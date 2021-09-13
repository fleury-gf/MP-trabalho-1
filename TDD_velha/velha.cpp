/**
 * \file  velha.cpp
 */

#include "velha.hpp"
#include <math.h>

/** 
 * @brief verifica situacao do jogo da velha  
 * @author Programador 
 * @param  velha descreve o parametro
 * 
 *  Descrever o que a funcao faz
 */

int VerificaVelha(int velha[3][3])
{
	int impossible = VerifyImpossible(velha); //verifies if difference beetween number of turns is more than 1
	if (impossible == -2)
		return -2; //impossible game (uneven number of turns breaks the rules)

	int sum_result = 0;
	for (int i = 1; i < 3; i++)
	{

		auto result = Verifywin(velha, i);
		sum_result += result;
		if (sum_result > 2)
			return -2; // impossible game (both players win)
	}

	int result = VerifyCompletion(velha);
	return result; //returns -1 if the game is unfinished,0 if it is a draw
}

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