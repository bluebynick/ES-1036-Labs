#include <iostream>
#include <ctime>
#include <string>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

/*
Nick's Grade Calculator 3.0
Programmer: Nicholas Paul
Date: November 21st 2017

This is a program that you will input your grades and your grade weights and it will calculate your final average for you.
This program makes heavy use of arrays for data storage and of while loops for error catching and program functionality.

This was modified formatically to match the format given.

Notes:
-used my methods from lab05_q2
-makes use of a very clever error catching sequence to error catch based on the sum. In if (counter >= 3).
*/

using namespace std;

void header();
void printHeader(string name, int lab, string date, int question);
void printFooter();
bool isValidGrade(double grade);


int main() {

	//variable declaration
	double gradeWeight[5];
	double gradeInput[5];
	string evaluationNames[5];
	double finalGrade = 0.0;
	int counter = 0; //this helps tell the program when to exit the input loop and helps to seperate the dat
	
	//introduction
	header();

	//input of grades and weights using while loop
	while (true) {

		cout << "\nPlease input the name of your evaluation #" << counter + 1 << " here \n(ex. exam, summative, lab, etc.) \nClick enter when you have finished. No spaces please:\n";

		cin >> evaluationNames[counter];

		cout << "\nAwesome! Now could you please input your grade for '" << evaluationNames[counter] << "' here:\n";


		while (true) { //while the error catcher is false

			cin >> gradeInput[counter]; //input the value held in the array at the index = to counter
			if (isValidGrade(gradeInput[counter]) == true) {   //if it's acceptable run the exit condition from this loop
				break; 
			}
			else {
				cout << "\nPlease input an acceptable value (0.0-100.0)\n";
				cin.clear();
				cin.ignore();
			}
		}

		cout << "\nAnd please input the weight of the grade towards your final mark \n(ex. 0.20, 0.30, 0.80) \nClick enter when you have finished. No spaces please:\n";

		while (true) { //while the error catcher is false

			cin >> gradeWeight[counter]; //input the value held in the array at the index = to counter
			
			if (cin.good()) { //check for numericy
				if ((gradeWeight[counter] >= 0.0) && (gradeWeight[counter] <= 1.0)) {//check to see if it's acceptable

					break; //if it's acceptable run the exit condition from this loop
				}
				else { //tell user about the error
					cout << "\nPlease input an acceptable value (0.0-1.0)\n";
					cin.clear();
					cin.ignore();
				}
			}
			else{ //tell user about the error
				cout << "\nPlease input an acceptable value (0.0-1.0)\n";
				cin.clear();
				cin.ignore();
			}
		}

		if (counter >= 3) { //this is the exit condition for the repetition while loop
			while (true) {
				double validation = 0.0;

				for (int i = 0; i < 4; i++) {
					validation += gradeWeight[i];
				}

				if (validation != 1.0) {
					cout << "\nYou're grade weights did not sum to 1.0\n" << endl;
					for (int i = 0; i < 4; i++) {
						while (true) { //error catching of the inputs
							cout << "Please input the weight for " << evaluationNames[i] << " here:\n";
							cin >> gradeWeight[i];
							if (cin.good()) { //check for numericy
								if ((gradeWeight[i] >= 0.0) && (gradeWeight[i] <= 1.0)) {//check to see if it's acceptable

									break; //if it's acceptable run the exit condition from this loop
								}
								else { //tell user about the error
									cout << "\nPlease input an acceptable value (0.0-1.0)\n";
									cin.clear();
									cin.ignore();
								}
							}
							else { //tell user about the error
								cout << "\nPlease input an acceptable value (0.0-1.0)\n";
								cin.clear();
								cin.ignore();
							}
						} //while
					} //for
				}

				else { //if it's ==1
					break; //break out of this while loop
				}

			} //while
			break;  //transition from the input section to the calcuation section
		}
		counter++;
	}

	//calculations of the final grade
	finalGrade = ((double)gradeInput[0] * ((double)gradeWeight[0])) + ((double)gradeInput[1] * ((double)gradeWeight[1])) + ((double)gradeInput[2] * ((double)gradeWeight[2])) + ((double)gradeInput[3] * ((double)gradeWeight[3]));

	//final output
	cout << "\n\nBased on your inputs, your final grade in the course would be: \n" << finalGrade << endl;
	printFooter();
}


bool isValidGrade(double grade) {
	if (cin.good()) {
		if ((grade >= 0.0) && (grade <= 100.0)) { //check to see if it's acceptable
			return true;
		}
		else { //tell user about the error
			return false;
		}
	}
}
void header() {
	const time_t timer = time(0); //creates a char pointer with the current time 

	tm* ttyl = localtime(&timer); //create a pointer of variable name ttyl of the struct type tm from the c++ time library and using the local time function to convert it to the local time

	int year = 1900 + ttyl->tm_year; //this is just the structure that the appropriate methods online comes from to get the year. add 1900
	int month = 1 + ttyl->tm_mon;
	int day = ttyl->tm_mday;

	bool loopEnder = false;
	string date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

	printHeader("Nicholas Paul", 6, date, 2);

}
void printHeader(string name, int lab, string date, int question) {
	cout << name << endl;
	cout << "Lab #" << lab << endl;
	cout << date << endl;
	cout << "Question #" << question << endl << endl;

	//instructions and game specific introduction
	cout << "\n\nHi!Welcome to Nick's final grade calculator 3.0!\n\nIn this program you will be able to calculate your final average based \nupon your current grades and their weights towards your final average \nin the course. We will be taking 4 marks and their weights to do the \ncalculation for you.\n\n";
}
void printFooter() {
	cout << "\nThank you for using Nick's final grade calculator 3.0!\n\nHave a nice day :)\n\n";
}