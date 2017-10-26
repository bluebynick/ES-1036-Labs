/*
Nick's Endcoder
Programmer: Nicholas Paul
Student Number: 250949057
Date : September 28th 2017
This is a program created for lab 01 of ES 1036A : Programming Fundamentals for Engineers.
This program endodes a given input using the ceaser cipher

*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {

	// variable declaration
	char inputChar = ' ';
	int asciiNumber = 0;
	char outputChar = ' ';

	//instructions
	cout << "Hi! Welcome to Nick's Encoder, a program where you will input a letter \nand we will encode it for you. \nSimple as that, please input the letter you would like us to scramble\n(One letter only please, click enter when you are done):\n";
	
	//input
	cin >> inputChar;

	//scrambling of the letter uby converting it to it's int value, raising that by three and reverting the new value to a letter that will be, in effect, 3 letters away
	asciiNumber = (int)inputChar;
	asciiNumber = asciiNumber + 3;
	outputChar = (char)asciiNumber;

	//output
	cout << "You inputed '" << inputChar << "' and by our encoder scrambled it to '" << outputChar << "'.\n\nWhat letter would you like to scramble next?\n";

	//input 2
	cin >> inputChar;

	//scrambling 2
	asciiNumber = (int)inputChar;
	asciiNumber = asciiNumber + 3;
	outputChar = (char)asciiNumber;

	//output 2
	cout << "You inputed '" << inputChar << "' and by our encoder scrambled it to '" << outputChar << "'.\n\nWhat letter would you like to scramble next?\n";

	//input 3
	cin >> inputChar;

	//scrambling 3
	asciiNumber = (int)inputChar;
	asciiNumber = asciiNumber + 3;
	outputChar = (char)asciiNumber;

	//output 3
	cout << "You inputed '" << inputChar << "' and by our encoder scrambled it to '" << outputChar << "'.\n\nWhat letter would you like to scramble last?\n";

	//input 4
	cin >> inputChar;

	//scrambling 4
	asciiNumber = (int)inputChar;
	asciiNumber = asciiNumber + 3;
	outputChar = (char)asciiNumber;

	//output 4
	cout << "You inputed '" << inputChar << "' and by our encoder scrambled it to '" << outputChar << "'.\n\nI hope you enjoyed your code, have a nice day! :)\n";




}