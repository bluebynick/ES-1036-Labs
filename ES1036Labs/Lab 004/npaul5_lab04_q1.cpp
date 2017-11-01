#include <iostream>

/*
Nick's More Choice Convertor
Programmer: Nicholas Paul
Date: October 26th 2017
In this program we will convert Celsius into Fahrenheit, Centimeters to Inches, Meters to Feet, or Km/h toMPH. 
You will be asked for an input at the beginning that will indicate your choice. 
The options are:
1. Celsius to Fahrenheit
2. Centimeters to Inches
3. Meters to Feet
4. Km/h to MPH
5. Exit

The program will follow the direction of the integer choice you inputted

Features:
-Uses method calls and makes use of Switch structure to handle the program direction
-Uses a do while loop for error catching (my first do-While loop yeeek)
*/


using namespace std;

double celToFaren() { //fucntion that converts the given Celsius input into Farenheit and returns the value
	double input;
	cout << "\nPlease input a temperature in Celsius:\n";
	cin >> input;

	input = (9.0/5.0)*input +32;

	return input;
}

double cmToInch() { //fucntion that converts the given cm input into inches and returns the value
	double input;
	cout << "\nPlease input a length in Cm:\n";
	cin >> input;

	input = 0.39*input;

	return input;
}

double mToFeet() { //fucntion that converts the given m input into feet and returns the value
	double input;
	cout << "\nPlease input a length in m:\n";
	cin >> input;

	input = 3.28*input;

	return input;
}

double kmphToMph() { //fucntion that converts the given kmph input into mph and returns the value
	double input;
	cout << "\nPlease input a speed in Km/h:\n";
	cin >> input;

	input = input/1.609;

	return input;
}


int main() {
	
	//variable declaration
	int input = 0;
	bool loopEnder = false;

	//introduction
	cout << "Hi! Welcome to Nick's More Choice Convertor! In this program we will convert \nCelsius into Fahrenheit, Centimeters to Inches, Meters to Feet, or Km/h toMPH. \nYou will be asked for an input at the beginning that will indicate your choice.\n";

	do {
		//program direction
		cout << "\nInput an integer choice(1-5):\n\nThe options are:\n\n\t1. Celsius to Fahrenheit\n\t2. Centimeters to Inches\n\t3. Meters to Feet\n\t4. Km/h to MPH\n\t5. Exit\n"; 
		cin >> input;

		switch (input) {
		case 1: 
			cout << "You're temperature in Farenheit is " << celToFaren() << endl;
			break;
		case 2:
			cout << "You're length in Inches is " << cmToInch() << endl;
			break;
		case 3:
			cout << "You're length in Inches is " << mToFeet() << endl;
			break;
		case 4:
			cout << "You're speed in MPH is " << kmphToMph() << endl;
			break;
		case 5:
			loopEnder = true;
			break;
		default:
			cout << "\nPlease input a number from 1-5\n\n";
			loopEnder = false;
		}
	} while (loopEnder == false);


	//conclusiton

	cout << "\nThank you for using Nick's More Choice Convertor!\n\nHave a nice day :)\n\n";

	return 0;
}