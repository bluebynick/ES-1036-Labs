#include <iostream>

/*
Nick's Factorials
Programmer: Nicholas Paul
Date: October 19th 2017

This is a program that give the factorial of any integer input

Notes:
-Factorial had to be a double for the big numbers

*/

using namespace std;

int main() {

	//variable declaration
	int num = 0;
	double factorial = 1;
	bool negative = false; //bool for handling the final output condition if it was negative

	//outputs and introduction
	cout << "Hi, welcome to Nick's Factorials. In this program you will input any \npositive integer and we will give you the it's factorial value.\n\nPlease input your integer here:\n";
	cin >> num;
	
	//error catching
	if (num < 0) { //if it's negative
		num = num*-1; //make it positive
		negative = true;
	}


	//calculations
	if (num == 0) {//condition if 0 is inputted
		factorial = 1;
	}

	else { 
		for (int i = num; i >1; i--) {
			factorial = factorial + factorial*(i-1);
		}
	}

	//output
	if (negative == false) {
		cout << "\nThe factorial of the integer " << num << " that you inputted is " << factorial << " \n\nHave a nice day! :)\n\n";
	}
	else { //display the correct input
		cout << "\nThe factorial of the integer " << num*-1 << " that you inputted is " << factorial << " \n\nHave a nice day! :)\n\n";
	}


}