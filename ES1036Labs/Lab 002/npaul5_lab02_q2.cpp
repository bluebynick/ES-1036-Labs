#include <iostream>
#include <cmath>
#include <string>

/*
Nick's Grade Calculator 2.0
Programmer: Nicholas Paul
Date: October 4th 2017

This is a program that you will input your grades and your grade weights and it will calculate your final average for you.
This program makes heavy use of arrays for data storage and of while loops for error catching and program functionality. 

Note:
-error catchinng for letters in numerical inputs were not required
*/

using namespace std;

int main() {

	//variable declaration
	double gradeWeight[5];
	double gradeInput[5];
	string evaluationNames[5];
	double finalGrade = 0.0;
	int counter = 0; //this helps tell the program when to exit the input loop and helps to seperate the data
	bool inputEnder = false; //boolean to control the transition from the input section to the calcuation section
	bool errorCatcher = false; //this is used to determine whether or not an error was detected

	//instructions
	cout << "ES1036A-2017 Lab02 Q2\nNicholas Paul\n\nHi! Welcome to Nick's final grade calculator 2.0!\n\nIn this program you will be able to calculate your final average based \nupon your current grades and their weights towards your final average \nin the course. We will be taking 4 marks and their weights to do the \ncalculation for you.\n\n";

	//input of grades and weights using while loop
	while (inputEnder == false) {
		
		cout << "\nPlease input the name of your evaluation #" << counter + 1 << " here \n(ex. exam, summative, lab, etc.) \nClick enter when you have finished. No spaces please:\n";
		
		cin >> evaluationNames[counter];

		errorCatcher = false;
		cout << "\nAwesome! Now could you please input your grade for '" << evaluationNames[counter] << "' here:\n";

		while (errorCatcher == false) { //while the error catcher is false

			cin >> gradeInput[counter]; //input the value held in the array at the index = to counter

			if ((gradeInput[counter] >=0.0) && (gradeInput[counter] <= 100.0)) { //check to see if it's acceptable

				errorCatcher = true; //if it's acceptable run the exit condition from this loop
			}
			else { //tell user about the error
				cout << "\nPlease input an acceptable value (0.0-100.0)\n";
				gradeInput[counter] = 0.0;
			}
		}

		errorCatcher = false; //reset condtion for the error catching variable

		cout << "\nAnd please input the weight of the grade towards your final mark \n(ex. 0.20, 0.30, 0.80) \nClick enter when you have finished. No spaces please:\n";

		while (errorCatcher == false) { //while the error catcher is false

			cin >> gradeWeight[counter]; //input the value held in the array at the index = to counter

			if ((gradeWeight[counter] >= 0.0) && (gradeWeight[counter] <= 1.0)) {//check to see if it's acceptable

				errorCatcher = true; //if it's acceptable run the exit condition from this loop
			}
			else { //tell user about the error
				cout << "\nPlease input an acceptable value (0.0-1.0)\n";
				gradeWeight[counter] = 0.0;
			}
		}

		errorCatcher = false; //reset condtion for the error catching variable

		if (counter >= 3) { //this is the exit condition for the repetition while loop

			inputEnder = true;
		}

		counter++;
	}

	//calculations of the final grade
	finalGrade = ((double)gradeInput[0] * ((double)gradeWeight[0])) + ((double)gradeInput[1] * ((double)gradeWeight[1])) + ((double)gradeInput[2] * ((double)gradeWeight[2])) + ((double)gradeInput[3] * ((double)gradeWeight[3]));

	//final output
	cout << "\n\nBased on your inputs, your final grade in the course would be: \n" << finalGrade << "\n\nHave a great day!\n\n";
}