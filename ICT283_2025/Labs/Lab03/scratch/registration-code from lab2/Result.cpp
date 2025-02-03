#include "Result.h" // Registration class declaration/interface

Result::Result() {}
unsigned Result::GetCredits() const { return unit.GetCredits(); }

ostream &operator<<(ostream& os, const Result& R) {
  
  os << R.unit;
  os << "  Mark: " << R.marks << '\n';

  return os;
}

istream &operator>>(istream& input, Result& R) {
   input >> R.unit >> R.marks;


  return input;

}
