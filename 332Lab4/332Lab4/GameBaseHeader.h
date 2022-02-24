/*
* File name: GameBaseHeader.h
* Author: Yuanpeng Li
* Email: l.yuanpeng@wustl.edu
*
* This header file contains the declarations of the abstract base class of GameBase, which provides common member variables and 
* functions inherited by its two derived classes.
*/


#pragma once

#include<vector>
#include<string>
#include<iterator>
#include<iostream>

#include"EnumHeader.h"



class GameBase {

protected:
	int OLength, XLength;
	std::string gameBoard[19][19];
	bool playerTurn;
	std::vector<std::string> instruction;
	int counter;
	bool winner;
	bool gameType;


public:
	
	int play();
	virtual int turn() = 0;
	virtual int prompt(unsigned int& x, unsigned int& y);
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual void print() = 0;

	static std::shared_ptr<GameBase> start(int argc, char** argv);

};




