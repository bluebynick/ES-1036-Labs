#include <iostream>
#include <cmath>
#include <string>

/*
Nick's Grade Converter
Programmer: Nicholas Paul
Date: October 3rd 2017

This is a program that you will input your numerical grade and the program will convert it to the letter equivelent for you.

Notes:
-Error catching wasn't requested so I didn't do it

*/

using namespace std;

int main() {

	//variable declaration
	double gradeInput = 0.0;
	string  outputLetter = " ";

	//instructions
	cout << "Hi! Welcome to Nick's Grade Converter, a program where you will input your \nnumerical grade and we will convert it to the letter equivelent for you. \n\nPlease input your numerical grade here: \n(ex. 90, 25, 100, 78.6, etc.)\n";

	//user input
	cin >> gradeInput;

	//calculations (using if and else statments)
	if ((gradeInput >= 95.0) && (gradeInput <= 100.0)) {
		outputLetter = "A+";
	}
	else if ((gradeInput >= 90.0) && (gradeInput < 95.0)) {
		outputLetter = "A";
	}
	else if ((gradeInput >= 85.0) && (gradeInput < 90.0)) {
		outputLetter = "A-";
	}
	else if ((gradeInput >= 80.0) && (gradeInput < 85.0)) {
		outputLetter = "B+";
	}
	else if ((gradeInput >= 75.0) && (gradeInput < 80.0)) {
		outputLetter = "B";
	}
	else if ((gradeInput >= 70.0) && (gradeInput < 75.0)) {
		outputLetter = "B-";
	}
	else if ((gradeInput >= 65.0) && (gradeInput < 70.0)) {
		outputLetter = "C+";
	}
	else if ((gradeInput >= 60.0) && (gradeInput < 65.0)) {
		outputLetter = "C";
	}
	else if ((gradeInput >= 50.0) && (gradeInput < 60.0)) {
		outputLetter = "C-";
	}
	else {
		outputLetter = "F";
	}

	//output
	cout << "\nBased on your input of: " << gradeInput << "%, your letter output will be '" << outputLetter << "'\nI hope this was helpful! Have a nice day :)\n\n";
	return 0;

}