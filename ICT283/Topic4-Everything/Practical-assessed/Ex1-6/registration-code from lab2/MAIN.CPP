// Count the number of courses taken by the student, calculate total credits
// author KRI
// modified smr

// MAIN.CPP - Case Study, Student Registration main program

// main program is the application program.
// It would have the main() function at the top, and possibly
// other functions/procedures below, like what you did in ict159

// #include your header files first, the the library header files.

// These are your header files.
#include "unit.h"  // Course class declaration/interface
#include "regist.h"  // Registration class declaration/interface
#include "result.h"
// The library header files
#include <iostream>
#include <fstream>

// A namespace is used to encapsulate code and data.
// Files/functions/procedures/methods/structs/classes are also
// encapsulation mechanisms. But namespaces go beyond these basics.
// The line below exposes the std namespace. Professional developers and
// Computer Scientists would like such open slather exposure of an
// encapsulation mechanism. However, we are still learning, and this opening
// of the std namespace is for convinience only to save a lot of typing.
using namespace std;  // check textbook for detials of the namespace concept

// Main program:
// Open an input file stream, read a Registration object,
// including its list of courses. Redisplay all information,
// and calculate the total credits taken. Write the results
// to a file stream.

int main()
{
  ifstream infile( "rinput.txt" ); //infile is an object on runtime stack
  if( !infile ) return -1;

  Registration R;  //R is now an object, like what you did in ict167
                   // As the keyword new is not used, object R exists
                   // on the runtime stack of main() and not on the heap
                   // concept of runtime stack, and various memory locations
                   // see ict170

  infile >> R;   //This is a subroutine call, to a function operator>>
                    // first parameter is infile, second parameter is R.
                    // syntax is different to what you have studied before
                    // but you will get used to it as the line just says
                    // from infile load into R
  unsigned totalCredits = R.GetCredits();

  ofstream ofile( "routput.txt" );

// Use a debugger and track down the calls made "behind the scene"
  ofile << R        // also a subroutine call. Can you guess what it means?
    << "Number of courses = " << R.GetCount() << '\n'
    << "Total credits     = " << totalCredits << '\n';

  // Declare and initialize a Course, and modify
  // its credits.


//  For Lab 3, you should comment out this line and the next 3 lines

//  Course aCourse( "MTH_3020", 'B', 2 );
// aCourse.SetCredits( 5 );
//  cout << aCourse << endl; // the operator << for Course is called


  return 0;
}

