#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include <string>
#include "Graph.h"
#include <string>
using namespace std;

class Algorithm
{
public:
	void shortPathAlgorithm();
	bool isValidInput(string input);
	void getInput(int& n, int& t, int& s);
	void executeShortPathAlgorithm();
	//Graph algorithmFirstSteps(int& n, int& s, int& t, Graph& g2);

private:

};


#endif 