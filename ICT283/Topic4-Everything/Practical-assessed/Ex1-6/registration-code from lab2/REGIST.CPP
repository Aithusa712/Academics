// REGIST.CPP - Registration class implementation.

#include "regist.h"
#include <string>
using namespace std;
Registration::Registration() : studentID(0), semester(0), count(0) {}

unsigned Registration::GetCredits() const
{
  unsigned sum = 0;
  for(unsigned i = 0; i < count; i++)
    sum += results[i].GetUnit().GetCredits();

  return sum;
}


unsigned Registration::GetCount() const {
    return count;
}
// The following routine does not belong to the Registration class, so it is NOT a method
// You can see that the prefix Registration:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.

istream& operator>>(istream& input, Registration& R) {
    input >> R.studentID >> R.semester >> R.count;

    for (unsigned i = 0; i < R.count; i++)
        input >> R.results[i];

    return input;
}


// The following routine does not belong to the Registration class, so it is NOT a method
// You can see that the prefix Registration:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.
ostream & operator <<( ostream & os, const Registration & R )
{
  os << "Student ID: " << R.studentID << '\n'
     << "Semester:   " << R.semester << '\n';

  for(unsigned i = 0; i < R.count; i++)
    os << R.results[i] << '\n';

  return os;
}
