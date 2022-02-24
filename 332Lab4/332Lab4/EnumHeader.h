/*
* File name: EnumHeader.h
* Author: Yuanpeng Li
* Email: l.yuanpeng@wustl.edu
*
* This header file contains the declarations of the usage funtion defined in the Lab1.cpp file and
* creates enumations groups for error cases and command line arguments.
*/

#pragma once

#include<vector>
#include<string>
#include<iterator>
#include<iostream>


//Enumerations:
enum errorCases { success = 0, usageMsg = 1, wrongArgc = 2, quit = 3, getLineError = 4, dimensionError = 5 };

enum argument { programName = 0, inputFile = 1, argCount = 2 };

enum constant { min = 0, mid = 1, mid2 = 2, max = 3, maxIndex = 4, repeatation = 5, diagonal = 15, gomokuLength = 19};
#pragma once


int usage(char* programName, std::string instruction);