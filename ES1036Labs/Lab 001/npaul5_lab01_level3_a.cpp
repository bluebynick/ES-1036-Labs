/*
Nick's Gravity Calculations
Programmer: Nicholas Paul
Student Number: 250949057
Date : September 29th 2017
This is a program created for lab 01 of ES 1036A : Programming Fundamentals for Engineers.
This program calculates the time required for a 5kg ball to fall from a user selected height

Note: I didn't do any error catching b/c it wasn't required. I also just have it exit instead of looping it until an exit condition
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {

	//declaring variables
	double textbookPrice = 0.0;
	double computerPrice = 0.0;
	double finalPrice = 0.0;
	double const taxRate = 0.13;
	double taxExpense = 0.0;

	//introduction
	cout << "Hi! Welcome to Nick's Final Price Calculator.\n\nWe know that sometimes you'd like to know the price of your final purchase \nafter tax, so in this program we will allow you to input the cost of your \nnew computer and then input a new textbook. We will add them, calculate \ntax and show you the final price for both items.\n\n";

	//input of the textbook price
	cout << "Please input the price of your new textbook here. Press Enter when you're done:\n(ex. 100, 200, 250.50, etc.)\n ";
	cin >> textbookPrice; 

	//input of the computer price
	cout << "\nPlease input the price of your new computer here. Press Enter when you're done:\n(ex. 1000, 2500, 2270.65, etc.)\n ";
	cin >> computerPrice;

	//calculations
	finalPrice = textbookPrice + computerPrice; 

	taxExpense = finalPrice*taxRate;

	finalPrice = finalPrice + taxExpense;

	//output

	cout << "\nBased on the prices you put in for your new laptop (" << textbookPrice << "$) and your new \ncomputer (" << computerPrice << "$), you're final price for the full purchase after tax \nwill be " << finalPrice << "$. \n\nI hope this is helpful! Have a nice day :)\n\n";




}