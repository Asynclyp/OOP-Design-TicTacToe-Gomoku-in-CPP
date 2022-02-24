/*
* File name: GomokuHeader.h
* Author: Yuanpeng Li
* Email: l.yuanpeng@wustl.edu
*
* This header file contains the declarations of the Gomoku class, a derived class of GameBase, that contains member variables and 
* functions declarations for the Gomoku game. 
*/


#pragma once

#include<vector>
#include<string>
#include<iterator>
#include<iostream>

#include"EnumHeader.h"
#include"GameBaseHeader.h"



class Gomoku : public GameBase {
public:

	Gomoku();
	virtual void print();
	virtual bool done();
	virtual bool draw();
	virtual int turn(); 

	friend std::ostream& operator<<(std::ostream& out, const Gomoku& game);

};

std::ostream& operator<<(std::ostream& out, const Gomoku& game);