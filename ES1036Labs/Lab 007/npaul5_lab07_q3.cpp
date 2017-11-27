#include <iostream>
#include <ctime>
#include <string>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

/*
Nick's Number Swapper
Programmer: Nicholas Paul
Date: November 26th 2017
In this program the user will input two real numbers and we will switch them for you, using pointers, and then triple the new 'first' number.

Notes:
-I used my methods from lab06_q1
-I used pointer passing in function calls
-I used pointers in a really great, efficient way to only require one loop structure, but changing the variable being computed within. This eliminates the need for a second loop for a second variable. This was done in the while loop in the main. I did this by:
	1. Declaring a pointer and making it equal to the first variable
	2. Running the loop and using a comparison within to the dereference of the pointer
	3. After the loop has run a second time, make the pointer point to the second variable
	4. The loop will now run, in respect to the second variable (because the computed variable is still the deference of the pointer, but it's just pointing to something else now)


*/

using namespace std;

void tripleRealNumber(double* num);
void swapRealNumbers(double* a, double* b);
double fetchRealNumber();
string date();
void printHeader(string name, int lab, string date, int question);
void printFooter();


int main() {
	//introduction
	printHeader("Nicholas Paul", 6, date(), 3);

	//variable declaration
	bool loopEnder = false;
	double firstNum, secondNum;
	double *dptr = &firstNum;
	int counter = 0;

	while (loopEnder == false) {
		*dptr = fetchRealNumber();
		switch ((int)*dptr) //running a switch with x
		{
		case 0:
			loopEnder = false; //here to remind me that if x erred (as i set it = 0 in fetchRealNumber), the loop will run again
			break; //break out of the condition so we don't run the number processing

		default:
			dptr = &secondNum;
			if (counter > 0) { //this is only so it will only actually exit the second time
				loopEnder = true;
			}
			counter++;
			break;
		}
	}
	//printing
	cout << "\n\nThe numbers you inputted are (" << firstNum << " , " << secondNum << ")" << endl;

	//program function (swapping)
	swapRealNumbers(&firstNum, &secondNum);

	//printing after swap
	cout << "The numbers swapped are  (" << firstNum << " , " << secondNum << ")" << endl;

	//program function (tripling the first number)
	tripleRealNumber(&firstNum);

	//final printing
	cout << "The numbers after we tripled the new first one are  (" << firstNum << " , " << secondNum << ")" << endl << endl;

	printFooter();
}

/** Project Specific Requirement.
*	This is a function that multiplies the input in the memory by three. 
*	Application of pointer values
*	Author: Nicholas Paul
*	Date: November 26th 2017
*/
void tripleRealNumber(double* num) {
	*num *= 3;
}

/** Project Specific Requirement.
*	This is a function that swaps the value of the two inputs.
*	Application of pointer values
*	Author: Nicholas Paul
*	Date: November 26th 2017
*/
void swapRealNumbers(double* a, double* b) {	int temp = *a;	*a = *b;	*b = temp;}
/** Project Specific Requirement.
*	This is a function that outputs an real number (double) based on the string that was inputted and outputs 0 if any invalid input is inputted.
*	Author: Logic by Dr. Q. Rahman. Reformatted for use by Nicholas Paul
*	Date: November 26th 2017
*/
double fetchRealNumber() {
	cout << "\nPlease input a real number value" << endl;
	string x = " ";
	double returnable = 0.0; //the value we will return to deteermine which portion in the switch in the main will run
	cin >> x;
	int dpcount = 0; //counter to count the number of decimal points
	for (int i = 0; i < (int)x.size(); i++)
	{
		if (x[i] == '.') {
			dpcount++;
		}
		if (i == 0)
		{
			if (!((x[0] == '-') || (x[0] == '.') || (x[0] >= '0' && x[0] <= '9')))
			{
				cout << "\nPlease input a valid real number here:\n"; getline(cin, x);
				i = -1.0;
				dpcount = 0;
				returnable = 0; //make returnable = -1.0 to run the correct condition in the switch in the main
			}
		}
		else if (!(((dpcount < 2) && (x[i] >= '0' && x[i] <= '9')) || (x[i] == '.')))
		{
			cout << "\nPlease input a valid real number here:\n"; getline(cin, x);
			i = -1;
			dpcount = 0;
			returnable = 0; //make returnable = -1.0 to run the correct condition in the switch in the main
		}

	}

	try
	{
		if (returnable != -1.0) { //if it's not been called unvalid already
			size_t size = x.size(); //a fancy kind of unsigned int used especially for sizes that is required for stoi
			returnable = atof(x.c_str()); //make returnable = to the double value of the string we looked through. doing this with atof function and making x a char array by c_str;
		}
	}
	catch (invalid_argument&)
	{
		returnable = 0; //make returnable = 0 to run the correct condition in the switch in the main
	}
	catch (out_of_range&)
	{
		returnable = 0; //make returnable = 0 to run the correct condition in the switch in the main
	}

	return returnable;

}

/** This is a function that gets the current date and outputs it as a string. 
*	Author: Nicholas Paul
*	Date: November 24th 2017
*/
string date() {
	const time_t timer = time(0); //creates a char pointer with the current time 

	tm* ttyl = localtime(&timer); //create a pointer of variable name ttyl of the struct type tm from the c++ time library and using the local time function to convert it to the local time

	int year = 1900 + ttyl->tm_year; //this is just the structure that the appropriate methods online comes from to get the year. add 1900
	int month = 1 + ttyl->tm_mon;
	int day = ttyl->tm_mday;

	bool loopEnder = false;
	string date = to_string(month) + "/" + to_string(day) + "/" + to_string(year); //converting the ints that were found using the time structure above to a single string for the date that can be printed
	return date;

}

/** This is a function that prints a header for the program according to guidlines given in ES 1036A. 
*	Author: Nicholas Paul
*	Date: November 8th 2017
*/
void printHeader(string name, int lab, string date, int question) {
	cout << name << endl;
	cout << "Lab #" << lab << endl;
	cout << date << endl;
	cout << "Question #" << question << endl << endl;

	//instructions and game specific introduction
	cout << "Hi! Welcome to Nick's Number Swapper! In this program the user will input two \nreal numbers and we will switch them for you, using a pointer computing \nsystem, and then triple the new 'first' number. \n\nLet's Go!!" << endl;
}

/** This is a function that prints a footer for the program according to guidlines given in ES 1036A and exits the code.
*	Author: Nicholas Paul
*	Date: November 8th 2017
*/
void printFooter() {
	cout << "\nThank you for using Nick's Number Swapper!\n\nHave a nice day :)\n\n";
	exit(EXIT_FAILURE); //runs an exit condition
}