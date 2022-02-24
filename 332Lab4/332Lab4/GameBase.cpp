/*
* File name: GameBase.cpp
* Author: Yuanpeng Li
* Email: l.yuanpeng@wustl.edu
*
* It is the source file of Lab4 program that contains the definations of the functions of GameBase class: play(), prompt(),
* and start() functions that are common to both derived classes.
*/

#include <fstream>
#include <sstream>
#include <iterator>

#include"GameBaseHeader.h"
#include"EnumHeader.h"
#include"GomokuHeader.h"
#include"TicTacToeHeader.h"



using namespace std;




//Funtion that repeatedly calls turn() until there is a winner or the game is draw. Returns the winner and the number of steps that
//has been played.
int GameBase::play() {
	print();
	cout << endl;
	while ((done() == false && draw() == false)) {

		if (turn() == errorCases::quit) {
			cout << "Player quits. " << counter << " turns has been played." << endl;
			return errorCases::quit;
		}


	}
	if (done() == true) {
		if (gameType == true) {
			if (winner == true) {
				cout << "Player O wins!!!";
			}
			else {
				cout << "Player X wins!!!"; 
			}
		}
		else {
			if (winner == false) {
				cout << "Player B wins!!!";
			}
			else {
				cout << "Player W wins!!!";
			}
		}
	}
	else {
		cout << "No more available moves remain. " << counter << " turns has been played. This is a draw." << endl;
	}
	return constant::min;
}



