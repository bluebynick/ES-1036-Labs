/*
Nick's Final Grade Calculator
Programmer: Nicholas Paul
Student Number: 250949057
Date: September 28th 2017
This is a program created for lab 01 of ES 1036A:Programming Fundamentals for Engineers. 
This program calculates a final grade based upon 4 different grade inputs from the user
and their respective weights. 

Note: I didn't do any error catching on any of the input values because it wasn't 
required and I didn't want to waste time.

Program specialites:
-included detailed instructions
-made use of strings 
-made use of arrays
-very user friendly and aesthetically pleasing
-code is formatted correctly with appropriate comments and industry standard header 
(I could've made the comments standardized for documentation but I felt it wasn't required 
and I didn't want to waste time.)
(I also could've used different methods and calls to those methods but it's too advanced for
a simple task like this)

*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
	// variable declaration
	int gradeInput[5];
	int gradeWeight[5];
	string evaluationNames[5];
	double finalGrade = 0.0;

	//instructions
	cout << "Hi! Welcome to Nick's final grade calculator!\nIn this program you will be able to calculate your final average based \nupon your current grades and their weights towards your final average \nin the course. We will be taking 4 marks and their weights to do the \ncalculation for you.\n\n";
	
	//input of first grade and weight 
	cout << "Please input the name of your first evaluation here \n(ex. exam, summative, lab, etc.) \nClick enter when you have finished. No spaces please:\n";
	cin >> evaluationNames[1];
	cout << "\nAwesome! Now could you please input your grade for '" << evaluationNames[1] << "' here:\n";
	cin >> gradeInput[1];
	cout << "\nAnd please input the weight of the grade towards your final mark \n(ex. 20, 30, 80) \nClick enter when you have finished. No spaces please:\n";
	cin >> gradeWeight[1];

	
	//input of second grade and weight 
	cout << "\nPlease input the name of your second evaluation here \n(ex. exam, summative, lab, etc.) \nClick enter when you have finished. No spaces please:\n";
	cin >> evaluationNames[2];
	cout << "\nNice! Now could you please input your grade for '" << evaluationNames[2] << "' here:\n";
	cin >> gradeInput[2];
	cout << "\nAnd please input the weight of the grade towards your final mark \n(ex. 20, 30, 80) \nClick enter when you have finished. No spaces please:\n";
	cin >> gradeWeight[2];

	//input of third grade and weight 
	cout << "\nPlease input the name of your third evaluation here \n(ex. exam, summative, lab, etc.) \nClick enter when you have finished. No spaces please:\n";
	cin >> evaluationNames[3];
	cout << "\nGreat job! Now could you please input your grade for '" << evaluationNames[3] << "' here:\n";
	cin >> gradeInput[3];
	cout << "\nAnd please input the weight of the grade towards your final mark \n(ex. 20, 30, 80) \nClick enter when you have finished. No spaces please:\n";
	cin >> gradeWeight[3];

	//input of fourth grade and weight 
	cout << "\nPlease input the name of your final evaluation here \n(ex. exam, summative, lab, etc.) \nClick enter when you have finished. No spaces please:\n";
	cin >> evaluationNames[4];
	cout << "\nGreat job! Now could you please input your grade for '" << evaluationNames[4] << "' here:\n";
	cin >> gradeInput[4];
	cout << "\nAnd please input the weight of the grade towards your final mark \n(ex. 20, 30, 80) \nClick enter when you have finished. No spaces please:\n";
	cin >> gradeWeight[4];

	//calculations of the final grade
	finalGrade = ((double)gradeInput[1] * ((double)gradeWeight[1] / 100)) + ((double)gradeInput[2] * ((double)gradeWeight[2] / 100)) + ((double)gradeInput[3] * ((double)gradeWeight[3] / 100)) + ((double)gradeInput[4] * ((double)gradeWeight[4] / 100));
	
	//final output
	cout << "\n\nBased on your inputs, your final grade in the course would be: \n" << finalGrade << "\nHave a great day!\n";



}
