// REGIST.H - Registration class definition/interface
// author KRI
// modified smr

#ifndef REGIST_H
#define REGIST_H

#include "unit.h" //#include your own files first
#include "result.h"
#include <iostream>


using namespace std;

const unsigned MaxUnits = 10;

class Registration {
public:
  Registration();

  unsigned GetCredits() const;
  unsigned GetCount() const;


  // These operators have been made friends. They have
  // privileged access to class internals.
  // Very useful for debugging the class, but not very good for class design.
  // We will keep using it for now but you will have a chance in a later lab
  // to redesign this class.



//private:
  long studentID;             // student ID number
  unsigned semester;          // semester year, number
  unsigned count;             // number of units
  Result results[MaxUnits]; // array of results

};

ostream & operator <<( ostream & os, const Registration& R);
istream & operator >>( istream & input, Registration& R );
// No implementation (code body) should be found after the line }; above.
// See topic 1 reading “Absolute C++. Pages 284-293. Separate
// Implementation/Interface. Structs vs Classes” available from My Unit Readings

// A .h file is interface or header file. Implementation should exist in
// the implementation file. Implemention file have .cpp extensions.
// Implementation is the body of the routine/method
// Concept is the same as what you did in ict159.
// So the following implementation needs to be moved to the corresponding
// implementation file (Regist.cpp)

// The method is inlined only if you have empirical evidence that inline would
// improve the run-time execution speed.





#endif

