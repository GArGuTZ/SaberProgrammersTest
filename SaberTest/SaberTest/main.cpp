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


	std::cout << "		THIRD SOLUTION		" << std::endl;
	/////////////////////// THIRD SOLUTION TESTING ///////////////
	std::string data1 = "somedata";
	std::string data2 = "some2data";
	std::string data3 = "5";
	std::string data4 = "";

	// Serialize Empty List
	List emptyL;
	std::cout << "Created Empty List" << std::endl;
	char* pathToEmpty = "Task03EmptyList.txt";
	FILE* fileToWrite = fopen(pathToEmpty, "wb");
	emptyL.Serialize(fileToWrite);
	fclose(fileToWrite);

	List emptyLRead;
	emptyLRead.push_back(data1);
	FILE* fileToRead = fopen(pathToEmpty, "rb");
	emptyLRead.Deserialize(fileToRead);
	fclose(fileToRead);
	std::cout << "Readed List:" << std::endl << emptyLRead << std::endl;

	// Serialize 4-nodes List
	List list1;
	list1.push_back(data1);
	list1.push_back(data2);
	list1.push_back(data4);
	list1.push_back(data3);
	list1.set_random(2, 1);
	list1.set_random(1, 3);
	std::cout << "Created List:" << std::endl << list1 << std::endl;
	
	char* path1 = "Task03SerializedList1.txt";
	fileToWrite = fopen(path1, "wb");
	list1.Serialize(fileToWrite);
	fclose(fileToWrite);

	List list1Read;
	fileToRead = fopen(path1, "rb");
	list1Read.Deserialize(fileToRead);
	fclose(fileToRead);
	std::cout << "Readed List:" << std::endl << list1Read << std::endl;

	// Serialize 1-node List
	List list2;
	list2.push_back(data2);
	list2.set_random(1, 1);
	list2.set_random(9, 12);
	std::cout << "Created List:" << std::endl << list2 << std::endl;

	char* path2 = "Task03SerializedList2.txt";
	fileToWrite = fopen(path2, "wb");
	list2.Serialize(fileToWrite);
	fclose(fileToWrite);

	List list2Read;
	fileToRead = fopen(path2, "rb");
	list2Read.Deserialize(fileToRead);
	fclose(fileToRead);
	std::cout << "Readed List:" << std::endl << list2Read << std::endl;

	return;
}