// COURSE.CPP - Course class implementation

#include "Unit.h"

#include <string.h>  // C string library needed here for the C string routines.
                     // revise your ict159 work if forgotten.

Unit::Unit()
{
  unitName[0] = '\0'; // it is a char * string, not a C++ string object.
}

Unit::Unit( const char * nam, char * id,
                unsigned cred )
{
  strncpy( unitName, nam, UnitNameSize );  //strncpy needed from string.h
  credits = cred;
}


// The following routine does not belong to the Course class, so it is NOT a method
// You can see that the prefix Course:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.
istream & operator >>( istream & input, Unit & unit )
{
  input >> unit.unitName>> unit.unitID >> unit.credits;
  return input;
}


// The following routine does not belong to the Course class, so it is NOT a method
// You can see that the prefix Course:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.
ostream & operator <<( ostream & os, const Unit & unit)
{
  os << "  Unit:  " << unit.unitName << '\n'
     << "  Unit ID: " << unit.unitID<< '\n'
     << "  Credits: " << unit.credits << '\n';
  return os;
}
