#include <iostream>
#include <string>

/*
Nick's Even Number Adder
Programmer: Nicholas Paul
Date: October 19th 2017

This is a program that sums all the even numbers from 2-30 inclusive

Notes:

*/

using namespace std;

int main() {


	//variable declaration
	int n = 0;
	bool loopEnder = false;
	int sum = 0;

	//loop for calculations
	while (loopEnder == false) {

		if (n % 2 == 0) {
			sum = sum + n;

		}


		if (n > 30) {
			loopEnder = true;

		}

		n++;
	}

	cout << "The sum of all even numbers from 2-30 inclusive is : " << sum << endl;


}