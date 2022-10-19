// Bishop Lohman
// Assignment 1
// 303
// Created: 9/19/22
// Due: 9/23/22

#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

void main() {
	ifstream fin("input.txt");
	char userInput;
	int arraySize = 100;
	int* numArray = new int[arraySize];

	FillArray(fin, arraySize, numArray);

	do {
		userInput = UserOption();

		switch (userInput) {
		case 'a':
			OutputArray(arraySize, numArray);
			break;
		case 'b':
			FindValue(arraySize, numArray);
			break;
		case 'c':
			ModifyValueOutput(arraySize, numArray);
			break;
		case 'd':
			AddValue(arraySize, numArray);
			break;
		case 'e':
			RemoveValue(arraySize, numArray);
			break;
		case 'q':
			break;
		default:
			cout << "Invalid Input" << endl;
			break;
		}

		cin.clear();
		cin.ignore(512, '\n');
		//I might remove this later
	} while (userInput != 'q');
}