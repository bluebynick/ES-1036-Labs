#include <iostream>
#include <string>
#include <cmath>

/*
Nick's Angular Convertor
Programmer: Nicholas Paul
Date: October 19th 2017

This is a program that will convert degrees to radians or radians to degrees depending on the user's choice. An exit is also
available. 

Notes:
-This program makes use of method calls and passing varibables cause I wanted to

*/

using namespace std;

double degToRad(double pi) { //method that takes in pi and asks for an angle in degrees then into radians
	double angle;
	cout << "Please input an angle in degrees:\n";
	cin >> angle;

	angle = (angle*pi) / 180.0;

	return angle;
}

double radToDeg(double pi) { //method that takes in pi and asks for an angle in radians then into degrees
	double angle;
	cout << "Please input an angle in radians:\n";
	cin >> angle;

	angle = (angle * 180) / pi;

	return angle;
}

int main() {

	//variable declaration
	int input = 0;
	bool inputBool = false;
	const double pi = 3.141592653589793;

	//input and instructions
	cout << "Hi! Welcome to Nick's Convertor. In this code we will convert degrees \nto radians or radians to degrees. You will be asked for an input at \nthe beginning that will indicate your choice. The options are:\n\n\t1. Degrees to radians\n\t2. Radians to degrees\n\t3. Exit\n\n";
	
	//while loop with error catching that directs the programs where the suer wanted it to dependant on the user's input
	while (inputBool == false) { //what choice the user wants
		cout << "Input an integer choice(1-3):\n";
		cin >> input;

		if (input == 1) { //this is the choice for degrees to radians. it calls the respective method
			
			cout << "\nBased on your choice of " << input << " the program will convert degrees to radians.\n";
			
			//output based on computation done in degToRad method
			cout << "\nBased on the angle you inputted, the angle in radians would be: " << degToRad(pi) << endl;
			
			//exit the error catching loop
			inputBool = true;
		}
		
		else if (input == 2) { //this is the choice for radians to degrees. it calls the respective method
			
			cout << "\nBased on your choice of " << input << " the program will convert radians to degrees.\n";

			//output based on computation done in radToDeg method
			cout << "\nBased on the angle you inputted, the angle in degrees would be: " << radToDeg(pi) << endl;

			//exit the error catching loop
			inputBool = true;
		}

		else if (input == 3) { //this is the choice for existing the program
			
			cout << "\nBased on your choice of " << input << " the program will exit.\n";

			//exit the error catching loop
			inputBool = true;
		}

		else { //this is the error catcher that restarts the loop if one of the above options isn't selected
			cout << "\nPlease input an input 1,2 or 3\n\n";

		}
	}

	//final goodbye
	cout << "\nThank you for using Nick's Angular Convertor! Have a nice day :)\n\n";

}