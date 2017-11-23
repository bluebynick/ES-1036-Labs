#include <iostream>
#include <ctime>
#include <string>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

/*
Nick's Array Sorter
Programmer: Nicholas Paul
Date: November 21st 2017

In this program we will sort an array of number you put in based upon whether you want them ascending or descending

Notes:
-used my methods from lab05_q2
*/

using namespace std;

void header();
void printHeader(string name, int lab, string date, int question);
void printFooter();
int displayMenu();
void sortAscending(int unsortedArray[], int size);
void sortDescending(int unsortedArray[], int size);

int intArray[10];
int unsortedArray[10];

int main() {
	//introduction
	header();
	\
		cout << "Please input your 10 numbers for the array:\n";
	//input of array indices
	for (int i = 0; i < 10; i++) {
		while (true) { //while the error catcher is false

			cin >> intArray[i]; //input the value held in the array at the index = to counter

			if (cin.good()) { //check for numericy
				unsortedArray[i] = intArray[i];
				break;
			}
			else { //tell user about the error
				cout << "\nPlease input an integer\n";
				cin.clear();
				cin.ignore();
			}
		}
	}

	while (true) {
		if (displayMenu() == 1) {
			for (int i = 0; i < 10; i++) {
				sortAscending(intArray, 10);
			}
			break;
		}

		else if (displayMenu() == 2) {
			for (int i = 0; i < 10; i++) {
				sortDescending(intArray, 10);
			}
			break;
		}
	}


	//final output
	cout << "\n\nBased on your inputs, your unsorted array would be: \n" << endl;
	for (int i = 0; i < 10; i++) {
		cout << unsortedArray[i] << endl;
	}
	cout << "\n\nBased on your inputs, your sorted array would be: \n" << endl;
	for (int i = 0; i < 10; i++) {
		cout << intArray[i] << endl;
	}
	printFooter();
}

void header() {
	const time_t timer = time(0); //creates a char pointer with the current time 

	tm* ttyl = localtime(&timer); //create a pointer of variable name ttyl of the struct type tm from the c++ time library and using the local time function to convert it to the local time

	int year = 1900 + ttyl->tm_year; //this is just the structure that the appropriate methods online comes from to get the year. add 1900
	int month = 1 + ttyl->tm_mon;
	int day = ttyl->tm_mday;

	bool loopEnder = false;
	string date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

	printHeader("Nicholas Paul", 6, date, 3);

}
void printHeader(string name, int lab, string date, int question) {
	cout << name << endl;
	cout << "Lab #" << lab << endl;
	cout << date << endl;
	cout << "Question #" << question << endl << endl;

	//instructions and game specific introduction
	cout << "Hi! Welcome to Nick's Array Sorter!\n\nIn this program we will sort an array of number you put in based \nupon whether you want them ascending or descending\n\n";
}
void printFooter() {
	cout << "\nThank you for using Nick's final grade calculator 3.0!\n\nHave a nice day :)\n\n";
}
int displayMenu() {
	int input = 0;
	while (true) {
		//program direction
		cout << "\n\nInput an number choice(1 or 2):\n\nThe options are:\n\n\t1. Sort Ascending\n\t2. Sort Descending\n\n";
		cin >> input;

		//method assining the correct value to make the switch work
		if (cin.good()) {
			if ((input > 0) && (input < 3)) {
				break;
			}
			else {
				cout << "\nPlease input an acceptable number 1 or 2";
				cin.clear();
				cin.ignore();
			}
		}
		else {
			cout << "\nPlease input an acceptable number 1 or 2";
			cin.clear();
			cin.ignore();
		}
	}

	return input;
}
void sortAscending(int unsortedArray[], int size) {
	for (int i = 0; i < size; i++) {
		if (unsortedArray[i] > unsortedArray[i + 1]) {
			int x = unsortedArray[i];
			unsortedArray[i] = unsortedArray[i + 1];
			unsortedArray[i + 1] = x;
		}
	}

}
void sortDescending(int unsortedArray[], int size) {
	for (int i = 0; i < size; i++) {
		if (unsortedArray[i] < unsortedArray[i + 1]) {
			int x = unsortedArray[i];
			unsortedArray[i] = unsortedArray[i + 1];
			unsortedArray[i + 1] = x;
		}
	}
}