#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include <string>
#include "Graph.h"
#include <string>
using namespace std;

class Algorithm
{
public:
	//The function activates the main function shortPathAlgorithm and calculate the run time
	void executeShortPathAlgorithm();
private:
	//The function verify if the user input includes obly numbers
	bool isValidInput(string input);
	//The function finds shortest path from a single vertex to a target vertex in directional graphs
	void shortPathAlgorithm();
	//The function recives the user input: the number of vertexs, single vertex and a target vertex 
	void getInput(int& n, int& t, int& s);
};


#endif 