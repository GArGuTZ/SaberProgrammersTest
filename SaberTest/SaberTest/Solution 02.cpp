#include "Solution 02.h"

void RemoveDups(char* _str)
{
	int inputLength = strlen(_str);

	if (inputLength < 2) // Primitive case
	{
		return;
	}

	// Count length of new str
	char currentSymbol = _str[0];
	int newLength = 2;
	for (int i = 1; i < inputLength; ++i)
	{
		if (_str[i] != currentSymbol)
		{
			currentSymbol = _str[i];
			++newLength;
		}
	}

	char* newStr = new char[newLength];
	newStr[newLength - 1] = '\0';

	// Delete duplicates
	currentSymbol = _str[0];
	newStr[0] = _str[0];
	int j = 1; // Counter for new str
	for (int i = 1; i < inputLength; ++i)
	{
		if (_str[i] != currentSymbol)
		{
			currentSymbol = _str[i];
			newStr[j] = _str[i];
			++j;
		}
	}

	// Copy result
	strcpy_s(_str, inputLength + 1, newStr);

	delete[] newStr;

	return;
}