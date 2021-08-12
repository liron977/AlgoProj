#include "Utils.h"

int Utils::getInput()
{
	string userInput;
	cin >> userInput;
	if (!cin.eof()) {
		if (!isValidInput(userInput))
		{
			invalidInputMessage();
		}

		return stoi(userInput);
	}

	return -1;
}
bool Utils::isValidInput(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] < '0' || input[i]>'9')//vetify if the char is a number
		{
			return false;
		}
	}
	return true;
}
void Utils::invalidInputMessage()
{
	cout << "Invalid input";
	exit(1);
}
void Utils::getGraphData(int& vertexNum, int& source, int& destination)
{
	int n,s,t;
	n = getInput();
	if (vertexNum == -1)
	{
		invalidInputMessage();
	}
	s =getInput();
	if (source == -1)
	{
		invalidInputMessage();
	}
	t =getInput();
	if (destination == -1)
	{
	 invalidInputMessage();
	}
	vertexNum = n;
	source = s;
	destination = t;
}