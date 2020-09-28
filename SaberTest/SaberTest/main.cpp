#define _CRT_SECURE_NO_DEPRECATE

#include "Solution 01.h"
#include "Solution 02.h"
#include "Solution 03.h"

#include <bitset>
#include <cstdio>


void main()
{
	/////////////////////// FIRST SOLUTION TESTING ///////////////
	std::cout << "     FIRST SOLUTION     " << std::endl;
	int firstInt = 0;
	std::cout << "firstInt: " << firstInt << std::endl;
	std::cout << "firstInt binary: " << std::endl << std::bitset<32>(firstInt).to_string() << std::endl;
	std::cout << "my representation: " << std::endl; 
	DecimalToBinary(firstInt);
	int secondInt = -1;
	std::cout << "secondInt: " << secondInt << std::endl;
	std::cout << "secondInt binary: " << std::endl << std::bitset<32>(secondInt).to_string() << std::endl;
	std::cout << "my representation: " << std::endl;
	DecimalToBinary(secondInt);
	int thirdInt = 5;
	std::cout << "thirdInt: " << thirdInt << std::endl;
	std::cout << "thirdInt binary: " << std::endl << std::bitset<32>(thirdInt).to_string() << std::endl;
	std::cout << "my representation: " << std::endl;
	DecimalToBinary(thirdInt);
	int fourthInt = -1023;
	std::cout << "fourthInt: " << fourthInt << std::endl;
	std::cout << "fourthInt binary: " << std::endl << std::bitset<32>(fourthInt).to_string() << std::endl;
	std::cout << "my representation: " << std::endl;
	DecimalToBinary(fourthInt);
	int fifthInt = -2147483647;
	std::cout << "fifthInt: " << fifthInt << std::endl;
	std::cout << "fifthInt binary: " << std::endl << std::bitset<32>(fifthInt).to_string() << std::endl;
	std::cout << "my representation: " << std::endl;
	DecimalToBinary(fifthInt);
	int sixthInt = 2147483647;
	std::cout << "sixthInt: " << sixthInt << std::endl;
	std::cout << "sixthInt binary: " << std::endl << std::bitset<32>(sixthInt).to_string() << std::endl;
	std::cout << "my representation: " << std::endl;
	DecimalToBinary(sixthInt);


	std::cout << "     SECOND SOLUTION     " << std::endl;
	/////////////////////// SECOND SOLUTION TESTING ///////////////
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


	std::cout << "     THIRD SOLUTION     " << std::endl;
	/////////////////////// THIRD SOLUTION TESTING ///////////////

	std::string a1 = "somedata";
	ListNode LN1 = { NULL, NULL, NULL, a1 };
	std::string a2 = "some2data";
	ListNode LN2 = { NULL, NULL, NULL, a2 };
	//LN.data = a;
	//std::cout << "LN: " << LN.next << std::endl;

	List l;
	l.push_back(a1);
	l.push_back(a2);
	l.push_back(a2);
	l.set_random(1, 2);
	std::cout << l << std::endl;

	std::cout << "		Test FILES		" << std::endl;

	char* path = "Task03SerializedList.txt";
	FILE* fileToWrite = fopen(path, "wb");
	l.Serialize(fileToWrite);
	fclose(fileToWrite);

	FILE* fileToRead = fopen(path, "rb");
	//l.Deserialize(fileToRead);
	fclose(fileToRead);
	/*
	FILE* f1;
	f1 = fopen("Task03SerializedList.txt", "w");
	fwrite("somedata", sizeof(char), sizeof("somedata"), f1);
	fclose(f1);

	FILE* f2B;
	f2B = fopen("Task03SerializedListBINARY.bin", "wb");
	fwrite("some3data", sizeof(char), sizeof("some3data"), f2B);
	fclose(f2B);
	*/

	return;
}