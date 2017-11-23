#include <iostream>
#include <ctime>
#include <string>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

/*
Nick's Dice Game
Programmer: Nicholas Paul
Date: November 21st 2017
I made a dice game

Notes:
-used my methods from lab05_q2
-used cin.good() and some pretty damn efficient while loop structures
*/

using namespace std;

int rollDice(int numberOfDice);
void header();
void printHeader(string name, int lab, string date, int question);
void printFooter();


int main() {

	//variable declaration
	int currentScore = 0;
	bool loopEnder = false;

	//introduction
	header();

	//game functions
	while (loopEnder == false) {

		//variable declaration
		int diceRolled = 0;

		//introduction
		cout << "\nYou're current score is: " << currentScore << endl;

		//input
		while (true) { //error catching while loop
			cout << "\nHow many dice would you like to roll (0, 1 or 2)?" << endl; //question
			cin >> diceRolled; //input
			if (cin.good()) { //validation of numericy of input
				if ((diceRolled >= 1) && (diceRolled <=2)) { //validation of value of input
					break;
				}
				else if ((diceRolled == 0)) {
					exit(EXIT_FAILURE);
				}
				else {
					cout << "\nPlease input an acceptable integer 0, 1 or 2" << endl;
					cin.clear();
					cin.ignore();
				}
			}
			else {
				cout << "\nPlease input an acceptable integer 0, 1 or 2" << endl;
				cin.clear();
				cin.ignore();
			}
		}

		//ouput
		int result = rollDice(diceRolled);
		cout << "The result from rolling " << diceRolled << " dice is " << result << endl;
		currentScore += result;
		if (currentScore < 50) {
			cout << "That puts your total score at " << currentScore << endl;
		}
		else if (currentScore == 50) {
			cout << "\n\nCongradulations! You recieved a score of 50! You win!\n\n";
			break;
		}
		else {
			cout << "\n\nOh no! You're total score was " << currentScore << " which put you over 50.\nBetter luck next time!!\n\n";
			break;
		}
	}

	//conclusion
	printFooter();

}
int rollDice(int numberOfDice) {
	time_t seed = time(0); //creating a new timer pointer with the parameter =0
	static int diceTotal;

	diceTotal += numberOfDice;

	/*
	The srand() makes all the rand in the code equal to the sequence that will be determined by the parameter of 
	srand and due to the dynamic memory allocation in the pointer the value of seed will increase with each second 
	so every time it consults this it will be different
	*/

	int randNum = 0;

	srand((unsigned int)seed); 

	for (int i = 0; i < numberOfDice; i++) {
		randNum += 1 + rand() % 6;
	}

	cout << "\nYou've now rolled " << diceTotal << " dice in this game.\n\n";

	return randNum;
}
void header() {
	const time_t timer = time(0); //creates a char pointer with the current time 

	tm* ttyl = localtime(&timer); //create a pointer of variable name ttyl of the struct type tm from the c++ time library and using the local time function to convert it to the local time

	int year = 1900 + ttyl->tm_year; //this is just the structure that the appropriate methods online comes from to get the year. add 1900
	int month = 1 + ttyl->tm_mon;
	int day = ttyl->tm_mday;

	bool loopEnder = false;
	string date = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

	printHeader("Nicholas Paul", 6, date, 1);

}
void printHeader(string name, int lab, string date, int question) {
	cout << name << endl;
	cout << "Lab #" << lab << endl;
	cout << date << endl;
	cout << "Question #" << question << endl << endl;

	//instructions and game specific introduction
	cout << "Hi! Welcome to Nick's dice game. In this game you will try to attain a score \nof 50 by rolling dice multiple times." << endl;
}
void printFooter() {
	cout << "\nThank you for using Nick's dice game!\n\nHave a nice day :)\n\n";
}