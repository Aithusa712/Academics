#include "Date.h"

// Default Constructor

Date::Date() {

  m_day = 0;
  m_month = 0;
  m_year = 0;
}

// Getters

int Date::GetDay() const { return m_day; }

int Date::GetMonth() const { return m_month; }

int Date::GetYear() const { return m_year; }

// Setters

void Date::SetDay(int day) { m_day = day; }

void Date::SetMonth(int month) { m_month = month; }

void Date::SetYear(int year) { m_year = year; }

// Operator Overloading

istream &operator>>(istream &input, Date &date) {
  int day = 0;
  int month = 0;
  int year = 0;

  input >> day >> month >> year;
  date.SetDay(day);
  date.SetMonth(month);
  date.SetYear(year);

  return input;
}

ostream &operator<<(ostream &os, const Date &date) {

  os << date.GetDay() << " " << date.GetMonth() << " " << date.GetYear();
  return os;
}

// Helper Function

string ConvertDate(int day, int month, int year) {

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
