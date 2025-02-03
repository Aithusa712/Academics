// COURSE.CPP - Unit class implementation

#include "Unit.h"

#include <string.h> // C string library needed here for the C string routines.
                    // revise your ict159 work if forgotten.

Unit::Unit() {
  unitName[0] = '\0'; // it is a char * string, not a C++ string object.
}

Unit::Unit(const char* unitName, const char* sect, unsigned credits) {
  strncpy(this->unitName, unitName,
          UnitNameSize); // strncpy needed from string.h
  strncpy(this->unitId, unitId, UnitIdSize);
  this->credits = credits;
}


unsigned Unit::GetCredits() const{
return credits;
}
void Unit::SetCredits(const unsigned credits){
this->credits = credits;
}

// The following routine does not belong to the Unit class, so it is NOT a
// method You can see that the prefix Unit:: isn't there. So it is general
// routine, just a function that you would have learnt in ict159, but this one
// has an unusual name.
istream& operator>>(istream& input, Unit& U) {
  input >> U.unitName >> U.unitId >> U.credits;
  return input;
}

// The following routine does not belong to the Unit class, so it is NOT a
// method You can see that the prefix Unit:: isn't there. So it is general
// routine, just a function that you would have learnt in ict159, but this one
// has an unusual name.
ostream& operator<<(ostream& os, const Unit& U) {
  os << "  Unit ID:  " << U.unitId << '\n'
     << "  Unit Name: " << U.unitName<< '\n'
     << "  Credits: " << U.credits << '\n';
  return os;
}
