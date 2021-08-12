
#ifndef _UTILS_H
#define _UTILS_H

#include <string>
#include "Graph.h"
#include <string>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
using namespace std;

//This fille handles with the user input,reciving the input and verify it 
class Utils
{

public:
	//Get the input from the user,the function return -1 if the input is invalid otherwise the function returns the input
	int getInput();

	//Check if the user input is valid,if the input is valid the function will return true,otherwise-false
	bool isValidInput(string input);

	//Prints message if the user input is invalid
	void invalidInputMessage();

	//Gets the parameters of the graph (n,s,t)
	void getGraphData(int& vertexNum, int& source, int& destination);

};
#endif