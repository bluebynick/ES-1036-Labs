#include <iostream>
#include <ctime>
#include <string>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

/*
Nick's Numerical Comparisons
Programmer: Nicholas Paul
Date: November 24th 2017
This is a program that takes in numbers entered by the user and stores them in an array, then giving a running average, maximum and minimum of the values that have been inputted since the initiation of the program.


Notes:
-modified my methods from lab06_q1
-use of a bubble sort. full explanation in comments 
-sucessful use of dynamic memory allocation in order to "change the size of an array" when in essence what i'm really doing is:
	1. Creating a temporary array and using loops to populate it with the same values as the old array
	2. Deleting the old array through dynamic memory allocation
	3. Increasing the size of the array variable (by one in this case)
	4. Creating a new array of the same name (b/c the old one's storage was released thus the name can be reused) with a size of the new size variable (up by one here)
	5. Populating the new array with the same values as the temporary array using loops (thus leaving the 1 extra new space unoccupied)
	6. Deleting the temporary array

*/

using namespace std;

string date();
void printHeader(string name, int lab, string date, int question);
int fetchInteger();
void printResults(double sum, double average, int count, int min, int max);
void printFooter();


int main() {

	//variable declaration
	bool loopEnder = false;
	int size = 1; //starting size for the array
	int *intArray = new int[size]; //declare a new dynamic array

	//introduction
	printHeader("Nicholas Paul", 6 , date() , 1);

	//input
	while (loopEnder == false) {
		//int *newIntArray = &intArray; 
		int x = fetchInteger(); //getting the value from fetchInteger and setting it equal to x
		switch (x) //running a switch with x
		{
		case 0:
			printFooter(); //calls the program end condition
			break; //here for no reason except good practice

		case -1:
			loopEnder = false; //here to remind me that if x erred (as i set it = -1 in fetchInteger), the loop will run again
			break; //break out of the condition so we don't run the number processing

		default: //now that we know x is valid
			//we know that size is the size of the array, but the last index of that array is always = size -1
			intArray[size - 1] = x;  //putting it in the last index of the array

			int sum = 0; //initializing sum = 0
			for (int i = 0; i < size; i++) {
				sum += intArray[i]; //summing all the values in the array
			}

			int average = sum/size; //creating the average by taking the sum and dividing it by the non-programming corrected array size (as in not size -1 like we had to do a few lines ago)
			
			//these are the conditions that need to be run if the array is at size one. we will change them later if not
			
			int min = intArray[0]; // declaring the first index in the array as the min 
			int max = intArray[size-1]; //declaring the last index in the array as the max (lol if the size is 1 these are the same) 

			if (size > 1) { // if the size of the array is greater than 1, i.e all the values are not = to each other

				for (int i = 0; i < size -1; i++) { //A bubble sort!!
					for (int j = 0; j < size - 1; j++){ 
						if (intArray[j] > intArray[j + 1]) { //compare if j is greater than the one above it and if so switch the values
							int temp = intArray[j];			 //create a temporary variable to hold the larger value
							intArray[j] = intArray[j + 1];   //assign the value at a lower index number in the comparison, to the smaller value
							intArray[j + 1] = temp;			 //assign the value at the higher index to the larger value that was being stored in temp
						}
					}
				} //run this comparsion the correct amount of times so that it will sucessfully sort it from smallest to largest value. the "correct amount of times" actually happens to be the same size of the array 'cause that's some math i'm too lazy to do but through trial and error i know it works LMAO	

				//it's sorted!

				min = intArray[0]; //since the array is now sorted from smallest to lowest, the smallest value will be at the smallest index and thus assign the minimum value to the value at this index
				max = intArray[size-1]; //the value at the highest index is now the biggest thus assign it to the max value
			}


			printResults(sum, average, size, min, max); //send the values to the print function

														/*This is the section where I am essentially "changing the size" of an array
														* The commented out sections are error catches
														* This is fully explained in the program description and corresponds to the numbers in comments here
														*/

			int *tempArray = new int[size]; ; // 1. 
											  //cout << "tempArray is: " << endl;
			for (int i = 0; i < size; i++) {
				tempArray[i] = intArray[i];
				//cout << tempArray[i] << endl;
			}

			delete intArray; intArray = NULL; // 2.

			size += 1; // 3. 

			intArray = new int[size]; //4. 
									  //cout << "intArray is: " << endl;
			for (int i = 0; i < size; i++) { //5. 
				intArray[i] = tempArray[i];
				//cout << intArray[i] << endl;
			}

			delete tempArray; tempArray = NULL; //6. 


		}
	}

	//conclusion
	printFooter();

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
	cout << "Hi! Welcome to Nick's Numerical Comparisons. In this code you will input \ninteger numbers and i'll show you the running average, max and min of all of \nthose which you have inputted since program initiation.\n\nTo begin please enter an integer number: " << endl;
}

/** This is a function that outputs an integer based on the string that was inputted and outputs -1 if any invalid input is inputted.
*	Author: Logic by Dr. Q. Rahman. Reformatted for use by Nicholas Paul
*	Date: November 24th 2017
*/
int fetchInteger() {
	string x;
	int returnable = 0; //the value we will return to deteermine which portion in the switch in the main will run
	cin >> x;
	int dpcount = 0; //counter to count the number of decimal points
	for (int i = 0; i< (int)x.size(); i++)
	{
		if (x[i] == '.') {
			cout << "Please input a valid integer number here:\n"; getline(cin, x);
			returnable = -1; //make returnable = -1 to run the correct condition in the switch in the main
			break;
		}
		if (i == 0)
		{
			if (!((x[0] == '-') || (x[0] == '.') || (x[0] >= '0' && x[0] <= '9')))
			{
				cout << "Please input a valid integer number here:\n"; getline(cin, x);
				i = -1;
				dpcount = 0;
				returnable = -1; //make returnable = -1 to run the correct condition in the switch in the main
			}
		}
		else if (!(((dpcount<2) && (x[i] >= '0' && x[i] <= '9')) || (x[i] == '.')))
		{
			cout << "Please input a valid integer number here:\n"; getline(cin, x);
			i = -1; 
			dpcount = 0;
			returnable = -1; //make returnable = -1 to run the correct condition in the switch in the main
		}
	}

	try
	{
		if (returnable != -1) { //if it's not been called unvalid already
			size_t size = x.size(); //a fancy kind of unsigned int used especially for sizes that is required for stoi
			returnable = stoi(x, &size, 10); //make returnable = to the int value of the string we looked through
		}
	}
	catch (invalid_argument&)
	{
		//return false; //wow you can return an int false lmao that's a new one
		returnable = -1; //make returnable = -1 to run the correct condition in the switch in the main
	}
	catch (out_of_range&)
	{
		//return false;
		returnable = -1; //make returnable = -1 to run the correct condition in the switch in the main
	}

	return returnable;
}

/** This is a function that prints the values sent as parameters to the console as required for the project.
*	Author: Nicholas Paul
*	Date: November 24th 2017
*/
void printResults(double sum, double average, int count, int min, int max) {
	cout << "The average of your " << count << " integers is " << average << endl;
	cout << "Your inputs have a minimum value of " << min << endl;
	cout << "Your inputs have a maximum value of " << max << endl;
}

/** This is a function that prints a footer for the program according to guidlines given in ES 1036A and exits the code.
*	Author: Nicholas Paul
*	Date: November 8th 2017
*/
void printFooter() {
	cout << "\nThank you for using Nick's Numerical Comparisons!\n\nHave a nice day :)\n\n";
	exit(EXIT_FAILURE); //runs an exit condition
}