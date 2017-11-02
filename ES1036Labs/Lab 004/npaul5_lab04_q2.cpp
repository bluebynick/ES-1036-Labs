#include <iostream>
#include <string>

/*
Nick's Advanced Functions
Programmer: Nicholas Paul
Date: October 31st 2017

I made a calculator that makes a sine, exp, factorial and power function without using the built in math libraries!
It took me a lot of work and i'm proud :)

Notes:

-made use of the isdigit() function a few times
-made use of the continue keyword
-made use of prototypes (function declarations before initializations so they can be written after the main
-the sine function stops working past 6?
*/

using namespace std; 
string powerFunction();
string sineFunction();
string expFunction(); 
string factorialFunction(); 
double factorialCalculator(int);
int assignment(char inputChar);


int main() {

	//variable declaration
	bool loopEnder = false;

	//introduction
	cout << "Hi! Welcome to Nick's Advanced Functions! In this program we will use a\nPower Function, Sine Function, Exponential Function, Factorial Function. \nYou will be asked for an input at the beginning that will indicate your \nchoice.\n";

	do {
		//program direction
		int input = 0;
		char inputChar = ' ';
		cout << "\n\nInput an letter choice(a-e):\n\nThe options are:\n\n\ta. Power Function\n\tb. Sine Function\n\tc. Exponential Function\n\td. Factorial Function\n\te. Exit\n\n";
		cin >> inputChar;

		//method assining the correct value to make the switch work
		if (isdigit(inputChar)) {
			continue; //skip the rest of the iteration
		}
		input = assignment(inputChar);


		switch (input) {
		case 1:
			cout << powerFunction() << endl;
			break;
		case 2:
			cout << sineFunction() << endl;
			break;
		case 3:
			cout << "You're length in Inches is " << expFunction() << endl;
			break;
		case 4:
			cout << factorialFunction() << endl;
			break;
		case 5:
			loopEnder = true;
			break;
		default:
			cout << "\nPlease input an acceptable letter a,b,c,d or e";
			loopEnder = false;
		}
	} while (loopEnder == false);

	cout << "\nThank you for using Nick's Advanced Functions! Have a nice day :)\n\n";

	return 0;


}

string powerFunction() {
	//variable declaration
	string input = " ";
	double base = 0.0;
	double power = 0.0;
	double result = 0.0;
	bool errorCatcher = false; 
	bool baseWasNegative = false; //condition that will alter output dependant on if base was a negative input but not affect the calculations
	bool powerWasNegative = false; //condition that will alter output dependant on if power was a negative input but not affect the calculations

	cout << "\nYou've selected power function. In this code you'll input a integer base and \nthe power to which it will be raised and we'll do the calcuation for you. \nLet's give it a try.";
	
	//base input
	while (errorCatcher == false) {
		cout << "\n\nPlease select an acceptable integer base that is a real number:\n";
		cin >> base;
		if (base < 0) { //make base positive so it doesn't break the isdigit function
			base = base*-1;
			baseWasNegative = true;
		}
		if (isdigit(base) == 0) { //if the input is a number which is interesting since i can't use true and false
			errorCatcher = true; //run the exit condition
		}
	}

	errorCatcher = false; //reset the error catching conditions

	//power input
	while (errorCatcher == false) {
		if (baseWasNegative == true) {
			cout << "\nPlease select the power to which you want (" << base*-1 << ") to be raised\n";
		}
		else {
			cout << "\nPlease select the power to which you want " << base << " to be raised:\n";
		}
		cin >> power;
		if (power < 0) { //make base positive so it doesn't break the isdigit function
			power = power*-1;
			powerWasNegative = true;
		}
		if (isdigit(power) == 0) { //if the input is a nummber
			errorCatcher = true; //run the exit condition
		}
	}

	//calculations 
	if (powerWasNegative ==false) {
		result = pow((double)base, (double)power);
	}
	else {
		result = 1.0 / (pow((double)base, (double)power));

	}

	//output based upon which condition was selected
	if ((baseWasNegative == true) && (powerWasNegative == true)){
		input = "\nThe result of (" + to_string(base*-1) + ") raised to the power of (" + to_string(power*-1) + ") is " + to_string(result);
	}
	else if ((baseWasNegative == false) && (powerWasNegative == true)) {
		input = "\nThe result of " + to_string((int)base) + " raised to the power of (" + to_string((int)power*-1) + ") is " + to_string((int)result);
	}
	else if ((baseWasNegative == true) && (powerWasNegative == false)) {
		input = "\nThe result of (" + to_string((int)base*-1) + ") raised to the power of " + to_string((int)power) + " is " + to_string((int)result);
	}
	else{
		input = "\nThe result of " + to_string((int)base) + " raised to the power of " + to_string((int)power) + " is " + to_string((int)result);
	}

	return input;
}

