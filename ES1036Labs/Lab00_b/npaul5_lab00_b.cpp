#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// Declare and initialize the variables
	cout << "Hi! And Welcome to Nick's Math! \nToday we will be asking you for the coordinates \nof two points so we can determine the length of \nthe triangle formed from computing the Xs as one \nside and the Ys as another\n\n";

	double x1 = 0 , y1(5), x2(4), y2 = 7,
		side1 = 0, side2 = 0, hypot = 0;

	cout << "To begin, please input the x-position of the first point.\nEnter x1 here:";
	cin >> x1;

	cout << "Next, please input the y-position of the first point.\nEnter y1 here:";
	cin >> y1;

	cout << "Please input the x-position of the second point.\nEnter x2 here:";
	cin >> x2;

	cout << "Finally, please input the y-position of the second point.\nEnter y2 here:";
	cin >> y2;

	// Compute the sides of the triangle
	side1 = x2 - x1;
	side2 = y2 - y1;

	// Calculate the distance
	hypot = sqrt(pow(side1, 2.0) + pow(side2, 2.0));

	// Print the distance

	cout << "\nThe sides of the triangle measure: " <<side1<< ", " <<side2<< " and " << hypot<< " \nand the perimeter of the traingle is: " << side1 + side2 + hypot << ". \n\nHave a nice day!\n" << endl;
	return 0; //indicate the end of the program

} // end function main