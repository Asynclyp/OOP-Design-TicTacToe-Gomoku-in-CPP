/*
* File name: Gomoku.cpp
* Author: Yuanpeng Li
* Email: l.yuanpeng@wustl.edu
*
* It is the source file of Lab4 program that contains the definations of the functions of the Gomoku class, which contains the 
* constructor and functions: insertion operation, print(), done(), draw(), and turn().
*/


#include <fstream>
#include <sstream>
#include <iterator>

#include"GameBaseHeader.h"
#include"EnumHeader.h"
#include"GomokuHeader.h"

using namespace std;


//Constructor for Gomoku class.
Gomoku::Gomoku()
{
	OLength = constant::min;
	XLength = constant::min;
	playerTurn = true;
	instruction;
	counter = constant::min;
	gameType = false;
	
	for (int i = constant::min; i < constant::gomokuLength; ++i) {
		for (int j = constant::min; j < constant::gomokuLength; ++j) {
			gameBoard[i][j]=" ";
		}
	}
	for (int i = constant::min; i < 361; ++i) {
		instruction.push_back(" ");
	}
}


//Insertion operation that prints out the current gameboard.
ostream& operator<<(ostream& out, const Gomoku& game) {
	for (int i = constant::gomokuLength; i >= constant::mid; --i) {
		cout << i;
		for (int j = constant::min; j <= 18; ++j) {
			cout.width(3);
			cout << game.instruction[(i-constant::mid) * constant::gomokuLength + j];
		}
		cout << endl;
	}

	cout << " ";
	for (int i = constant::mid; i <= constant::gomokuLength; ++i) {
		cout.width(3);
		cout << i;
	}

	return out;
}


//Prints the current gameboard.
void Gomoku::print() {
	cout << *this;
}


//Function that checks if there are 5 pieces of same game pieces that are in alignment, which indicates a win.
bool Gomoku::done() {

	//Check vertically
	for (unsigned int i = constant::min; i < constant::gomokuLength; ++i) {
		for (unsigned int j = constant::min; j < constant::diagonal; ++j) {
			if ((gameBoard[i][j] != " ") && (gameBoard[i][j] == gameBoard[i][j+constant::mid]) && (gameBoard[i][j+constant::mid] == gameBoard[i][j+2]) && (gameBoard[i][j+2] == gameBoard[i][j+3]) && (gameBoard[i][j+3] == gameBoard[i][j+4])) {
				if (playerTurn == true) {
					winner = true;
					return true;
				}
				else {
					return true;
				}
			}
		}
		
	}

	//Check horizontally
	for (unsigned int i = constant::min; i < constant::diagonal; ++i) {
		for (unsigned int j = constant::min; j < constant::gomokuLength; ++j) {
			if ((gameBoard[i][j] != " ") && (gameBoard[i][j] == gameBoard[i+constant::mid][j]) && (gameBoard[i+constant::mid][j] == gameBoard[i+2][j]) && (gameBoard[i+2][j] == gameBoard[i+3][j]) && (gameBoard[i+3][j] == gameBoard[i+4][j])) {
				if (playerTurn == true) {
					winner = true;
					return true;
				}
				else {
					return true;
				}
			}
		}

	}

	//Check diagonally
	for (unsigned int i = constant::min; i < constant::diagonal; ++i) {
		for (unsigned int j = constant::min; j < constant::diagonal; ++j) {
			if ((gameBoard[i][j] != " ") && (gameBoard[i][j] == gameBoard[i + constant::mid][j + constant::mid]) && (gameBoard[i + constant::mid][j + constant::mid] == gameBoard[i + 2][j + 2]) && (gameBoard[i + 2][j + 2] == gameBoard[i + 3][j + 3]) && (gameBoard[i + 3][j + 3] == gameBoard[i + 4][j + 4])) {
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

	for (unsigned int i = constant::min; i < constant::diagonal; ++i) {
		for (unsigned int j = 4; j < constant::gomokuLength; ++j) {
			if ((gameBoard[i][j] != " ") && (gameBoard[i][j] == gameBoard[i + constant::mid][j - constant::mid]) && (gameBoard[i + constant::mid][j - constant::mid] == gameBoard[i + 2][j - 2]) && (gameBoard[i + 2][j - 2] == gameBoard[i + 3][j - 3]) && (gameBoard[i + 3][j - 3] == gameBoard[i + 4][j - 4])) {
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



bool Gomoku::draw() {
	bool full = true;
	for (int i = constant::min; i < constant::gomokuLength; ++i) {
		for (int j = constant::min; j < constant::gomokuLength; ++j) {
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



//Function that calls prompt() that prompts for user input and prints out the gameboard based on user inputs.
int Gomoku::turn() {

	if (playerTurn == true) {
		cout << endl;
		cout << "It is player White's turn. Please enter the coordinate:  " << endl;
		unsigned int x, y;
		if (prompt(x, y) == errorCases::quit) {
			return errorCases::quit;
		}
		cout << *this << endl;
		cout << endl;
		cout << "Player White: ";
		counter++;
		cout << endl;
		return errorCases::success;
	}
	else {
		cout << endl;
		cout << "It is player Black's turn. Please enter the coordinate:  " << endl;
		unsigned int x, y;
		if (prompt(x, y) == errorCases::quit) {
			return errorCases::quit;
		}
		cout << *this << endl;
		cout << endl;
		cout << "Player Black: ";
		counter++;
		cout << endl;
		return errorCases::success;
	}

}
 