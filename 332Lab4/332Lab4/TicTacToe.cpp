/*
* File name: TicTacToe.cpp
* Author: Yuanpeng Li
* Email: l.yuanpeng@wustl.edu
*
* It is the source file of Lab4 program that contains the definations of the functions of the TicTacToe class, which contains the
* constructor and functions: insertion operation, print(), done(), draw(), and turn().
*/


#include <fstream>
#include <sstream>
#include <iterator>

#include"GameBaseHeader.h"
#include"EnumHeader.h"
#include"GomokuHeader.h"
#include"TicTacToeHeader.h"

using namespace std;

//Constructor for TicTacToe class
TicTacToeGame::TicTacToeGame()
{
	OLength = constant::min;
	XLength = constant::min;
	playerTurn = true;
	instruction;
	counter = constant::min;
	gameType = true;

	for (int i = constant::min; i < constant::gomokuLength; ++i) {
		for (int j = constant::min; j < constant::gomokuLength; ++j) {
			gameBoard[i][j] = " ";
		}
	}
	for (int i = constant::min; i < 25; ++i) {
		instruction.push_back(" "); 
	}
}


//Function that calls prompt() that prompts for user input and prints out the gameboard based on user inputs.
int TicTacToeGame::turn() {

	if (playerTurn == true) {
		cout << endl;
		cout << "It is player O's turn. Please enter the coordinate:  " << endl;
		unsigned int x, y;
		if (prompt(x, y) == errorCases::quit) {
			return errorCases::quit;
		}
		cout << *this << endl;
		cout << endl;
		cout << "Player O: ";
		counter++;
		cout << endl;
		return errorCases::success;
	}
	else {
		cout << endl;
		cout << "It is player X's turn. Please enter the coordinate:  " << endl;
		unsigned int x, y;
		if (prompt(x, y) == errorCases::quit) {
			return errorCases::quit;
		}
		cout << *this << endl;
		cout << endl;
		cout << "Player X: ";
		counter++;
		cout << endl;
		return errorCases::success;
	}

}


//Function that check if there are 3 aligned same pieces, which indicates a win. 
bool TicTacToeGame::done() {


	//Check vertically
	for (unsigned int i = constant::min; i < constant::gomokuLength; ++i) {
		if ((gameBoard[i][constant::min] != " ") && (gameBoard[i][constant::min] == gameBoard[i][constant::mid]) && (gameBoard[i][constant::mid] == gameBoard[i][constant::mid2])) {
			if (playerTurn == true) {
				winner = true;
				return true;
			}
			else {
				return true;
			}
		}
	}

	//Check horizontally
	for (unsigned int i = constant::min; i < constant::gomokuLength; ++i) {
		if ((gameBoard[constant::min][i] != " ") && (gameBoard[constant::min][i] == gameBoard[constant::mid][i]) && (gameBoard[constant::mid][i] == gameBoard[constant::mid2][i])) {
			if (playerTurn == true) {
				winner = true;
				return true;
			}
			else {
				winner = false;
				return true;
			}
		}
	}

	//Check diagonally
	for (unsigned int i = constant::min; i < 14; ++i) {
		for (unsigned int j = constant::min; j < 14; ++j) {
			if ((gameBoard[i][j] != " ") && (gameBoard[i][j] == gameBoard[i+constant::mid][j+constant::mid]) && (gameBoard[i+constant::mid][j+constant::mid] == gameBoard[i+2][j+2])) {
				if (playerTurn == true) {
					winner = true;
					return true;
				}
				else {
					winner = false;
					return true;
				}
			}
		}
	}
	

	for (unsigned int i = constant::min; i < 14; ++i) {
		for (unsigned int j = 4; j < constant::gomokuLength; ++j) {
			if ((gameBoard[i][j] != " ") && (gameBoard[i][j] == gameBoard[i+1][j-constant::mid]) && (gameBoard[i+constant::mid][j-constant::mid] == gameBoard[i+2][j-2])) {
				if (playerTurn == true) {
					winner = true;
					return true;
				}
				else {
					winner = false;
					return true;
				}
			}
		}
	}



	if (playerTurn == true) {
		playerTurn = false;
		return false;
	}
	else {
		playerTurn = true;
		return false;
	}

	 
}


//Function that detect if there is no available step for any of the player to win the game. 
bool TicTacToeGame::draw() {
	bool full = true;
	for (int i = constant::min; i < constant::max; ++i) {
		for (int j = constant::min; j < constant::max; ++j) {
			if (gameBoard[i][j] == " ") {
				full = false;
			}
		}
	}

	if (full == true) {
		return true;
	}
	else {
		return false;
	}

}


//Print the current gameboard.
void TicTacToeGame::print() {
	cout << *this;
}


//Insertion operation that print out the current gameboard.
ostream& operator<<(ostream& out, const TicTacToeGame& game) {
	for (int i = 4; i >= constant::min; --i) {
		cout << i;
		for (int j = constant::mid; j < 5; ++j) {
			cout.width(2);
			cout << game.instruction[i * constant::repeatation + j];

		}
		cout << endl;
	}

	cout << " ";
	for (int i = constant::min; i <= 4; ++i) {
		cout.width(2);
		cout << i;
	}

	return out;


}
