// REGIST.CPP - Registration class implementation.

#include "regist.h"


Registration::Registration()
{
  count = 0;
}

unsigned Registration::GetCredits() const
{
  unsigned sum = 0;
  for(unsigned i = 0; i < count; i++)
    sum += results[i].GetUnit().GetCredits();

  return sum;
}


// The following routine does not belong to the Registration class, so it is NOT a method
// You can see that the prefix Registration:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.

istream & operator >>( istream & input, Registration & R )
{
  input >> R.studentId >> R.semester >> R.count;

  for(unsigned i = 0; i < R.count; i++)
    input >> R.results[i];  // track down which >> operator is called. Hint: look at what is being input.

  return input;
}


// The following routine does not belong to the Registration class, so it is NOT a method
// You can see that the prefix Registration:: isn't there.
// So it is general routine, just a function that you would have learnt in
// ict159, but this one has an unusual name.
ostream & operator <<( ostream & os, const Registration & R )
{
  os << "Student ID: " << R.studentId << '\n'
     << "Semester:   " << R.semester << '\n';

  for(unsigned i = 0; i < R.count; i++)
    os << R.results[i] << '\n'; //no match for 'operator'

  return os;
}
