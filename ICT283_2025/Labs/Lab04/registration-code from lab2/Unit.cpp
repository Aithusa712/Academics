// COURSE.CPP - Unit class implementation

#include "Unit.h"

Unit::Unit() {
unitName = " ";
unitId = " ";
credits = 0;
}

Unit::Unit(const string unitName, const string unitId, unsigned credits) {
  this->unitName = unitName;
  this->unitId = unitId;
  this->credits = credits;
}


string Unit::GetUnitName() const{return unitName;}
string Unit::GetUnitId() const{return unitId;}
unsigned Unit::GetCredits() const { return credits; }

void Unit::SetUnitName(const string unitName){this->unitName = unitName;}
void Unit::SetUnitId(const string unitId){this->unitId = unitId;}
void Unit::SetCredits(const unsigned credits) { this->credits = credits; }


istream& operator>>(istream& input, Unit& unit) {
  string tempUnitName;
  string tempUnitId;
  unsigned tempCredits;
  input >> tempUnitName >> tempUnitId >> tempCredits;

  unit.SetUnitName(tempUnitName);
  unit.SetUnitId(tempUnitId);
  unit.SetCredits(tempCredits);
  return input;
}

// The following routine does not belong to the Unit class, so it is NOT a
// method You can see that the prefix Unit:: isn't there. So it is general
// routine, just a function that you would have learnt in ict159, but this one
// has an unusual name.
ostream& operator<<(ostream& os, const Unit& unit) {
  os << "  Unit ID:  " << unit.GetUnitId() << '\n'
     << "  Unit Name: " << unit.GetUnitName() << '\n'
     << "  Credits: " << unit.GetCredits() << '\n';
  return os;
}
