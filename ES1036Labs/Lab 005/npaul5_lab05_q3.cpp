#include <iostream>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <string>

/*
Nick's Advanced Functions 2.0
Programmer: Nicholas Paul
Date: November 8th 2017
I made a calculator that makes a sine, exp, factorial and power function without using the built in math libraries!
It took me a lot of work and i'm proud :)

In 2.0 I changed the way the program is structured in order to make it fit with professor prototypes and expectations

Notes:

-made use of the isdigit() function a few times
-made use of the continue keyword
-made use of prototypes (function declarations before initializations so they can be written after the main
-the sine function stops working past 6?
-uses the time library and makes use of rudementary pointers in order to get current date and time
-> https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm (for tutorial on the time library)
-uses a warning disable thing #pragma warning(disable : 4996)
*/

using namespace std;

void printHeader(string name, int lab, string date, int question);
char displayMenu();
double computePower(double base, int exponent);
double computeSine(double radians, int numberOfIterations);
double computeExponential(double exponential, int numberOfIterations);
double computeFactorial(int number);void printFooter();
int assignment(char inputChar);

int main() {
	//variable declaration and time usage
	const time_t timer = time(0); //creates a char pointer with the current time 

	tm* ttyl = localtime(&timer); //create a pointer of variable name ttyl of the struct type tm from the c++ time library and using the local time function to convert it to the local time

	int year = 1900 + ttyl->tm_year; //this is just the structure that the appropriate methods online comes from to get the year. add 1900
	int month = 1 + ttyl->tm_mon;
	int day = ttyl->tm_mday;

	bool loopEnder = false;
	string date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

	printHeader("Nicholas Paul", 5, date, 3);

	//introduction
	cout << "Hi! Welcome to Nick's Advanced Functions 2.0! In this program we will use a\nPower Function, Sine Function, Exponential Function, Factorial Function. \nYou will be asked for an input at the beginning that will indicate your \nchoice.\n";

	do {

		double input = 0;
		double base = 0.0;
		double power = 0.0;
		double limit = 0.0;
		long double inputAngle = 0.0;
		bool errorCatcher = false;
		bool baseWasNegative = false; //condition that will alter output dependant on if base was a negative input but not affect the calculations
		bool powerWasNegative = false; //condition that will alter output dependant on if power was a negative input but not affect the calculations

		switch (assignment(displayMenu())) {
			case 1://power function

			cout << "\nYou've selected Power Function. In this code you'll input a integer base and \nthe power to which it will be raised and we'll do the calcuation for you. \nLet's give it a try.";

			//base input
			while (errorCatcher == false) {
				cout << "\n\nPlease select an acceptable integer base that is a real number:\n";
				cin >> base;

				if (cin.good()) { //if the input is a nummber
					errorCatcher = true; //run the exit condition

					if (base < 0) { //make this positive for ouput sake
						baseWasNegative = true;
					}
				}
				else {
					cin.clear(); //this flushes out the input so it can be checked if it's an int again. otherwise it will just give \n characters that aren't ints indefinitely
					cin.ignore(INT_MAX, '\n');
				}
				
			}

			errorCatcher = false; //reset the error catching conditions

			//power input
			while (errorCatcher == false) {
				
				cout << "\nPlease select the power to which you want (" << base << ") to be raised\n";
				
				cin >> power;

				if (cin.good()) { //if the input is a nummber
					errorCatcher = true; //run the exit condition

					if (power < 0) { //make this for output sake
						powerWasNegative = true;
					}
				}
				else {
					cin.clear(); //this flushes out the input so it can be checked if it's an int again. otherwise it will just give \n characters that aren't ints indefinitely
					cin.ignore(INT_MAX, '\n');
				}

			}

			//output
			if ((baseWasNegative == true) && (powerWasNegative == true)) {
				cout << "\nThe result of (" << base << ") raised to the power of (" << power << ") is " << computePower(base, power);
			}
			else if ((baseWasNegative == false) && (powerWasNegative == true)) {
				cout << "\nThe result of " << (int)base << " raised to the power of (" << (int)power<< ") is " << computePower(base, power);
			}
			else if ((baseWasNegative == true) && (powerWasNegative == false)) {
				cout << "\nThe result of (" << (int)base << ") raised to the power of " << (int)power << " is " << computePower(base, power);
			}
			else {
				cout << "\nThe result of " << (int)base << " raised to the power of " << (int)power << " is " << computePower(base, power);
			}

			break;
			case 2: //sine function
				//introduction
				cout << "\nYou have chosen the Sine Function. For this computation, we need a calculation \nlimit. This will be the number of times the computer runs the calculations. \nPlease input a number limit for calculation: \n\n(Note: limit of 14 cycles due to max processing ability of a 64bit computer)\n(ex. 1, 4, 14,... etc.)\n\n";

				//input of calculation limit
				while (errorCatcher == false) { //error catcher for the caculations

					cin >> limit;
					if ((limit > 15) || (limit <0)) {
						cout << "\nPlease input a suitable calculation limit from 1 to 14\n";
						errorCatcher = false;
					}

					else {
						errorCatcher = true;
					}
				}

				errorCatcher = false; //reset the error condition

				cout << "\nThank you. You've chosen that the calculation will be performed " + to_string((int)limit) + " \ntimes. Please input the angle in radians that you would like us to compute:\n";
				
				//input of angle
				while (errorCatcher == false) { 

					cin >> inputAngle;

					if ((inputAngle < 0)) {
						cout << "\nPlease input a suitable angle that's greater than 0\n";
						errorCatcher = false;
					}

					else {
						errorCatcher = true;
					}
				}

				//output
				cout << "The sine of the angle " << (int)inputAngle + " you inputted is " << computeSine(inputAngle, limit);
				
				break;
			case 3: //exponential function
				//introduction
				cout << "\nYou have chosen the Exponential Function. For this computation, we need a \ncalculation limit. This will be the number of times the computer runs the \ncalculations. \nPlease input a number limit for calculation: \n\n(Note: limit of 14 cycles due to max processing ability of a 64bit computer)\n(ex. 1, 4, 14,... etc.)\n\n";

				//input of limit

				while (errorCatcher == false) { //error catcher for the caculations

					cin >> limit;
					if ((limit > 14) || (limit <0)) {
						cout << "\nPlease input a suitable calculation limit from 1 to 14\n";
						errorCatcher = false;
					}

					else {
						errorCatcher = true;
					}
				}

				errorCatcher = false; //reset the error condition

				cout << "\nThank you. You've chosen that the calculation will be performed " << limit << " \ntimes. Please input the number that you would like us to compute:\n";

				//input of base. using base for the sake of not making another variable thus saving space
				while (errorCatcher == false) { //error catcher for the caculations

					cin >> base ;

					if ((base < 0)) {
						base *= -1;
						errorCatcher = false;
					}

					else {
						errorCatcher = true;
					}
				}

				//output
				cout<< "The exponential value of the angle " << base << " you inputted is " << computeExponential(base,limit);

				break;
			case 4: //factorial function
				//intro 
				cout << "\nYou've selected the Factioral Function. In this code you will input any \ninteger and we will give you the it's factorial value.\n\nPlease input your integer here:\n";

				//input 
				cin >> base; //using base and baseWasNegative just so i don't have to make another variable 

				//error catching
				if (base < 0) { //if it's negative
					base = base*-1; //make it positive
					baseWasNegative = true;
				}

				//output
				if (baseWasNegative == false) {
					cout << "\nThe factorial of the integer " << base << " that you inputted is " << computeFactorial(base);
				}
				else { //display the correct input
					cout << "\nThe factorial of the integer " << base*-1 << " that you inputted is " << computeFactorial(base);
				}

				break;
				
			case 5:
				loopEnder = true;
				break;
				
		}
	} while (loopEnder == false);

	//conclusion
	printFooter();
	return 0;

	
}


