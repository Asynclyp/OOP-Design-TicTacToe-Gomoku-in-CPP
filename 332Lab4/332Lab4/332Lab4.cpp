/*
* File name: 332Lab4.cpp
* Author: Yuanpeng Li
* Email: l.yuanpeng@wustl.edu
*
* It is the source file of Lab4 program that contains the main methods that executes the program which allows users to play either
* TicTacToe or Gomoku depends on the argument passed into the program.
*/


#include <fstream>
#include <sstream>
#include <iterator>

#include"GameBaseHeader.h"
#include"EnumHeader.h"


using namespace std;


int main(int argc, char** argv){

	shared_ptr<GameBase> game = GameBase::start(argc, argv);

	if (game != 0) {
		game->play();
		
	}
	else {
		string usageMsg = "The program takes one argument of either TicTacToe or Gomoku";
		return usage(argv[argument::programName], usageMsg);
	}
	return errorCases::success;
}

