#include <iostream>
#include <string>

/*
Nick's Triangles
Programmer: Nicholas Paul
Date: November 1st 2017



Notes:

*/

using namespace std; 
void triangleCreation(int, int[], bool);


int main() {

	//variable declaration
	bool loopEnder = false;
	int input = 0;
	int size = 0;
	int rows = 0;
	char inputChar = ' ';
	bool inputBool = false;

	int * starsInRow;


	//introduction
	cout << "Hi! Welcome to Nick's Triangles! In this program we will create a\nright angle triangle based on your choice of shape.\n\nYou will be asked for an input at the beginning that will indicate your choice.\n\n\t1. Bottom Left\n\t2. Top Left\n\t3. Top Right\n\t4. Bottom Right\n\t5. Exit\n";

	//while loop with error catching that directs the programs where the suer wanted it to dependant on the user's input
	while (inputBool == false) { //what choice the user wants
		cout << "\nInput an integer choice(1-5):\n";
		cin >> input;

		if (input == 1) { //this is the choice for the bottom left

			cout << "\nBased on your choice of " << input << ", you chose bottom left shape.\n";
			cout << "Enter the right triangle size : " << endl;
			cin >> size;
			starsInRow = new int[size];
			cout << "The length of the longest side will be : " << size << endl;
			rows = size+1;
			
			//creating the right number for the correct diagram
			for (int i = 0; i < size; i++) {
				starsInRow[i] = i + 1;
			}

			//this calls the triangle method and sends it the appropriate amount of rows and the pattern
			triangleCreation(rows,starsInRow, false);
		}

		else if (input == 2) { //this is the choice for the top left

			cout << "\nBased on your choice of " << input << ", you chose top left shape.\n";
			cout << "Enter the right triangle size : " << endl;
			cin >> size;
			starsInRow = new int[size];
			cout << "The length of the longest side will be : " << size << endl;
			rows = size+1;

			//creating the right number for the correct diagram
			for (int i = size; i >0; i--) {
				starsInRow[size-i] = i; //because the first time it'll be [5-5 =0] = 5, then [5-4=1] =4. nice logic!
			}

			//this calls the triangle method and sends it the appropriate amount of rows and the pattern
			triangleCreation(rows, starsInRow, false);
		}

		else if (input == 3) { //this is the choice for the top right

			cout << "\nBased on your choice of " << input << ", you chose top right shape.\n";
			cout << "Enter the right triangle size : " << endl;
			cin >> size;
			starsInRow = new int[size];
			cout << "The length of the longest side will be : " << size << endl;
			rows = size+1;

			//creating the right number for the correct diagram
			for (int i = size; i >0; i--) {
				starsInRow[size - i] = i; // because the first time it'll be [5-5 =0] = 5, then [5-4=1] =4. nice logic!
			}

			//this calls the triangle method and sends it the appropriate amount of rows and the pattern
			triangleCreation(rows, starsInRow, true);
		}

		else if (input == 4) { //this is the choice for the bottom right

			cout << "\nBased on your choice of " << input << ", you chose bottom right shape.\n";
			cout << "Enter the right triangle size : " << endl;
			cin >> size;
			starsInRow = new int[size];
			cout << "The length of the longest side will be : " << size <<endl;
			rows = size+1;

			//creating the right number for the correct diagram
			for (int i = 0; i < size; i++) {
				starsInRow[i] = i + 1;
			}

			//this calls the triangle method and sends it the appropriate amount of rows and the pattern
			triangleCreation(rows, starsInRow, true);
		}

		else if (input == 5) { //this is the exit condition

			cout << "\nBased on your choice of " << input << ", the program will exit.\n";
			starsInRow = new int[5];
			inputBool = true;
		}

		else { //this is the error catcher that restarts the loop if one of the above options isn't selected
			cout << "\nPlease input an input 1,2 or 3\n\n";

		}
	}

	cout << "\nThank you for using Nick's Triangles! Have a nice day :)\n\n";

	return 0;


}

void triangleCreation(int rows, int starsInRow[], bool flip) {

	for (int i = 0; i < rows; i++) { //number of rows

		int x = starsInRow[i];

		if (flip == false) {
			for (int j = 0; j <= rows; j++) { //stars per row
				if (flip == false) {
					if (j < x) {
						cout << "*";
					}
					else {
						cout << " ";
					}
				}
			}
		}

		else {
			for (int j =rows-1; j > 0; j--) { //stars per row
				if (j <= x) {
					cout << "*";
				}
				else {
					cout << " ";
				}
			}
		}



		cout << endl;

	}

}