void printHeader(string name, int lab, string date, int question) {
	cout << name << endl;
	cout << "Lab #" << lab << endl;
	cout << date << endl;
	cout << "Question #" <<question << endl<< endl;

}

char displayMenu() {
	int input = 0;
	char inputChar = ' ';
	bool loopEnder = false;
	do {
		//program direction
		cout << "\n\nInput an letter choice(a-e):\n\nThe options are:\n\n\ta. Power Function\n\tb. Sine Function\n\tc. Exponential Function\n\td. Factorial Function\n\te. Exit\n\n";
		cin >> inputChar;

		//method assining the correct value to make the switch work
		if (isdigit(inputChar)) {
			cout<< "\nPlease input an acceptable letter a,b,c,d or e";
			continue; //skip the rest of the iteration
		}
		loopEnder = true;
		
	} while (loopEnder == false);

	return inputChar;
}

double computePower(double base, int exponent) {
	//variable declaration
	double result = 1.0;
	double power;
	if (exponent < 0) { //this is to make it so i only need one for loop
		power = exponent*-1;
	}
	else {
		power = exponent;
	}

	//calculations 
	for (int j = power; j > 0; j--) { //this handles the second term on the top

		result *= base;

	}
	if (exponent < 0) { //if it was a negative power
		result = 1.0 / result;

	}
	if (exponent == 0) {
		result = 1;
	}
	return result;

}

