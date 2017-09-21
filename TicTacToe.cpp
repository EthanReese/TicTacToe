/*
 *Play tic tac toe against another player
 *Date: September 19, 2017
 *Created by: Ethan Reese
 */
#include <iostream>
#include <cstdlib>
//Create constants that can show turns and possession of squares
#define BLANK = 0;
#define X_HELD = 1;
#define O_HELD = 2;
#define X_TURN = 1;
#define O_TURN = 2;

//Define all the functions
boolean checkWin(int player, int[][] board);
boolean checkTie(int[][] board);

int main(){
	//Make counters that can count how many wins each player has
	int xWins = 0;
	int oWins = 0;
	int tie = 0;
	
	//Make a variable that tracks if a user wants to keep playing
	boolean stillPlaying = true;

	//Make a two dimensional int array that represents the game board
	int board[3][3];

	while(stillPlaying){
		//Make the initial turn X
		int turn  = X_TURN;
		//Main game loop
		while(checkWin(X_HELD, board) == false && checkWin(O_HELD, board) && !checkTie()){

		}
	}
	return 0;
}


//A function that checks if the board has a win condition
boolean checkWin(int player, int[][] board){
	//Check all of the possible win conditions
	if(board[0][0] == player && board[0][1] == player && board[0][2] == player){
		return true;
	}
	if(board[1][0] == player && board[1][1] == player && board[1][2] == player){
		return true;
	}
	if(board[2][0] == player && board[2][1] == player && board[2][2] == player){
		return true;
	}
	if(board[0][0] == player && board[1][0] == player && board[2][0] == player){
		return true;
	}
	if(board[0][1] == player && board[1][1] == player && board[2][1] == player){
		return true;
	}
	if(board[0][2] == player && board[1][2] == player && board[2][2] == player){
		return true;
	}
	if(board[0][0] == player && board[1][1] == player && board[2][2]== player){
		return true;
	}
	if(board[2][0] == player && board[1][1] == player &&board[0][2] == player){
		return true;
	}
	else{
		return false;
	}
}


