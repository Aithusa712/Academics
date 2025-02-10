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

  os << date.GetDay() << " " << date.GetMonth()<< " " << date.GetYear();
  return os;
}
