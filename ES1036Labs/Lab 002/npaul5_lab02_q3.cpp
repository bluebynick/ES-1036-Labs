#include <iostream>


/*
Nick's Encoder 2.0
Programmer: Nicholas Paul
Date: October 16th 2017
This is a program that scrambles a given input character, beit upper or lowercase and compensates for extreme values such as x,y,z and X,Y,Z. 
Bringing them back to a,b,c and A,B,C respectively 

Notes:
" You can assume the user will enter a single character, and not a string, integer, or double." 

Thus I didn't include error catching for the possiblility of these inputs

*/

using namespace std; 


int main(){

	// variable declaration
	char inputChar[4];
	int asciiNumber = 0;
	char outputChar = ' ';
	bool errorCatcher = false;
	bool inputLoop = false;
	int counter = 0;

	//instructions
	cout << "ES1036A-2017 Lab02 Q3\nNicholas Paul\n\nHi! Welcome to Nick's Encoder, a program where you will input a letter and we \nwill encode it for you. Please input the letter you would like us to scramble:\n(One letter only please, click enter when you are done):\n";
	
	//input
	while (inputLoop == false) {
		while (errorCatcher == false) {
			cin >> inputChar[counter];
			if ((((int)inputChar[counter] >= 97) && ((int)inputChar[counter] <= 122)) || (((int)inputChar[counter] >= 65) && ((int)inputChar[counter] <= 90))) { //this checks if the ascii value of the character is in the appropriate range
				errorCatcher = true;
			}
			else {
				cout << "Please input a letter from a-z or A-Z\n";
			}
		}

		//scrambling of the letter uby converting it to it's int value, raising that by three and reverting the new value to a letter that will be, in effect, 3 letters away
		asciiNumber = (int)inputChar[counter];
		if ((asciiNumber >= 120) || ((asciiNumber >= 88) && (asciiNumber <=90))) {
			asciiNumber = asciiNumber - 26; //going back all the letters of the alphabet 
		
		}
		asciiNumber = asciiNumber + 3; //adding 3 in order to find the accurate 
		outputChar = (char)asciiNumber;

		if (counter >= 3) {
			// final output
			cout << "You inputed '" << inputChar[counter] << "' and by our encoder scrambled it to '" << outputChar << "'.\n\nI hope you enjoyed your code, have a nice day!:)\n";
			inputLoop = true;
		}

		else {
			//recurring output
			cout << "You inputed '" << inputChar[counter] << "' and by our encoder scrambled it to '" << outputChar << "'.\n\nWhat letter would you like to scramble next?\n";

		}
		counter++;
		errorCatcher = false;
	
	} 
}