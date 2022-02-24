/*
* File name: Other.cpp
* Author: Yuanpeng Li
* Email: l.yuanpeng@wustl.edu
*
* It is the source file of Lab4 program that contains the definations of the usage function.
*/


#include <fstream>
#include <sstream>
#include <iterator>

#include"EnumHeader.h"



using namespace std;

//Usage function that provide the user with instructions on how to execute the the program. Called when invalid formatted input
//is passed to the program.
int usage(char* programName, string instruction) {
	cout << instruction << endl;
	cout << "Usage: " << programName << " TicTacToe/Gomoku" << endl;
	return errorCases::usageMsg;
}




