#include <iostream>

/*
Nick's Capitalization
Programmer: Nicholas Paul
Date: November 5th 1017
This is a program that takes in an upper or lower case letter, checks if the input is valid and the outputs the opposite
case. I.e if a lowercase letter was inputted it will output an uppercase letter and vice versa. 

Notes:

-I used isalpha() in this code


*/

using namespace std;

//function prototypes
char toUppercase(char lowercase);
char toLowercase(char uppercase);

int main() {
	//variable declaration
	bool errorCatcher = false;
	char input = ' ';

	//introduction
	cout << "Hi! Welcome to Nick's Capitalization. In this program, you will input a \nlowercase letter and we'll give you the same letter as a capital letter \nor vice versa.\n\nPlease input your characcter here:\n";

	//input and error catcher. if proven error it sends it back to input

	while (errorCatcher == false) { 
		cin >> input;

		if (isalpha(input)) { //if it's a letter, exit the loop
			errorCatcher = true;

		}
		else{ // if not, run again
			cout << "\nPlease input an acceptable upper or lowercase letter:" << endl;
			errorCatcher = false; 
		}
	}

	/*
	Convert to the opposite case by converting it to ascii value by adding or subtracting dependant on whether it's 
	uppercase or lowercase. they will have to call methods called char toUppercase(char lowercase); and char 
	toLowercase(char uppercase); the difference is 32 
	*/

	//output


	if (((int)input >= 97) && ((int)input <= 122)) { //this is the case if it's lowercase
		cout << "\nYour input was converted to " << toUppercase(input) << endl;
	}
	else if (((int)input >= 65) && ((int)input <= 90)) {
		cout << "\nYour input was converted to " << toLowercase(input) <<endl;
	}
	else {
		cout << "\nPlease input an acceptable upper or lowercase letter" << endl;
	}

	//conclusion

	cout << "\nThank you for using Nick's Capitalization! Have a great day :) \n\n";
}
char toUppercase(char lowercase) {
	int asciiValue = (int)lowercase;
	char output = ' ';

	asciiValue -= 32;

	return output = (char)asciiValue;
}

char toLowercase(char uppercase) {
	int asciiValue = (int)uppercase;
	char output = ' ';

	asciiValue += 32;

	return output = (char)asciiValue;
}
