/*
* File name: TicTacToeHeader.h
* Author: Yuanpeng Li
* Email: l.yuanpeng@wustl.edu
*
* This header file contains the declarations of the TicTacToe class, a derived class of GameBase, that contains member variables and
* functions declarations for the TicTacToe game.
*/


#pragma once

#include<vector>
#include<string>
#include<iterator>
#include<iostream>

#include"EnumHeader.h"
#include"GameBaseHeader.h"

class TicTacToeGame : public GameBase {

public:
	TicTacToeGame();
	virtual void print();
	virtual bool done();
	virtual bool draw();
	virtual int turn();

	friend std::ostream& operator<<(std::ostream& out, const TicTacToeGame& game);
};

std::ostream& operator<<(std::ostream& out, const TicTacToeGame& game);





