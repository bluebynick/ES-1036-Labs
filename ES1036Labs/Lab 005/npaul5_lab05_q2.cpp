#include <iostream>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <string>

/*
Nick's More Choice Convertor 2.0
Programmer: Nicholas Paul
Date: November 8th 2017
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
-Uses method calls based on teacher prototypes and makes use of Switch structure to handle the program direction
-Uses a do while loop for error catching (my first do-While loop yeeek)
-uses the time library and makes use of rudementary pointers in order to get current date and time
-> https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm (for tutorial on the time library)
-uses a warning disable thing #pragma warning(disable : 4996)
*/

using namespace std;

void printHeader(string name, int lab, string date, int question);
int displayMenu();
float computeCelsiusConversion(float degreesCelsius);
float computeCentimetersConversion(float centimeters);
double computeMetersConversion(double meters);
double computeKilometersPerHourConversion(double kilometersPerHour);void printFooter();

int main() {
	//variable declaration and time usage
	const time_t timer = time(0); //creates a char pointer with the current time 

	tm* ttyl = localtime(&timer); //create a pointer of variable name ttyl of the struct type tm from the c++ time library and using the local time function to convert it to the local time

	int year = 1900 + ttyl->tm_year; //this is just the structure that the appropriate methods online comes from to get the year. add 1900
	int month = 1 + ttyl->tm_mon;
	int day = ttyl->tm_mday;

	string date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

	printHeader("Nicholas Paul", 5, date, 2);

	//introduction
	cout << "Hi! Welcome to Nick's More Choice Convertor 2.0! In this program we will convert \nCelsius into Fahrenheit, Centimeters to Inches, Meters to Feet, or Km/h toMPH. \nYou will be asked for an input at the beginning that will indicate your choice.\n";

	double input = 0;
	switch (displayMenu()) {
	case 1:
		cout << "\nPlease input a temperature in Celsius:\n";
		cin >> input;
		cout << "You're temperature in Farenheit is " << computeCelsiusConversion(input) << endl;
		break;
	case 2:
		cout << "\nPlease input a length in Cm:\n";
		cin >> input;
		cout << "You're length in Inches is " << computeCentimetersConversion(input) << endl;
		break;
	case 3:
		cout << "\nPlease input a length in m:\n";
		cin >> input;
		cout << "You're length in Inches is " << computeMetersConversion(input) << endl;
		break;
	case 4:
		cout << "\nPlease input a speed in Km/h:\n";
		cin >> input;
		cout << "You're speed in MPH is " << computeKilometersPerHourConversion(input) << endl;
		break;
	case 5:
		break;
	}

	//conclusiton
	printFooter();
	return 0;

	
}


void printHeader(string name, int lab, string date, int question) {
	cout << name << endl;
	cout << "Lab #" << lab << endl;
	cout << date << endl;
	cout << "Question #" <<question << endl<< endl;

}

int displayMenu() {
	int input = 0;
	bool loopEnder = false;

	do {
		//program direction
		cout << "\nInput an integer choice(1-5):\n\nThe options are:\n\n\t1. Celsius to Fahrenheit\n\t2. Centimeters to Inches\n\t3. Meters to Feet\n\t4. Km/h to MPH\n\t5. Exit\n";
		cin >> input;
		if ((input > 0) && (input < 6)) {
			loopEnder = true;
		}
		else {
			cout << "\nPlease input a number from 1-5\n\n";
			loopEnder = false;
		}
	} while (loopEnder == false);

	return input;
}

float computeCelsiusConversion(float degreesCelsius){ //fucntion that converts the given Celsius input into Farenheit and returns the value
	degreesCelsius = (9.0 / 5.0)*degreesCelsius + 32;

	return degreesCelsius;
}

float computeCentimetersConversion(float centimeters) { //fucntion that converts the given cm input into inches and returns the value
	centimeters = 0.39*centimeters;

	return centimeters;
}

double computeMetersConversion(double meters) { //fucntion that converts the given m input into feet and returns the value
	meters = 3.28*meters;

	return meters;
}

double computeKilometersPerHourConversion(double kilometersPerHour) { //fucntion that converts the given kmph input into mph and returns the value
	kilometersPerHour = kilometersPerHour / 1.609;

	return kilometersPerHour;
}

void printFooter() {
	cout << "\nThank you for using Nick's More Choice Convertor!\n\nHave a nice day :)\n\n";
}

