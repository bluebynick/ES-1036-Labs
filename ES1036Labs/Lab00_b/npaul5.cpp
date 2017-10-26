#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// Declare and initialize the variables

	double x1 = 1, y1(5), x2(4), y2 = 7,
		side1 = 0, side2 = 0, distance = 0;

	// Compute the sides of the triangle
	side1 = x2 - x1;
	side2 = y2 - y1;

	// Calculate the distance
	distance = sqrt(side1*side1 + pow(side2, 2.0));

	// Print the distance

	cout << "The distance between points (" << x1 << ',' << y1 << ") and (" << x2 << ',' << y2 << ") is " << distance << endl;
	return 0; //indicate the end of the program

} // end function main