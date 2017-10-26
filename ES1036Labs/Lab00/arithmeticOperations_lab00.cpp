/* ---------Arithmetic_Operations_lab0.cpp
   This program shows some simple arithmetic operations-------*/

//Review class handouts for writing the line comments and paragraph comments inside the code

#include <iostream>
using namespace std;

int main()
{
   int integer1 = 0;  // first number to be input by user
   int integer2(0);  // second number to be input by user
   int result;    // variable in which sum will be stored

   cout << "Enter first integer: ";  // prompt; "\n" represents a new line
   cin >> integer1;                  // read an integer

   cout << "Enter second integer: "; // prompt
   cin >> integer2;                  // read an integer

   result = integer1 / integer2 * integer1 + integer2;  
   
   /*In the above statement, the output of the arithmetic operation 
   is assigned to the variable result. Here. '/' represents integer division and '*' 
   represents multiplication. In C++, arithmetic operations
   follow the order of operation according to
   the BODMAS principle we learnt in our high schools.
   Review BODMAS: http://www.mathsisfun.com/operation-order-bodmas.html
   */
   
   /*Please read lab_0 handout and ask questions to your TAs
     before working on the follwoing commented statements*/
   
   result = integer1 * integer2 / integer1 + integer2; 
   //result = integer1 * integer2 / (integer1 + integer2);
   //result = integer2+ integer1 / integer2 * integer1 ;
   
   //cout << "The result is " << result << endl; // print result
   cout << " 1 / 5 = " << 1 / 5 << endl;
   cout << " 1.0 / 5 = " << 1.0 / 5 << endl;
   cout << "The result is " << result << "\n"; // print result
   
   return 0;   // indicate that the program ended successfully

} // end function main
