#include "Solution 01.h"
#include "Solution 02.h"
#include "Solution 03.h"

void main()
{
	char* firstString = new char[10];
	strcpy_s(firstString, 10, "AAABBBbCC");
	std::cout << "firstString: " << firstString << std::endl;
	RemoveDups(firstString);
	std::cout << "firstStringRemovedDups: " << firstString << std::endl;
	delete[] firstString;

	char* secondString = new char[2];
	strcpy_s(secondString, 2, "A");
	std::cout << "secondString: " << secondString << std::endl;
	RemoveDups(secondString);
	std::cout << "secondStringRemovedDups: " << secondString << std::endl;
	delete[] secondString;

	char* thirdString = new char[8];
	strcpy_s(thirdString, 8, "AAAAAAA");
	std::cout << "thirdString: " << thirdString << std::endl;
	RemoveDups(thirdString);
	std::cout << "thirdStringRemovedDups: " << thirdString << std::endl;
	delete[] thirdString;

	char* fourthString = new char[9];
	strcpy_s(fourthString, 9, "cAAAAAAA");
	std::cout << "fourthString: " << fourthString << std::endl;
	RemoveDups(fourthString);
	std::cout << "fourthStringRemovedDups: " << fourthString << std::endl;
	delete[] fourthString;
	return;
}