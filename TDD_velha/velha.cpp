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

int VerificaVelha( int velha[3][3] )
{	
	return 0; /*!< retorna zero para teste */
}

int VerifyXwin( int xwin[3][3])
{
	int c,i,j;  
	for(i=0;i<3;i++){     /*line verifying loop*/
	for (c=0,j=0; j<3; j++){
		if (xwin[i][j] != 1){
			j=3;
		}
		if (xwin[i][j] == 1){
			c++;

		}
		
		

	}
		
		
		if (c == 3) {
			return 1;
		}

		
	}

	for(i=0;i<3;i++){       /*column verifying loop*/
	for (c=0,j=0; j<3; j++){
		if (xwin[j][i] != 1){
			j=3;
		}
		if (xwin[j][i] == 1){
			c++;

		}
		
		

	}
		
		
		if (c == 3) {
			return 1;
		}

		
	}



	return 0;
}


int VerifyOwin( int owin[3][3])
{
	int c,i,j;  
	for(i=0;i<3;i++){     /*line verifying loop*/
	for (c=0,j=0; j<3; j++){
		if (owin[i][j] != 2){
			j=3;
		}
		if (owin[i][j] == 2){
			c++;

		}
		
		

	}
		
		
		if (c == 3) {
			return 2;
		}

		
	}

	for(i=0;i<3;i++){       /*column verifying loop*/
	for (c=0,j=0; j<3; j++){
		if (owin[j][i] != 2){
			j=3;
		}
		if (owin[j][i] == 2){
			c++;

		}
		
		

	}
		
		
		if (c == 3) {
			return 2;
		}

		
	}



	return 0;
}
