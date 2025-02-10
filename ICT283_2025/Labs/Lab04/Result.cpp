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

// Helper Function

string Result::convertDate (int day, int month, int year) const{

  string s_day = "";
  string s_year = "";
  string s_month = "";

  s_day = to_string(day);
  s_year = to_string(year);
  
  switch (month) {
  case 1:
    s_month = "January";
    break;
  case 2:
    s_month = "February";
    break;
  case 3:
    s_month = "March";
    break;
  case 4:
    s_month = "April";
    break;
  case 5:
    s_month = "May";
    break;
  case 6:
    s_month = "June";
    break;
  case 7:
    s_month = "July";
    break;
  case 8:
    s_month = "August";
    break;
  case 9:
    s_month = "September";
    break;
  case 10:
    s_month = "October";
    break;
  case 11:
    s_month = "November";
    break;
  case 12:
    s_month = "December";
    break;
  default:
    s_month = "N/A";
  }

  return s_day + " " + s_month + " " + s_year;
}

// Operator Overloading

ostream &operator<<(ostream &os, const Result &R) {

  int day = R.GetDate().GetDay();
  int month = R.GetDate().GetMonth();
  int year = R.GetDate().GetYear();
  string date = R.convertDate(day, month, year); // Call Helper function to convert integer date values into string value

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