string sineFunction() { 

	//variable declaration
	string output = " ";
	double limit = 0;
	long double inputAngle = 0;
	bool errorCatcher = false;
	long double result = 0.0;
	int counter = 0; //this is a counter for the signs


	//introduction
	cout << "\nYou have chosen the Sine Function. For this computation, we need a calculation \nlimit. This will be the number of times the computer runs the calculations. \nPlease input a number limit for calculation: \n\n(Note: limit of 14 cycles due to max processing ability of a 64bit computer)\n(ex. 1, 4, 14,... etc.)\n\n";

	//input

	while (errorCatcher == false) { //error catcher for the caculations

		cin >> limit;
		if ((limit > 1100) || (limit <0)) {
			cout << "\nPlease input a suitable calculation limit from 1 to 14\n";
			errorCatcher = false;
		}

		else {
			errorCatcher = true;
		}
	}

	errorCatcher = false; //reset the error condition

	cout << "\nThank you. You've chosen that the calculation will be performed " + to_string((int)limit) + " \ntimes. Please input the angle in radians that you would like us to compute:\n"; 
	
	while (errorCatcher == false) { //error catcher for the caculations

		cin >> inputAngle;

		if ((inputAngle < 0)) {
			cout << "\nPlease input a suitable angle that's greater than 0\n";
			errorCatcher = false;
		}

		else {
			errorCatcher = true;
		}
	}

	//calculation 

	for (int i = limit; i >=0 ; i--) {

		double twonPlusOne = (2 * i) + 1;
		long angleResult = 1;
		counter += 1;

		for (int j = twonPlusOne; j > 0; j--) { //this handles the second term on the top

			angleResult = angleResult*inputAngle;

		}

		long long numerator;

		if (counter % 2) { //if the counter %2 = a non zero this returns true aka every odd number in the sequence is positive
			numerator = angleResult *1;
		}
		else{
			numerator = angleResult * -1;
		}

		long double denominator = factorialCalculator(twonPlusOne);

		result += (numerator / denominator);

		// This was my error catcher. Uncomment this section to see the actual calculations in the code
		cout << "exponent n = "<< i << ", 2n+1 = " << twonPlusOne << ", numerator = " << numerator << ", denominator = " << denominator<< "\n";
		
	}

	output = "The sine of the angle " + to_string((int)inputAngle) + " you inputted is " + to_string(result);

	return output;
}

string expFunction() { 

	//variable declaration
	string output = " ";
	double limit = 0;
	long double inputInt = 0;
	bool errorCatcher = false;
	long double result = 0.0;
	int counter = 0; //this is a counter for the signs


					 //introduction
	cout << "\nYou have chosen the Exponential Function. For this computation, we need a calculation \nlimit. This will be the number of times the computer runs the calculations. \nPlease input a number limit for calculation: \n\n(Note: limit of 14 cycles due to max processing ability of a 64bit computer)\n(ex. 1, 4, 14,... etc.)\n\n";

	//input

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

	cout << "\nThank you. You've chosen that the calculation will be performed " + to_string((int)limit) + " \ntimes. Please input the number that you would like us to compute:\n";

	while (errorCatcher == false) { //error catcher for the caculations

		cin >> inputInt;

		if ((inputInt < 0)) {
			inputInt *= -1;
			errorCatcher = false;
		}

		else {
			errorCatcher = true;
		}
	}

	//calculation 

	for (int i = limit; i >= 0; i--) {

		long intResult = 1;
		counter += 1;

		for (int j = i; j > 0; j--) { //this handles the second term on the top

			intResult = intResult*inputInt;

		}

		long double numerator = intResult * 1;
		

		long double denominator = factorialCalculator(i);

		result += (numerator / denominator);

	}

	output = "The exponential value of the angle " + to_string((int)inputInt) + " you inputted is " + to_string(result);

	return output;
}

string factorialFunction() { 
	
	//variable declaration
	string output = " ";
	int num = 0;
	bool negative = false; //bool for handling the final output condition if it was negative

	//intro 
	cout << "\nYou've selected the Factioral Function. In this code you will input any \ninteger and we will give you the it's factorial value.\n\nPlease input your integer here:\n";

	//inpuut
	cin >> num;

	//error catching
	if (num < 0) { //if it's negative
		num = num*-1; //make it positive
		negative = true;
	}

	double result = factorialCalculator(num);

	//output
	if (negative == false) {
		cout<< "\nThe factorial of the integer " + to_string((int)num) + " that you inputted is "+ to_string((int)result);
	}
	else { //display the correct input
		cout<< "\nThe factorial of the integer " + to_string((int)num*-1) + " that you inputted is " + to_string((int)result);
	}

	return output;

}

double factorialCalculator(int numBase) {

	double factorialResult = 1;

	//calculations
	if(numBase == 0) {//condition if 0 is inputted
		double factorialResult = 1;
	}
	else {
		for (int i = 1; i <=numBase; i++) {
			factorialResult *= i;
		}
	}

	return factorialResult;
}

int assignment(char inputChar) {
	int charAsNumber = 0;
	
	if ((inputChar == 'a')|| (inputChar == 'A')) {
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
