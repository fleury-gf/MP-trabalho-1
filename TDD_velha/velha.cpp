/**
 * \file  velha.cpp
 */

#include "velha.hpp"

/** 
 * @brief verifica situacao do jogo da velha  
 * @author Programador 
 * @param  velha descreve o parametro
 * 
 *  Descrever o que a funcao faz
 */

int VerificaVelha(int velha[3][3])
{
	for (int i = 1; i < 3; i++)
	{
		Verifywin(velha, i);
	}

	return 0; /*!< retorna zero para teste */
}

int Verifywin(int win[3][3], int player)
{

	int winner, sum_result = 0;
	for (int i = 0; i < 2; i++)
	{
		auto resultrc = VerifySet(win, player, i);
		sum_result += resultrc;
	}
	if (sum_result > 2)
	{
		return -2;
	}
	for (int i = 0; i < 2; i++)
	{
		VerifyDiagonal(win, player, i);
	}

	return 0;
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

	if (win[1][1] == 1)
	{ //middle space condition
		for (int c, i = 0; i < 3; i += 2)
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
