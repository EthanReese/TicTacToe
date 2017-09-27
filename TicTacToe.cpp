/*
 *Play tic tac toe against another player
 *Date: September 19, 2017
 *Created by: Ethan Reese
 */
#include <iostream>
#include <cstdlib>

using namespace std;
//Create constants that can show turns and possession of squares
#define BLANK 0
#define X_HELD 1
#define O_HELD 2
#define X_TURN 1
#define O_TURN 2

//Define all the functions
bool checkWin(int player, int board[3][3]);
bool checkTie(int board[3][3]);
void printBoard(int board[3][3]);
void clearBoard(int board[3][3]);

int main(){
	
	//Make a variable that tracks if a user wants to keep playing
	bool stillPlaying = true;

	//Make a two dimensional int array that represents the game board
	int board[3][3];
    int oWinCounter = 0;
    int xWinCounter = 0;

	while(stillPlaying){
		//Make the initial turn X
		int turn  = X_TURN;
		//Main game loop
        clearBoard(board);

		while(!checkWin(X_HELD, board) && !checkWin(O_HELD, board) && !checkTie(board)){
            printBoard(board);
            //Check the turn and ask the proper player for the turn
            if(turn == X_TURN){
                cout << "X Turn. Please enter your move." << endl;
            }
            else if(turn == O_TURN){
                cout << "O Turn. Please enter your move." << endl;
            }
            //Get input
            char input[2];
            cin >> input;
            //Make sure the input is proper
            if(input[0] != 'a' && input[0] != 'b' && input[0] != 'c'){
                cout << "Please enter a row a, b, c" << endl;
                continue;
            }
            else if(input[1] != '1' && input[1] != '2' && input[1] != '3'){
                cout << "Please enter a column 1, 2, or 3" << endl;
                continue;
            }
            //Convert the input into usable numbers
            int row = input[0] - 'a';
            int column = input[1] - '1';
            //Check if the square is available
            if(board[row][column] == BLANK){
                //Then, check the turn and adjust the board appropriately
                if(turn == X_TURN){
                    board[row][column] = X_HELD;
                    turn = O_TURN;
                }
                else{
                    board[row][column] = O_HELD;
                    turn = X_TURN;
                }
            }
            //If the square isn't available then it needs to take another turn
            else{
                cout << "The square you picked is already taken." << endl;
                continue;
            }
        } //Restart the round while
        //If x wins then they should be congratulated
        if(checkWin(X_HELD, board)){
            cout << "X Wins.";
            ++xWinCounter;
            //Print out a properly formatted number
            if(xWinCounter == 1){
                cout << "This is X's 1st time winning";
                }
            else if(xWinCounter == 2){
                cout << "This is X's 2nd time winning";
              }
            else if(xWinCounter == 3){
                cout << "This is X's 3rd time winning";
                }
            else{
                cout << "This is X's " << xWinCounter << "th time winning";
                }
        }
        //Tell the user if O wins
        if(checkWin(O_HELD, board)){
            cout << "O Wins. ";
            ++oWinCounter;
            //Print out a properly formatted number of wins
            if(oWinCounter == 1){
                cout << "This is O's 1st time winning" << endl;
                }
            else if(oWinCounter == 2){
                cout << "This is O's 2nd time winning" << endl;
                }
            else if(oWinCounter == 3){
                cout << "This is O's 3rd time winning" << endl;
                }
            else{
                cout << "This is O's " << oWinCounter << "th time winning" << endl;
                }
        }
        if(checkTie){
            cout << "It was a tie." << endl;
        }
        //Check if the player would like to play again
        cout << "Would you like to play again? (y/n)";
        char input;
        cin >> input;
        //If the input is yes than it needs to clear the board and restart the loop
        if(tolower(input) == 'y'){
            clearBoard(board);
            turn = X_TURN;
        }
        else{
            stillPlaying = false;
            return 0;
        }
	}
	return 0;
}


//A function that checks if the board has a win condition
bool checkWin(int player, int board[3][3]){
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

//Check if it is a tie game
bool checkTie(int board[3][3]){
    //Loop through all the rows
   for(int row = 0; row < 3; row++){
         //Loop through all of the columns
        for(int column = 0; column < 3; column++){
             //If any of the slots are blank return false
            if(board[row][column] == BLANK){
                return false;
            }
        }
   }
   //If there are no blank spots then its a tie game
   return true;

}

//Function to print the game board out to the command line
void printBoard(int board[3][3]){
    cout << "\t1\t2\t3" << endl;
   //Loop through the rows of the board
    for(int row = 0; row < 3; row++){
       //Output the row letter
        cout << (char)('a' + row) << "\t";
        //Loop through the columns of the board
        for(int column = 0; column < 3; column++){
            //Check who controls each square
            if(board[row][column] == BLANK){
                cout << " \t";
            }   
            else if(board[row][column] == X_HELD){
                cout << "X\t";
            }
            else if(board[row][column] == O_HELD){
                cout << "O\t";
            }
        }
        cout << endl;
    }
}

//Function to clear off the game board
void clearBoard(int board[3][3]){
   //Loop through all rows
    for(int row = 0; row < 3; row++){
        //Loop through all columns
        for(int column = 0; column < 3; column++){
            //Make the selected board square blank
            board[row][column] = BLANK;
        }
    }
    
}


