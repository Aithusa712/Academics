#include "Unit.h"
// The library header files
#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

const unsigned MaxUnits = 10;

class Result {
public:
  Result();
  unsigned GetCredits() const;
  // These operators have been made friends. They have
  // privileged access to class internals.
  // Very useful for debugging the class, but not very good for class design.
  // We will keep using it for now but you will have a chance in a later lab
  // to redesign this class.
  friend ostream & operator <<( ostream& os, const Result& R);

  friend istream & operator >>( istream& input, Result& R );

private:
  Unit unit;
  unsigned marks; // marks
};
