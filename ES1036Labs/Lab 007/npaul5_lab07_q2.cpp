#include <iostream>
#include <ctime>
#include <string>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

/*
Nick's War Cards
Programmer: Nicholas Paul
Date: November 25th 2017
This is a program the user will be drawn a random card and will guess if they think the next card drawn will be higher or lower than that which they've drawn.
This program uses a very cool system of ranking strings based on their values and and thus searches through strings as chararrays for certain values in order to use them as an int.

Notes:
-used my methods from lab06_q1
-uses a very unique system of getting values from strings based on what should be in the ranking system
-26 line main method
*/

using namespace std;

bool gameFunctions(string oldCard, string newCard, int displayMenuOutput);
int getInteger(string card);
int displayMenu(string card);
void compileCardDeck(string cardDeck[], const string suits[], const string denominations[]);
string date();
void printHeader(string name, int lab, string date, int question);
void printFooter();


int main() {
	//variable declaration
	const string suits[4] = { "S", "H", "D", "C"};
	const string denominations[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	string deck[52];

	string card = ""; //I wanted to make a class for this that tbh would've been to much work lmao
	
	//introduction
	printHeader("Nicholas Paul", 6 , date() , 2);

	//compiling the deck
	compileCardDeck(deck,suits,denominations);

	//game fuctions
	while (true) {
		time_t seed = time(0);
		srand((unsigned int)seed);
		card = deck[rand() % 51]; 
		string newCard = deck[rand() % 51]; //this is wehere i was error catching
		if (gameFunctions(card, newCard, displayMenu(card)) == false) {
			printFooter(); 
			break;
		} 

	}
}

/** Project Specific Requirement.
*	This is a function that computes whether the user won or not, prints it the returns a bool if they want to play again.
*	Author: Nicholas Paul
*	Date: November 25th 2017
*/
bool gameFunctions(string oldCard, string newCard, int displayMenuOutput) {
	
	char input = ' ';

	cout << "\nThe next card was " << newCard << endl;

	if (displayMenuOutput == 1) { //they guessed the new card would be higher
		if (getInteger(newCard) > getInteger(oldCard)) {
			cout << "\n" << newCard << " > " << oldCard << endl;
			cout << "\nYou guessed right! You win! :)" << endl;
		}
		else {
			cout << "\n" << newCard << " < " << oldCard << endl;
			cout << "\nYou guessed wrong. Better luck next time! :)" << endl;
		}
	}
	else if (displayMenuOutput == 2) { //they guessed the new card would be lower
		if (getInteger(newCard) < getInteger(oldCard)) {
			cout << "\n" << newCard << " < " << oldCard << endl;
			cout << "\nYou guessed right! You win! :)" << endl;
		}
		else {
			cout << "\n" << newCard << " > " << oldCard << endl;
			cout << "\nYou guessed wrong. Better luck next time! :)" << endl;
		}
	}

	while (true) {
		cout << "\nWould you like to play again? (Y or N)" << endl;
		cin >> input;

		if (isalpha(input)) { //if it's a letter, exit the loop
			if ((input == 'Y') || (input == 'y') || (input == 'N') || (input == 'n')) { //if it's valid
				break;
			}
			else {
				cout << "\nPlease type the letter 'Y' or 'N'" << endl;
			}
		}
		else {
			cout << "\nPlease type the letter 'Y' or 'N'" << endl;
		}
	}

	if ((input == 'Y') || (input == 'y')) {
		return true;
	}
	else { //cause at this point it can only be y or n
		return false;
	}
}

/** Project Specific Requirement.
*	This is a function that gets the value of the card input and returns it for comparison.
*	52/4 is 13. So the order of suits is ♠<♥<♦<♣ so for spades the value retuned is +0. 
*	For hearts +13, for diamonds +26 and for clubs +39.
*	Author: Nicholas Paul
*	Date: November 25th 2017
*/
int getInteger(string card) {

	int returnable = 0; //the value we will return as the numeric value of the card.
	int numberIsTen = 5;

	/*This is for the denomination section of the card string
	*
	*/
	if (!(card[0] >= '2' && card[0] <= '9')) //if it's not a number (so if it's A,J,Q or K)
	{
		if (card[0] == 'A') {
			returnable += 1;
		}
		else if (card[0] == 'J') {
			returnable += 11;
		}
		else if (card[0] == 'Q') {
			returnable += 12;
		}
		else if (card[0] == 'K') {
			returnable += 13;
		}
	}
	else if (card[0] == 1) { //this means it's 10
		returnable += 13;
		numberIsTen += 1;
	}
	else { //any number other than 10
		returnable += card[0];
	}

	/*This is for the suits section of the card string
	*
	*/
	if (card[numberIsTen] == 'S') { // if it's spades (the lowest "ranked")  "\u2660"
		returnable += 0; 
	}
	else if (card[numberIsTen] == 'H') { //if it's hearts (the 3rd highest "ranked") "\u2665"
		returnable += 13;
	}
	else if (card[numberIsTen] == 'D') { //if it's diamonds (the 2nd highest "ranked") "\u2666"
		returnable += 26;
	}
	else if (card[numberIsTen] == 'C') { //if it's clubs (the highest "ranked") "\u2663"
		returnable += 39;
	}

	return returnable;
}

/** Project Specific Requirement.
*	This is a function that displays the menu and returns the user's choice for the game functionality.
*	Modification of the displayMenu() function in lab05_q2. 
*	Author: Nicholas Paul
*	Date: November 25th 2017
*/
int displayMenu(string card) {
	int input = 0;

	cout << "\nYou've drawn the card: " << card << endl;
	cout << "Do you think the next card will be higher or lower? \nNote: S < H < D < C " << endl;

	do {
		//program direction
		cout << "\nInput an integer choice(1-2):\n\nThe options are:\n\n\t1. Higher\n\t2. Lower\n\n";
		cin >> input;
		if ((input > 0) && (input < 3)) {
			break;
		}
		else {
			cout << "\nPlease input a number from 1-2\n\n";
		}
	} while (true);

	return input;
	
}

/** Project Specific Requirement.
*	This is a function that compiles the deck based on the inputs it was given.
*	Author: Nicholas Paul
*	Date: November 25th 2017
*/
void compileCardDeck(string cardDeck[], const string suits[], const string denominations[]) {
	int counter = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {

			cardDeck[counter] = denominations[j] + " of " + suits[i];

			counter++;
		}
	}
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
	cout << "Hi! Welcome to Nick's War Cards! In this card game, we will draw you a random \ncard and you will guess if you think the next card drawn will be higher or \nlower than that which you've drawn.\n\nLet's Play!!" << endl;
}

/** This is a function that prints a footer for the program according to guidlines given in ES 1036A and exits the code.
*	Author: Nicholas Paul
*	Date: November 8th 2017
*/
void printFooter() {
	cout << "\nThank you for using Nick's War Cards!\n\nHave a nice day :)\n\n";
	exit(EXIT_FAILURE); //runs an exit condition
}