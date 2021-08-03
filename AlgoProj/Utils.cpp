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
		if (input[i] < '0' || input[i]>'9')
		{
			return false;
		}
	}
	return true;
}
void Utils:: invalidInputMessage()
{
	cout << "Invalid input";
	exit(1);
}
