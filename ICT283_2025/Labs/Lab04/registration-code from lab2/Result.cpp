#include "Result.h" // Registration class declaration/interface

Result::Result() {}
unsigned Result::GetCredits() const { return unit.GetCredits(); }

Unit Result::GetUnit() const { return unit; }
unsigned Result::GetMarks() const { return marks; }

void Result::SetUnit(Unit &unit) { this->unit = unit; }
void Result::SetMarks(unsigned marks) { this->marks = marks; }
ostream &operator<<(ostream &os, const Result &R) {

  os << R.GetUnit();
  os << "  Mark: " << R.GetMarks() << '\n';

  return os;
}

istream &operator>>(istream &input, Result &R) {

  Unit tempUnit;
  unsigned tempMarks;

  input >> tempUnit >> tempMarks;

  R.SetUnit(tempUnit);
  R.SetMarks(tempMarks);

  return input;
}
