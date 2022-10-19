#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"
using namespace std;

void FillArray(ifstream& fin, int arraySize, int*& numArray) {
	while (fin.good()) {
		for (int i = 0; i < arraySize; i++) {
			fin >> numArray[i];
		}
	}
}

void PrintMenu() {
	cout << "Menu:" << endl;
	cout << "a) - print array" << endl;
	cout << "b) - Find Value" << endl;
	cout << "c) - Modify Value" << endl;
	cout << "d) - Add Value" << endl;
	cout << "e) - Remove Value" << endl;
	cout << "q) - quit" << endl << endl;
}

//I cpuld use getline and string for this garbage
char UserOption() {
	//list of possible options
	string inputOptions = "abcdeq";
	char userOption;
	PrintMenu();
	while (true) {
		cout << "Input option => ";
		cin >> userOption;
		cout << endl;
		if (inputOptions.find(tolower(userOption)) != string::npos) {
			return tolower(userOption);
		}
		else {
			cout << "Incorrect Input - Try Again" << endl;
		}
	}
}

void OutputArray(int arraySize, int numArray[]) {
	for (int i = 0; i < (arraySize - 1); i++) {
		cout << numArray[i] << ", ";
		//formats the output so that the numbers are in lines of 10
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}
	cout << numArray[arraySize-1] << endl << endl;
}

void FindValue(int arraySize, int numArray[]) {
	int index;
	int userInput;
	while (true) {
		try {
			userInput = ValueNum();
			index = SearchValue(userInput, arraySize, numArray);
			break;
		}
		catch (runtime_error& ex) {
			cout << ex.what() << endl << "Enter a different value to search" << endl << endl;
		}
		catch (...) {
			cout << "Undefined exception occurred when searching for a value";
			abort();
		}
	}

	if (index == -1) {
		cout << "Number not found" << endl << endl;
	}
	else {
		cout << "Value " << userInput << " found at index " << index << endl << endl;
	}
}

//used in both FindValue and ModifyValue
int ValueNum() {
	string userInput;
	bool inputCheck;

	cout << "Input a value => ";
	cin >> userInput;
	inputCheck = CheckingInput(userInput);

	if (!inputCheck) {
		throw runtime_error("Invalid value for input");
	}
	return stoi(userInput);
}

//used in FindValue
int SearchValue(int userInput, int arraySize, int numArray[]) {
	//the entire array is searched to find the first occurence of the value
	for (int i = 0; i < arraySize + 1; i++) {
		if (numArray[i] == userInput) {
			return i;
		}
	}
	return -1;
}

int ModifyValue(int arraySize, int*& numArray, int userIndex) {
	int newUserValue;

	newUserValue = ValueNum();
	numArray[userIndex] = newUserValue;

	//the new value
	return newUserValue;
	
}

void ModifyValueOutput(int arraySize, int*& numArray){
	int originalValue;
	int newUserValue;
	int userIndex;

	while (true) {
		try {
			userIndex = VerifyIndex(arraySize);
			originalValue = numArray[userIndex];
			newUserValue = ModifyValue(arraySize, numArray, userIndex);
			cout << endl;
			break;
		}
		catch (runtime_error& ex) {
			cout << ex.what() << endl << "Try modifying value again" << endl << endl;
		}
		catch (...) {
			cout << "Undefined exception occurred when modifying a value";
			abort();
		}
	}

	OutputArray(arraySize, numArray);
	cout << "Original value: " << originalValue << " New value: " << newUserValue << endl << endl;
}

//used in ModifyValueOutput and RemoveValue
int VerifyIndex(int arraySize) {
	string userInput;
	bool inputCheck;

	cout << "Input index => ";
	cin >> userInput;
	inputCheck = CheckingInput(userInput);

	//clears the stream and throws an error if the input is not an integer
	if (!inputCheck) {
		throw runtime_error("Invalid value for index input");
	}
	else if ((stoi(userInput) < 0) || (stoi(userInput) >= arraySize)) {
		throw runtime_error("Error: Index out of range");
	}
	else {
		cout << endl;
		return stoi(userInput);
	}
}

void AddValue(int& arraySize, int*& numArray) {
	int newValue;

	while (true){
		try {
			newValue = AddValueNum();
			break;
		}
		catch (runtime_error& ex) {
			cout << ex.what() << endl << endl;
		}
		catch (...) {
			cout << "Undefined exception occurred when inputting a value";
			abort();
		}
	}

	//calls the increase array function before placing the new value
	IncreaseArray(arraySize, numArray);
	numArray[arraySize - 1] = newValue;
	OutputArray(arraySize, numArray);
}

void IncreaseArray(int& arraySize, int*& numArray) {
	arraySize++;
	int* q = new int[arraySize];
	//The values are coppied into the new larger array
	for (int i = 0; i < arraySize; i++) {
		q[i] = numArray[i];
	}

	delete[]numArray;
	numArray = q;
	q = NULL;
}

int AddValueNum() {
	string userInput;
	bool inputCheck;
	cout << "Input a value to add => ";
	cin >> userInput;
	inputCheck = CheckingInput(userInput);

	if (!inputCheck) {
		throw runtime_error("Invalid input for value to add");
	}
	cout << endl;
	return stoi(userInput);
}

void RemoveValue(int& arraySize, int*& numArray) {
	int userIndex;

	while (true) {
		try{
			userIndex = VerifyIndex(arraySize);
			DecreaseArray(userIndex, arraySize, numArray);
			OutputArray(arraySize, numArray);
			break;
		}
		catch (runtime_error& ex) {
			cout << ex.what() << endl << endl;
		}
		catch (...) {
			cout << "Undefined exception occurred when remvoing a value";
			abort();
		}
	}
}

void DecreaseArray(int numIndex, int& arraySize, int*& numArray) {
	arraySize--;
	int* q = new int[arraySize];
	//the loop skips over the index of the removed value when copying everything
	for (int i = 0; i < arraySize + 1; i++) {
		if (i < numIndex) {
			q[i] = numArray[i];
		}
		else if (i > numIndex) {
			q[i - 1] = numArray[i];
		}
	}

	delete[]numArray;
	numArray = q;
	q = NULL;
}

bool CheckingInput(string userInput) {
	for (int i = 0; i < userInput.size(); i++) {\
		//returns false if a non-number is reached
		if (!isdigit(userInput.at(i)))
			return false;
	}
	return true;
}