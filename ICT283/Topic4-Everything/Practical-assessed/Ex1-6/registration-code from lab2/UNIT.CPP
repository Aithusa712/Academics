// COURSE.CPP - Course class implementation

#include "unit.h"
#include <string>
using namespace std;
Unit::Unit() : unitName(""), unitID(""), credits(0) {}

Unit::Unit( const string& unitName, const string& unitID,unsigned cred )
            : unitName(unitName), unitID(unitID), credits(cred) {}

unsigned Unit::GetCredits() const
{
    return credits;
}

void Unit::SetCredits(unsigned cred)
{
    credits = cred;
}

const string& Unit::GetUnitName() const
{
    return unitName;
}

void Unit::SetUnitName(const string& unitName)
{
    this->unitName = unitName;
}


// The following routine does not belong to the Course class, so it is NOT a method
// You can see that the prefix Course:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.
istream& operator>>(istream& input, Unit& U) {
    input >> U.unitName >> U.unitID >> U.credits;
    return input;
}


// The following routine does not belong to the Course class, so it is NOT a method
// You can see that the prefix Course:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.
ostream& operator<<(ostream& os, const Unit& U) {
    os << "Unit Name: " << U.unitName << endl;
    os << "Unit ID: " << U.unitID << endl;
    os << "Credits: " << U.credits << endl;
    return os;
}