//Function that prompts for user input on the location of the game pieces on the gameboard. 
int GameBase::prompt(unsigned int& x, unsigned int& y) {

	string temp;
	cin >> temp;
	if (temp == "quit") {
		return errorCases::quit;
	}

	if (gameType == true) {
		while (temp[constant::mid] != ',') {
			cout << "Invalid input. Please enter the coordinate in following format: x,y" << endl;
			cin >> temp;
			if (temp == "quit") {
				return errorCases::quit;
			}
		}

		temp[1] = ' ';
		stringstream iss(temp);
		iss >> x >> y;
		while ((x < constant::mid || x > constant::max || y < constant::mid || y > constant::max) || (gameBoard[x - constant::mid][y - constant::mid] != " ")) {
			if (x < constant::mid || x > constant::max || y < constant::mid || y > constant::max) {
				cout << "The input is out of the bound of 1-3. Please re-enter the coordinate by the format: x,y " << endl;
			}
			else {
				cout << "The coordinate has been occupied. Please choose an empty coordinate: " << endl;
			}
			cin >> temp;
			if (temp == "quit") {
				return errorCases::quit;
			}
			while (temp[constant::mid] != ',') {
				if (temp == "quit") {
					return errorCases::quit;
				}
				cout << "Invalid input. Please enter the coordinate in following format: x,y" << endl;
				cin >> temp;
			}
			temp[constant::mid] = ' ';
			stringstream iss(temp);
			iss >> x >> y;
		}

		unsigned int index = (x + constant::mid) + constant::repeatation * y;
		
		if (playerTurn == true) {
			//O_Record.push_back(piece_O(x, y));
			OLength++;
			instruction[index] = "O";
			gameBoard[x - constant::mid][y - constant::mid] = "O";
			return constant::min;
		}
		else {
			//X_Record.push_back(piece_X(x, y));
			XLength++;
			instruction[index] = "X";
			gameBoard[x - constant::mid][y - constant::mid] = "X";
			return constant::min;
		}
	}

	else {

		while (temp[constant::mid2] != ',' && temp[constant::mid]!=',') {
			cout << "Invalid input. Please enter the coordinate in following format: x,y" << endl;
			cin >> temp;
			if (temp == "quit") {
				return errorCases::quit;
			}
		}

		if (temp[constant::mid2] == ',') {
			temp[constant::mid2] = ' ';
			stringstream iss(temp);
			iss >> x >> y; 

			while ((x < constant::mid || x > constant::gomokuLength || y < constant::mid || y > constant::gomokuLength) || (gameBoard[x - constant::mid][y - constant::mid] != " ")) {
				if (x < constant::mid || x > constant::gomokuLength || y < constant::mid || y > constant::gomokuLength) {
					cout << "The input is out of the bound of 1-19. Please re-enter the coordinate by the format: x,y " << endl;
				}
				else {
					cout << "The coordinate has been occupied. Please choose an empty coordinate: " << endl;
				}
				cin >> temp;
				if (temp == "quit") {
					return errorCases::quit;
				}
				while (temp[constant::mid2] != ',' && temp[constant::mid] != ',') {
					if (temp == "quit") {
						return errorCases::quit;
					}
					cout << "Invalid input. Please enter the coordinate in following format: x,y" << endl;
					cin >> temp;
				}
				if (temp[constant::mid2] == ',') {
					temp[constant::mid2] = ' ';
					stringstream iss(temp);
					iss >> x >> y;
				}
				else {
					temp[1] = ' ';
					stringstream iss(temp);
					iss >> x >> y;
				}
			}

			unsigned int index = (x - constant::mid) + constant::gomokuLength * (y - constant::mid);

			if (playerTurn == true) {
				//O_Record.push_back(piece_O(x, y));
				OLength++;
				instruction[index] = "W";
				gameBoard[x - constant::mid][y - constant::mid] = "W";
				return constant::min;
			}
			else {
				//X_Record.push_back(piece_X(x, y));
				XLength++;
				instruction[index] = "B";
				gameBoard[x - constant::mid][y - constant::mid] = "B";
				return constant::min;
			}
		}

		else {
			temp[constant::mid] = ' ';
			stringstream iss(temp);
			iss >> x >> y;
			while ((x < constant::mid || x > constant::gomokuLength || y < constant::mid || y > constant::gomokuLength) || (gameBoard[x - constant::mid][y - constant::mid] != " ")) {
				if (x < constant::mid || x > constant::gomokuLength || y < constant::mid || y > constant::gomokuLength) {
					cout << "The input is out of the bound of 1-19. Please re-enter the coordinate by the format: x,y " << endl;
				}
				else {
					cout << "The coordinate has been occupied. Please choose an empty coordinate: " << endl;
				}
				cin >> temp;
				if (temp == "quit") {
					return errorCases::quit;
				}
				while (temp[constant::mid2] != ',' && temp[constant::mid] != ',') {
					if (temp == "quit") {
						return errorCases::quit;
					}
					cout << "Invalid input. Please enter the coordinate in following format: x,y" << endl;
					cin >> temp;
				}
				if (temp[constant::mid2] == ',') {
					temp[constant::mid2] = ' ';
					stringstream iss(temp);
					iss >> x >> y;
				}
				else {
					temp[constant::mid] = ' ';
					stringstream iss(temp);
					iss >> x >> y;
				}
			}

			unsigned int index = (x - constant::mid) + constant::gomokuLength * (y - constant::mid);

			if (playerTurn == true) {
				//O_Record.push_back(piece_O(x, y));
				OLength++;
				cout <<"Index :  " << index << endl;
				instruction[index] = "W";
				gameBoard[x - constant::mid][y - constant::mid] = "W";
				return constant::min;
			}
			else {
				//X_Record.push_back(piece_X(x, y));
				XLength++;
				cout << "Index :  " << index << endl;
				instruction[index] = "B";
				gameBoard[x - constant::mid][y - constant::mid] = "B";
				return constant::min;
			}
		}		
	}
}
	
	


//Function that construct a specified game type depends on user input. Returns a pointer to the object constructed for later
//calls of functions.
 shared_ptr<GameBase> GameBase::start(int argc, char** argv) {
	 if (argc == argument::argCount) {
		 cout << argv[1] << endl;
		 if (strcmp(argv[1],"TicTacToe")==0) {
			shared_ptr<TicTacToeGame> game = make_shared<TicTacToeGame>();
			return game;
		 }
		 else if (strcmp(argv[1],"Gomoku")==0) {
			shared_ptr<GameBase> game = make_shared<Gomoku>();
			return game;
		 }
		 else {
			 return 0;
		 }
	 }
	 else {
		 cout << "3" << endl;
		 return 0;
	 }
	 
}










// Run program: Ctrl + Fconstant::repeatation or Debug > Start Without Debugging menu
// Debug program: Fconstant::repeatation or Debug > Start Debugging menu

// Tips for Getting Started: 
//   constant::mid. Use the Solution Explorer window to add/manage files
//   constant::mid2. Use the Team Explorer window to connect to source control
//   constant::max. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   constant::repeatation. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
