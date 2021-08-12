
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
class Utils
{
public:
	//Get the input from the user
	int getInput();
	//Check if the user input is valid
	bool isValidInput(string input);
	//Prints message if the user input is invalid
	void invalidInputMessage();
	//Gets the parameters of the graph (n,s,t)
	void getGraphData(int& vertexNum, int& source, int& destination);

};
#endif