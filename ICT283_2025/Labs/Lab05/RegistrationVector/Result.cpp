#include "Result.h" 

// Default Constructors

Result::Result() {
  m_unit = Unit();
  m_date = Date();
  m_marks = 0;
}

// Getters

int Result::GetCredits() const { return m_unit.GetCredits(); }

Unit Result::GetUnit() const { return m_unit; }

Date Result::GetDate() const { return m_date; }

int Result::GetMarks() const { return m_marks; }

// Setters

void Result::SetUnit(Unit &unit) { m_unit = unit; }

void Result::SetDate(Date &date) { m_date = date; }

void Result::SetMarks(int marks) { m_marks = marks; }

// Operator Overloading

ostream &operator<<(ostream &os, const Result &R) {

  int day = R.GetDate().GetDay();
  int month = R.GetDate().GetMonth();
  int year = R.GetDate().GetYear();
  string date = ConvertDate(day, month, year); // Call Helper function to convert integer date values into string value

  os << R.GetUnit();
  os << "  Mark: " << R.GetMarks() << '\n';
  os << "  Date: " << date << '\n';
  return os;
}

istream &operator>>(istream &input, Result &R) {

  Unit tempUnit;
  Date tempDate;
  int tempMarks;

  input >> tempUnit >> tempMarks >> tempDate;

  R.SetUnit(tempUnit);
  R.SetMarks(tempMarks);
  R.SetDate(tempDate);
  return input;
}
