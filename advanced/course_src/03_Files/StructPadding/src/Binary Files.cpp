//============================================================================
// Name        : Binary.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1)

struct Person {
    // cannot use string because only pointer in stack, actual data in heap
	char name[50];
	int age;
	double weight;
};

#pragma pack(pop)

int main() {

	cout << sizeof(Person) << endl;



	return 0;
}
