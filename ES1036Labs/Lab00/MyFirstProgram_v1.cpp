// MyFirstProgram_v1.cpp
// A first program in C++.
// A double-forward-slash ("//") represents comments which are 
// ignored by the compiler

// A "#" sign represents pre-processor directive 
#include <iostream>  // this line tells the compiler to include the code
                     // for I/O manipulations ('cin' and 'cout')

using namespace std; // 'using' directive is specified by including the using 
                     // and namespace keywords,followed by the name of a namespace 
                     // and a semicolon. This particular namespace directive enbles 
                     // one to access technologies provided by the C++ stnadard
                     // library 

// function 'main' begins program execution
int main()
{								//beigns the body of the main funciton
   
	cout << "Hello World!\n";//'\'represents escape sequence. '\n' means position 
								//the screen cursor at the begining of the next line

   return 0;					// indicate that program ended successfully

}								// end function main