double computeSine(double radians, int numberOfIterations) {

	//variable declaration
	int counter = 0;
	double result = 0;
	//calculation 

	for (int i = numberOfIterations; i >= 0; i--) {

		double twonPlusOne = (2 * i) + 1;
		long angleResult = 1;
		counter += 1;

		for (int j = twonPlusOne; j > 0; j--) { //this handles the second term on the top

			angleResult *= radians;

		}

		long long numerator;

		if (counter % 2) { //if the counter %2 = a non zero this returns true aka every odd number in the sequence is positive
			numerator = angleResult * 1;
		}
		else {
			numerator = angleResult * -1;
		}

		long double denominator = computeFactorial(twonPlusOne);

		result += (numerator / denominator);

		// This was my error catcher. Uncomment this section to see the actual calculations in the code
		//cout << "exponent n = " << i << ", 2n+1 = " << twonPlusOne << ", numerator = " << numerator << ", denominator = " << denominator << "\n";

	}

	return result;
}

double computeExponential(double exponential, int numberOfIterations) {
	//calculation 
	int counter = 0;
	double result = 0.0;

	for (int i = numberOfIterations; i >= 0; i--) {

		long intResult = 1;
		counter += 1;

		for (int j = i; j > 0; j--) { //this handles the second term on the top

			intResult = intResult*exponential;

		}

		long double numerator = intResult * 1;


		long double denominator = computeFactorial(i);

		result += (numerator / denominator);

	}
	return result;
}

double computeFactorial(int number) {

	double factorialResult = 1;

	//calculations
	if(number == 0) {//condition if 0 is inputted
		double factorialResult = 1;
	}
	else {
		for (int i = 1; i <=number; i++) {
			factorialResult *= i;
	}
}

return factorialResult;
}

void printFooter() {
	cout << "\nThank you for using Nick's Advanced Functions 2.0!\n\nHave a nice day :)\n\n";
}

int assignment(char inputChar) {
	int charAsNumber = 0;

	if ((inputChar == 'a') || (inputChar == 'A')) {
		charAsNumber = 1;
	}

	else if ((inputChar == 'b') || (inputChar == 'B')) {
		charAsNumber = 2;
	}

	else if ((inputChar == 'c') || (inputChar == 'C')) {
		charAsNumber = 3;;
	}

	else if ((inputChar == 'd') || (inputChar == 'D')) {
		charAsNumber = 4;
	}

	else if ((inputChar == 'e') || (inputChar == 'E')) {
		charAsNumber = 5;
	}

	else {
		charAsNumber = 100;

	}
	return charAsNumber;
}

