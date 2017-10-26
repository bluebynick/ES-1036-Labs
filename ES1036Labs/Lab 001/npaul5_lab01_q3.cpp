/*
Nick's Gravity Calculations
Programmer: Nicholas Paul
Student Number: 250949057
Date : September 28th 2017
This is a program created for lab 01 of ES 1036A : Programming Fundamentals for Engineers.
This program calculates the time required for a 5kg ball to fall from a user selected height

Note: I didn't do any error catching b/c it wasn't required. I also just have it exit instead of looping it until an exit condition
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {

	//declaring the variables
	double ballWeight = 5.0;
	const double gravity = 9.81;
	double ballHeight = 0; 
	double time = 0;

	//introduction
	cout << "Hi! Welcome to Nick's Calculations!\nIn this program we will ask you for any positive height, and based \non basic kinematic equations we will calculate the time it would \ntake for a 5 kg ball to fall from your chosen height. \n\nNote: For this simple calculation we're assuming all forces except \ngravity are negligible\n\n";

	//inputs
	cout << "Please input the height you would like the ball to fall from here: \n(ex. 80, 100, 1000)\n";
	cin >> ballHeight;

	//calculations
	time = sqrt((2 * (double)ballHeight) / gravity);

	//output
	cout << "\nFrom a height of " << ballHeight << "m, the ball would fall in " << time << " seconds. \nI hope you found this helpful! Have a nice day :)\n\n";

}