
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
	int getInput();
	bool isValidInput(string input);
	void invalidInputMessage();
	void getGraphData(int& vertexNum, int& source, int& destination);

};
#endif